//File name: lab01-solution.ino
//Description: software PWM

***/

int count=0, count_max=10, threshold=3, clock=1000;
int cycles=0, cycles_per_threshold_value=8, threshold1=5.5, threshold2=5.5;
int pwm_pin = 2; // pin that will act like a pwm pin

void setup() 
{
  pinMode(pwm_pin, OUTPUT);
  digitalWrite(pwm_pin, LOW);
}


void loop() 
{


  // Task 9 resonse tid
  if (cycles ==cycles_per_threshold_value)
  {
    cycles =0;
    if (threshold == threshold1)
      threshold = threshold2;
    else
      threshold = threshold1;
  }

  if (count > count_max)
  {
    count = 0;
    digitalWrite(pwm_pin, HIGH);
    cycles++;
  }
  if (count >= threshold)
  {
    digitalWrite(pwm_pin, LOW);
  }
  count++;
  delayMicroseconds(clock); //delay clock -> resolution

}
