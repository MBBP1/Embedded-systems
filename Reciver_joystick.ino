#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Motor A
int enA = 9;  
int in1 = 8;  
int in2 = 7;

// Motor B
int enB = 10; 
int in3 = 6;  
int in4 = 5;

RF24 radio(7, 8);  // CE, CSN
const byte address[6] = "00010";  // Skal matche transmitterens adresse

// Struktur til at modtage joystickdata
struct DataPacket {
  int x;
  int y;
};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);  
  radio.setPALevel(RF24_PA_MIN);  
  radio.startListening();  // Sætter modulet til at modtage

  // Sæt motorpins til output
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  if (radio.available()) {  // Lytter efter data
    DataPacket packet;
    radio.read(&packet, sizeof(packet));  // Læs joystickdata

    Serial.print("X: ");
    Serial.print(packet.x);
    Serial.print(" | Y: ");
    Serial.println(packet.y);

    // Behandl joystick Y (frem/tilbage)
    int deadZone = 20; // Undgå små udsving i midten
    int speed = map(abs(packet.y), 0, 512, 0, 255);

    if (packet.y > deadZone) { // Fremad
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    } 
    else if (packet.y < -deadZone) { // Tilbage
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    } 
    else { // Stop
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      speed = 0;
    }

    // Sæt motorhastighed
    analogWrite(enA, speed);
    analogWrite(enB, speed);
  }
}
