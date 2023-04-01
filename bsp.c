
#include <msp430.h>
#include <bsp.h>
void MSP_init()



{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  /*P1.0-7 set as out*/
  P1DIR = 0xFF;                             // P1.x output
  P1OUT = 0x00;                             // P1   set to 0
  
  /*P2.0-3 set as out*/
  P2DIR = 0x00;                             // P2.x input
  P2REN |= 0x03;                            // P2.0 ,p2.1 pullup rest pulldown
  P2IE |= 0x0F;                             // P1.x interrupt enabled
  P2IES |= 0x0F;                            // P1.x Hi/lo edge
  P2IFG &= ~0x0F;                           // P1.x IFG cleared

  __bis_SR_register(LPM4_bits + GIE);       // Enter LPM4 w/interrupt
}

