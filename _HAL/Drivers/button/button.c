/* 
 * File:   LED.c
 * Author: Abdulrahman
 *
 * Created on November 26, 2023, 5:33 PM
 */

/* lib includes START */
/* lib includes END */

/* includes START */
#include "button.h"
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
std_return push_button_init(push_button_t * p_push_button)
{
  if(NULL == p_push_button)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
       
    }
    
    return EXCUTION_OK;  
}


std_return push_button_read(push_button_t * p_push_button, button_state_t * p_button_state)
{
  if(NULL == p_push_button || NULL == p_button_state)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
       
    }
    
    return EXCUTION_OK;  
}
/* Code END */
