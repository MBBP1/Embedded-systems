#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
Serial.begin(9600);

// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address for 128x64
Serial.println(F("SSD1306 allocation failed"));
for(;;); // Don't proceed, loop forever
}

}

void loop() {
display.clearDisplay();

display.setTextSize(4); // Normal 1:1 pixel scale
display.setTextColor(WHITE); // Draw white text
display.setCursor(0,0); // Start at top-left corner
display.println(F("TEST"));

display.display();
delay(2000);
}
