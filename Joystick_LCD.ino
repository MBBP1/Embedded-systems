/***********************************************************
File name: lab23.ino
Description: Example with JoyStick
Based on (source):www.uctronics.com,Lesson_19_Joy_stick,Lee
***********************************************************/



#include <LiquidCrystal.h>
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
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  

int JoyStick_X = A1; //PS2 joystick X-axis is defined
int JoyStick_Y = A2; //PS2 joystick Y axis is defined
int JoyStick_Z = 2; //Defined PS2 joystick Z axis - (SW)



void setup(void)
{
  Serial.begin(9600);
  lcd.begin(16, 2);    // set up the LCD's number of columns and rows: 
  lcd.clear();         //Clears the LCD screen and positions the cursor in the upper-left corner 
  pinMode(JoyStick_Z, INPUT_PULLUP); //Z axis is defined as an input PS2


}

void loop(void)
{
  int x,y,z;
  x=analogRead(JoyStick_X);
  y=analogRead(JoyStick_Y);
  z=digitalRead(JoyStick_Z);
  int deadzone1 = 550;
  int deadzone2 = 450;


  // print the results:
  

  lcd.setCursor(0, 0); // set the cursor to column 0, line 0
  if (x > deadzone1) 
  lcd.print("UP");
  else if (x < deadzone2)
  lcd.print("DOWN");
  else 
  lcd.print("");
//  lcd.print("X:");// Print a message of "X: "to the LCD.
 // lcd.print(x);// Print the x value to the LCD.
  lcd.print("   ");//  
  

  lcd.setCursor(0, 1); // set the cursor to column 0, line 1 
  if (y > deadzone1)
  lcd.print ("RIGHT");
  else if (y < deadzone2)
  lcd.print("LEFT");
  else
  lcd.print("");
  //lcd.print("Y:"); // Print a message of "Y: "to the LCD.
  //lcd.print(y);// Print the y value to the LCD.
  lcd.print("   ");//  

  lcd.setCursor(13, 0 ); // set the cursor to column 0, line 0 
  lcd.print("Z:"); // Print a message of "Z: "to the LCD.
  lcd.print(z);// Print the z value to the LCD.
  delay(25);
  
lcd.clear();
}