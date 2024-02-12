#include "external_interrupt.h"

static std_return interrupt_INTx_enable        (const interrupt_INTx_t * interrupt_INTx_st); 
static std_return interrupt_INTx_disable       (const interrupt_INTx_t * interrupt_INTx_st); 
static std_return interrupt_INTx_pin_init      (const interrupt_INTx_t * interrupt_INTx_st); 
static std_return interrupt_INTx_priority_init (const interrupt_INTx_t * interrupt_INTx_st); 
static std_return interrupt_INTx_edge_init     (const interrupt_INTx_t * interrupt_INTx_st); 
static std_return interrupt_INTx_clear_flag    (const interrupt_INTx_t * interrupt_INTx_st); 

static std_return interrupt_RBx_enable        (const interrupt_RBx_t * interrupt_RBx_st); 
static std_return interrupt_RBx_disable       (const interrupt_RBx_t * interrupt_RBx_st); 
static std_return interrupt_RBx_pin_init      (const interrupt_RBx_t * interrupt_RBx_st); 
static std_return interrupt_RBx_priority_init (const interrupt_RBx_t * interrupt_RBx_st); 

std_return interrupt_INTx_init  (const interrupt_INTx_t * interrupt_INTx_st)
{
    if (NULL == interrupt_INTx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        /*disable the external interrupt at first*/
        interrupt_INTx_disable(interrupt_INTx_st);
        /*clear external interrupt flag*/
        interrupt_INTx_clear_flag(interrupt_INTx_st);
        /*configure external interrupt edge parameter*/
        interrupt_INTx_edge_init(interrupt_INTx_st);
        /*configure the external interrupt pin*/
        interrupt_INTx_pin_init(interrupt_INTx_st);
        /*configure the interrupt callback*/
        
        /*enable the external interrupt now*/
        interrupt_INTx_enable(interrupt_INTx_st);
        
        
    }
    
    return EXCUTION_OK;
}

std_return interrupt_INTx_deinit (const interrupt_INTx_t * interrupt_INTx_st)
{
    if (NULL == interrupt_INTx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        interrupt_INTx_disable(interrupt_INTx_st); 
    }
    
    return EXCUTION_OK;}
//------------------------------------------------------------------------------
std_return interrupt_RBx_init   (const interrupt_RBx_t * interrupt_RBx_st)
{
    if (NULL == interrupt_RBx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        
    }
    
    return EXCUTION_OK;
}

std_return interrupt_RBx_deinit  (const interrupt_RBx_t * interrupt_RBx_st)
{
    if (NULL == interrupt_RBx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        
    }
    
    return EXCUTION_OK;
}

//-----------------------------------------------------------------------------
#if (EXTERNAL_INTERRUPT_INTx_ENABLE == FEATURE_ENABLE)
static std_return interrupt_INTx_enable (const interrupt_INTx_t * interrupt_INTx_st)
{
    if (NULL == interrupt_INTx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        switch(interrupt_INTx_st->interrupt_source)
        {
            case interrupt_external_INT0: INTERRUPT_external_INT0_enable(); break;
            case interrupt_external_INT1: INTERRUPT_external_INT1_enable(); break;
            case interrupt_external_INT2: INTERRUPT_external_INT2_enable(); break;
            default: return EXCUTION_NOT_OK;
        }
    }
    
    return EXCUTION_OK;
}

static std_return interrupt_INTx_disable (const interrupt_INTx_t * interrupt_INTx_st)
{
    if (NULL == interrupt_INTx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        switch(interrupt_INTx_st->interrupt_source)
        {
            case interrupt_external_INT0: INTERRUPT_external_INT0_disable(); break;
            case interrupt_external_INT1: INTERRUPT_external_INT1_disable(); break;
            case interrupt_external_INT2: INTERRUPT_external_INT2_disable(); break;
            default: return EXCUTION_NOT_OK;
        }
    }
    
    return EXCUTION_OK;
}
#endif

static std_return interrupt_INTx_pin_init (const interrupt_INTx_t * interrupt_INTx_st)
{
    if (NULL == interrupt_INTx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        gpio_pin_direction_initialize( &(interrupt_INTx_st->interrupt_pin) );
    }
    
    return EXCUTION_OK;
}

#if (INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLE)
static std_return interrupt_INTx_priority_init (const interrupt_INTx_t * interrupt_INTx_st)
{
    if (NULL == interrupt_INTx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        switch(interrupt_INTx_st->interrupt_source)
        {
            case interrupt_external_INT1: 
                if(INTERRUPT_LOW_PRIORITY == interrupt_INTx_st->priority_level)
                {INTERRUPT_external_INT1_low_periority_set();}
                else if (INTERRUPT_HIGH_PRIORITY == interrupt_INTx_st->priority_level)
                {INTERRUPT_external_INT1_high_periority_set();}
                else
                {return EXCUTION_NOT_OK;};
                break;
            case interrupt_external_INT2:
                if(INTERRUPT_LOW_PRIORITY == interrupt_INTx_st->priority_level)
                {INTERRUPT_external_INT2_low_periority_set();}
                else if (INTERRUPT_HIGH_PRIORITY == interrupt_INTx_st->priority_level)
                {INTERRUPT_external_INT2_high_periority_set();}
                else
                {return EXCUTION_NOT_OK;};
                break;
            default: return EXCUTION_NOT_OK;
        }
    }
    
    return EXCUTION_OK;
}
#endif

static std_return interrupt_INTx_edge_init (const interrupt_INTx_t * interrupt_INTx_st)
{
    if (NULL == interrupt_INTx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        switch(interrupt_INTx_st->interrupt_source)
        {
            case interrupt_external_INT0: 
                if(RISING_EDGE == interrupt_INTx_st->edge)
                {INTERRUPT_external_INT0_set_on_rising_edge();}
                else if (FALLING_EDGE == interrupt_INTx_st->edge)
                {INTERRUPT_external_INT0_set_on_falling_edge();}
                else
                {return EXCUTION_NOT_OK;};
                break;
            case interrupt_external_INT1: 
                if(RISING_EDGE == interrupt_INTx_st->edge)
                {INTERRUPT_external_INT1_set_on_rising_edge();}
                else if (FALLING_EDGE == interrupt_INTx_st->edge)
                {INTERRUPT_external_INT1_set_on_falling_edge();}
                else
                {return EXCUTION_NOT_OK;};
                break;
            case interrupt_external_INT2:
                if(RISING_EDGE == interrupt_INTx_st->edge)
                {INTERRUPT_external_INT2_set_on_rising_edge();}
                else if (FALLING_EDGE == interrupt_INTx_st->edge)
                {INTERRUPT_external_INT2_set_on_falling_edge();}
                else
                {return EXCUTION_NOT_OK;};
                break;
            default: return EXCUTION_NOT_OK;
        }
    }
    
    return EXCUTION_OK;
}

static std_return interrupt_INTx_clear_flag (const interrupt_INTx_t * interrupt_INTx_st)
{
    if (NULL == interrupt_INTx_st)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        switch(interrupt_INTx_st->interrupt_source)
        {
            case interrupt_external_INT0: 
                INTERRUPT_external_INT0_flag_clear();
                break;
            case interrupt_external_INT1: 
                INTERRUPT_external_INT1_flag_clear();
                break;
            case interrupt_external_INT2:
                INTERRUPT_external_INT2_flag_clear();
                break;
            default: return EXCUTION_NOT_OK;
        }
    }
    
    return EXCUTION_OK;
}