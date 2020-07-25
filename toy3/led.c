#include <msp430.h>
#include "led.h"
#include "switches.h"


unsigned char red_led = 0, green_led = 0;
unsigned char leds_changed = 0;
static int state=0;// keeps track of lights
static char red_val[] = {0,LED_RED};
static char green_val[] = {0,LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update(1);
}

void led_update(){

  char ledFlags = 0;

  if(leds_changed)
    {
      ledFlags|= red_led ? LED_RED:0;
      ledFlags|= green_led ? LED_GREEN:0;
      
      P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
      P1OUT |= ledFlags;         // set bits for on leds
  }
  leds_changed = 0;
}

