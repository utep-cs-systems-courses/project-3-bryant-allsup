#ifndef stateMachine_included
#define stateMachine_included

void state_advance();
void toggle_led();
void bright();
void count();
void draw();


extern char sc;
extern char sr;
extern char dif;
extern int colorBGR;
extern int active;
extern char state;
extern char led_toggle;
extern char counter;

#endif // included
