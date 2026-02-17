#include "standardTypes.h"
#include "tm4c123gh6pm.h"
#include "button.h"
#include "light.h"
#include "systick.h"

/**
 * main.c
 */
int main(void)
{

	  INT8U event;
  INT8U counter_value;
  INT8U alive_timer = TIM_500_MSEC;

  init_systick();
  init_gpio();

  // Loop forever.
  while(1)
  {
	// System part of the super loop.
    // ------------------------------
	while( !ticks );

	// The following will be executed every 5ms
    ticks--;

	if( ! --alive_timer )
	{
	  alive_timer        = TIM_500_MSEC;
	  //GPIO_PORTD_DATA_R ^= 0x40; //0100 0000
	}

	// Application part of the super loop.
	// -----------------------------------
	event = select_button();
	counter_value = counter( event );
	counter_leds( counter_value );
  }
	return 0;
}
