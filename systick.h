/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: systick.h
*
* PROJECT....: EMP
*
* DESCRIPTION: Initialize the systick interrupt.
*
* Change Log:
******************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 150215  MoH    Module created.
*
*****************************************************************************/

#ifndef _EMP_H
  #define _EMP_H

/***************************** Include files *******************************/

/*****************************    Defines    *******************************/
#define SYSTICK_RELOAD_VALUE 80000              // 5 mS

// Missing definitions in tm4c123gh6pm.h file
#define NVIC_INT_CTRL_PEND_SYST   0x04000000    // Pend a systick int
#define NVIC_INT_CTRL_UNPEND_SYST 0x02000000    // Unpend a systick int

#define SYSTICK_PRIORITY    0x7E

/*****************************   Constants   *******************************/
extern volatile INT16S ticks;
/*****************************   Functions   *******************************/
void enable_global_int();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Enable global interrupt.
******************************************************************************/


void disable_global_int();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Disable global interrupt.
******************************************************************************/


void init_systick();
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Initialize the systick interrupt.
******************************************************************************/


/****************************** End Of Module *******************************/
#endif


