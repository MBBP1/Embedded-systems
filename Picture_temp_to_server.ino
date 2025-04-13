// EMB2
// lab05.ino
#include <Wire.h>
#include <dhtnew.h>

DHTNEW mySensor(6);   // DATA pin, DHT22 pin 6 Arduino

void setup()
{
  Serial.begin(9600);
  //Serial.println();
  Serial1.begin(9600);
  delay(2000);
}

void loop()
{

  // Check if there is a character available for reading from the serial port 1
  if (Serial1.available()) {

    char incomingByte = Serial1.read();  // // read from port 1 (from Raspberry Pi)
    Serial.print("Message from Raspberry Pi: ");
    Serial.println(incomingByte);

    if(incomingByte == 'R') {
      // now we can read data from MAX6675 -> K-Type Thermocouple Temperature Sensor
      read_temp();
    }

  }
  
}

void read_temp()
{
  mySensor.read();
  float temperature = mySensor.getTemperature();

  Serial.print(temperature);
  Serial.print('\n');

  Serial1.print(temperature, 1);
  Serial1.print('\n');
  
}
