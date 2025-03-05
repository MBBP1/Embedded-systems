/*
 Controlling the Position of a Servo
*/

#include <Servo.h>

Servo myservo; // create servo object to control a servo
int angle = 0; // variable to store the servo position
int servoPin = 9;

void setup()
{
  myservo.attach(servoPin); // attaches the servo on pin ? to the servo object
  Serial.begin(9600);       // for debugging via the Serial Monitor
}
void loop()
{
  for(angle = 0; angle < 180; angle += 1) // goes from 0 degrees to 180 degrees in steps of 1 degree
  {                                    
    myservo.write(angle); // tell servo to go to position in variable 'angle'
    
    Serial.print("angle: ");
    Serial.println(angle);     
    delay(500); // waits 20ms between servo commands
  }
  
  for(angle = 180; angle >= 1; angle -= 1) // goes from 180 degrees to 0 degrees in steps of 1 degree
  {
    myservo.write(angle); // tell servo to go to position in variable 'pos'
    
    Serial.print("angle: ");
    Serial.println(angle); 
    delay(500); // waits 20ms between servo commands

  }
}

