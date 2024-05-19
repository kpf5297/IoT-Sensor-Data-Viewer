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

## License

This project is licensed under the MIT License.




```md
# IoT Sensor Data Viewer

## Description
This project visualizes sensor data from an IoT setup, including temperature, microphone, and IMU (accelerometer and gyroscope) readings. The data is collected using a Raspberry Pi RP2040, sent to a Flask server running on a Raspberry Pi 4B, and displayed in a C# application.

## Setup Instructions

### Setting Up the Raspberry Pi 4B

1. **Install Raspbian OS on your Raspberry Pi 4B.**
2. **Update your system:**
   ```sh
   sudo apt update
   sudo apt upgrade
   ```
3. **Install MariaDB:**
   ```sh
   sudo apt install mariadb-server
   ```
4. **Secure your MariaDB installation:**
   ```sh
   sudo mysql_secure_installation
   ```
5. **Create the database and user:**
   ```sql
   sudo mysql -u root -p
   CREATE DATABASE SensorData;
   CREATE USER 'test'@'localhost' IDENTIFIED BY 'Monkey79';
   GRANT ALL PRIVILEGES ON SensorData.* TO 'test'@'localhost';
   FLUSH PRIVILEGES;
   ```
6. **Create the necessary table in the database:**
   ```sql
   USE SensorData;
   CREATE TABLE SensorReadings (
       id INT AUTO_INCREMENT PRIMARY KEY,
       timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
       temperature FLOAT,
       mic INT,
       accelX FLOAT,
       accelY FLOAT,
       accelZ FLOAT,
       gyroX FLOAT,
       gyroY FLOAT,
       gyroZ FLOAT
   );
   ```

### Setting Up the Flask Server

1. **Install Python and necessary libraries:**
   ```sh
   sudo apt install python3 python3-pip
   pip3 install flask mysql-connector-python
   ```
2. **Copy the `app.py` file to your Raspberry Pi.**
3. **Run the Flask server:**
   ```sh
   python3 app.py
   ```

### Setting Up the Raspberry Pi RP2040

1. **Install Arduino IDE and configure it for RP2040.**
2. **Open the `SensorDataCollector.ino` file in Arduino IDE.**
3. **Upload the code to the RP2040.**

### Running the C# Application

1. **Clone the repository and open the solution in Visual Studio.**
2. **Build and run the C# application to start visualizing the sensor data.**

## Additional Information

### Cloning the Repository

```sh
git clone https://github.com/yourusername/IoT-Sensor-Data-Viewer.git
```
Replace `yourusername` with your GitHub username.

### Organizing Your Project Files

- Create directories for the Arduino code, Python code, and any other necessary files.
- Create a text file for the setup instructions.

Here’s an example structure:

```
IoT-Sensor-Data-Viewer/
├── Arduino/
│   └── SensorDataCollector.ino
├── Python/
│   └── app.py
├── CSharp/
│   └── SensorDataViewer.sln
├── setup_instructions.md
└── README.md
```

### Adding, Committing, and Pushing the Files

```sh
cd IoT-Sensor-Data-Viewer
git add .
git commit -m "Initial commit with project files"
git push origin main
```

This guide provides step-by-step instructions for setting up the IoT Sensor Data Viewer project, from installing and configuring software on the Raspberry Pi to running the C# application for data visualization.
```

You can copy and paste the above text directly into your `README.md` file in your GitHub repository. This will create a well-formatted document with all the necessary setup instructions.
