#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);  // CE, CSN
const byte address[6] = "00010";
unsigned long lastReceivedTime = 0; // Track last received message

void setup() {
    Serial.begin(9600);
    
    // **Ensure SPI uses correct Mega2560 pins**
    SPI.begin();
    
    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_HIGH);
    radio.startListening();
    
    Serial.println("Receiver Initialized.");
}

void loop() {
    if (radio.available()) {
        char text[32] = "";  
        radio.read(&text, sizeof(text));  

        Serial.print("Received message: ");
        Serial.println(text);

        lastReceivedTime = millis();  // Update last received time
    }

    // If no data for 5 seconds, restart the receiver
    if (millis() - lastReceivedTime > 5000) {
        Serial.println("No data for 5s, restarting receiver...");
        radio.stopListening();
        delay(100);
        radio.startListening();
        lastReceivedTime = millis();
    }

    delay(5);
}
