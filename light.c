#include "tm4c123gh6pm.h"
#include "standardTypes.h"
#include "button.h"
#include "light.h"

INT16U counter_timer = TIM_2_SEC;

void ClearColor(){
    GPIO_PORTF_DATA_R &= 0xF1; // 1111 0001
}

void SetColor(INT16U Color){
    ClearColor();
    GPIO_PORTF_DATA_R |= Color;
}

void ToggleColor(INT16U Color){
    GPIO_PORTF_DATA_R ^= Color;
}

void HandleState(INT8U state){
    switch(state){
        case RED_STATE:
            SetColor(RED);
            if(! --counter_timer){
                counter_timer = TIM_1_SEC;
                state = RED_YELLOW_STATE;
            }
            break;
        case RED_YELLOW_STATE:
            SetColor(RED_YELLOW);
            if(! --counter_timer){
                counter_timer = TIM_2_SEC;
                state = GREEN_STATE;
            }
            break;
        case YELLOW_STATE:
            SetColor(YELLOW);
            if(! --counter_timer){
                counter_timer = TIM_2_SEC;
                state = RED_STATE;
            }
            break;
        case GREEN_STATE:
            if(! --counter_timer){
                counter_timer = TIM_1_SEC;
                state = YELLOW_STATE;
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

INT8U GetState(INT8U button_event){
    static INT8U state = RED_STATE;
    //read state from button and figure out what to do
    switch (button_event)
    {
    case IDLE:
        //do nothing
        break;
    case SINGLE_PRESS: //switch to Norwegian state
        state = NORWEGIAN_STATE;
        counter_timer = TIM_1_SEC; 
        SetColor(YELLOW);
        break;
    case DOUBLE_PRESS: //switch to emergency state
        state = EMERGENCY_STATE;
        break;
    case LONG_PRESS: //reset the traffic light
        state = RED_STATE;
        counter_timer = TIM_2_SEC;
        break;
    default:
        break;
    }
    return state;
}
