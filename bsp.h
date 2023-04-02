#define LEDs P1OUT
#define BUTTONs P2IN^0x3
#define DELAY_05_SECS 0x8000
#define PWM_DELAY_75 0xC0
#define PWM_DELAY_25 0x40

void delay(volatile unsigned int t);
void MSP_init();

inline void PWM_signal(int PWM_duty,int PWM_period);
void PWM_stop();
