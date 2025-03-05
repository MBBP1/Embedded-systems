
// lab21-solution.ino

#include <dhtnew.h>

DHTNEW mySensor(6);   // pin 6 is connected to pin DATA from AM2302 (DHT22)


void setup()
{

  // initialize pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  Serial.println();


  //Serial.println("BEFORE OFFSET");
  delay(2000);
  mySensor.read();
  Serial.print("Temperature: ");
  Serial.println(mySensor.getTemperature(), 1);

  Serial.print("Humidity: ");
  Serial.println(mySensor.getHumidity(), 1);   

 // mySensor.setHumOffset(10);

  //Serial.println("AFTER OFFSET");
}


void loop()
{
  if (millis() - mySensor.lastRead() > 3000)
  {
    mySensor.read();
    Serial.print("Temperature: ");
    Serial.println(mySensor.getTemperature(), 1);

    Serial.print("Humidity: ");
    Serial.println(mySensor.getHumidity(), 1);    

    if(mySensor.getHumidity()> 50)
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
    else  
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED off
  }
}