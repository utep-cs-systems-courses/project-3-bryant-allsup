#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char time_count = 0;


  P1OUT &= ~LED_RED;
  P1OUT &= ~LED_GREEN;
  switch(state)
    {


    case 1://button 1 action
      if(++time_count == 1)
	{
	  active = 1;
	  state_advance();
	}
      break;

      
      case 2://button 2 action
	if(++time_count == 15){
	  clearScreen(COLOR_BLACK);
	  state_advance();
	  active = 0;	  
	  }
      break;
      

    case 3://button 3
      if(++time_count == 50)
	{
	  bright();
	  state_advance();
	  time_count=0;
	  active = 1;
	}
      break;


    case 4://button 4
      if(++time_count == 50)
	{
	  bright();
	  state_advance();
	  time_count=0;
	  active = 1;
	}
      break;


    }
  toggle_led();
  
}
