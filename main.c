

#include <msp430.h>
#include <bsp.h>


int main(void)
{

  MSP_init();

  for (;;)
  {
    volatile unsigned int i;

    LEDs |= BUTTONs;
    LEDs <<= 1;

    for(i=0; i<5000;i++);


  }
}
