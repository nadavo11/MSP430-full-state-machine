

#include <msp430.h>
#include <bsp.h>
int main(void)
{

  MSP_init();

  for (;;)
  {
    volatile unsigned int i;

    LEDs = BUTTONs;


  }
}
