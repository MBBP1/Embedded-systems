/***********************************************************
File name: lab02.ino
Description: hardware PWM with DC motor
***********************************************************/

int motor_pin = 8; // PWM pin for motor control

#include <Servo.h>

int JoyStick_X = A0; // PS2 joystick X-axis
int JoyStick_Y = A1; // PS2 joystick Y-axis

void setup() {
  Serial.begin(9600);
  pinMode(motor_pin, OUTPUT); // Initialize motor pin as output
  analogWrite(motor_pin, 128); // Start motor with 50% duty cycle
}

void loop() {
  int y = analogRead(JoyStick_Y); // Read joystick Y-axis
  int mapY = map(y, 0, 1023, 0, 99); // Map joystick value to 0-100%
  set_duty_cycle(mapY); // Update motor speed
  delay(100); // Small delay to prevent excessive serial output
}

void set_duty_cycle(int percentage) {
  int dutyCycle = (int)((percentage / 100.0) * 255.0);
  analogWrite(motor_pin, dutyCycle); // Set PWM duty cycle

  Serial.print("PWM works on pin ");
  Serial.print(motor_pin);
  Serial.print(". The duty cycle is ");
  Serial.print(percentage);
  Serial.println("%.");
  Serial.print("Analog Write Value: ");
  Serial.println(dutyCycle);
}
