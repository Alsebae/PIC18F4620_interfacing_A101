#include "DCmotor.h"
//-----------------------------------------------------------------------------
std_return DCmotor_init(DCmotor_t * p_DCmotor)
{
    if (NULL == p_DCmotor)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        gpio_pin_direction_initialize(&p_DCmotor->forward_pin);
        gpio_pin_write_logic(&p_DCmotor->forward_pin,p_DCmotor->forward_pin.logic);

        gpio_pin_direction_initialize(&p_DCmotor->backward_pin);
        gpio_pin_write_logic(&p_DCmotor->backward_pin,p_DCmotor->backward_pin.logic);
    }
    return EXCUTION_OK;
}        
//-----------------------------------------------------------------------------
std_return DCmotor_rotate_CW_CCW(DCmotor_t * p_DCmotor,DCmotor_dir_t d_DCmotor_dir)
{
    if (NULL == p_DCmotor)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        if (CLOCKWISE == d_DCmotor_dir)
        {
        gpio_pin_write_logic(&p_DCmotor->forward_pin , LOGIC_ON);
        gpio_pin_write_logic(&p_DCmotor->backward_pin, LOGIC_OFF);
        }
        else if (COUNTER_CLOCKWISE == d_DCmotor_dir)
        {
        gpio_pin_write_logic(&p_DCmotor->forward_pin , LOGIC_OFF);
        gpio_pin_write_logic(&p_DCmotor->backward_pin, LOGIC_ON);            
        }
        else
        {
            /*NOTHING*/
        }
        
    }
    
    return EXCUTION_OK;
}        
//-----------------------------------------------------------------------------
std_return DCmotor_brake(DCmotor_t * p_DCmotor)
{
    if (NULL == p_DCmotor)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
     gpio_pin_write_logic(&p_DCmotor->forward_pin , LOGIC_OFF);
     gpio_pin_write_logic(&p_DCmotor->backward_pin, LOGIC_OFF);
    }
    
    return EXCUTION_OK;
}                
//-----------------------------------------------------------------------------