/*
* Read the temperature sensor LM35
*/
int LM35_pin = A0; // LM35 output connected to analog pin ?
float LM35_temp; // temperature from LM35
void setup()
{
pinMode(LM35_pin, INPUT); // make pin as Input reading pin
Serial.begin(9600); // Open serial connection at 9600 bps:
}
void loop()
{
int temp;


temp = analogRead(LM35_pin);

float voltage = temp * (5000 / 1023.0);

float truetemp = voltage / 10;  //10mV = 1 C

// read analog voltage from LM35, convert to digital and use formula
// Converts the analog voltage from LM35 to digital reading where 5
// is the supply voltage 5V


// prints on serial monitor
Serial.print("Temperature from LM35: ");
// Prints current temperature on Serial Monitor
Serial.print(truetemp); Serial.println(" *C");

delay(5000); // 5 seconds delay before taking the new reading
}