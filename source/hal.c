

#include <msp430.h>
#include "../header/bsp.h"
volatile unsigned int state_1 = 1;
int PWM_flag;
int state;

/************************************************************************
 *                                                                      *
 *                    declarations & helpers                             *
 *                                                                      *
 ********************************************************************** */
//software delay function

void LEDsArrayToggle(char a){
  LEDs ^= a;
}
//------------------------------------------------------------------
void LEDsArraySet(char a){
  LEDs= a;
}
//------------------------------------------------------------------
void LEDsArrayShow(char a){
  LEDs |= a;
}
//------------------------------------------------------------------
void LEDsArrayClear(char a){
  LEDs &= ~a;
}

//blink example test case
void LED_blink(int n){
    int i;
    LEDs = 0x3;
    for(i = 20; i>0;i--){
        LEDs ^= 0x3;
        delay(5000);
    }
    LEDs =0;
}

void setLeds(int leds){
    LEDs = leds;
}

inline void Sleep(){
    __bis_SR_register( LPM3_bits + GIE);
}


/************************************************************************
 *                                                                      *
 *                    HAL drivers - ISR handler                         *
 *                                                                      *
 ********************************************************************** */
#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {
  // Check which button triggered the interrupt
  volatile unsigned int i;
  volatile unsigned int t;

  //delay(DEBOUNCE); // TODO ADD DEBOUNCE
  state = 0;
  if (P2IFG & BIT0){
      // Button 0 pressed
      state = 0;
      LPM3_EXIT;
  }


  if (P2IFG & BIT1) {
    // Button 1 pressed
      state = 1;
      LPM3_EXIT;


  }
  if (P2IFG & BIT2) {

      // Button 2 pressed
      state = 2;
      LPM3_EXIT;
      // Enable nested interrupts
      //__bis_SR_register(GIE);
    // Do something
  }
  if (P2IFG & BIT3) {
    // Button 3 pressed
      state = 3;
      LPM3_EXIT;

    // Do something
  }


  // Clear interrupt flags
  P2IFG &= ~(BIT0 | BIT1| BIT2 | BIT3);
}

