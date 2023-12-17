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


led_t led_1 = {.port_idx   =  IDX_PORT_C,
               .pin_idx    =  IDX_PIN_5,
               .led_status =  LED_ON};


/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
//LOGIC_t logic_check = 0;

/* Global Variables END */

/* Helper Function Definitions START */
/* Helper Function Definitions END */

/* Code START */
int main() {
led_init(&led_1);

for(;;)
    {
       
    }

return (EXCUTION_OK);
}
/* Code END */