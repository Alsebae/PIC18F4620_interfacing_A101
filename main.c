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
pin_config_t pinpin = {
    .port      = IDX_PORT_A,
    .pin_num   = IDX_PIN_1,
    .direction = DIRECTION_OUTPUT,
    .logic     = LOGIC_ON,
    .status    = LOGIC_ON};

/* Code START */
int main()
{
    app_init();
    for(;;)
    {
        uint8_t idx = 0, msecond=0;
        for(idx=0; idx<100; idx++)
        {
            for(msecond=0; msecond<50; msecond++)
            {
            SSD_write_number(&SSD_1, idx);
            __delay_ms(20);
            }
        }
    }
    return (EXCUTION_OK);
}
/* Code END */