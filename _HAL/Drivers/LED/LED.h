/* 
 * File:   LED.h
 * Author: Abdulrahman
 *
 * Created on November 26, 2023, 5:33 PM
 */

#ifndef LED_H
#define	LED_H

/* lib includes START */
/* lib includes END */

/* includes START */
#include "../../MCAL/GPIO/HAL_GPIO.h"
/* includes END */

/* Defines START */
typedef enum
{
    LED_OFF = 0,
    LED_ON  = 1
}led_status_t;

typedef struct
{
  IDX_PORT_X_t port_idx;
  IDX_PIN_X_t  pin_idx;
  led_status_t led_status;
}led_t;

/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
/* Global Variables END */

/* Function Prototypes START */
/* Function Prototypes END */

/* Public Function Definitions START */

std_return led_init(led_t * p_led);
std_return led_on_off(led_t * p_led, led_status_t led_status);
std_return led_toggle(led_t * p_led);

/* Public Function Definitions END */

#endif	/* LED_H */

