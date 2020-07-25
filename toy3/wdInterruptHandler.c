#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "switches.h"
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char time_count = 0;


  if(button1_down == 1)
    state = 1;
  if(button2_down == 1)
    state = 2;
  if(button3_down == 1)
    state = 3;
  if(button4_down == 1)
    state = 4;



  switch(state)
    {
    case 1:

      if(++time_count == 125)
	{
	  state_advance();
	}
      break;
    case 2:

      if(++time_count == 125)
	{
	  state_advance();
	}      
      break;
    case 3:

      if(++time_count == 125)
	{
	  bright();
	  state_advance();
	}
      
      break;
    case 4:

      if(++time_count == 125)
	{
	  bright();
	  state_advance();
	}
      
      break;
    }

  toggle_led();
  
}
