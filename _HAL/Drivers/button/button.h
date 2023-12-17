/* 
 * File:   button.h
 * Author: alseb
 *
 * Created on December 17, 2023, 9:38 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

/* lib includes START */
/* lib includes END */

/* includes START */
#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "button_cfg.h"
/* includes END */

/* Defines START */
typedef enum
{
    BUTTON_PRESSED  = 0,
    BUTTON_RELEASED = 1
            
}button_state_t;

typedef enum
{
    BUTTON_ACTIVE_HIGH = 0,
    BUTTON_ACTIVE_LOW  = 1
            
}button_active_state_t;

typedef struct
{
    pin_config_t           button_pin;
    button_state_t         button_state;
    button_active_state_t  button_active_state;
}push_button_t;

/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
/* Global Variables END */

/* Function Prototypes START */
/* Function Prototypes END */

/* Public Function Definitions START */
std_return push_button_init(push_button_t * p_push_button);
std_return push_button_read(push_button_t * p_push_button, button_state_t * p_button_state);
/* Public Function Definitions END */


#endif	/* BUTTON_H */

