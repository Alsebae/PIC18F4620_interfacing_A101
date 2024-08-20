#include "external_interrupt.h"

static void (*INT0_InterruptHandler) (void) = NULL;
static void (*INT1_InterruptHandler) (void) = NULL;
static void (*INT2_InterruptHandler) (void) = NULL;

static std_return INT0_SetInterruptHandler( void(*InterruptHandler)(void) );
static std_return INT1_SetInterruptHandler( void(*InterruptHandler)(void) );
static std_return INT2_SetInterruptHandler( void(*InterruptHandler)(void) );
static std_return Interrupt_INTX_SetInterruptHandler(const interrupt_INTx_t * interrupt_object); //This is the function that will call one of the three function based on the i nterrupt source in the int obj.



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
        //-------------------------------------------------------
        /*clear external interrupt flag*/
        interrupt_INTx_clear_flag(interrupt_INTx_st);
        /*configure external interrupt edge parameter*/
        interrupt_INTx_edge_init(interrupt_INTx_st);
        #if (INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLE)
        /*Configure the external interrupt priority*/
        interrupt_INTx_priority_init(interrupt_INTx_st);
        #endif
        /*configure the external interrupt pin*/
        interrupt_INTx_pin_init(interrupt_INTx_st);
        /*configure the interrupt callback*/
        Interrupt_INTX_SetInterruptHandler(interrupt_INTx_st);
        //-------------------------------------------------------
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


//----------------------------------------------------------------------------------------------------
static std_return INT0_SetInterruptHandler( void(*InterruptHandler)(void) )
{
    if (NULL == InterruptHandler)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
       INT0_InterruptHandler = InterruptHandler;
    }
    
    return EXCUTION_OK;
}
//----------------------------------------------------------------------------------------------------
static std_return INT1_SetInterruptHandler( void(*InterruptHandler)(void) )
{
    if (NULL == InterruptHandler)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        INT1_InterruptHandler = InterruptHandler;
    }
    
    return EXCUTION_OK;
}
//----------------------------------------------------------------------------------------------------
static std_return INT2_SetInterruptHandler( void(*InterruptHandler)(void) )
{
    if (NULL == InterruptHandler)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        INT2_InterruptHandler = InterruptHandler;
    }
    
    return EXCUTION_OK;
}
//----------------------------------------------------------------------------------------------------
static std_return Interrupt_INTX_SetInterruptHandler(const interrupt_INTx_t * interrupt_object)
{
    if (NULL == interrupt_object)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        switch (interrupt_object->interrupt_source)
        { 
                case(interrupt_external_INT0):  INT0_SetInterruptHandler(interrupt_object->external_interrupt_handler); break;
                case(interrupt_external_INT1):  INT1_SetInterruptHandler(interrupt_object->external_interrupt_handler); break;
                case(interrupt_external_INT2):  INT2_SetInterruptHandler(interrupt_object->external_interrupt_handler); break;
                default                      :  return EXCUTION_NOT_OK;
    
        }
    }
    return EXCUTION_OK;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void INT0_ISR(void)
{
    /*First, clear the external interrupt flag as stated in data sheet*/
    INTERRUPT_external_INT0_flag_clear();

    /*Input user code for interrupt in MCAL*/
    
    /*CALL THE INT_ISR*/
    if(INT0_InterruptHandler)
    {
        INT0_InterruptHandler();
    }
}
//----------------------------------------------------------------------------------------------------
void INT1_ISR(void)
{
    /*First, clear the external interrupt flag as stated in data sheet*/
    INTERRUPT_external_INT1_flag_clear();

    /*Input user code for interrupt in MCAL*/
    
    /*CALL THE INT_ISR*/
    if(INT1_InterruptHandler)
    {
        INT1_InterruptHandler();
    }
}
//----------------------------------------------------------------------------------------------------
void INT2_ISR(void)
{
    /*First, clear the external interrupt flag as stated in data sheet*/
    INTERRUPT_external_INT2_flag_clear();

    /*Input user code for interrupt in MCAL*/
    
    /*CALL THE INT_ISR*/
    if(INT2_InterruptHandler)
    {
        INT2_InterruptHandler();
    }
}