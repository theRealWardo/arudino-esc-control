#include <Servo.h>

Servo esc;
boolean usePoten = false;
int potenValue = 0;
int value = 1;

int printLoop = 10;
int l = 0;

void setup()
{
  // Plug ESC into digital pin 9.
  esc.attach(9);

  Serial.begin(9600);
}

void loop() {
  // Always read from the potentiometer on analog pin 0.
  potenValue = (analogRead(A0) / 1023.0) * 180;
  
  // Try to read from serial if available.
  int serialValue = 0;
  if (Serial.available()) {
    serialValue = Serial.parseInt();
    Serial.println(serialValue);
  }
  
  // Do nothing if there is no serial input
  // (when serialValue == 0).
  if (serialValue > 0) {
    usePoten = false;
    value = serialValue;
  } else if (serialValue < 0) {
    // Serial input of less than 0 activates the potentiometer 
    // and changes the frequency of the display.
    printLoop = serialValue * -1;
    usePoten = true;
  }
 
  // Display the values occassionally. 
  if (++l >= printLoop) {
    Serial.print("v: ");
    Serial.print(value);
    Serial.print("  p: ");
    Serial.print(potenValue);
    if (usePoten) {
      Serial.println(" p");
    } else {
      Serial.println(" v");
    }
    l = 0;
  }
  
  if (usePoten) {
    value = potenValue;
  }
  esc.write(value);
  delay(20);
}
