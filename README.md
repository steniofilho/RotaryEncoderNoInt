# RotaryEncoderNoInt
Arduino Library to user Rotary Encoder with no Interrupts. It can be used in analog ports.

## Usage

- Constructor **RotaryEncoderNoInt(uint8_t sw, uint8_t dt, uint8_t clk)**
  - sw --> switch button pin
  - dt --> dt pin
  - clk --> clk pin
- Method **``void init(void)``**: used to initialize pin modes
- Method **``void check(void)``**: used to check arduino pin inputs and setup status of rotary encoder
- Method **``uint8_t read(void)``**: used to read rotary encoder status. it returns:
  - if button released, set least significant bit of status to 1, otherwise, set to 0
  - if clockwise turn, set 3rd bit to 1 and 2nd bit to 0 --> 0b100 or 0b101 (if button released)
  - if counter-clockwise turn, set 3rd bit to 0 and 2nd bit to 1 --> 0b010 or 0b011 (if button released)
  
## Example

```C++
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
```
<img src="https://github.com/steniofilho/RotaryEncoderNoInt/raw/master/RotaryEncoderNoInt.png" height="50%" width="50%">
