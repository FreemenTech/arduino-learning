# 🔧 Arduino Learning — Embedded Systems from Scratch

I'm a cybersecurity student building my way toward IoT security. This repo documents my embedded systems learning journey — starting from zero, one Sunday at a time.

**Format:** 1 project per session · 24 weeks (July → December 2026)

## Projects

| # | Project | Concepts | Status |
|---|---------|----------|--------|
| 01 | [LED Blink + Chaser](./01-led-blink) | pinMode, digitalWrite, delay, basic circuits | ✅ |
| 02 | [Button LED Control](./02-button-led-control) | digitalRead, pull-down resistors, state variables, debouncing | ✅ |
| 03 | [Analog & PWM](./03-analog-pwm) | analogRead, analogWrite, map(), potentiometer, Serial monitor | ✅ |
| 04 | [Automatic Night Light](./04-auto-nightlight) | Photoresistor, voltage divider, threshold logic | ✅ |
| 05 | [DHT11 Sensor](./05-dht11-sensor) | One-wire protocol, external libraries, isnan() error handling | ✅ |
| 06 | [Temperature Alert System](./06-temp-alert-system) | tone(), Servo library, attach/detach pattern, timer conflicts, power management | ✅ |
| 07 | [LCD 16x4 Display](./07-lcd-display) | LiquidCrystal, HD44780, 4-bit mode, soldering, continuity testing | ✅ |
| 08 | [Weather Station](./08-weather-station) | DHT11 + LCD integration, pin conflict resolution, sensor fusion, comfort thresholds | ✅ |
| 09 | Proximity Detector | HC-SR04 ultrasonic, PIR sensor, pulseIn() | 🔜 |
| 10 | Relay & DC Motor | Relay switching, back-EMF protection, external power | 🔜 |
| 11 | Shift Register + 7-Segment | 74HC595, shiftOut(), bit operations | 🔜 |
| 12 | IR Remote Control | IRremote library, NEC protocol decoding | 🔜 |
| 13 | RFID Access Control | RC522, SPI communication, UID authentication | 🔜 |
| 14 | RFID Access v2 | Lockout logic, admin mode, multi-sensor integration | 🔜 |
| 15 | Interrupts & millis() | Hardware interrupts, FSM, cooperative multitasking | 🔜 |
| 16 | I2C Communication | Wire.h, address scanning, serial command parser | 🔜 |

## Hardware

- Arduino UNO R3 (starter kit)
- Breadboard + jumper wires
- LEDs, resistors, buttons, potentiometer
- DHT11, photoresistor, HC-SR04, PIR sensor
- LCM1604A LCD 16x4 (HD44780), buzzer, servo (continuous rotation), DC motor, relay
- RC522 RFID module
- IR receiver + remote

## Why this repo exists

Every project is documented with code, circuit description, and lessons learned. This isn't a tutorial — it's a real learning log from someone building embedded skills from the ground up.

**Goal:** IoT security. You can't secure what you don't understand.

## Author

**Freemen Houngbedji** — Cybersecurity student · Open-source tools builder
- 🔗 [GitHub](https://github.com/FreemenTech)
- 🔗 [LinkedIn](https://linkedin.com/in/freemen-houngbedji)
- 🔗 [YouTube — Freemen OS](https://youtube.com/@Freemen_OS)
