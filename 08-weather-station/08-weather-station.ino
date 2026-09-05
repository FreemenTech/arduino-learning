#include <LiquidCrystal.h>
#include <DHT.h>


#define DHTTYPE DHT11
#define DHTPIN 7

DHT dht(DHTPIN , DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  
  Serial.begin(9600);
  Serial.println("Demarrage");
  lcd.begin(16, 4);
  Serial.println("LCD init OK");
  lcd.print("Weather Station");
  delay(2000);
  lcd.clear();
  dht.begin();
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  char* state;

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Erreur lecture DHT");
    return;
  }

//display temperature
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.write(0xDF); // it's for "°" 
  lcd.print("C");

//display humidity
  lcd.setCursor(0, 2);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print("%");

//Comfort thresholds
  if (humidity < 40){
    state = "DRY";
  }
  else if (humidity > 60){
    state = "HUMID";
  }
  else {
    state = "COMFORT";
  }

  lcd.setCursor(0,3);
  lcd.print(state);

  delay(2000);

}