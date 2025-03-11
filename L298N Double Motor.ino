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
 

 
void setup()
{
 
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
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
 
  demoTwo();
  delay(1000);
 
}
