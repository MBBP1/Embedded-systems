/***********************************************************
File name: lab04.ino
Description: use push buttons with digital inputs to turn
an LED on and off
***********************************************************/
const int ledPin = 5;
const int buttonBpin = 8;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonBpin, INPUT);
}



void loop(){
  int uyt = (digitalRead(buttonBpin));

  if (uyt == HIGH)

  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}