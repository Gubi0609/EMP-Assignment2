/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: button.c
*
* PROJECT....: Traffic Light
*
* DESCRIPTION: See module specification file (.h-file).
*****************************************************************************/

/***************************** Include files *******************************/
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "standardTypes.h"
#include "button.h"

/*****************************    Defines    *******************************/


/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/
INT8U button_pushed()
{
  return( !(GPIO_PORTF_DATA_R & 0x10) );  // SW at PF4
}

INT8U select_button(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function :
******************************************************************************/
{
  static INT8U  button_state = IDLE;
  static INT16U button_timer;
         INT8U  button_event = IDLE;

  switch( button_state )
  {
    case IDLE:
	    if( button_pushed() )		            // if button pushed
	    {
	        button_state = FIRST_PRESS;
		    button_timer = TIM_2_SEC;		    // start timer = 2 sec;
	    }
	    break;
    case FIRST_PRESS:
	    if( ! --button_timer )			        // if timeout
	    {
	        button_state = LONG_PRESS;
		    button_event = LONG_PRESS;
	    }
	    else
	    {
	        if( !button_pushed() )	                // if button released
			{
		        button_state = FIRST_RELEASE;
			    button_timer = TIM_100_MSEC;	    // start timer = 100 milli sec;
		    }
	    }
	    break;
    case FIRST_RELEASE:
	    if( ! --button_timer )			        // if timeout
	    {
	        button_state = IDLE;
		    button_event = SINGLE_PRESS;
	    }
	    else
	    {
	        if( button_pushed() )		            // if button pressed
			{
		         button_state = SECOND_PRESS;
			     button_timer = TIM_2_SEC;		    // start timer = 2 sec;
	        }
	    }
	    break;
    case SECOND_PRESS:
	    if( ! --button_timer )			        // if timeout
	    {
	        button_state = LONG_PRESS;
		    button_event = LONG_PRESS;
	    }
	    else
	    {
	        if( !button_pushed() )				    // if button released
			{
		          button_state = IDLE;
			      button_event = DOUBLE_PRESS;
	        }
	    }
	    break;
    case LONG_PRESS:
        if( !button_pushed() )					// if button released
            button_state = IDLE;
	    break;
    default:
        break;
  }
  return( button_event );
}

/****************************** End Of Module *******************************/












