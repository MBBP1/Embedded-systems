/***********************************************************
File name: lab22.ino
Description: Example with interrupt
***********************************************************/

int ledPin = 11;   // select the pin for the LED
int buttonApin = 2;

// Interrupt Service Routine (ISR)
void switchPressed ()
{
  if  (digitalRead (buttonApin) == LOW) 
        digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);  
}  // end of switchPressed


void setup ()
{
  pinMode (ledPin, OUTPUT);  // so we can update the LED
  pinMode(buttonApin, INPUT_PULLUP);    // internal pull-up resistor
  attachInterrupt (digitalPinToInterrupt (buttonApin), switchPressed, CHANGE);  // attach interrupt handler
}  // end of setup

void loop ()
{

} 
