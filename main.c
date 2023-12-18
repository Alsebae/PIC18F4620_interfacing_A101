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
/* Global Variables END */

/* Helper Function Definitions START */
/* Helper Function Definitions END */

/* Code START */
int main()
{
    app_init();
    for(;;)
    {
        calculate_step_counter();
        magic_switch_led_programs();
    }
    return (EXCUTION_OK);
}
/* Code END */