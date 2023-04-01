/*
 * hal.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Nadavo
 */

#include <msp430.h>
#include <bsp.h>

int ID[9]= {3,1,2,3,4,9,5,0,9};
/************************************************************************
 *                                                                      *
 *                    declarations & helpers                             *
 *                                                                      *
 ********************************************************************** */

//software delay function
void delay(volatile unsigned int t){
    while(t--);
}
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

}
void inline ISR_2(){

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

  if (P2IFG & BIT0){
      ISR_0();


    // Button 0 pressed
  }



  if (P2IFG & BIT1) {
    // Button 1 pressed
      ISR_1();

    // Do something

  }
  if (P2IFG & BIT2) {
    // Button 2 pressed
      void ISR_2();

    // Do something
  }
  if (P2IFG & BIT3) {
    // Button 3 pressed
      void ISR_3();
    // Do something
  }

  // Clear interrupt flags
  P2IFG &= ~(BIT0 | BIT1 | BIT2 | BIT3);
}

