#include "standardTypes.h"
#include "tm4c123gh6pm.h"
#include "button.h"
#include "light.h"
#include "systick.h"
#include "portF.h"

/**
 * main.c
 */

extern volatile INT16S ticks;
 
int main(void)
{

	  INT8U event;
  INT8U alive_timer = TIM_500_MSEC;

  init_systick();
  init_portF();

  // Loop forever.
  while(1)
  {
	while( !ticks );

	// The following will be executed every 5ms
    ticks--;

	event = select_button();
	HandleState(GetState(event));
  }
	return 0;
}
