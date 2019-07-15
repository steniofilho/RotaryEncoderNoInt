/*
 * RotaryEncoderNoInt.h - Library for use Rotary Encoder without interrupt
 * Created by Stenio Filho, July, 2019
 * This lib is public domain
 */

#ifndef RotaryEncoderNoInt_h
#define RotaryEncoderNoInt_h

#include "Arduino.h"

class RotaryEncoderNoInt {
   public:
      RotaryEncoderNoInt(uint8_t sw, uint8_t dt, uint8_t clk) { switchBtnPin = sw; dtPin = dt; clkPin = clk; };
      void init(void);
      void check(void);
      uint8_t read(void);
   private:
      uint8_t switchBtnPin;
      uint8_t dtPin;
      uint8_t clkPin;
      bool clkSet = false;
      bool dtSet = false;
      bool btnSet = false;
      unsigned long last_check = 0;
      uint8_t counter = 0;
      
};

#endif
