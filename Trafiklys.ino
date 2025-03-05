
int LEDGRON1 = 8;
int LEDGUL1 = 9;
int LEDROD1 = 10;
int LEDGRON2 = 11;
int LEDGUL2 = 12;
int LEDROD2 = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDGRON1, OUTPUT);
  pinMode(LEDGUL1, OUTPUT);
  pinMode(LEDROD1, OUTPUT);
  pinMode(LEDGRON2, OUTPUT);
  pinMode(LEDGUL2, OUTPUT);
  pinMode(LEDROD2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LEDROD1, HIGH); // turn the LED on (HIGH is the voltage level)
  digitalWrite(LEDGRON2, HIGH);
  delay(5000); 
  digitalWrite(LEDGUL1, HIGH);  
  digitalWrite(LEDGRON2, LOW);
  digitalWrite(LEDGUL2, HIGH);
  delay(3000); 
  digitalWrite(LEDGUL2, LOW);
  digitalWrite(LEDROD2, HIGH);
  digitalWrite(LEDROD1, LOW);                        
  digitalWrite(LEDGUL1, LOW);   
  delay(100);
  digitalWrite(LEDGRON1, HIGH);  
  delay(5000);
  digitalWrite(LEDGRON1, LOW);     
  digitalWrite(LEDGUL1, HIGH);
  digitalWrite(LEDGUL2, HIGH);
  delay(3000);
  digitalWrite(LEDGUL2, LOW);
  digitalWrite(LEDROD2, LOW);
  digitalWrite(LEDGRON1, LOW);
  digitalWrite(LEDGUL1, LOW);
}
