/* 
 * File:   DCmotor.h
 * Author: alseb
 *
 * Created on December 20, 2023, 6:00 PM
 */

#ifndef DCMOTOR_H
#define	DCMOTOR_H

#include "../../MCAL/GPIO/HAL_GPIO.h"

typedef enum
{
    CLOCKWISE         = 0,
    COUNTER_CLOCKWISE = 1
}DCmotor_dir_t;

typedef struct
{
    pin_config_t forward_pin;
    pin_config_t backward_pin;
}DCmotor_t;

//
//DCmotor_t DCmotor_1 ={
//                        .forward_pin .direction = DIRECTION_OUTPUT,
//                        .forward_pin .logic     = LOGIC_OFF,
//                        .forward_pin .pin_num   = IDX_PIN_0,
//                        .forward_pin .port      = IDX_PORT_C,
//                        .forward_pin .status    = LOGIC_OFF,
//                        .backward_pin.direction = DIRECTION_OUTPUT,
//                        .backward_pin.logic     = LOGIC_OFF,
//                        .backward_pin.pin_num   = IDX_PIN_1,
//                        .backward_pin.port      = IDX_PORT_C,
//                        .backward_pin.status    = LOGIC_OFF};
//
//DCmotor_t DCmotor_2 ={
//                        .forward_pin .direction = DIRECTION_OUTPUT,
//                        .forward_pin .logic     = LOGIC_OFF,
//                        .forward_pin .pin_num   = IDX_PIN_2,
//                        .forward_pin .port      = IDX_PORT_C,
//                        .forward_pin .status    = LOGIC_OFF,
//                        .backward_pin.direction = DIRECTION_OUTPUT,
//                        .backward_pin.logic     = LOGIC_OFF,
//                        .backward_pin.pin_num   = IDX_PIN_3,
//                        .backward_pin.port      = IDX_PORT_C,
//                        .backward_pin.status    = LOGIC_OFF};

std_return DCmotor_init(DCmotor_t * p_DCmotor);
std_return DCmotor_rotate_CW_CCW(DCmotor_t * p_DCmotor, DCmotor_dir_t d_DCmotor_dir);
std_return DCmotor_brake(DCmotor_t * p_DCmotor);

#endif	/* DCMOTOR_H */

