/* 
 * File:   LCD.h
 * Author: alseb
 *
 * Created on December 31, 2023, 4:52 PM
 */

#ifndef LCD_H
#define	LCD_H
 
#include "../../MCAL/GPIO/HAL_GPIO.h"

#define LCD_CLEAR                  0x01
#define LCD_RETURN_HOME            0x02
#define LCD_ENTRY_MODE             0x06
#define LCD_CURSOR_OFF_DISPLAY_ON  0x0C
#define LCD_CURSOR_OFF_DISPLAY_OFF 0x08
#define LCD_CURSOR_ON_BLINK_ON     0x0F
#define LCD_CURSOR_ON_BLINK_OFF    0x0E
#define LCD_DISPLAY_SHIFT_RIGHT    0x1C
#define LCD_DISPLAY_SHIFT_LEFT     0x18
#define LCD_8_BIT_MODE_2_LINE      0x38
#define LCD_4_BIT_MODE_2_LINE      0x28
#define LCD_CGRAM_START            0x40
#define LCD_DDRAMSTART_START       0x80

#define ROW1                       0x01
#define ROW2                       0x02


typedef struct{
    pin_config_t lcd_reg_select_pin;
    pin_config_t lcd_enable_pin;
    pin_config_t lcd_data_pin[4];
}lcd_4bit_t;


typedef struct{
    pin_config_t lcd_reg_select_pin;
    pin_config_t lcd_enable_pin;
    pin_config_t lcd_data_pin[8];
}lcd_8bit_t;

//extern lcd_4bit_t lcd_1_4bit;
extern lcd_8bit_t lcd_2_8bit;

std_return lcd_4bit_init(    lcd_4bit_t *    p_lcd);
std_return lcd_4bit_send_cmd(  lcd_4bit_t *   p_lcd, const uint8_t d_cmd);
std_return lcd_4bit_send_char(  lcd_4bit_t *   p_lcd, const uint8_t d_data);
std_return lcd_4bit_send_char_pos(  lcd_4bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column,const uint8_t d_data);
std_return lcd_4bit_send_strng(  lcd_4bit_t *   p_lcd, const uint8_t * p_strng);
std_return lcd_4bit_send_strng_pos(  lcd_4bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column, const uint8_t * p_strng);
std_return lcd_4bit_send_custom_char_pos(  lcd_4bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column, const uint8_t _char[], uint8_t mem_pos);
std_return lcd_4bit_set_cursor(  lcd_4bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column);

std_return lcd_8bit_init(  lcd_8bit_t *   p_lcd);
std_return lcd_8bit_send_cmd(  lcd_8bit_t *   p_lcd, const uint8_t d_cmd);
std_return lcd_8bit_send_char(  lcd_8bit_t *   p_lcd, const uint8_t d_data);
std_return lcd_8bit_send_char_pos(  lcd_8bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column,const uint8_t d_data);
std_return lcd_8bit_send_strng(  lcd_8bit_t *   p_lcd, const uint8_t * p_strng);
std_return lcd_8bit_send_strng_pos(  lcd_8bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column, const uint8_t * p_strng);
std_return lcd_8bit_send_custom_char_pos(  lcd_8bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column, const uint8_t * _char, uint8_t mem_pos);
std_return lcd_8bit_set_cursor(  lcd_8bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column);


std_return convert_uint8_to_strng(uint8_t d_input, uint8_t * d_strng);
std_return convert_uint16_to_strng(uint16_t d_input, uint8_t * d_strng);
std_return convert_uint32_to_strng(uint32_t d_input, uint8_t * d_strng);

#endif	/* LCD_H */

