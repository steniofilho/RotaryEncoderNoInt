/*
 * RotaryEncoderNoInt.h - Library for use Rotary Encoder without interrupt
 * Created by Stenio Filho, July, 2019
 * This lib is public domain
 */
#include "Arduino.h"
#include "RotaryEncoderNoInt.h"

void RotaryEncoderNoInt::init(void) {
  pinMode(switchBtnPin,INPUT_PULLUP);
  pinMode(dtPin,INPUT_PULLUP);
  pinMode(clkPin,INPUT_PULLUP); 
}

  void RotaryEncoderNoInt::check(void) {
     if ( ! (PINC & 0x01) ) { btnSet = true; } // pressed
     else { 
        if (btnSet) { counter |= 1 << 0; } // released
        else { counter &= ~(1 << 0); } // not pressed
     }
    const unsigned long check_now = millis();
    if (check_now - last_check > 1) { 
    switch (PINC & 0x06) {
      case 0x00 :
         if ( (clkSet) and (! dtSet) ) {
          counter |= 1 << 2;
          counter &= ~(1 << 1);
         } else if ( (dtSet) and (! clkSet) ) {
          counter |= 1 << 1;
          counter &= ~(1 << 2);
         }
      break;
      case 0x02 :
        clkSet = true;
      break;
      case 0x04 :
         dtSet = true;
      break;
      case 0x06 :
        if ( (!dtSet) and (!clkSet) ){
          counter &= 0x01;
        }
      break;
    }
    last_check = check_now;
    }
}

uint8_t RotaryEncoderNoInt::read(void) {
  if ( (dtSet & clkSet) or (btnSet & (counter & 0x01)) ) {
    dtSet = false; clkSet = false; btnSet = false;
    const uint8_t result = counter;
    counter = 0;
    return result;
  }
  return 0;
} 
