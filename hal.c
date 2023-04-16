/*
 * hal.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Nadavo
 */

#include <msp430.h>
#include <bsp.h>
volatile unsigned int state_1 = 1;
int PWM_flag;
int state;

/************************************************************************
 *                                                                      *
 *                    declarations & helpers                             *
 *                                                                      *
 ********************************************************************** */
//software delay function


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


/************************************************************************
 *                                                                      *
 *                    high-level ISRs for each button                   *
 *                                                                      *
 ********************************************************************** */
void inline ISR_0(){
    state = 0;
}


void inline ISR_1(){
    state = 1;
}
void inline ISR_2(){
    state = 2;


}
void inline ISR_3(){

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

  state = 0;
  if (P2IFG & BIT0){
      // Button 0 pressed
      ISR_0();
      LPM3_EXIT;
  }


  if (P2IFG & BIT1) {
    // Button 1 pressed
      ISR_1();
      LPM3_EXIT;


  }
  if (P2IFG & BIT2) {

      // Button 2 pressed
      ISR_2();
      LPM3_EXIT;
      // Enable nested interrupts
      //__bis_SR_register(GIE);
    // Do something
  }
  if (P2IFG & BIT3) {
    // Button 3 pressed
      ISR_3();

    // Do something
  }

  // Clear interrupt flags
  P2IFG &= ~(BIT0 | BIT1| BIT2 | BIT3);
}

