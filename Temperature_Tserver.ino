//LAB 

#include <Wire.h>
#include <dhtnew.h>


DHTNEW mySensor(6);   // DATA pin på DHT22 til pin 6 på Arduino

void setup() {
  Serial.begin(9600);    // Til USB Serial Monitor
  Serial1.begin(9600);   // Til Raspberry Pi via TX1/RX1
}

void loop() {

  mySensor.read();
  float temperature = mySensor.getTemperature();

  Serial1.println(temperature, 1);
  Serial.print("Temperature: ");
  Serial.println(temperature, 1);

  //Serial1.println("Hello from Arduino!");
  //Serial.println("Hello from Arduino (USB)");
  delay(10000);
}
