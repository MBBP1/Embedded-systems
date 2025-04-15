#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define RightRX_PIN A1  // X-akse
#define RightRY_PIN A0  // Y-akse
#define SW1_PIN  2
#define LeftRX_PIN A3  // X-akse
#define LeftRY_PIN A2  // Y-akse
#define SW2_PIN  5   // Knap (Z-akse)

void setup() {
    Serial.begin(9600);

    // Initialiser OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println("OLED fejl!");
        while (true); // Stop programmet, hvis skærmen ikke virker
    }

    pinMode(SW1_PIN, INPUT_PULLUP); // Initialiser joystick-knappen
    pinMode(SW2_PIN, INPUT_PULLUP); // Initialiser joystick-knappen

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Joystick Test");
    display.display();
    delay(2000); // Vent lidt, så teksten kan ses
}

void loop() {
    int RxValue = analogRead(RightRX_PIN);
    int RyValue = analogRead(RightRY_PIN);
    int RzState = digitalRead(SW1_PIN);

    int LxValue = analogRead(LeftRX_PIN);
    int LyValue = analogRead(LeftRY_PIN);
    int LzState = digitalRead(SW2_PIN);

    // Serial output for debugging
    Serial.print("Right -> X: "); Serial.print(RxValue);
    Serial.print(" | Y: "); Serial.print(RyValue);
    Serial.print(" | Z: "); Serial.println(RzState == LOW ? "Pressed" : "Not Pressed");

    Serial.print("Left  -> X: "); Serial.print(LxValue);
    Serial.print(" | Y: "); Serial.print(LyValue);
    Serial.print(" | Z: "); Serial.println(LzState == LOW ? "Pressed" : "Not Pressed");

    // OLED output
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);

    // Row 1: X values
    display.setCursor(0, 0);
    display.print("R:");
    display.print(RxValue);
    display.setCursor(70, 0);
    display.print("L:");
    display.print(LxValue);

    // Row 2: Y values
    display.setCursor(0, 22);
    display.print("R:");
    display.print(RyValue);
    display.setCursor(70, 22);
    display.print("L:");
    display.print(LyValue);

    // Row 3: Z (switches)
    display.setCursor(0, 44);
    display.print("R:");
    display.print(RzState == LOW ? "ON " : "OFF");
    display.setCursor(70, 44);
    display.print("L:");
    display.print(LzState == LOW ? "ON " : "OFF");

    display.display(); // Update screen
    delay(300);
}

