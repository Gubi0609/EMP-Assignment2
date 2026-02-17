/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: portF.c
*
* PROJECT....: Traffic Light
*
* DESCRIPTION: See module specification file (.h-file).
*****************************************************************************/

/***************************** Include files *******************************/
#include "portF.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
/*****************************    Defines    *******************************/

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

void init_portF(void)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Initialize needed port F pins (PF1 - PF4)
******************************************************************************/
{
    int dummy; // Dummy to do a few cycles

    // Enable GPIO port F (used for RBG and switch) by turning on power to the port
    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF; // System Control Run-Mode Clock Gating Control

    // Do a dummy read to insert a few cycles after enabling the peripheral
    dummy = SYSCTL_RCGC2_R;

    // Enable RGB (PF1 - PF3) as output and switch (PF4) as input
    GPIO_PORTF_DIR_R = ENABLE_DIR; // Bit 1 is output, bit 0 is input

    // Enable pull-up resister for switch (PF4)
    GPIO_PORTF_PUR_R = ENABLE_PUR;

    // Enable digital function for PF1 - PF4
    GPIO_PORTF_DEN_R = ENABLE_DEN;
}

void init_portFInterrupt(void)
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Initialize port F as interrupt - UNUSED
******************************************************************************/
{

    // Set switch (PF4) as edge-sensitive
    GPIO_PORTF_IS_R = ENABLE_EDGE_SENSITIVE;

    // Trigger controlled by IEV
    GPIO_PORTF_IBE_R = ENABLE_IBE_TRIGGER;

    // Falling Edge Trigger
    GPIO_PORTF_IEV_R = ENABLE_IEV_TRIGGER;

    // Clear any Prior Interrupts
    GPIO_PORTF_ICR_R = CLEAR_PF4_INTERUPTS;

    // Unmask interrupts for PF4
    GPIO_PORTF_IM_R = UNMASK_PF4_INTERRUPTS;

    // Enable interrupts from port F in NVIC
    NVIC_EN0_R |= (1 << (INT_GPIOF - INT_GPIOA));
}

/****************************** End Of Module *******************************/
