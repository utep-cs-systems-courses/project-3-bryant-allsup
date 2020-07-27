#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char time_count = 0;



  switch(state)
    {


    case 1://button 1 action
      if(++time_count == 1)
	{
	  state_advance();
	  //time_count=0;
	}
      break;

      
      case 2://button 2 action
	if(++time_count == 15){
	  clearScreen(COLOR_BLACK);
	  state_advance();
	  
	  }
      break;
      

    case 3://button 3
      if(++time_count == 50)
	{
	  bright();
	  state_advance();
	  time_count=0;
	}
      break;


    case 4://button 4
      if(++time_count == 50)
	{
	  bright();
	  state_advance();
	  time_count=0;
	}
      break;


    }
  toggle_led();
  
}
