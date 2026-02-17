#include "portF.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

void init_portF(void) {
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