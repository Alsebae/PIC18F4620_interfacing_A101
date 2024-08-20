#include "interrupt_manager.h"

#if (INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLE)
/*If priority levels are enabled, then we will have two vectors*/
void __interrupt() InterruptManagerHigh(void)
{
    
}

void __interrupt(low_priority) InterruptManagerLow(void)
{
    
}

#else
/* If periority levels are not enables, then you will have one vectors.*/
void __interrupt() InterruptManager(void)
{
    if (  (INTERRUPT_ENABLE == INTCONbits.INT0IE)
        &&(INTERRUPT_OCCUR  == INTCONbits.INT0IF) )
    {
        INT0_ISR();
    }
}
#endif

