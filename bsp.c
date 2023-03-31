
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

  //__bis_SR_register(LPM4_bits + GIE);       // Enter LPM4 w/interrupt
}


#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR(void) {
  // Check which button triggered the interrupt
  if (P2IFG & BIT0) {
    // Button 0 pressed
    // Do something
  }
  if (P2IFG & BIT1) {
    // Button 1 pressed
    // Do something
  }
  if (P2IFG & BIT2) {
    // Button 2 pressed
    // Do something
  }
  if (P2IFG & BIT3) {
    // Button 3 pressed
    // Do something
  }

  // Clear interrupt flags
  P2IFG &= ~(BIT0 | BIT1 | BIT2 | BIT3);
}
