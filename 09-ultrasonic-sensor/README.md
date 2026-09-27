# 09 — Ultrasonic Distance Sensor (HC-SR04)

Measure distance using sound waves. The HC-SR04 emits 8 ultrasonic bursts at 40 kHz, waits for the echo, and reports the round-trip time. The Arduino converts that time into centimeters.

## Components

| Component | Quantity |
|-----------|----------|
| Arduino UNO R3 | 1 |
| HC-SR04 ultrasonic sensor | 1 |
| Jumper wires (M-M) | 4 |
| USB cable | 1 |

## Circuit Wiring
[!Montage](image/montage.jpg)

| HC-SR04 Pin | Arduino Pin |
|-------------|-------------|
| VCC | 5V |
| Trig | 2 |
| Echo | 3 |
| GND | GND |

No resistors needed — both the Arduino and the HC-SR04 operate at 5V logic levels, and the module drives its own output pins.

## How It Works

1. The Arduino sends a 10 µs HIGH pulse on the Trig pin to start a measurement.
2. The HC-SR04 emits 8 ultrasonic pulses at 40 kHz.
3. The sound wave travels forward, hits an obstacle, and bounces back.
4. The module holds the Echo pin HIGH for the duration of the round trip.
5. `pulseIn(echoPin, HIGH)` measures that duration in microseconds.
6. Distance is calculated: `distance_cm = (duration_us * 0.034) / 2` — 0.034 cm/µs is the speed of sound, divided by 2 because the wave travels there and back.

## Key Concepts Learned

- **Time-of-flight measurement** — distance derived from the time a signal takes to travel to a target and back.
- **`pulseIn()`** — built-in Arduino function that measures how long a pin stays HIGH (or LOW), returning the duration in microseconds. No external library needed.
- **`delayMicroseconds()` vs `delay()`** — microsecond precision for hardware trigger sequences; millisecond precision for pacing the loop.
- **`unsigned long`** — `pulseIn()` returns values that can exceed the 32,767 max of a 16-bit `int`. `unsigned long` handles up to 4,294,967,295.
- **Datasheet-first approach** — all timing requirements (10 µs trigger, 38 ms timeout, 40 kHz burst frequency) come from the manufacturer's datasheet, not tutorials.

## Debugging Notes

- **All zeros** — the obstacle is too close (< 10–15 cm on cheap clones), the Trig/Echo wires are swapped, or the module is not receiving 5V.
- **Values stable but wildly wrong** — the sensor may be reading a surface behind the intended obstacle. The detection cone is ~15°; small or angled objects can be missed entirely. Test against a flat wall first.
- **Minimum distance** — the datasheet claims 2 cm, but clone modules often fail below 10–15 cm because the echo returns before the module switches from transmit to receive mode.
- **Pin 4 issue** — pin 4 returned only zeros when used for Echo on this particular Arduino board; switching to pin 3 resolved it. Possible dead pin or poor header contact.
- **Temperature affects accuracy** — the speed of sound increases with temperature. In hot climates (~30 °C), the actual speed is ~0.0350 cm/µs rather than 0.0340. This introduces a ~3 % error at room temperature.

## Security Angle

The HC-SR04 has zero signal authentication. An attacker can emit a 40 kHz ultrasonic pulse toward the receiver to spoof a false obstacle (or mask a real one). In physical security systems that rely on ultrasonic distance — garage door sensors, industrial proximity alarms, robot collision avoidance — this is a real attack vector. Mitigations in production include sensor fusion (combining ultrasonic with IR, LIDAR, or camera), randomized trigger intervals to break replay attacks, and anomaly detection on readings (sudden impossible jumps).
