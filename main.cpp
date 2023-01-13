#include <Arduino.h>
#include <BleKeyboard.h>

/**
 *turns the ESP32 into a button-controlled bluetooth keyboard 
 *button press (short) -> right arrow key
 *button press (long) -> left arrow key
 */

// optional bluetooth specific info: ("device name", "manufacturer", battery lvl)
BleKeyboard bleKeyboard("NoHandsHere", "Espressif", 100);

#define inputPin 13  // input pin to D13

void setup() {
  pinMode(inputPin, INPUT_PULLUP); // use input pullup mode (HIGH when not pressed) 
  // default bleKeyboard setup
  Serial.begin(115200); // monitor speed 
  Serial.println("Starting BLE");
  bleKeyboard.begin();
}

int buttonHeldFor = 0;  // default

// main loop 
void loop() {
  char buttonPressed = digitalRead(inputPin) == LOW;

  if (buttonPressed) {
    buttonHeldFor++;
    // Serial.println((String) "Increasing " + buttonHeldFor); // for debugging 
  }

  // if button released
  if (!buttonPressed && bleKeyboard.isConnected() && buttonHeldFor > 10000) { //10000 as min value
    // Serial.println((String) "Button held for " + buttonHeldFor); // for debugging 
    // keyboard output : adjust value to required sensitivity
    bleKeyboard.write(buttonHeldFor < 50000 ? KEY_RIGHT_ARROW : KEY_LEFT_ARROW); 
    delay(100);  // key press for 0.1 sec
    bleKeyboard.releaseAll();
    buttonHeldFor = 0;  // reset
  }
}