#include <SPI.h> 
#include <nRF24L01.h> 
#include <RF24.h> 

RF24 radio(7, 8); // CE, CSN          
const byte address[6] = "00002";  // Adresse, som skal matche receiverens adresse

int button_pin = 2; 
boolean button_state = 0;

// Struktur til at sende både tekst og knapstatus i én pakke
struct DataPacket {
  char text[32];
  boolean button_state;
};

void setup() { 
  Serial.begin(9600);
  pinMode(button_pin, INPUT); 
  radio.begin();  
  radio.openWritingPipe(address);  
  radio.setPALevel(RF24_PA_MIN);  
  radio.stopListening();  // Sætter modulet til at sende 
} 
 
void loop() {
  delay(3000);  // Ventetid for testformål  
  button_state = digitalRead(button_pin); 

  // Opretter en pakke med både tekst og knapstatus
  DataPacket packet;
  if (button_state == HIGH) {
    strcpy(packet.text, "Mikkel_Your Button State is HIGH");
  } else {
    strcpy(packet.text, "Your Button State is LOW");
  }
  packet.button_state = button_state; 

  // Send pakken
  radio.write(&packet, sizeof(packet));  
  Serial.println(packet.text);
}
