const int Btn1 = 2;
const int Btn2 = 4;

const int Led1 = 7;
const int Led2 = 8;

bool led1Allumee = false;
bool led2Allumee = false;

int dernierEtat1 = LOW;
int dernierEtat2 = LOW;

void setup(){
  pinMode(Btn1, INPUT);
  pinMode(Btn2, INPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
}

void loop(){
  int etat1 = digitalRead(Btn1);
  int etat2 = digitalRead(Btn2);

  if(etat1 == HIGH && dernierEtat1 == LOW){
    led1Allumee = !led1Allumee;
    digitalWrite(Led1, led1Allumee ? HIGH : LOW);
    delay(200);
  }

  if(etat2 == HIGH && dernierEtat2 == LOW){
    led2Allumee = !led2Allumee;
    digitalWrite(Led2, led2Allumee ? HIGH : LOW);
    delay(200);
  }


  dernierEtat1 = etat1;
  dernierEtat2 = etat2;
}