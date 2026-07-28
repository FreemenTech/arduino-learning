const int led = 3;
int value ;
int convert_value;


void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  value = analogRead(A0);
  convert_value = map(value, 0, 1023, 0, 255);
  Serial.println(convert_value);

  if (value > 400 ){
    analogWrite(led, 0);
  }else {
    analogWrite(led, 255); //s'allume quand il fait sombre ( when value is < 400)
  }
  delay(100);
}