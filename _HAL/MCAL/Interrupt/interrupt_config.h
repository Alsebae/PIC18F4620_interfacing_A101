/* 
 * File:   interrupt_config.h
 * Author: alseb
 *
 * Created on February 12, 2024, 1:15 PM
 */

#ifndef INTERRUPT_CONFIG_H
#define	INTERRUPT_CONFIG_H

#include <xc.h>
#include "../MCAL_std_types.h"
#include "../GPIO/HAL_GPIO.h"
#include "interrupt_configuration_generator.h"

#define INTERRUPT_ENABLE             1
#define INTERRUPT_DISABLE            1
#define INTERRUPT_OCCUR              1
#define INTERRUPT_NOT_OCCUR          1
#define INTERRUPT_PRIORITY_ENABLE   1
#define INTERRUPT_PRIORITY_DISABLE  1

typedef enum{
    INTERRUPT_LOW_PRIORITY  = 0,
    INTERRUPT_HIGH_PRIORITY = 1        
}interrupt_priorirty_level_t;

/* MACRO LIKE FUCNTIONS */

#if (INTERRUPT_PRIORITY_LEVELS == FEATURE_ENABLE)
  #define INTERRUPT_periprity_levels_enable()       (RCONbits.IPEN = 1)   //enable interrupt periority levels.
  #define INTERRUPT_periprity_levels_disable()      (RCONbits.IPEN = 0)   //disable interrupt periority levels.
  #define INTERRUPT_global_interrupt_high_enable()  (INTCONbits.GIEH = 1) //enable high periority global interrupts if interrupt periority is enabled.
  #define INTERRUPT_global_interrupt_high_disable() (INTCONbits.GIEH = 0) //disable high periority global interrupts if interrupt periority is enabled.
  #define INTERRUPT_global_interrupt_low_enable()   (INTCONbits.GIEL = 1) //enable low periority global interrupts if interrupt periority is enabled.
  #define INTERRUPT_global_interrupt_low_disable()  (INTCONbits.GIEL = 0) //disable low periority global interrupts if interrupt periority is enabled.
#else
  #define INTERRUPT_global_interrupt_enable()       (INTCONbits.GIE = 1)  //enable global interrupts if interrupt periority is disabled.
  #define INTERRUPT_global_interrupt_disable()      (INTCONbits.GIE = 0)  //disable global interrupts if interrupt periority is disabled.
  #define INTERRUPT_peripheral_interrupt_enable()   (INTCONbits.PEIE = 1) //enable peripheral interrupts if interrupt periority is disabled.
  #define INTERRUPT_peripheral_interrupt_disable()  (INTCONbits.PEIE = 0) //disable peripheral interrupts if interrupt periority is disabled.
#endif


#endif	/* INTERRUPT_CONFIG_H */

