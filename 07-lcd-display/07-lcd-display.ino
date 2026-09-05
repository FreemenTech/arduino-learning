#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long tempsPrecedent = 0;
const long intervalle = 1000 ;
int i = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Demarrage");
  lcd.begin(16, 4);
  Serial.println("LCD init OK");
  lcd.print("Hello Freemen!");
  delay(3000);
  lcd.clear();
}

void loop() {
  unsigned long tempsActuel = millis();
  float potentio = analogRead(A0);


  if (tempsActuel - tempsPrecedent >= intervalle){
      tempsPrecedent = tempsActuel;

      lcd.setCursor(0,1);
      lcd.print(i++);
    }

  lcd.setCursor(0, 2);
  lcd.print(potentio);

}