# 04 - Auto Nightlight

Automatic nightlight using a photoresistor (LDR) - LED brightness adjusts
based on ambient light level.

## Components
- Arduino UNO R3
- 1 photoresistor (LDR)
- 1 x 10K ohm resistor (voltage divider)
- 1 LED
- 1 x 220 ohm resistor
- Breadboard + jumper wires

## Circuit
![Montage](image/montage.HEIC)
Voltage divider on A0:
- 5V → photoresistor → A0 → 10K ohm → GND

LED on pin 3 (PWM) with 220 ohm resistor to GND.

## How it works
The photoresistor and the 10K resistor form a voltage divider.
In bright light, the photoresistor resistance drops → voltage on A0 rises → 
high analogRead() value.
In darkness, the photoresistor resistance rises → voltage on A0 drops → 
low analogRead() value.

To get nightlight behavior (bright in dark, off in light), the map() output
is inverted: map(value, 0, 1023, 255, 0) instead of map(value, 0, 1023, 0, 255).
More elegant than rewiring the circuit.

## What I learned
- Resistive sensors: components that change resistance based on environment
- Voltage divider: two resistors in series share voltage proportionally
- Formula: Vout = Vin x R2 / (R1 + R2)
- Why 10K ohm as fixed resistor: must be in the same order of magnitude
  as the variable resistor for best reading range
- Analog pins A0-A5 don't need pinMode() - analog input by default
- Inverting map() output is more elegant than rewiring the circuit
- Observed light values: ~30-50 (dark), ~220-260 (normal), ~1023 (bright light)
- Threshold around 400 separates dark from light in this environment
- Without Arduino, a photoresistor + transistor can switch a LED with zero code
- Programmable nightlights add intelligence: timers, motion detection,
  progressive dimming, WiFi control
- Auto-brightness on smartphones uses the exact same principle
