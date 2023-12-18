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
uint32_t  btn_counter = 0;
DIGITAL_t btn_1_high_valid_state = LOW;
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
    if(BUTTON_PRESSED == button_1_state)
    {
        btn_counter++;
        
        if(btn_counter>=500)
        {
            btn_counter = 500;
            btn_1_high_valid_state = HIGH;
        }
        
    }
    else
    {
        btn_counter = 0;
        btn_1_high_valid_state = LOW;
    }
    
    if(HIGH == btn_1_high_valid_state)
    {
        led_on_off(&led_1, LED_ON);
    }
    else
    {
        led_on_off(&led_1, LED_OFF);
    }
    
}

return (EXCUTION_OK);
}
/* Code END */