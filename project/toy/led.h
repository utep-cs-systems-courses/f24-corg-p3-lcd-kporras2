#ifndef led_included
#define led_included

#define LED_RED BIT6
#define LEDS (BIT6)

extern unsigned char redOn;
extern unsigned char led_diff;

void led_init();
void led_update();
void redC(int on);
#endif
