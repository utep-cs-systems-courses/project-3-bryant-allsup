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
  clearScreen(COLOR_BLACK);
  switch_init();
  led_init();
  buzzer_init();
 
  enableWDTInterrupts();


  or_sr(0x08); // GIE on (enable interrupts)
  
  for(;;){
    while(!active)//nothing is changing
      {
	leds_changed=1;
	green_led=0;
	red_led=1;
	led_update();//led on when CPU OFF
	status = get_sr();//saves a copy of the sr
	or_sr(0x10); // CPU off
      }
    active = 0;
  }
}
