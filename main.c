#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/bsp.h"
#include "header/hal.h"
#include "header/api.h"

// T_mclk = 2^-20
#define PWM_PERIOD   250 // 4 kHz PWM frequency
#define PWM_DUTYCYCLE  187 // 75% duty cycle

int ID[9]= {3,1,2,3,4,9,5,0,9};
volatile unsigned int state_ISR_1 = 1;




/************************************************************************
 *                                                                      *
 *                    high-level ISRs for each button                   *
 *                                                                      *
 ********************************************************************** */
char name[] = "Nadav";

int str[6]  = {1,2,4,8,4,2};

void inline ISR_0(){

    unsigned int i;
    for(i = 0; i<9; i++){

        LEDsArraySet(ID[i]);
        delay(DELAY_05_SECS);
    }
    LEDsArraySet(0);
    state = -1;
}

void inline ISR_1(){

    unsigned int i;
    for(i=14; i>0;i--){
        LEDsArraySet(state_ISR_1);
        delay(DELAY_05_SECS);

        state_ISR_1 <<= 1;
        if (state_ISR_1 > 0xFF){
            state_ISR_1 = 1;
        }
    }
    LEDsArraySet(0);
    state = -1;

}
void inline ISR_2(){


//*************//

}
void inline ISR_3(){
    LEDsArraySet(0);
    state = -1;
}

/************************************************************************
 *                                                                      *
 *                              Main Function                           *
 *                                                                      *
 ********************************************************************** */
int main(void)
{

  MSP_init();

  for(;;){
      if(state == -1)
          Sleep();     // Enter LPM4 w/interrupt

      if(state == 0){
          ISR_0();
      }

      if(state == 1){
          ISR_1();
      }

      if(state == 2){

         PWM_signal( PWM_DUTYCYCLE, PWM_PERIOD);
      }

      if(state == 3){
         ISR_3();
      }
  }

}



