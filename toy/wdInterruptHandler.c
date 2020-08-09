#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "toggleLed.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char time_count = 0;


  P1OUT &= ~LED_RED;//led off while cpu on
  P1OUT &= ~LED_GREEN;
  switch(state)
    {
    
      
    case 1://button 4 action
      if(++time_count == 125){
	state_advance();	
      }
      break;
      
    case 2: //button 2
      if(++time_count == 125)
	{
	  if(!active)
	    {
	      and_sr(0xef);
	    }
	  
	  state_advance();
	  time_count=0;
	}
      break;  
      

    case 3://button 3
      if(++time_count == 125)
	{
	  if(!active)
	    {
	      and_sr(0xef);
	    }
	  
	  state_advance();
	  time_count=0;
	}
      break;

      case 4://button 1 action
      if(++time_count == 125)
	{
	  if(!active)
	    {
	      and_sr(0xef);
	    }
	  state_advance();
	  time_count=0;
	}
      break;
    }
  toggleLed();
}
