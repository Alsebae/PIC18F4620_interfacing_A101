/* 
 * File:   application.h
 * Author: Abdulrahman
 *
 * Created on November 26, 2023, 5:22 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "../_HAL/Drivers/LED/LED.h"
#include "../_HAL/Drivers/button/button.h"

extern uint32_t program_step_counter;

push_button_t push_btn_1 = {.button_pin.port      = IDX_PORT_C,
                            .button_pin.pin_num   = IDX_PIN_0,
                            .button_pin.direction = DIRECTION_INPUT,
                            .button_pin.logic     = HIGH,
                            .button_pin.status    = HIGH,
                            .button_active_state  = LOW,
                            .button_state         = HIGH};

push_button_t push_btn_2 = {.button_pin.port      = IDX_PORT_C,
                            .button_pin.pin_num   = IDX_PIN_1,
                            .button_pin.direction = DIRECTION_INPUT,
                            .button_pin.logic     = LOW,
                            .button_pin.status    = LOW,
                            .button_active_state  = HIGH,
                            .button_state         = LOW};

led_t led_1 = {.port_idx   =  IDX_PORT_C,
               .pin_idx    =  IDX_PIN_2,
               .led_status =  LED_OFF};

led_t led_2 = {.port_idx   =  IDX_PORT_C,
               .pin_idx    =  IDX_PIN_3,
               .led_status =  LED_OFF};

uint32_t  btn_counter                     = 0     ;
uint8_t   program_counter                 = 0     ;
DIGITAL_t btn_1_high_valid_state          = LOW   ;
DIGITAL_t btn_1_high_valid_state_previous = LOW   ;
bool_t    rise_edge                       = FALSE ;

button_state_t button_1_state = BUTTON_RELEASED;
button_state_t button_2_state = BUTTON_RELEASED;

typedef enum
{
    PROGRAM_1 = 1,
    PROGRAM_2 = 2,
    PROGRAM_3 = 3,
}PROGRAM_t;

void calculate_step_counter(void)    ;
void app_init(void)                  ;
void magic_button(void)              ;
void magic_switch_led_programs(void) ;
void led_program_1(void)             ;
void led_program_2(void)             ;
void led_program_3(void)             ;
#endif	/* APPLICATION_H */





