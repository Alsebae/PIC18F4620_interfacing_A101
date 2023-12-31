
//-----------------------------------------------------------------------------
#include "relay.h"
#if 0
//-----------------------------------------------------------------------------
std_return relay_init(relay_t * p_relay)
{
    if(NULL == p_relay)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        gpio_pin_direction_initialize(&p_relay->relay_pin);
        gpio_pin_write_logic(&p_relay->relay_pin,p_relay->relay_pin.logic);
//        gpio_pin_initialize(&relay_pin);

    }
    return EXCUTION_OK;
}
//-----------------------------------------------------------------------------
std_return relay_on_off(relay_t * p_relay, LOGIC_t d_logic)
{
    if(NULL == p_relay)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        if (LOGIC_ON == d_logic)
        {
            gpio_pin_write_logic(&p_relay->relay_pin, LOGIC_ON);
        }
        else if (LOGIC_OFF == d_logic)
        {
            gpio_pin_write_logic(&p_relay->relay_pin, LOGIC_OFF);      
        }
        else
        {
            /*NOTHING*/
        }
    }
    return EXCUTION_OK;
}
//-----------------------------------------------------------------------------
std_return relay_toggle(relay_t * p_relay)
{
    if(NULL == p_relay)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        gpio_pin_toggle_logic(&p_relay->relay_pin);
    }
    return EXCUTION_OK;
}
//-----------------------------------------------------------------------------
#endif