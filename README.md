# README #

Used an Arduino Microcontroller and cloud-based MQTT broker service to create an Internet-of-Things Red-Green-Blue light that can be controlled over the internet.

![Screenshot](images/iot-light-green.jpg?raw=true)
![Screenshot](images/iot-light-back.jpg?raw=true)


**Components:**

- Arduino UNO R3 [View](images/components/Arduino_Uno_R3.jpg?raw=true)

- W5100 Arduino Ethernet Shield [View](images/components/EthernetShield_W5100.jpg?raw=true)

- RGB LED [View](images/components/RGB_LED.jpg?raw=true)

- Light Ceiling Fixture [View](images/components/LightCeilingFixture.jpg?raw=true)

- Round Cylinder Plastic Saucer [View](images/components/RoundCylinderPlasticSaucer.jpg?raw=true)

- Micro USB extension lead [View](images/components/MicroUsbExtensionLead.jpg?raw=true)

- RJ45 Inline Joiner [View](images/components/RJ45InlineJoiner.jpg?raw=true)


**Commands:**

- setLightColorRed

- setLightColorGreen

- setLightColorBlue

- setLightColorYellow

- setLightColorOrange

- setLightColorNone


**Bash Command Example:**

mosquitto_pub -r -h "m11.cloudmqtt.com" -p "12806" -u "LightPublisher" -P "<Password>" -t "Light1" -m "setLightColorRed"﻿
