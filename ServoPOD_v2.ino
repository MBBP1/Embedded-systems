/*
 Controlling Servo with a Potentiometer
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potPin = A0;  // analog pin used to connect the potentiometer
int potVal;    // variable to read the value from the analog pin
int servoPin = 9;

void setup() {
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);            // reads the value of the potentiometer (value between 0 and 1023)
  potVal = map(potVal, 0, 1023, 0, 180);     		// scale it to use it with the servo (value between 0 and 180)
  myservo.write(potVal);             // sets the servo position according to the scaled value
  Serial.println(potVal);
  delay(32);   
                          // waits for the servo to get there
}
