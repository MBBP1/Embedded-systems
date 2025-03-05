/***************************************
File name: lab09.ino
Description: analogRead() Example
**************************************/
int analogValue = 0;
int ledPin = 2;
int ledPin2 = 3;

void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, OUTPUT);

Serial.begin(250000);
}





void loop() {


int ldrValue = analogRead(A1);
Serial.println(ldrValue);

if (ldrValue > 500) {
  digitalWrite(ledPin2, HIGH);
} else {
  digitalWrite(ledPin2, LOW);
}
delay (100);





analogValue = analogRead(A0);
int voltage = map(analogValue, 0 , 1023, 000, 500);
/*
Serial.print("Voltage: ");
Serial.print(voltage);
Serial.print(", Analog Value: ");
Serial.println(analogValue);
*/



digitalWrite(ledPin, HIGH);
delay(analogValue);
digitalWrite(ledPin, LOW);
delay(analogValue);
}