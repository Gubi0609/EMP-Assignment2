/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: light.c
*
* PROJECT....: Traffic Light
*
* DESCRIPTION: See module specification file (.h-file).
*****************************************************************************/

/***************************** Include files *******************************/
#include "tm4c123gh6pm.h"
#include "standardTypes.h"
#include "button.h"
#include "light.h"

/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/
INT16U counter_timer = TIM_2_SEC;
static INT8U current_state = RED_STATE;

/*****************************   Functions   *******************************/

void ClearColor()
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Clear the color LEDs on Port F (PF1-PF3)
******************************************************************************/
{
    GPIO_PORTF_DATA_R &= 0xF1; // 1111 0001
}

void SetColor(INT16U Color)
/*****************************************************************************
*   Input    : Color - Color code to set on the LEDs
*   Output   : -
*   Function : Set the specified color on the LEDs
******************************************************************************/
{
    ClearColor();
    GPIO_PORTF_DATA_R |= Color;
}

void ToggleColor(INT16U Color)
/*****************************************************************************
*   Input    : Color - Color code to toggle on the LEDs
*   Output   : -
*   Function : Toggle the specified color on the LEDs
******************************************************************************/
{
    GPIO_PORTF_DATA_R ^= Color;
}

void HandleState(INT8U state)
/*****************************************************************************
*   Input    : state - Current traffic light state
*   Output   : -
*   Function : Handle the current state and manage state transitions
******************************************************************************/
{
    switch(state){
        case RED_STATE:
            SetColor(RED);
            if(! --counter_timer){
                counter_timer = TIM_1_SEC;
                current_state = RED_YELLOW_STATE;
            }
            break;
        case RED_YELLOW_STATE:
            SetColor(RED_YELLOW);
            if(! --counter_timer){
                counter_timer = TIM_2_SEC;
                current_state = GREEN_STATE;
            }
            break;
        case YELLOW_STATE:
            SetColor(YELLOW);
            if(! --counter_timer){
                counter_timer = TIM_2_SEC;
                current_state = RED_STATE;
            }
            break;
        case GREEN_STATE:
            if(! --counter_timer){
                counter_timer = TIM_1_SEC;
                current_state = YELLOW_STATE;
            }
            SetColor(GREEN);
            break;
        case NORWEGIAN_STATE:
            if(! --counter_timer){
                counter_timer = TIM_1_SEC;
                ToggleColor(YELLOW);
            }
            break;
        case EMERGENCY_STATE:
            //set solid color
            SetColor(RED);
            break;
    }

}

INT8U GetState(INT8U button_event)
/*****************************************************************************
*   Input    : button_event - Button event from select_button()
*   Output   : Current state
*   Function : Process button events and return the current traffic light state
******************************************************************************/
{
    //read state from button and figure out what to do
    switch (button_event)
    {
    case IDLE:
        //do nothing
        break;
    case SINGLE_PRESS: //switch to Norwegian state
        current_state = NORWEGIAN_STATE;
        counter_timer = TIM_1_SEC; 
        SetColor(YELLOW);
        break;
    case DOUBLE_PRESS: //switch to emergency state
        current_state = EMERGENCY_STATE;
        break;
    case LONG_PRESS: //reset the traffic light
        current_state = RED_STATE;
        counter_timer = TIM_2_SEC;
        break;
    default:
        break;
    }
    return current_state;
}

/****************************** End Of Module *******************************/
