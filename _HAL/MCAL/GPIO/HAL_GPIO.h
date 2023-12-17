/* 
 * File:   HAL_GPIO.h
 * Author: Abdulrahman
 *
 * Created on November 26, 2023, 4:16 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* lib includes START */
/* lib includes END */

/* includes START */
#include "../device_config.h"
#include "../MCAL_std_types.h"
/* includes END */

/* Defines START */

typedef struct{
    IDX_PORT_X_t port;
    IDX_PIN_X_t  pin_num;
    DIRECTION_t  direction;
    LOGIC_t      logic;
    LOGIC_t      status;
}pin_config_t;

/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
/* Global Variables END */

/* Function Prototypes START */
/* Function Prototypes END */

/* Public Function Definitions START */
std_return set_bit_uint8(REGISTER_t * p_reg, IDX_BIT_X_t d_IDX_BIT_X)                             ;
std_return clear_bit_uint8(REGISTER_t * p_reg, IDX_BIT_X_t d_IDX_BIT_X)                           ;
std_return toggle_bit_uint8(REGISTER_t * p_reg, IDX_BIT_X_t d_IDX_BIT_X)                          ;
std_return gpio_pin_direction_initialize(const pin_config_t * p_pin_config)                       ;
std_return gpio_pin_write_logic(pin_config_t * p_pin_config, const LOGIC_t d_logic_desired)       ;
std_return gpio_pin_get_direction_status(pin_config_t * p_pin_config,DIRECTION_t * p_direction)   ;
std_return gpio_pin_initialize(pin_config_t * p_pin_config)                                       ;
std_return gpio_pin_read_logic(const pin_config_t * p_pin_config,LOGIC_t * p_logic)               ;
std_return gpio_pin_toggle_logic(pin_config_t * p_pin_config)                                     ;
std_return gpio_port_direction_initialize(IDX_PORT_X_t p_port_idx, uint8_t d_port_direction_mask) ;
std_return gpio_port_get_direction_status(IDX_PORT_X_t p_port_idx, uint8_t * p_port_direction)    ;
std_return gpio_port_write_logic(IDX_PORT_X_t p_port_idx, uint8_t d_port_logic)                   ;
std_return gpio_port_read_logic(IDX_PORT_X_t p_port_idx, uint8_t * p_port_logic)                  ;
std_return gpio_port_toggle_logic(IDX_PORT_X_t p_port_idx)                                        ;
/* Public Function Definitions END */



#endif	/* HAL_GPIO_H */

