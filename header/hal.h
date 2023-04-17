
#ifndef HAL_H_
#define HAL_H_

int PWM_flag;
int state;

void LED_blink(int n);
inline void Sleep();

extern void LEDsToggle(char);
extern void LEDsArraySet(char);
extern void LEDsArrayShow(char);
extern void LEDsArrayClear(char);
#endif /* HAL_H_ */
