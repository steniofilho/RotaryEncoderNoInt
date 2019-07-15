#include "RotaryEncoderNoInt.h"

RotaryEncoderNoInt rotary(A0,A1,A2);

void setup()
{
  rotary.init();
  Serial.begin(9600);
}

void loop()
{
  rotary.check();
  uint8_t rotaryStatus = rotary.read();
  if ((rotaryStatus >> 0) & 1) {  //BTN Click
       Serial.println("Menu enter");
  } 
  switch (rotaryStatus & 0x06) {
    case 0x04:  //Clockwise
        Serial.println("Menu option down");
    break;
    case 0x02:  //Counter-Clockwise
         Serial.println("Menu option up");
    break;
  }
}
