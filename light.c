#include "tm4c123gh6pm.h"
#include "standardTypes.h"
#include "button.h"
#include "light.h"
#include "portF.h"

void SetColor(INT16U Color){
    ClearColor();
    GPIO_PORTF_DATA_R |= Color;
}

void ClearColor(){
    GPIO_PORTF_DATA_R &= 0xF1; // 1111 0001
}

void SetLightState(INT8U state){
    switch(state){
        case RED_STATE:
            //transtion after some time
            SetColor(RED);
            break;
        case RED_YELLOW_STATE:
            //-||-
            SetColor(RED_YELLOW);
            break;
        case YELLOW_STATE:
        //-||-
            SetColor(YELLOW);
            break;
        case GREEN_STATE:
        //-||-
            SetColor(GREEN);
            break;
        case NORWEGIAN_STATE:
            //start blinking 
            SetColor(YELLOW);
            break;
        case EMERGENCY_STATE:
            //set solid color
            SetColor(RED);
            break;
    }
}