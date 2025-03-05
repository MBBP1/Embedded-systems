
// lab20.ino

#include <dhtnew.h>

DHTNEW mySensor(6);   // pin 6 is connected to the DATA pin of AM2302 (DHT22)


void setup()
{

  Serial.begin(9600);
  Serial.println(__FILE__);
  Serial.println();



  delay(2000);

}


void loop()
{
  if (millis() - mySensor.lastRead() > 5000)
  {
    mySensor.read();
    Serial.print("Temperature: ");
    Serial.println(mySensor.getTemperature(), 1);
  }
  delay (5000);
}