#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "images.h"




void switch_state_advance(){
  switch (switch_state){
  case 1:
    cop();
    break;
  case 2:
    marry_had_a_little_lamb();
    break;
  case 3:
    twinkle_twinkle_little_star();
    break;
  case 4:
    buzzer_off();
    break;
  default:
    buzzer_set_period(800);
    break;
  }
}
