/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: standardTypes.h
*
* PROJECT....: Traffic Light
*
* DESCRIPTION: Standard type definitions and timer constants
*****************************************************************************/

#ifndef STANDARD_TYPES_H
    #define STANDARD_TYPES_H

/***************************** Include files *******************************/

/*****************************    Defines    *******************************/

// Timer constants
#define TIM_100_MSEC   20
#define TIM_200_MSEC   40
#define TIM_500_MSEC  100
#define TIM_1_SEC     200
#define TIM_2_SEC     400

/*****************************   Constants   *******************************/

typedef unsigned char BOOLEAN;
typedef unsigned char INT8U; /* Unsigned 8 bit quantity */
typedef signed char INT8S; /* Signed 8 bit quantity */
typedef unsigned short INT16U; /* Unsigned 16 bit quantity */
typedef signed short INT16S; /* Signed 16 bit quantity */
typedef unsigned long INT32U; /* Unsigned 32 bit quantity */
typedef signed long INT32S; /* Signed 32 bit quantity */
typedef unsigned long long INT64U; /* Unsigned 64 bit quantity */
typedef signed long long INT64S; /* Signed 64 bit quantity */
typedef float FP32; /* Single precision floating point */
typedef double FP64; /* Double precision floating point */

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

/****************************** End Of Module *******************************/

#endif /* STANDARD_TYPES_H */
