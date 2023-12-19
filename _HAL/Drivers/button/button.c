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
       gpio_pin_direction_initialize(&p_push_button->button_pin);
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
      *p_button_state = BUTTON_RELEASED;
      
      LOGIC_t btn_pin_logic;
      gpio_pin_read_logic(&p_push_button->button_pin,&btn_pin_logic);
  
      if((HIGH == btn_pin_logic) && (BUTTON_ACTIVE_HIGH == p_push_button->button_active_state))
      {
          *p_button_state = BUTTON_PRESSED;
      }
      else if((LOW == btn_pin_logic) && (BUTTON_ACTIVE_LOW == p_push_button->button_active_state))
      {
          *p_button_state = BUTTON_PRESSED;
      }
      else
      {
          /*NOTHING*/
      }
    }

    return EXCUTION_OK;  
}
/* Code END */
