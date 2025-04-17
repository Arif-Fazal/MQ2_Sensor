# MQ2 Gas Sensor Analog Reading and LED Alert

This project is based on reading analog values from the **MQ2 gas sensor** using an Arduino. The analog readings are mapped to corresponding gas concentration levels using **logarithmic plotting**, following the guidelines provided in the sensor's datasheet.

An **LED** is used to provide a **visual indication** whenever a predefined gas concentration threshold is exceeded. The MQ2 sensor can be calibrated to detect multiple gases such as:

- LPG
- Smoke
- Alcohol
- Propane
- Hydrogen
- Methane
- Carbon Monoxide

## Features

- Reads analog values from the MQ2 gas sensor
- Converts raw values to gas concentration using logarithmic scale
- Alerts via LED when threshold is reached
- Can be calibrated for different gases

##  Reference

Further details about the MQ2 gas sensor and how to interface it with Arduino can be found at:

[MQ2 Gas Sensor with Arduino - Last Minute Engineers](https://lastminuteengineers.com/mq2-gas-senser-arduino-tutorial/)

##  Project Files

- `main.ino` – Arduino sketch with sensor reading and LED logic
- `README.md` – This documentation file

##  Hardware Used

- MQ2 Gas Sensor
- Arduino Board (Uno, Nano, etc.)
- LED and resistor
- Jumper wires
- Breadboard

---

Feel free to fork, improve, or expand on this project!
