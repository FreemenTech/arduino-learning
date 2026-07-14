// declaration de variable :

const int PIN = 4;

void setup() { //s'execute une fois
  pinMode(PIN , OUTPUT);

}

void loop() { //s'execute en boucle

  digitalWrite(PIN , HIGH);
  delay(100);
  digitalWrite(PIN , LOW);
  delay(2000);

}
