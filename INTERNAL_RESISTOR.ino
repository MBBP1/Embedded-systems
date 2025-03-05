

int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

byte leds = 0;
int count = 0;


void setup() 
{
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT);
  //pinMode(buttonApin, INPUT_PULLUP);  
  //pinMode(buttonBpin, INPUT_PULLUP);  
  digitalWrite(ledPin, HIGH);
}

void loop() 
{

 
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, LOW);
    Serial.println("LED Button Pressed");
  }
  else
  {digitalWrite(ledPin, HIGH);
  }
    
    

  while (digitalRead(buttonApin) == HIGH) 
  {}
  count++;
  Serial.println(count);
  while (digitalRead(buttonApin) == LOW) 
  {}  

  //RESET COUNTER
  if (count >= 10 ) 
  {
    count = 0;
  }

}



/*

int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

byte leds = 0;
int count = 0;


void setup() 
{
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(ledPin, OUTPUT);
  //pinMode(buttonApin, INPUT_PULLUP);  
  //pinMode(buttonBpin, INPUT_PULLUP);  
  digitalWrite(ledPin, HIGH);
}

void loop() 
{

  // Step 6
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
  else
    digitalWrite(ledPin, HIGH);


  // Step 7
  while (digitalRead(buttonApin) == LOW) 
  {}
  count++;
  Serial.println(count);
  while (digitalRead(buttonApin) == HIGH) 
  {}   

}

*/