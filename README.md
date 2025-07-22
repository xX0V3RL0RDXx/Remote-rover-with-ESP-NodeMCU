# Remote Rover with ESP8266 (NodeMCU) 🚗📡

This project allows you to remotely control a small four-wheel rover using a NodeMCU (ESP8266) over Wi-Fi. The rover responds to commands such as forward, backward, left, right, and stop — all from a simple web browser interface.

## 🚀 Features
- Control DC motors via an H-Bridge (e.g., L298N)
- Simple web-based control panel
- Wi-Fi access point hosted directly on the ESP
- LED indicators for rover status (e.g., direction or stop)

## 🔧 Hardware Requirements
- NodeMCU ESP8266
- L298N H-Bridge motor driver
- 2 or 4 DC gear motors (TT motors)
- Power supply (battery pack or Li-Ion cells)
- Jumper wires (and optionally a breadboard)
- 2x LEDs with appropriate resistors

## 🛠️ How to Use
1. Upload the code to the ESP8266 using Arduino IDE
2. Connect the motors, power supply, LEDs, and driver.
3. Power on the NodeMCU – it will create a Wi-Fi hotspot
4. Connect to the ESP’s network (SSID and password in the code)
5. Open the control interface in your browser (HTML page)
6. Start driving your rover!

---
