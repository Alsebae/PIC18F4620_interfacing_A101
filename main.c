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
        magic_button();
    }
    return (EXCUTION_OK);
}
/* Code END */