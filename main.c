

#include <msp430.h>
#include <bsp.h>
#include <hal.h>

// T_mclk = 2^-20
#define PWM_PERIOD   4000 // 4 kHz PWM frequency
#define PWM_DUTYCYCLE  3000 // 75% duty cycle

int ID[9]= {3,1,2,3,4,9,5,0,9};
volatile unsigned int state_ISR_1 = 1;




/************************************************************************
 *                                                                      *
 *                    high-level ISRs for each button                   *
 *                                                                      *
 ********************************************************************** */
void inline ISR_0(){

    unsigned int i;
    for(i = 0; i<9; i++){

        LEDs = ID[i];
        delay(DELAY_05_SECS);
    }
    LEDs =0;
    state = -1;
}


void inline ISR_1(){

    unsigned int i;
    for(i=14; i>0;i--){
        LEDs = state_ISR_1;
        delay(DELAY_05_SECS);

        state_ISR_1 <<= 1;
        if (state_ISR_1 > 0xFF){
            state_ISR_1 = 1;
        }
    }
    LEDs = 0;
    state = -1;

}
void inline ISR_2(){


}
void inline ISR_3(){

}

/************************************************************************
 *                                                                      *
 *                              Main Function                           *
 *                                                                      *
 ********************************************************************** */
int main(void)
{

  MSP_init();
  unsigned int i;

  for(;;){
      if(state == -1)
          __bis_SR_register( LPM3_bits + GIE);       // Enter LPM4 w/interrupt

      if(state == 0){
          ISR_0();
      }

      if(state == 1){
          ISR_1();
      }

      if(state == 2){

         PWM_signal( PWM_DUTYCYCLE, PWM_PERIOD);
      }

  }

}



