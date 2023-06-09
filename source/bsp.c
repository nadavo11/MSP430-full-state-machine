
#include <msp430.h>
#include "../header/bsp.h"

#define FREQUANCY_us 1


void MSP_init()
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  /*P1.0-7 set as out*/
  P1SEL= 0x0;                               // P1 GPIO
  P1DIR = 0xFF;                             // P1.x output
  P1OUT = 0x00;                             // P1   set to 0
  
  /*P2.0-3 set as out*/
  P2DIR = 0x00;                             // P2.x input
  P2REN |= 0x03;                            // P2.0 ,p2.1 pullup rest pulldown
  P2IE |= 0x0F;                             // P2.x interrupt enabled
  P2IES |= 0x0F;                            // P2.x Hi/lo edge
  P2IFG &= ~0x0F;                           // P1.x IFG cleared

  // Set up P2.7 as a PWM output
  P2DIR |= BIT7;                            // Set P2.7 as output
  //
  P2SEL &= 0;                            // Select GPIO for P2.7
  P2OUT &= ~BIT7;
//
  __bis_SR_register( GIE +LPM4_bits);       // Enter LPM4 w/interrupt

}

void delay(volatile unsigned int t){
    // the delay is in microseconds
    while(t--);
}


inline void PWM_signal(int PWM_duty,int PWM_period){
    P2OUT |= BIT7;
    delay(PWM_duty);
    P2OUT &= ~BIT7;
    delay( PWM_period- PWM_duty);
}

inline void PWM_stop(){
    P2OUT &= ~BIT7;                       // power off PWM leg
}
