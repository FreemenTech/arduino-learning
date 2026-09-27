const int led = 4;
const int PIR = 2 ;
int reader;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(PIR , INPUT);
}

void loop() {

  reader = digitalRead(PIR);
  if(reader == HIGH ){
    digitalWrite(led,HIGH);
    Serial.println("Alert Movment detected !");
  }
  else {
    digitalWrite(led,LOW);
  }

}
