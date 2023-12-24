/* 
 * File:   keypad.h
 * Author: alseb
 *
 * Created on December 24, 2023, 6:12 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#include "../../MCAL/GPIO/HAL_GPIO.h"

#define KPD_ROWS_NUM     (4)
#define KPD_COLUMNS_NUM  (4)

typedef struct{
    pin_config_t kpd_rows_pins_arr[KPD_ROWS_NUM];
    pin_config_t kpd_columns_pins_arr[KPD_COLUMNS_NUM];
}keypad_t;

extern keypad_t keypad_1;

std_return keypad_init(keypad_t * p_keypad);
std_return keypad_read(keypad_t * p_keypad, uint8_t * p_pressed_key);

#endif	/* KEYPAD_H */

