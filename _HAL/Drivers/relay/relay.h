/* 
 * File:   relay.h
 * Author: alseb
 *
 * Created on December 19, 2023, 3:07 PM
 */

#ifndef RELAY_H
#define	RELAY_H

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "relay_cfg.h"

        
typedef struct
{
pin_config_t relay_pin   ;
LOGIC_t      relay_state ;
}relay_t;

std_return relay_init   (relay_t * p_relay)                  ;
std_return relay_on_off (relay_t * p_relay, LOGIC_t d_logic) ;
std_return relay_toggle (relay_t * p_relay)                  ;

#endif	/* RELAY_H */

