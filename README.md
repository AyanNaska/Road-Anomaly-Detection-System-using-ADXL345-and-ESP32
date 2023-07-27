# Road-Anomaly-Detection-System-using-ADXL345-and-ESP32
![Screenshot_20230727-232427](https://github.com/AyanNaska/Road-Anomaly-Detection-System-using-ADXL345-and-ESP32/assets/113054786/ad54709e-b98a-4343-a6aa-540c2076d782)

## Overview

This repository contains the Arduino code and documentation for a Road Anomaly Detection System. The system is designed to detect jerks and unusual movements using an ADXL345 accelerometer sensor interfaced with an ESP32 microcontroller. When a jerk is detected, the system sends the data to ThingSpeak, an Internet of Things (IoT) platform, for further analysis and visualization.

## Table of Contents

- [Project Description](#project-description)
- [Hardware Requirements](#hardware-requirements)
- [Setup Instructions](#setup-instructions)
- [Circuit Diagram](#circuit-diagram)
- [Configuration](#configuration)
- [Demo](#demo)
- [Contributing](#contributing)
- [License](#license)

## Project Description

The Road Anomaly Detection System aims to enhance road safety by identifying jerks and sudden movements that might be indicative of potholes, speed bumps, or other irregularities on the road. The system uses the ADXL345 accelerometer sensor to measure acceleration in three axes (X, Y, and Z) and calculates the total jerk. If the total jerk exceeds a predefined threshold, the data is sent to ThingSpeak, where it can be further analyzed or used for real-time monitoring of road conditions.

## Hardware Requirements

To build this project, you will need the following components:

- ESP32 development board
- ADXL345 accelerometer sensor
- Connecting wires
- Power supply (e.g., USB cable)

## Setup Instructions

1. **Install Arduino IDE**: Download and install the Arduino IDE from the official website (https://www.arduino.cc/en/software).

2. **Add ESP32 Board**: Follow the instructions here (link_to_ESP32_setup_instructions) to add the ESP32 board to the Arduino IDE.

3. **Wire Connections**: Connect the ADXL345 sensor to the ESP32 as described in the code comments.

4. **WiFi Configuration**: Replace the placeholder values in the code for `ssid` and `password` with your WiFi network credentials.

5. **ThingSpeak API Key**: Create a ThingSpeak account (https://thingspeak.com/) and a channel. Replace `Your_ThingSpeak_API_Key` and `YOUR_CHANNEL_ID` in the code with your API key and channel ID, respectively.

6. **Upload Code**: Open the Arduino IDE, load the provided code, and upload it to your ESP32 board.

7. **Monitor Data**: Once the system is running, the ESP32 will send data to ThingSpeak whenever a jerk is detected by the ADXL345 sensor.

## Circuit Diagram

Include an image or diagram of your circuit setup here. You can use Fritzing or any other tool to create the circuit diagram.

## Configuration

Explain any additional configuration or customization options in this section. For example, you might want to calibrate the jerk threshold or modify the data sent to ThingSpeak.


