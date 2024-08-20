/* 
* File:   main.c
* Author: Abdulrahman
*
* Created on November 26, 2023, 4:09 PM
*/

/* lib includes START */
/* lib includes END */

/* includes START */
#include "main.h"
/* includes END */
led_t led1 = {.led_status = LED_OFF, .port_idx = IDX_PORT_C, .pin_idx = IDX_PIN_0};

uint32_t program_step_counter = 0;

void int0_APP_ISR(void)
{
    led_toggle(&led1);
}

interrupt_INTx_t int0_object = {
    
    .external_interrupt_handler = int0_APP_ISR,
    .edge                       = RISING_EDGE,
    .priority_level             = INTERRUPT_HIGH_PRIORITY,
    .interrupt_source           = interrupt_external_INT0,
    .interrupt_pin.direction    = DIRECTION_INPUT,
    .interrupt_pin.logic        = LOGIC_OFF,
    .interrupt_pin.pin_num      = IDX_PIN_0,
    .interrupt_pin.port         = IDX_PORT_B,
    .interrupt_pin.status       = LOGIC_OFF             
};


/* Defines START */
/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
 
/* Global Variables END */

/* Helper Function Definitions START */
/* Helper Function Definitions END */

/* Code START */
int main()
{
    app_init();
    led_init(&led1);
    interrupt_INTx_init(&int0_object);
    for(;;)
    {
    
        
     }
    return (EXCUTION_OK);
}
/* Code END */