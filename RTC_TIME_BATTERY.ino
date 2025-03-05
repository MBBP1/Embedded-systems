/***********************************************************
lab24 - work with RTC—Real Time Clock Module — DS3231
***********************************************************/
#include <Wire.h>
#include <DS3231.h>
#include <time.h>


//Class og object
DS3231 clock;
RTCDateTime dt;

void setup()
{
  // begin serial
  Serial.begin(9600);
  
  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);

  // Set from UNIX timestamp
  // clock.setDateTime(1397408400);

  //Manual (YYYY, MM, DD, HH, II, SS)
  // clock.setDateTime(2016, 12, 9, 11, 46, 00); //Husk at kommentere det ud efter det er oploadet en/første gang
}

void loop()
{
  //dt henter dato
  dt = clock.getDateTime();

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  // print month
  Serial.print(dt.month);   Serial.print("-");
  // print day
  Serial.print(dt.day);   Serial.print("-");
  // print hour
  Serial.print(dt.hour);   Serial.print("-");
  // print minute
  Serial.print(dt.minute);   Serial.print("-");
  // print second
  Serial.print(dt.second);   Serial.print("-");
  Serial.println();
  
  // some delay
  delay(10000);
}
