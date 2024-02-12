/* 
* File:   main.c
* Author: Abdulrahman
*
* Created on November 26, 2023, 4:09 PM
*/

/* lib includes START */
/* lib includes END */

/* includes START */
#include "main.h"
/* includes END */

uint32_t program_step_counter = 0;
uint8_t _car_char_arr[8]= {0x00,0x0A,0x0A,0x0A,0x00,0x1F,0x11,0x0E};
uint8_t _musicNote_char_arr[8]= { 0b00000100, 0b00000110, 0b00000101, 0b00000101, 0b00001101, 0b00011100, 0b00011000, 0b00000000 };
/* Defines START */
/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
 
/* Global Variables END */

/* Helper Function Definitions START */
/* Helper Function Definitions END */

/* Code START */
int main()
{
    app_init();
    init_msg_lcd();
    hello_world_lcd();
    uint8_t msg_X[4];
    uint8_t X = 0;
    uint8_t msg_boom[17] = "****BOOOOOOM****";
    uint8_t msg_space[17]= "                ";
    for(;;)
    {
       
        convert_uint8_to_strng(X,msg_X);
        lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 1, msg_X);
        lcd_8bit_send_custom_char_pos(  &lcd_2_8bit, 2, 1, _musicNote_char_arr, 1);
        lcd_8bit_send_custom_char_pos(  &lcd_2_8bit, 2, 2, _car_char_arr, 0);
        lcd_8bit_send_custom_char_pos(  &lcd_2_8bit, 2, 3, _musicNote_char_arr, 1);
        X++;
        __delay_ms(50);
        memset(msg_X, '\0', 4);
        memset(msg_X, ' ', 3);
        lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 1, msg_X);
        if(60==X)
        {
           X=0;
           lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 1,msg_space);
           lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1,msg_space);
           lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 1,msg_boom );
           __delay_ms(2000);
           lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 1,msg_space);
           lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1,msg_space);
        }
        
     }
    return (EXCUTION_OK);
}
/* Code END */