#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
#include "lcddraw.h"
#include "lcdutils.h"

static int sound=1000;
static enum{off=0,dim=1,on=2}brightness;
char counter =0;
char state = 0;
int active = 1;
char sc = 0;
char sr = 0;
char dif = 0;
int colorBGR = 0;


void state_advance()
{
  switch(state)
    {

    case 1: // everything is off and screen is blue
      sound = 0;
      buzzer_set_period(sound);
      colorBGR=COLOR_BLUE;
      draw();
      break;

    case 2: 
      sound = 0;
      buzzer_set_period(sound);
      break;

    case 3:
      if(sound<2000)
	{sound+=100;}
      draw();
      buzzer_set_period(sound);
      break;

    case 4:
      if(sound>500)
	{sound-=100;}
      sc=110;
      sr=20;
      dif=5;
      colorBGR = COLOR_WHITE;
      draw();
      buzzer_set_period(sound);
      break;      
    }
}

void
toggle_led()
{
  leds_changed = 1;
  count();
  switch(state)
    {
    case 1:
      green_led = 0;
      red_led = 0;
      break;
    case 3:
      green_led = (counter<1);
      red_led = 0;
      break;
    case 4:
      green_led = 0;
      red_led = (counter>1);
      break;
      //case 2:
      // green_led = 1;
      //red_led = 1;
      //break;
    }
  led_update();
}

void bright()
{brightness = (brightness+1)%3;}

void count()
{counter = (counter+1)%3;}

void draw()
{
  switch(state)
    {
    case 1:
      clearScreen(colorBGR);
      fillRectangle(0,50,180,180,COLOR_GREEN);
      drawString6x8(30,20,"Hello world",COLOR_WHITE,COLOR_BLUE);
      break;

      //case 2:
      //break;

    case 3://green bush
      fillRectangle(20,20,10,10,COLOR_RED);
      break;
    case 4://red square
      for(int c = 0; c<dif;c++){
	  for(int r = 0; r<=c; r++)
	    {
	      drawPixel(c+sc,sr+r,colorBGR);
	      drawPixel(sc-c+(dif*2)-1,sr+r,colorBGR);
	      drawPixel(c+sc,sr-r,colorBGR);
	      drawPixel(sc-c+(dif*2)-1,sr-r,colorBGR);
	    }
	}
      break;
    }
}