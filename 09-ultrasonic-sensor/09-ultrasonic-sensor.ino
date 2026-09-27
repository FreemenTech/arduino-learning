
const int pinTrig = 2 ;
const int pinEcho = 4;
unsigned long duree_us;
int distance_cm; 

void setup(){
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);

}

void loop() {

  digitalWrite(pinTrig , LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig , HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig , LOW);
  duree_us = pulseIn(pinEcho, HIGH);

  distance_cm = (duree_us * 0.034) / 2;
  Serial.print("Distance: ");
  Serial.print(distance_cm) ;
  Serial.println("cm");

  delay(200);

}
