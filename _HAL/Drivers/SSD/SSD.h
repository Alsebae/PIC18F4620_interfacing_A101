/* 
 * File:   SSD.h
 * Author: alseb
 *
 * Created on December 21, 2023, 5:47 PM
 */

#ifndef SSD_H
#define	SSD_H

#include "../../MCAL/GPIO/HAL_GPIO.h"

typedef enum
{
 SSD_pin_A   =0,
 SSD_pin_B   =1,
 SSD_pin_C   =2,
 SSD_pin_D   =3,
 SSD_pin_num =4,        
}SSD_pins_et;

typedef enum
{
    COMMON_ANODE_SSD   = 0,
    COMMON_CATHODE_SSD = 1
}SSD_type_t;

typedef struct
{
    pin_config_t SSD_pins_arr[SSD_pin_num];
    SSD_type_t   SSD_type;
}SSD_t;
//
//SSD_t SSD_1 = {
//    .SSD_pins_arr[SSD_pin_A].direction = DIRECTION_OUTPUT,
//    .SSD_pins_arr[SSD_pin_A].logic     = LOGIC_OFF,
//    .SSD_pins_arr[SSD_pin_A].pin_num   = IDX_PIN_0,
//    .SSD_pins_arr[SSD_pin_A].port      = IDX_PORT_C,
//    .SSD_pins_arr[SSD_pin_A].status    = LOGIC_OFF,
//    
//    .SSD_pins_arr[SSD_pin_B].direction = DIRECTION_OUTPUT,
//    .SSD_pins_arr[SSD_pin_B].logic     = LOGIC_OFF,
//    .SSD_pins_arr[SSD_pin_B].pin_num   = IDX_PIN_1,
//    .SSD_pins_arr[SSD_pin_B].port      = IDX_PORT_C,
//    .SSD_pins_arr[SSD_pin_B].status    = LOGIC_OFF,
//    
//    .SSD_pins_arr[SSD_pin_C].direction = DIRECTION_OUTPUT,
//    .SSD_pins_arr[SSD_pin_C].logic     = LOGIC_OFF,
//    .SSD_pins_arr[SSD_pin_C].pin_num   = IDX_PIN_2,
//    .SSD_pins_arr[SSD_pin_C].port      = IDX_PORT_C,
//    .SSD_pins_arr[SSD_pin_C].status    = LOGIC_OFF,
//    
//    .SSD_pins_arr[SSD_pin_D].direction = DIRECTION_OUTPUT,
//    .SSD_pins_arr[SSD_pin_D].logic     = LOGIC_OFF,
//    .SSD_pins_arr[SSD_pin_D].pin_num   = IDX_PIN_3,
//    .SSD_pins_arr[SSD_pin_D].port      = IDX_PORT_C,
//    .SSD_pins_arr[SSD_pin_D].status    = LOGIC_OFF,
//    
//    .SSD_type                          = COMMON_ANODE_SSD
//};
//
//pin_config_t SSD1_D1_enable_pin = {
//    .direction = DIRECTION_OUTPUT,
//    .logic     = LOGIC_OFF,
//    .pin_num   = IDX_PIN_4,
//    .port      = IDX_PORT_C,
//    .status    = LOGIC_OFF
//};
//
//pin_config_t SSD1_D2_enable_pin = {
//    .direction = DIRECTION_OUTPUT,
//    .logic     = LOGIC_OFF,
//    .pin_num   = IDX_PIN_5,
//    .port      = IDX_PORT_C,
//    .status    = LOGIC_OFF
//};

std_return SSD_init(SSD_t * p_SSD);
std_return SSD_write_number(SSD_t * p_SSD, uint8_t d_number);
#endif	/* SSD_H */

