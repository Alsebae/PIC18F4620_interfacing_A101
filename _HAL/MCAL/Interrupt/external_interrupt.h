/* 
 * File:   external_interrupt.h
 * Author: alseb
 *
 * Created on February 12, 2024, 1:16 PM
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H

#include "interrupt_config.h"

#if (EXTERNAL_INTERRUPT_INTx_ENABLE == FEATURE_ENABLE)

 #define INTERRUPT_external_INT0_enable()              (INTCONbits.INT0IE   = 1) //enable external interrupt0 when external interrupt feature is enabled.
 #define INTERRUPT_external_INT0_disable()             (INTCONbits.INT0IE   = 0) //enable external interrupt0 when external interrupt feature is enabled.
 #define INTERRUPT_external_INT0_set_on_rising_edge()  (INTCON2bits.INTEDG0 = 1) //detect external interrupt0 when rising edge happens.
 #define INTERRUPT_external_INT0_set_on_falling_edge() (INTCON2bits.INTEDG0 = 0) //detect external interrupt0 when falling edge happens.
 #define INTERRUPT_external_INT0_flag_clear()          (INTCONbits.INT0IF   = 0) //clear external interrupt0 flag.

 #define INTERRUPT_external_INT1_enable()              (INTCON3bits.INT1IE   = 1) //enable external interrupt1 when external interrupt feature is enabled.
 #define INTERRUPT_external_INT1_disable()             (INTCON3bits.INT1IE   = 0) //enable external interrupt1 when external interrupt feature is enabled.
 #define INTERRUPT_external_INT1_set_on_rising_edge()  (INTCON2bits.INTEDG1 = 1) //detect external interrupt1 when rising edge happens.
 #define INTERRUPT_external_INT1_set_on_falling_edge() (INTCON2bits.INTEDG1 = 0) //detect external interrupt1 when falling edge happens.
 #define INTERRUPT_external_INT1_flag_clear()          (INTCON3bits.INT1IF   = 0) //clear external interrupt1 flag.

 #define INTERRUPT_external_INT2_enable()              (INTCON3bits.INT2IE   = 1) //enable externa2 interrupt1 when external interrupt feature is enabled.
 #define INTERRUPT_external_INT2_disable()             (INTCON3bits.INT2IE   = 0) //enable externa2 interrupt1 when external interrupt feature is enabled.
 #define INTERRUPT_external_INT2_set_on_rising_edge()  (INTCON2bits.INTEDG2 = 1) //detect externa2 interrupt1 when rising edge happens.
 #define INTERRUPT_external_INT2_set_on_falling_edge() (INTCON2bits.INTEDG2 = 0) //detect externa2 interrupt1 when falling edge happens.
 #define INTERRUPT_external_INT2_flag_clear()          (INTCON3bits.INT2IF   = 0) //clear externa2 interrupt1 flag.

 #if (INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLE)
   #define INTERRUPT_external_INT1_high_periority_set() (INTCON3bits.INT1IP   = 1) //enable externa2 interrupt1 when external interrupt feature is enabled.
   #define INTERRUPT_external_INT1_low_periority_set()  (INTCON3bits.INT2IP   = 0) //enable externa2 interrupt1 when external interrupt feature is enabled.
   #define INTERRUPT_external_INT2_high_periority_set() (INTCON3bits.INT2IP   = 1) //enable externa2 interrupt1 when external interrupt feature is enabled.
   #define INTERRUPT_external_INT2_low_periority_set()  (INTCON3bits.INT2IP   = 0) //enable externa2 interrupt1 when external interrupt feature is enabled.
 #endif

#endif

//----------------------------------------------------------------------------

#if (EXTERNAL_INTERRUPT_OnChange_ENABLE == FEATURE_ENABLE)

 #define INTERRUPT_portB_external_interrupt_enable()     (INTCONbits.RBIE   = 1) //enable Port_B external interrupt when external interrupt feature is enabled.
 #define INTERRUPT_portB_external_interrupt_disable()    (INTCONbits.RBIE   = 0) //enable Port_B external interrupt when external interrupt feature is enabled.
 #define INTERRUPT_portB_external_interrupt_flag_clear() (INTCONbits.RBIF   = 0) //clear Port_B external interrupt flag.

 #if (INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLE)
  #define INTERRUPT_portB_external_interrupt_high_periority_set() (INTCON2bits.RBIP   = 1) //enable externa2 interrupt1 when external interrupt feature is enabled.
  #define INTERRUPT_portB_external_interrupt_low_periority_set()  (INTCON2bits.RBIP   = 0) //enable externa2 interrupt1 when external interrupt feature is enabled.
 #endif

#endif

//----------------------------------------------------------------------------

typedef enum{
 interrupt_external_INT0 = 0,   
 interrupt_external_INT1 = 1,   
 interrupt_external_INT2 = 2  
}interrupt_INTx_source_t;

typedef enum{
    FALLING_EDGE = 0,
    RISING_EDGE = 1
}interrupt_INTx_edge_t;

typedef struct{
    void (* external_interrupt_handler) (void)    ; //a pointer to the handler function that will be invoked when the interrupt happens.
    pin_config_t                 interrupt_pin    ; //The pin that gives us the external interrupt.
    interrupt_INTx_source_t      interrupt_source ; //The interrupt source: external INT0/INT1/INT2.
    interrupt_INTx_edge_t        edge             ; //Does this interrupt happen when a rising/falling edge is detected on the pin?
    interrupt_priorirty_level_t  priority_level   ; //Does this interrupt has low/high priority if the priority levels are enabled?
}interrupt_INTx_t;

typedef struct{
    void (* external_interrupt_handler) (void)    ; //a pointer to the handler function that will be invoked when the interrupt happens.
    pin_config_t                 interrupt_pin    ; //The pin that gives us the external interrupt on PortB.
    interrupt_priorirty_level_t priority_level  ; //Does this interrupt has low/high priority if the priority levels are enabled?
}interrupt_RBx_t;


std_return interrupt_INTx_init   (const interrupt_INTx_t * interrupt_INTx_st);
std_return interrupt_INTx_deinit (const interrupt_INTx_t * interrupt_INTx_st);

std_return interrupt_RBx_init    (const interrupt_RBx_t * interrupt_RBx_st);
std_return interrupt_RBx_deinit  (const interrupt_RBx_t * interrupt_RBx_st);

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

#endif	/* EXTERNAL_INTERRUPT_H */

