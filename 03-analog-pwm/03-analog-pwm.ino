const int led = 3;
const int btn = 2;

bool ledIsOn = false ;

int buttonState = LOW;
int lastButtonState = LOW;
int value ;
int new_value ;
 

 void setup(){
  pinMode(led , OUTPUT);
  pinMode(btn , INPUT);

 }

 void loop(){

  buttonState = digitalRead(btn);
  if (buttonState == HIGH && lastButtonState == LOW){
    ledIsOn = !ledIsOn ;
  }

  if (ledIsOn){
    value = analogRead(A0);
    new_value = map(value, 0, 1023, 0, 255);

    analogWrite(led , new_value);
  }else {
    analogWrite(led , 0);
  }
  lastButtonState = buttonState;

 }
