/* 
 * File:   application.c
 * Author: Abdulrahman
 *
 * Created on November 26, 2023, 5:22 PM
 */

/* lib includes START */
/* lib includes END */

/* includes START */
#include "application.h"
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

void app_init(void){
push_button_init(&push_btn_1);
push_button_init(&push_btn_2);
led_init(&led_1);
led_init(&led_2);
}



void magic_button(void)
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
    
    if ((LOW == btn_1_high_valid_state_previous) && (HIGH == btn_1_high_valid_state))
    {
        rise_edge = TRUE;
    }
    else
    {
        rise_edge = FALSE;
    }
    
    if (TRUE == rise_edge)
    {
        led_toggle(&led_1);
    }
    
    btn_1_high_valid_state_previous = btn_1_high_valid_state;
 
}
/* Code END */