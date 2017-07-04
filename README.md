# README #

Used an Arduino Microcontroller and cloud-based MQTT broker service to create an Internet-of-Things Red-Green-Blue light that can be controlled over the internet.



Components:

- Arduino UNO R3

- W5100 Arduino Ethernet Shield

- RGB LED

- Light Ceiling Fixture

- Round Cylinder Plastic Saucer

- Micro USB extension lead

- RJ45 Inline Joiner

Commands:
- setLightColorRed
- setLightColorGreen
- setLightColorBlue
- setLightColorYellow
- setLightColorOrange
- setLightColorNone

Bash Command Example:
mosquitto_pub -r -h "m11.cloudmqtt.com" -p "12806" -u "LightPublisher" -P "<Password>" -t "Light1" -m "setLightColorRed"﻿