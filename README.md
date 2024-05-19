# IoT Sensor Data Viewer

## Description

IoT Sensor Data Viewer is a comprehensive system designed to collect, store, and visualize sensor data in real-time. This project leverages the power of IoT devices, such as Raspberry Pi and Raspberry Pi RP2040, to gather data from various sensors. The data is stored in a MariaDB database managed by a Flask server and displayed using a C# Windows application. The system is designed for real-time monitoring and historical data analysis, providing valuable insights into sensor readings.

## Features

- **Real-Time Data Collection and Visualization**
- **Historical Data Analysis**
- **User-Friendly Interface**
- **Auto-Update Feature**

## Technologies Used

- **Languages**: Python, C#
- **Frameworks**: Flask, .NET Framework
- **Databases**: MariaDB
- **Hardware**: Raspberry Pi 4B, Raspberry Pi RP2040
- **Sensors**: Temperature Sensor, Microphone Sensor, Accelerometer, Gyroscope

## Prerequisites

- **Hardware**: Raspberry Pi 4B, Raspberry Pi RP2040, Sensors (Temperature, Microphone, Accelerometer, Gyroscope), SD Card (32GB), Power Supply
- **Software**: Raspbian OS, Python 3, Flask, MariaDB, Arduino IDE, Visual Studio, .NET Framework

## Installation and Usage

### Setting Up Raspberry Pi 4B

1. Install Raspbian OS on your Raspberry Pi 4B.
2. Install and configure MariaDB.
3. Set up the Flask server to manage data collection and retrieval.

### Setting Up Raspberry Pi RP2040

1. Install Arduino IDE and configure it for RP2040.
2. Upload the sensor data collection code to the RP2040.

### Running the C# Application

1. Clone the repository and open the solution in Visual Studio.
2. Build and run the C# application to start visualizing the sensor data.

## Contributing

Contributions are welcome! Fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License.

## Contact

For any questions or issues, please open an issue in the repository or contact the maintainer.
