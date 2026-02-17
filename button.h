/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: button.h
*
* PROJECT....: Traffic Light
*
* DESCRIPTION: Button states and functions
*****************************************************************************/
#ifndef BUTTON_H
#define BUTTON_H

/***************************** Include files *******************************/

/*****************************    Defines    *******************************/
// Button states
#define IDLE 0
#define FIRST_PRESS 1
#define SECOND_PRESS 2
#define LONG_PRESS 3
#define FIRST_RELEASE 4
#define SINGLE_PRESS 5
#define DOUBLE_PRESS 6

#define BS_IDLE           0
#define BS_FIRST_PUSH     1
#define BS_FIRST_RELEASE  2
#define BS_SECOND_PUSH    3
#define BS_LONG_PUSH      4

#define TIM_100_MSEC   20
#define TIM_200_MSEC   40
#define TIM_500_MSEC  100
#define TIM_1_SEC     200
#define TIM_2_SEC     400

/*****************************   Constants   *******************************/

/*****************************   Functions   *******************************/

/****************************** End Of Module *******************************/

#endif /*BUTTON_H*/