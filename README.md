Smart Home Environment Monitoring System:

A hardware-free smart home monitoring system built and tested entirely using online simulator(Wokwi). It monitors temperature, humidity, light intensity, and distance, then displays results on an LCD, prints them to the Serial Monitor, and triggers LED alerts based on thresholds.

Objective:
Design a low-cost smart home environment monitoring system that measures key environmental parameters and provides real-time feedback — all simulated without physical hardware

Features and Components:
1.Temperature Monitoring — DHT22 sensor;
2.Humidity Monitoring — DHT22 sensor;
3.Light Intensity Detection — LDR (Light Dependent Resistor);
4.Distance Measurement — HC-SR04 ultrasonic sensor;
5.LCD Display — 16x2 I2C LCD shows live readings;
6.Serial Monitor Output — real-time data logging;
7.Alarm Using Buzzer — alerts on threshold breach;
8.LED Status Indicators — visual status per condition.

Components Used and their Purposes:
1.Arduino Uno-Microcontroller;
2.DHT22 (or DHT11)-Temperature & humidity;
3.LDR + resistor-Light intensity;
4.HC-SR04-Distance measurement;
5.16x2 LCD (I2C)-Display;
6.Buzzer-Alarm;
7.Red / Yellow / Green LEDs-Status indicators;
8.Resistors-Current limiting;

Simulators used:
WOWKI-full multi-sensor simulation.

How It Works:
Sensors read environmental data continuously.
Values are displayed on the LCD and printed to the Serial Monitor.
Threshold logic triggers alerts:
Condition-Action:
Temperature > 30°C-Buzzer ON + Red LED;
Humidity < 40%-Yellow LED;
Light too low / too high-Green LED status change;
Distance too close-Buzzer alarm.

Limitations:
Simulated environment, not real-world hardware validation.
Sensor accuracy reflects simulator values, not physical devices.
Requires internet access for Wokwi simulation.

Future Improvements:
Add Wi-Fi (ESP32) for cloud logging.
Add mobile app or web dashboard.
Add more sensors (gas, motion, pressure).
Store historical data in a database.

License:
This project is for educational purposes. Feel free to use and modify it.
