#ifndef stateMachine_included
#define stateMachine_included

void state_advance();
void toggle_led();
void bright();
void count();

extern char state;
extern char led_toggle;
extern char counter;

#endif // included
