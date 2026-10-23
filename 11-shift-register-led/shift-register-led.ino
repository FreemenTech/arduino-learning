// 74HC595 Shift Register — LED Chase Pattern
// 3 Arduino pins control 8 LEDs via the shift register

const int dataPin = 11;    // DS (pin 14 du 74HC595)
const int clockPin = 12;   // SHCP (pin 11 du 74HC595)
const int latchPin = 8;    // STCP (pin 12 du 74HC595)

void envoyer(byte valeur) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, valeur);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("74HC595 LED Chase ready");
}

void loop() {
  // Pattern 1 : Chase aller
  for (int i = 0; i < 8; i++) {
    envoyer(1 << (7 - i));
    delay(100);
  }

  // Pattern 2 : Chase retour
  for (int i = 0; i < 8; i++) {
    envoyer(1 << i);
    delay(100);
  }

  // Pattern 3 : Remplissage progressif
  byte valeur = 0;
  for (int i = 7; i >= 0; i--) {
    valeur |= (1 << i);
    envoyer(valeur);
    delay(150);
  }

  // Pattern 4 : Vidage progressif
  for (int i = 7; i >= 0; i--) {
    valeur &= ~(1 << i);
    envoyer(valeur);
    delay(150);
  }

  // Pattern 5 : Clignotement toutes
  for (int j = 0; j < 3; j++) {
    envoyer(B11111111);
    delay(200);
    envoyer(B00000000);
    delay(200);
  }
}
