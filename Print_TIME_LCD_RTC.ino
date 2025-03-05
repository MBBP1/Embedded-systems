/*
  lab25 - work with RTC—Real Time Clock Module — DS3231 and LCD
  DS3231: Real-Time Clock. Alarm simple
  library DS3231 from GIT: https://github.com/UCTRONICS/UCTRONICS_Arduino_kits
*/

#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal.h>

/*
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  

DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16, 2);    // set up the LCD's number of columns and rows: 
  lcd.clear();         //Clears the LCD screen and positions the cursor in the upper-left corner 

  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();

  // Disarm alarms and clear alarms for this example, because alarms is battery backed.
  // Under normal conditions, the settings should be reset after power and restart microcontroller.
  clock.armAlarm1(false); 
  clock.clearAlarm1();
  
 
  // Manual (Year, Month, Day, Hour, Minute, Second)
  //clock.setDateTime(2023, 4, 25, 0, 0, 0);

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);  

  // Set Alarm - Every second.
  // DS3231_EVERY_SECOND is available only on Alarm1.
  // setAlarm1(Date or Day, Hour, Minute, Second, Mode, Armed = true)
  // clock.setAlarm1(0, 0, 0, 0, DS3231_EVERY_SECOND);
  
  // Set Alarm1 - Every 0s in each minute
  // setAlarm1(Date or Day, Hour, Minute, Second, Mode, Armed = true)
  clock.setAlarm1(0, 0, 0, 0, DS3231_MATCH_S);


  // Check alarm settings
  checkAlarms();
}

void checkAlarms()
{
  RTCAlarmTime a1;  

  if (clock.isArmed1())
  {
    a1 = clock.getAlarm1();

    Serial.print("Alarm1 is triggered ");
    switch (clock.getAlarmType1())
    {
      case DS3231_EVERY_SECOND:
        Serial.println("every second");
        break;
      case DS3231_MATCH_S:
        Serial.print("when seconds match: ");
        Serial.println(clock.dateFormat("__ __:__:s", a1));
        break;
      case DS3231_MATCH_M_S:
        Serial.print("when minutes and sencods match: ");
        Serial.println(clock.dateFormat("__ __:i:s", a1));
        break;
      case DS3231_MATCH_H_M_S:
        Serial.print("when hours, minutes and seconds match: ");
        Serial.println(clock.dateFormat("__ H:i:s", a1));
        break;
      case DS3231_MATCH_DT_H_M_S:
        Serial.print("when date, hours, minutes and seconds match: ");
        Serial.println(clock.dateFormat("d H:i:s", a1));
        break;
      case DS3231_MATCH_DY_H_M_S:
        Serial.print("when day of week, hours, minutes and seconds match: ");
        Serial.println(clock.dateFormat("l H:i:s", a1));
        break;
      default: 
        Serial.println("UNKNOWN RULE");
        break;
    }
  } else
  {
    Serial.println("Alarm1 is disarmed.");
  }

}

void loop()
{

  
  dt = clock.getDateTime();

  lcd.setCursor(0, 0); // set the cursor to column 0, line 0
  lcd.print(dt.year);
  lcd.print("-");
  lcd.print(dt.month);  
  lcd.print("/");
  lcd.print(dt.day); 
  lcd.print("");
/*
  lcd.setCursor(0, 1);
  lcd.print(dt.hour);
  lcd.print(":");
  lcd.print(dt.minute);  
  lcd.print(":");
  */
  lcd.setCursor(0, 1);
  char timeBuffer[9]; // Buffer til at holde tidsstrengen (hh:mm:ss)
  sprintf(timeBuffer, "%02d:%02d:%02d", dt.hour, dt.minute, dt.second);
  lcd.print(timeBuffer); // Print den formaterede streng
 


  // Call isAlarm1(false) if you want clear alarm1 flag manualy by clearAlarm1();
  if (clock.isAlarm1())
  {
    lcd.clear();
    delay(100);
    Serial.println("ALARM 1 TRIGGERED!");
    lcd.setCursor(4, 0);
    lcd.print("!ALARM!");
     
    //??? // print alarm message - "ALARM !!!"
  }
  else
  {
    // ???
  }


  delay(1000);
  lcd.clear();
}


