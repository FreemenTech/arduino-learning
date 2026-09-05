#include <Servo.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
Servo myservo;

const int servoPin = 6;
const int buzzer = 8;
const float seuil = 31;

void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Erreur lecture DHT");
    return;
  }

  Serial.println(temperature);

  if (temperature >= seuil) {
    tone(buzzer, 262, 1000);
    myservo.attach(servoPin);
    myservo.write(180);
    delay(500);
    myservo.detach();
    Serial.println("ALERTE");
  } else {
    noTone(buzzer);
    myservo.attach(servoPin);
    myservo.write(90);
    delay(500);
    myservo.detach();
  }

  delay(2000);
}