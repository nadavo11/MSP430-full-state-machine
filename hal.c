/*
 * hal.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Nadavo
 */

#include <msp430.h>
#include <bsp.h>
int ID[9]= {3,1,2,3,4,9,5,0,9};
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
    int i;
    for(i = 0; i<9; i++){
            LEDs = ID[i];
            delay(DELAY_05_SECS);
        }
    LEDs =0;
}


void inline ISR_1(){
    int i;
    for(i=14; i>0;i--){
        LEDs = state_1;
        delay(DELAY_05_SECS);

        state_1 <<= 1;
        if (state_1 > 0xFF){
            state_1 = 1;
        }
    }
    LEDs = 0;
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
  }


  if (P2IFG & BIT1) {
    // Button 1 pressed
      ISR_1();


  }
  if (P2IFG & BIT2) {
      // Enable nested interrupts
     //__bic_SR_register(LPM0_bits);
     //__bis_SR_register(GIE);
      // Button 2 pressed
      state = 2;
      ISR_2();

    // Do something
  }
  if (P2IFG & BIT3) {
    // Button 3 pressed
      ISR_3();
      P2IFG &= ~BIT2;
    // Do something
  }

  // Clear interrupt flags
  P2IFG &= ~(BIT0 | BIT1| BIT2 | BIT3);
}

