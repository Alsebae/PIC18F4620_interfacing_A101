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
#define _XTAL_FREQ (8000000UL) // a define for __delay_ms() built in func.
DIGITAL_t flag = LOW;  
/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
//LOGIC_t logic_check = 0;

/* Global Variables END */

/* Helper Function Definitions START */
/* Helper Function Definitions END */

/* Code START */
int main()
{

    app_init();

for(;;)
{ 
    push_button_read(&push_btn_1, &button_1_state);
    if ((BUTTON_PRESSED == button_1_state) && (LOW == flag))
    {
        led_on_off(&led_1, LED_ON);
        flag = HIGH;
    }
    else if ((BUTTON_PRESSED == button_1_state) && (HIGH == flag))
    {
        led_on_off(&led_1, LED_OFF);
        flag = LOW;
    }
 
    push_button_read(&push_btn_2, &button_2_state);
    if (BUTTON_PRESSED == button_2_state)
    {
        led_on_off(&led_2, LED_ON);
    }
    else
    {
       led_on_off(&led_2, LED_OFF);
    }
}

return (EXCUTION_OK);
}
/* Code END */