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

/* Defines START */
/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
uint8_t keypad_pressed_value = 0;
pin_config_t led_keypad = {.port      = IDX_PORT_D,
                           .pin_num   = IDX_PIN_0,
                           .direction = DIRECTION_OUTPUT,
                           .logic     = LOGIC_OFF,
                           .status    = LOGIC_OFF};
/* Global Variables END */

/* Helper Function Definitions START */
/* Helper Function Definitions END */

/* Code START */
int main()
{
    app_init();
    gpio_pin_direction_initialize( &led_keypad );
    gpio_pin_write_logic( &led_keypad, LOGIC_OFF);
    
    for(;;)
    {
        keypad_read(&keypad_1, &(keypad_pressed_value));
        if( '1' == keypad_pressed_value)
        {
            gpio_pin_write_logic( &led_keypad, LOGIC_ON);
        }
        else if( '4' == keypad_pressed_value)
        {
            gpio_pin_write_logic( &led_keypad, LOGIC_OFF);
        }
    }
    return (EXCUTION_OK);
}
/* Code END */