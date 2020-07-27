#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachines.h"
#include "lcdutils.h"
#include "lcddraw.h"

void picture();


void main(void) 
{  
  configureClocks();

  lcd_init();
  u_char width = screenWidth, height = screenHeight;  
  switch_init();
  led_init();
  buzzer_init();

 
  enableWDTInterrupts();


  or_sr(0x08); // GIE on (enable interrupts)
  
  for(;;){
    while(!active)//nothing is changing
      {
	leds_changed=1;
	green_led=1;
	red_led=1;
	toggle_led();//led on when CPU OFF
	or_sr(0x10); // CPU off
      }
    active = 0;
  }
}
