#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>
#include "SensorData.h"

// Network credentials
const char* ssid = "ssid";  // The SSID should match exactly
const char* password = "Password";
const byte desiredBSSID[] = { 0x12, 0x34, 0x56, 0xC5, 0xBD, 0x3C };  // Replace with your network's BSSID

// Server details
const char* serverAddress = "192.168.1.152";  // Replace with your Raspberry Pi's IP address
const int port = 5000;

WiFiClient wifiClient;
HttpClient client = HttpClient(wifiClient, serverAddress, port);

// LED pin
const int ledPin = LED_BUILTIN;

bool isDesiredNetwork(uint8_t* bssid) {
    for (int i = 0; i < 6; i++) {
        if (bssid[i] != desiredBSSID[i]) {
            return false;
        }
    }
    return true;
}

void connectToWiFi() {
    Serial.println("Scanning for networks...");
    int numNetworks = WiFi.scanNetworks();
    Serial.println("Scan completed");

    if (numNetworks == 0) {
        Serial.println("No networks found");
        return;
    }

    bool foundNetwork = false;
    for (int i = 0; i < numNetworks; ++i) {
        Serial.print("Network name: ");
        Serial.println(WiFi.SSID(i));

        uint8_t bssid[6];
        WiFi.BSSID(i, bssid);

        if (isDesiredNetwork(bssid)) {
            Serial.print("Connecting to: ");
            Serial.println(WiFi.SSID(i));
            WiFi.begin(WiFi.SSID(i), password);
            foundNetwork = true;
            break;
        }
    }

    if (!foundNetwork) {
        Serial.println("Desired network not found");
        return;
    }

    // Check the connection status
    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {  // 10 seconds timeout
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("WiFi connected");
        // Serial.print("IP Address: ");
        // Serial.println(WiFi.localIP());
        digitalWrite(ledPin, HIGH);  // Solid LED to indicate connection
    } else {
        Serial.println("Failed to connect to WiFi");
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    // Initialize the sensor
    SensorData::getInstance().begin();

    // Connect to WiFi
    connectToWiFi();
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi not connected, attempting to reconnect...");
        connectToWiFi();
    } else {
        Serial.println("Sending data to server...");
        digitalWrite(ledPin, LOW);  // Turn off LED before blinking for data transmission

        // Read data from the sensor
        float temperature = SensorData::getInstance().readTemperature();

        // Dummy data for other sensors (or real data if available)
        float humidity = 0.0;  // Assuming no humidity sensor, set to 0.0
        int mic = 100;         // Dummy microphone data
        float accelX, accelY, accelZ;
        SensorData::getInstance().readAcceleration(accelX, accelY, accelZ);
        float gyroX, gyroY, gyroZ;
        SensorData::getInstance().readGyroscope(gyroX, gyroY, gyroZ);

        // Create JSON payload
        String payload = "{\"temperature\":";
        payload += temperature;
        payload += ",\"humidity\":";
        payload += humidity;
        payload += ",\"mic\":";
        payload += mic;
        payload += ",\"accelX\":";
        payload += accelX;
        payload += ",\"accelY\":";
        payload += accelY;
        payload += ",\"accelZ\":";
        payload += accelZ;
        payload += ",\"gyroX\":";
        payload += gyroX;
        payload += ",\"gyroY\":";
        payload += gyroY;
        payload += ",\"gyroZ\":";
        payload += gyroZ;
        payload += "}";

        // Blink LED rapidly to indicate data transmission
        for (int i = 0; i < 6; ++i) {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
            delay(100);
        }

        client.beginRequest();
        client.post("/add_data");
        client.sendHeader("Content-Type", "application/json");
        client.sendHeader("Content-Length", payload.length());
        client.beginBody();
        client.print(payload);
        client.endRequest();

        int statusCode = client.responseStatusCode();
        String response = client.responseBody();

        Serial.print("Status code: ");
        Serial.println(statusCode);
        Serial.print("Response: ");
        Serial.println(response);

        delay(500);  // Wait 5 seconds before sending next data
    }
}
