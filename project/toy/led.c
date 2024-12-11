#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"


unsigned char redOn = 0;
unsigned char led_diff = 0;

void led_init(){
  P1DIR |= LEDS;
  led_diff = 1;
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if(switch_state_changed){
    char ledFlags = 0;
    switch_state_changed =0;
  }
}

void redC(int on){
  if(on){
    P1OUT |= LED_RED;
  }
  else{
    P1OUT &= ~LED_RED;
  }
}
