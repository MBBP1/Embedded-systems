// EMB2
// lab01.ino
/*	
L298N Motor Demonstration
Demonstrates functions of L298N Motor Controller
The code is based on the source code - DroneBot Workshop 2017 - https://dronebotworkshop.com/dc-motors-l298n-h-bridge/
*/
	
 
// Motor A
int enA = 9;  // ENABLE 1 (6)
int enB = 10; // ENABLE 2 (11)
int in1 = 8;  // INPUT 1  (5)
int in2 = 7;  // INPUT 2  (7)
int in3 = 6;  // INPUT 3  (10)
int in4 = 5;  // INPUT 4  (12)
 
//Joystick
int JoyStick_X = A1; //PS2 joystick X-axis is defined
int JoyStick_Y = A2; //PS2 joystick Y axis is defined
//int JoyStick_Z = 2; //Defined PS2 joystick Z axis - (SW)


 
void setup()
{
 
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //pinMode(JoyStick_Z, INPUT_PULLUP); //Z axis is defined as an input PS2
 
}

// This function will run the motor in both directions at a fixed speed 
void demoOne()
{

  // Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 
   // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  analogWrite(enB, 200);
 
  delay(2000);
 
  // Now change motor A directions
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
    // Now change motor B directions
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 

  delay(2000);
 
  // Now turn off motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  

  // Now turn off motor B 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  

 
}
void JoystickPWM() 
{
  int x, y;
  
  x = analogRead(JoyStick_X);
  y = analogRead(JoyStick_Y);

  // Create a dead zone around the center to prevent small unwanted movement
  int deadZone = 20; 

  // Center the values: 512 becomes 0, positive for forward, negative for backward
  int mappedY = y - 512;

  // Apply the dead zone
  if (abs(mappedY) < deadZone) {
    mappedY = 0;
  }

  // Map the values to the PWM range (0 - 255) while keeping direction
  if (mappedY > 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);  // Motor A forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);  // Motor B forward
  } 
  else if (mappedY < 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);  // Motor A reverse
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);  // Motor B reverse
    mappedY = -mappedY;  // Convert negative to positive for PWM
  } 
  else {
    // Stop the motors when joystick is centered
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }

  // Scale PWM output (map to 0-255 only if joystick moves)
  int pwmValue = map(mappedY, 0, 512, 0, 255);
  analogWrite(enA, pwmValue);
  analogWrite(enB, pwmValue);

  delay(20);
}


// This function will run the motors across the range of possible speeds
// Note that maximum speed is determined by the motor itself and the operating voltage 
void demoTwo()
{
 
  // Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  

  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  

 
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++)
  {
 
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
 
  } 
 
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i)
  {
 
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
 
  } 
 
  // Now turn off motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  

  // Now turn off motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);  
 
}
 
void loop()
{
 
  //demoOne();
  //delay(1000);
 
  //demoTwo();
  //delay(1000);
 
  JoystickPWM();


}
