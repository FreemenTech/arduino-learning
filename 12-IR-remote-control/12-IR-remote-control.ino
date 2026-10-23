#include <IRremote.hpp>

const int irPin = 2;
const int red = 3;
const int yellow = 4;
const int green = 5;

//const int servo = 7;

void setup(){
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  IrReceiver.begin(irPin);

  Serial.println("Program is running...");
}

void loop(){

  if (IrReceiver.decode()){
    int code = IrReceiver.decodedIRData.command;
    Serial.print("Code:0x");
    Serial.println(code);
    switch (code){
      //led red and btn1 
      case 0x45:
        digitalWrite(red,!digitalRead(red));
        break;

      //led yellow and btn2
      case 0x46:
        digitalWrite(yellow,!digitalRead(yellow));
        break;
      
      //led green and btn3
      case 0x47:
        digitalWrite(green , !digitalRead(green));
        break;

      //ok button 

      case 0x1C:
          digitalWrite(red,LOW);
          digitalWrite(yellow,LOW);
          digitalWrite(green,LOW);
        break;
      
      default :
        break;

    }

    IrReceiver.resume();
  }
}