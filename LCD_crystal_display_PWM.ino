/***********************************************************
File name: lab14.ino
Description: Print a message to the LCD
***********************************************************/
// include the library code:
#include <LiquidCrystal.h>

int potPin = A0; // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int potVal = 0;    // variable to store the value coming from the sensor

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
/*
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/

void setup() 
{
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Hello!");    
}



void loop() 
{
  // read the value from the pot
  int sensorReading = analogRead(potPin);

  // scale value to use it with the LED - use your map function
  int blink = map(sensorReading, 0, 1023, 0, 255);   
  // scale PWM
  int PWM = map(sensorReading, 0, 1023, 0, 100);
  // set brightness - use analogWrite
  analogWrite(ledPin, blink);

  // print values
  //Serial.println(blink);
  Serial.println(PWM);


  //lcd.print("HELLO");
  lcd.setCursor(0, 1);

  lcd.print(PWM); 
  lcd.setCursor(0, 0);

  delay (400);
  lcd.clear();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
  // print the number of seconds since reset:
  ////lcd.print(millis() / 1000);
  //lcd.print("WARNING");
}
