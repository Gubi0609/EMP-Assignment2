/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: portF.h
*
* PROJECT....: Traffic Light
*
* DESCRIPTION: Defines for enabling port F as needed.
******************************************************************************/
#ifndef PORTF_H
#define PORTF_H

/***************************** Include files *******************************/

/*****************************    Defines    *******************************/
#define ENABLE_DIR 0x0E // 0000 1110
#define ENABLE_PUR 0x10 // 0001 0000
#define ENABLE_DEN 0x1E // 0001 1110

#define ENABLE_EDGE_SENSITIVE 0x00
#define ENABLE_IBE_TRIGGER    0x00
#define ENABLE_IEV_TRIGGER    0x00
#define CLEAR_PF4_INTERUPTS   0x10
#define UNMASK_PF4_INTERRUPTS 0x10

/*****************************   Constants   *******************************/

/*****************************   Functions   *******************************/

void init_portF(void);
/*****************************************************************************
*   Input    :
*   Output   :
*   Function : Initialize needed port F pins (PF1 - PF4)
******************************************************************************/

void init_portFInterrupt(void);
/*****************************************************************************
*   Input    :
*   Output   :
*   Function : Initialize port F as interrupt - UNUSED
******************************************************************************/

/****************************** End Of Module *******************************/

#endif /*PORTF_H*/