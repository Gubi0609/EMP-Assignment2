/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: light.h
*
* PROJECT....: Traffic Light
*
* DESCRIPTION: Light states and functions
*****************************************************************************/
#ifndef LIGHT_H
#define LIGHT_H

/***************************** Include files *******************************/

/*****************************    Defines    *******************************/

// Colors
#define RED 0x02
#define RED_YELLOW 0x06
#define YELLOW 0x0A
#define GREEN 0x08
#define OFF 0x00


// Light states'
#define RED_STATE 0
#define RED_YELLOW_STATE 1
#define YELLOW_STATE 2
#define GREEN_STATE 3
#define NORWEGIAN_STATE 4
#define EMERGENCY_STATE 5

/*****************************   Constants   *******************************/
extern INT16U counter_timer;

/*****************************   Functions   *******************************/
void HandleState(INT8U state);
INT8U GetState(INT8U button_event);

/****************************** End Of Module *******************************/

#endif
