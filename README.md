# Sensor Data Viewer

## Overview
Sensor Data Viewer is a comprehensive system designed to collect, process, and visualize sensor data from an Arduino device. The system includes a Python Flask server to handle data storage and retrieval, an iOS app to display the data, and an Apple Watch app to monitor key sensor metrics such as temperature, pitch, and roll.

## Features
- **Arduino**: Collects data from temperature, accelerometer, and gyroscope sensors.
- **Python Flask Server**: Handles data storage in a MariaDB database and provides endpoints for data retrieval.
- **iOS App**: Displays sensor data with auto-update functionality.
- **Apple Watch App**: Shows real-time temperature, pitch, and roll with auto-update functionality.
- **WiFi Connection Indicators**: Uses the Arduino built-in LED to indicate WiFi connection status and data transmission.

## Requirements
- **Hardware**:
  - Arduino with WiFi capabilities (e.g., Arduino Nano 33 IoT)
  - Sensors: Temperature, Accelerometer, Gyroscope
  - Raspberry Pi (for running the Flask server)
  - Apple iPhone
  - Apple Watch

- **Software**:
  - Arduino IDE
  - Xcode
  - Python 3
  - Flask
  - MariaDB

## Installation

### Arduino Setup
1. **Clone the Repository**:
    ```bash
    git clone -b pitch-and-roll https://github.com/<your-username>/SensorDataViewer.git
    cd SensorDataViewer
    ```

2. **Upload Code to Arduino**:
    - Open `WiFiProject.ino` in the Arduino IDE.
    - Configure your network credentials and BSSID in the code.
    - Upload the code to your Arduino.

### Python Flask Server
1. **Install Dependencies**:
    ```bash
    pip install flask mysql-connector-python
    ```

2. **Setup MariaDB**:
    - Install MariaDB on your Raspberry Pi.
    - Create a database and user for the project.
    - Import the SQL schema provided in the repository.

3. **Run the Server**:
    ```bash
    python app.py
    ```

### iOS App
1. **Open Project in Xcode**:
    - Open `SensorDataViewer.xcodeproj` in Xcode.

2. **Configure Network Settings**:
    - Update the server URL in `SensorDataViewModel.swift` to match your Flask server's IP address.

3. **Build and Run**:
    - Build and run the project on your iPhone.

### Apple Watch App
1. **Add Watch Target**:
    - Ensure the Apple Watch target is added to the Xcode project.

2. **Configure Network Settings**:
    - Update the server URL in `SensorDataViewModel.swift` for the watch app.

3. **Build and Run**:
    - Build and run the project on your Apple Watch.

## Usage

### Arduino Indicators
- **Trying to Connect**: LED blinks slowly.
- **Connected**: LED is solid.
- **Transmitting Data**: LED blinks rapidly.

### iOS App
- Displays real-time sensor data with options to view data from the last hour, day, or week.
- Auto-update functionality to refresh data at regular intervals.

### Apple Watch App
- Displays temperature, pitch, and roll with a 1-minute data range.
- Auto-update switch to refresh data at regular intervals.

## Contributing
We welcome contributions! Please fork the repository and submit pull requests to the `pitch-and-roll` branch.

## License
This project is licensed under the MIT License.

## Acknowledgments
Special thanks to the contributors and the open-source community for their invaluable support and resources.

---

For detailed setup instructions, refer to the `SETUP.md` file in the repository.
