

#include <msp430.h>
#include <bsp.h>
#include <hal.h>

// T_mclk = 2^-20
#define PWM_PERIOD   4000 // 4 kHz PWM frequency
#define PWM_DUTYCYCLE  3000 // 75% duty cycle

int main(void)
{

  MSP_init();

  for(;;){
      if(state == 2){
         PWM_signal( PWM_DUTYCYCLE, PWM_PERIOD);
      }

  }

}



