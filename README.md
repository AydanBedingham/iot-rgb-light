# README #

Used an Arduino Microcontroller and cloud-based MQTT broker service to create an Internet-of-Things Red-Green-Blue light that can be controlled over the internet.

![Scheme](https://bitbucket.org/AydanBedingham/iot-light/raw/master/images/iot-light-green.jpg)
![Scheme](https://bitbucket.org/AydanBedingham/iot-light/raw/master/images/iot-light-back.jpg)

**Components:**

- Arduino UNO R3 [View](https://bitbucket.org/AydanBedingham/iot-light/raw/master/images/components/Arduino_Uno_R3.jpg)

- W5100 Arduino Ethernet Shield [View](https://bitbucket.org/AydanBedingham/iot-light/raw/master/images/components/EthernetShield_W5100.jpg)

- RGB LED [View](https://bitbucket.org/AydanBedingham/iot-light/raw/master/images/components/RGB_LED.jpg)

- Light Ceiling Fixture [View](https://bitbucket.org/AydanBedingham/iot-light/raw/master/images/components/LightCeilingFixture.jpg)

- Round Cylinder Plastic Saucer [View](https://bitbucket.org/AydanBedingham/iot-light/raw/master/images/components/RoundCylinderPlasticSaucer.jpg)

- Micro USB extension lead [View](https://bitbucket.org/AydanBedingham/iot-light/raw/master/images/components/MicroUsbExtensionLead.jpg)

- RJ45 Inline Joiner [View](https://bitbucket.org/AydanBedingham/iot-light/raw/master/images/components/RJ45InlineJoiner.jpg)


**Commands:**

- setLightColorRed

- setLightColorGreen

- setLightColorBlue

- setLightColorYellow

- setLightColorOrange

- setLightColorNone

**
Bash Command Example:**

mosquitto_pub -r -h "m11.cloudmqtt.com" -p "12806" -u "LightPublisher" -P "<Password>" -t "Light1" -m "setLightColorRed"﻿