#include <msp430.h>
#include <libTimer.h>
#include "stateMachines.h"
#include "led.h"
#include "images.h"
#include "switches.h"


void
__interrupt_vec(WDT_VECTOR) WDT(){
  switch_state_advance();
  led_update();
}
