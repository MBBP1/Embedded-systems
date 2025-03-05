//LAB 16


int buzzerPin = 8;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  tone(buzzerPin, 20000, 1000);
  delay (1000);
  tone(buzzerPin, 1000, 1000);
  delay (1000);

}
