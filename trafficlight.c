#include "tm4c123gh6pm.h"
#include "standardTypes.h"
#include "button.h"
#include "portF.h"

void ShowColor(BOOLEAN red, BOOLEAN green, BOOLEAN blue){
    ClearColor();
    if(red){
        GPIO_PORTF_DATA_R |= ; // Red on (PF1)
    }

    if(green){
        GPIO_PORTF_DATA_R |= 0x08; // Green on (PF3)
    }

    if(blue){
        GPIO_PORTF_DATA_R |= 0x04; // Blue on (PF2)
    }
}
void ClearColor(){
    GPIO_PORTF_DATA_R &= ~(0x02);
    GPIO_PORTF_DATA_R &= ~(0x04);
    GPIO_PORTF_DATA_R &= ~(0x08);
}