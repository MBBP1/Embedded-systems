#include <SPI.h> 
#include <nRF24L01.h> 
#include <RF24.h> 

RF24 radio(7, 8); // CE, CSN          
const byte address[6] = "00010";  // Adresse, der skal matche receiveren

int JoyStick_X = A0; // PS2 joystick X-akse
int JoyStick_Y = A1; // PS2 joystick Y-akse

// Struktur til at sende joystickdata
struct DataPacket {
  int x;
  int y;
};

void setup() { 
  Serial.begin(9600); 
  radio.begin();  
  radio.openWritingPipe(address);  
  radio.setPALevel(RF24_PA_MIN);  
  radio.stopListening();  // Sætter modulet til at sende 
} 
 
void loop() {
  delay(50);  // Reduceret forsinkelse for hurtigere respons

  DataPacket packet;
  packet.x = analogRead(JoyStick_X) - 512; // Centerer værdier (fra -512 til 512)
  packet.y = analogRead(JoyStick_Y) - 512;

  // Send joystick-data
  radio.write(&packet, sizeof(packet));  
  Serial.print("X: ");
  Serial.print(packet.x);
  Serial.print(" | Y: ");
  Serial.println(packet.y);
}
