/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_BLUE);


  //draw a square of size ten

  int colum=50;
    int row=50;
    for(colum = 0; colum<=screenWidth;colum++)
      {
	drawPixel(colum,60,BLACK);
      }

    colum=50;

    while(colum<=60)
      {
	    drawPixel(colum,50,BLACK);
	    drawPixel(colum,60,BLACK);
	    drawPixel(50,row,BLACK);
	    drawPixel(60,row,BLACK);
	    row++;
	    colum++;
      }
    colum = 50;
    row=50;
    for(int change = 0, max = 60;change<=5;change++)
      {
	drawPixel(colum+change,row-change,BLACK);
	drawPixel(max-change,row-change,BLACK);
	
      }
  
  
    }

  //drawString5x7(20,20, "hello", COLOR_GREEN, COLOR_RED);

  //fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  
