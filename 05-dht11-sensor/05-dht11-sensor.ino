#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C");
  Serial.print(" | ");
  Serial.print("Humidité: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);
}