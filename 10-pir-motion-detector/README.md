# 10 — PIR Motion Detector

Detect human movement using a passive infrared sensor. The PIR module senses changes in infrared radiation caused by a warm body moving across its field of view and outputs a digital HIGH signal.

## Components

| Component | Quantity |
|-----------|----------|
| Arduino UNO R3 | 1 |
| PIR motion sensor (HC-SR501 or similar) | 1 |
| LED | 1 |
| 220 Ω resistor | 1 |
| Jumper wires (M-M) | 5 |
| USB cable | 1 |

## Circuit Wiring
[!Montage](image/montage.jpg)

| PIR Pin | Arduino Pin |
|---------|-------------|
| VCC | 5V |
| OUT | 2 |
| GND | GND |

| LED Circuit | Connection |
|-------------|------------|
| LED anode (+) | Pin 4 via 220 Ω resistor |
| LED cathode (−) | GND |

No pull-up or pull-down resistor needed on the PIR output — the module drives the pin actively HIGH or LOW.

## How It Works

1. The PIR module contains two pyroelectric elements sensitive to infrared radiation (~9–10 µm wavelength — the range emitted by the human body).
2. Both elements see the same ambient IR level at rest — their outputs cancel out, and OUT stays LOW.
3. When a warm body moves across the sensor's field of view, it crosses one element before the other, creating a momentary difference in IR levels.
4. That difference triggers the module's comparator circuit, pulling OUT to HIGH.
5. The Arduino reads the pin with `digitalRead()` — HIGH means motion detected.
6. A Fresnel lens (the white dome) splits the field of view into multiple zones and focuses IR from a wide angle (~120°) onto the small sensor, increasing both range and sensitivity.

## Key Concepts Learned

- **Passive vs active sensing** — the PIR emits nothing; it only listens for changes in infrared radiation. The ultrasonic sensor (HC-SR04) is active — it emits sound and listens for the echo. This distinction matters for stealth and power consumption.
- **Differential detection** — the PIR detects *change*, not presence. Two pyroelectric elements cancel each other out at rest; only motion across their boundary triggers a signal. Standing still in front of the sensor will not keep it triggered.
- **Fresnel lens** — the white dome is an optical element that divides the field of view into discrete zones, allowing a tiny sensor to cover a ~120° area at several meters range.
- **Calibration period** — the PIR needs 30–60 seconds at startup to learn the ambient IR level. False positives during this phase are expected.
- **`"HIGH"` vs `HIGH`** — `"HIGH"` is a string literal (text); `HIGH` without quotes is an Arduino constant equal to 1. Comparing an `int` to a string will never be true.

## Debugging Notes

- **LED stays on permanently** — most likely the sensor is detecting continuous motion. The PIR has a 120° cone and several meters of range — the operator sitting nearby, breathing, typing, or any movement in the room will re-trigger it. Point the sensor toward an empty wall, away from people and heat-emitting electronics (laptops, chargers, monitors).
- **False triggers at startup** — normal during the 30–60 second calibration phase. Wait without moving before testing.
- **Module without potentiometers** — some basic PIR modules have fixed sensitivity and delay settings with no adjustment. If the sensor stays triggered too easily, the only option is physical isolation: narrow the field of view with a cardboard tube over the lens, or increase distance from heat sources.
- **Heat sources cause false positives** — electronics, sunlight through a window, air conditioning vents, and even warm walls can create IR changes that trigger the sensor.

## Security Angle

PIR sensors are trivially defeated. Moving slowly enough prevents the differential threshold from being reached. Holding a flat surface (cardboard, glass) between the body and the sensor blocks IR radiation. Uniformly heating the area in front of the sensor eliminates the contrast needed for detection. This is why commercial security systems never rely on a single PIR — they combine it with microwave radar (dual-tech sensors), ultrasonic detection, magnetic door contacts, or camera-based analytics. The principle is defense in depth: the same layered approach used in network security, applied to physical access control.
