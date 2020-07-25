#ifndef switches_included
#define switches_included

//#define SW1 BIT3		/* switch1 is p1.3 */
//#define SWITCHES SW1		/* only 1 switch on this board */

#define SW1 BIT0 /* set bits at bit number */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)

void switch_init();//initialize to  port 2 in here //p2.0,p2.1,p2.2,p2.3
void switch_interrupt_handler();

extern char button1_down,button2_down,button3_down,button4_down,switch_state_changed;
/* effectively boolean */

#endif // included
