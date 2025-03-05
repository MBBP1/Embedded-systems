#include <DHT.h>      // DHT biblotek
#include <SD.h>       // SD biblotek
#include <DS3231.h>   // RTC biblotek


DHT OutdoorSensor(6, DHT22);  // Udendørs DHT på pin 6 og definerer DHT-sensortypen som DHT22 (AM2302)
DHT IndoorSensor(7, DHT22);   // Indendørs DHT på pin 7 og definerer DHT-sensortypen som DHT22 (AM2302)

// Pins og tider
const int chipSelect = 53;  // CS pin til SD-kortet
const int sensorPin = A1;   // Analog pin til Lys sensor
const int ErrorLed = 23;    // LED til fejl indikation
const unsigned long period = 600000; // Loginterval - 10 minutter i millisekunder
unsigned long previousMillis = 0;    // Gemmer tidspunktet for sidste logning. Sættes til 0 fordi der ikke er gemt noget tidspunkt til at starte med.

// Struct/variable til at gemme dato og tid fra RTC
RTCDateTime dt; 

// Initialiserer RTC og SD-kort objekter
DS3231 clock; 
File myFile;

void setup() {
  
  // Initialiser Serial Monitor
  Serial.begin(9600);

  // Sætter LED som output
  pinMode(ErrorLed, OUTPUT);

  // Initialiser RTC modulet
  clock.begin();
  //clock.setDateTime(__DATE__, __TIME__); // Set RTC to compile time

  // Initialiser SD-kort læser
  Serial.println("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed.");
    digitalWrite(ErrorLed, HIGH); // Tænder LED ved fejl
    while (true); // Stopper programmet, hvis SD-kortet fejler
  }
  Serial.println("SD card initialized successfully.");

  // Opretter og/eller åbner filen "exam1.txt" og skriv overskriften
  myFile = SD.open("exam1.txt", FILE_WRITE);
  if (myFile) {
    Serial.print("Writing to exam1.txt...");
    myFile.println("Date,Time,OutdoorTemp,OutdoorHumidity,IndoorTemp,IndoorHumidity,Light");
    myFile.close();
    Serial.println("exam1.txt");
  } else {
    Serial.println("Error opening exam1.txt");
    digitalWrite(ErrorLed, HIGH); // Tænder LED ved fejl
  }

  // Initialiser DHT-sensorer
  Serial.println("Initializing DHT sensors...");
  OutdoorSensor.begin();
  IndoorSensor.begin();
}


void logSensorsDateTime() {
  // Henter den aktuelle dato og tid fra RTC modulet
  dt = clock.getDateTime();
  
    // Læs sensorværdier fra LDR og DHT
    int LightSensorValue = analogRead(sensorPin); // Read value from LDR
    int outdoorTemp = (OutdoorSensor.readTemperature() * 10); // skriver uden kommmatal
    int outdoorHumidity = (OutdoorSensor.readHumidity() * 10);
    int indoorTemp = (IndoorSensor.readTemperature() * 10);
    int indoorHumidity = (IndoorSensor.readHumidity() * 10);
    
  // Tjekker om der er fejl i DHT-sensorerne hvis det er det bliver der ikke logget noget i denne iteration
  if (isnan(outdoorTemp) || isnan(outdoorHumidity) || isnan(indoorTemp) || isnan(indoorHumidity)) {
    Serial.println("Failed to read from DHT sensors.");
    return;  // Afslutter/stopper logSensorsDateTime, hvis der er fejl.
  }

  // Formater dato og tid (tidspunkt)
  char timeBuffer[32];
  snprintf(timeBuffer, sizeof(timeBuffer), "%04d-%02d-%02d,%02d:%02d:%02d,",
           dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);

char timeBuffer[32] = {dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second};

Serial.print("%04d-%02d-%02d,%02d:%02d:%02d,", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);


  // Åbner filen og skriver data
  myFile = SD.open("exam1.txt", FILE_WRITE);
  if (myFile) {
    myFile.print(timeBuffer); 
    myFile.print(outdoorTemp);
    myFile.print(",");
    myFile.print(outdoorHumidity);
    myFile.print(",");
    myFile.print(indoorTemp);
    myFile.print(",");
    myFile.print(indoorHumidity);
    myFile.print(",");
    myFile.println(LightSensorValue);
    myFile.close();

    // Skriver til Serial Monitor
    Serial.print("Logged: ");
    Serial.print(timeBuffer);
    Serial.print(outdoorTemp);
    Serial.print(",");
    Serial.print(outdoorHumidity);
    Serial.print(",");
    Serial.print(indoorTemp);
    Serial.print(",");
    Serial.print(indoorHumidity);
    Serial.print(",");
    Serial.println(LightSensorValue);
  } else {
    Serial.println("Error opening exam1.txt for writing.");
  }
}

void loop() {
  // Hent det nuværende tidspunkt
  unsigned long currentMillis = millis();  //millis() viser hvor længe arduinoen har været tændt i millisekunder

  // Tjek, om logintervallet er gået
  if (currentMillis - previousMillis >= period) {
    previousMillis = currentMillis;  // Opdater sidste logtidspunkt
    logSensorsDateTime();  // Kalder logSensorsDateTime som logger dato,tid og sensorværdier 
  }
}