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
/* Code END */