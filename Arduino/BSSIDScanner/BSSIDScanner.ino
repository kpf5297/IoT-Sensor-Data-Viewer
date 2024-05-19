#include <WiFiNINA.h>

void setup() {
    Serial.begin(115200);

    // Check for the WiFi module:
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        while (true);
    }

    // Scan for nearby networks:
    int numNetworks = WiFi.scanNetworks();
    Serial.println("Scan completed");

    if (numNetworks == 0) {
        Serial.println("No networks found");
    } else {
        Serial.print(numNetworks);
        Serial.println(" networks found");
        for (int i = 0; i < numNetworks; ++i) {
            Serial.print("Network name: ");
            Serial.println(WiFi.SSID(i));

            Serial.print("Signal strength (RSSI): ");
            Serial.println(WiFi.RSSI(i));

            Serial.print("Encryption type: ");
            Serial.println(WiFi.encryptionType(i));

            Serial.print("BSSID: ");
            uint8_t bssid[6];
            WiFi.BSSID(i, bssid);  // Corrected function call
            for (int j = 0; j < 6; ++j) {
                if (bssid[j] < 16) {
                    Serial.print("0");
                }
                Serial.print(bssid[j], HEX);
                if (j < 5) {
                    Serial.print(":");
                }
            }
            Serial.println();
            Serial.println("-----------------------");
        }
    }
}

void loop() {
    // Nothing to do here
}
