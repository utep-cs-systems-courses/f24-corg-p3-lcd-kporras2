#include <msp430.h>
#include <libTimer.h>
#include "lcdtypes.h"
#include "lcddraw.h"
#include "lcdutils.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"
#include "images.h"


int main(void){
  led_init();
  configureClocks();
  switch_init();
  lcd_init();
  buzzer_init();
  enableWDTInterrupts(); //enable periodic interrupts
  or_sr(0x18);               /**< GIE (enable interrupts) && CPU SLEEP (low power mode enable) */

}
