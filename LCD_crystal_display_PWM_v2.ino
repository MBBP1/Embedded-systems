//LAB 15

/***********************************************************
File name: lab15.ino
Description: Read analog values from potentiometer. Writes an analog value (PWM wave) to a pin- light a LED at varying brightnesses.
***********************************************************/

int potPin = A0; // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int potVal = 0;    // variable to store the value coming from the sensor

 
void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  Serial.begin(9600);       // for debugging via the Serial Monitor
}

// define you own map function



void loop() {
  // read the value from the pot
  int sensorReading = analogRead(potPin);

  // scale value to use it with the LED - use your map function
  int blink = map(sensorReading, 0, 1023, 0, 255);   
  // scale PWM
  int PWM = map(sensorReading, 0, 1023, 0, 100);
  // set brightness - use analogWrite
  analogWrite(ledPin, blink);
 // test

 // print values
 //Serial.println(blink);
 Serial.println(PWM);
}
