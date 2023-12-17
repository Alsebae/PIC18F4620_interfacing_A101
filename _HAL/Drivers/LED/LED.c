/* 
 * File:   LED.c
 * Author: Abdulrahman
 *
 * Created on November 26, 2023, 5:33 PM
 */

/* lib includes START */
/* lib includes END */

/* includes START */
#include "LED.h"
/* includes END */

/* Defines START */
/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
/* Global Variables END */

/* Helper Function Definitions START */
/* Helper Function Definitions END */

/* Code START */

std_return led_init(led_t * p_led)
{
    if(NULL == p_led)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        std_return func_return;
        pin_config_t led_pin = {.direction= DIRECTION_OUTPUT,
                                .port     = p_led->port_idx,
                                .pin_num  = p_led->pin_idx,
                                .logic    = p_led->led_status};
        
        func_return = gpio_pin_initialize(&led_pin);
    }
    
    return EXCUTION_OK;
}


/* Code END */
