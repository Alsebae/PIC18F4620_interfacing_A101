/* 
 * File:   application.c
 * Author: Abdulrahman
 *
 * Created on November 26, 2023, 5:22 PM
 */

/* lib includes START */
/* lib includes END */

/* includes START */
#include "application.h"
/* includes END */

/* Defines START */
/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
//uint8_t   program_counter                 = 0     ;
/* Global Variables END */

/* Helper Function Definitions START */
/* Helper Function Definitions END */

/* Code START */

void calculate_step_counter()
{
    program_step_counter++;
    if (0xFFFFFFFE == program_step_counter)
    {
        program_step_counter = 0;
    }
}

 

void app_init( )
{
//   lcd_4bit_init( &lcd_1_4bit);
    lcd_8bit_init( &lcd_2_8bit);
}

//void led_program_1()
//{
//    led_on_off(&led_1, LED_ON);
// 
//}
//
//void led_program_2()
//{
//    if (0 == (program_step_counter%100))
//    {
//    led_toggle(&led_1);
//    }
//}
//
//void led_program_3()
//{
//    led_on_off(&led_1, LED_OFF);
//}
//
//
//void magic_button()
//{
//    push_button_read(&push_btn_1, &button_1_state);
//    if(BUTTON_PRESSED == button_1_state)
//    {
//        btn_counter++;
//        
//        if(btn_counter>=500)
//        {
//            btn_counter = 500;
//            btn_1_high_valid_state = HIGH;
//        }
//        
//    }
//    else
//    {
//        btn_counter = 0;
//        btn_1_high_valid_state = LOW;
//    }
//    
//    if ((LOW == btn_1_high_valid_state_previous) && (HIGH == btn_1_high_valid_state))
//    {
//        rise_edge = TRUE;
//    }
//    else
//    {
//        rise_edge = FALSE;
//    }
//    
//    if (TRUE == rise_edge)
//    {
//        led_toggle(&led_1);
//    }
//    
//    btn_1_high_valid_state_previous = btn_1_high_valid_state;
//    
//  
//}
//
//void magic_switch_led_programs()
//{
//    push_button_read(&push_btn_1, &button_1_state);
//    if(BUTTON_PRESSED == button_1_state)
//    {
//        btn_counter++;
//        
//        if(btn_counter>=100)
//        {
//            btn_counter = 100;
//            btn_1_high_valid_state = HIGH;
//        }
//        
//    }
//    else
//    {
//        btn_counter = 0;
//        btn_1_high_valid_state = LOW;
//    }
//    
//    if ((LOW == btn_1_high_valid_state_previous) && (HIGH == btn_1_high_valid_state))
//    {
//        rise_edge = TRUE;
//    }
//    else
//    {
//        rise_edge = FALSE;
//    }
//    
//    if (TRUE == rise_edge)
//    {
//        program_counter++;
//        if (program_counter>3)
//        {
//            program_counter=1;
//        }
//    }
//    
//    switch(program_counter)
//    {
//        case(PROGRAM_1):
//        {
//            led_program_1();
//            break;
//        }
//        case(PROGRAM_2):
//        {
//            led_program_2();
//            break;
//        }
//        case(PROGRAM_3):
//        {
//            led_program_3();
//            break;
//        }
//        default:
//        {
//            break;
//        }
//    }
//    
//    btn_1_high_valid_state_previous = btn_1_high_valid_state;
//    
//    
// 
//}
//----------------------------------------------------------------------------
void two_reverse_relay_5s(void)
{
//    static uint8_t _flag = 0;
//    if ((0 == (program_step_counter%3000)) && (0 == _flag))
//    {
//        relay_toggle(&relay_1);
//        _flag = 1;
//    }
//    else if ((0 == (program_step_counter%3000)) && (1 == _flag))
//    {
//        relay_toggle(&relay_2);
//        _flag = 0;
//    }
//    else
//    {
//        /*NOTHING*/
//    }
    //relay_toggle(&relay_1);
    //__delay_ms(1000);
    //relay_toggle(&relay_1);
    //relay_toggle(&relay_2);
    //__delay_ms(1000);
    //relay_toggle(&relay_2);
}
//-----------------------------------------------------------------------------
#if CODE_DISABLED
void two_DCmotor_sequence(void)
{
    DCmotor_rotate_CW_CCW(&DCmotor_1, CLOCKWISE);
    DCmotor_rotate_CW_CCW(&DCmotor_2, CLOCKWISE);
    __delay_ms(1000);
    DCmotor_brake(&DCmotor_1);
    DCmotor_brake(&DCmotor_2);
    __delay_ms(1000);
    DCmotor_rotate_CW_CCW(&DCmotor_1, COUNTER_CLOCKWISE);
    DCmotor_rotate_CW_CCW(&DCmotor_2, COUNTER_CLOCKWISE);
    __delay_ms(1000);
    DCmotor_brake(&DCmotor_1);
    DCmotor_brake(&DCmotor_2);
    __delay_ms(1000);
    DCmotor_rotate_CW_CCW(&DCmotor_1, CLOCKWISE);
    DCmotor_rotate_CW_CCW(&DCmotor_2, COUNTER_CLOCKWISE);
    __delay_ms(1000);
    DCmotor_brake(&DCmotor_1);
    DCmotor_brake(&DCmotor_2);
    __delay_ms(1000);
    DCmotor_rotate_CW_CCW(&DCmotor_1, COUNTER_CLOCKWISE);
    DCmotor_rotate_CW_CCW(&DCmotor_2, CLOCKWISE);
    __delay_ms(1000);
    DCmotor_brake(&DCmotor_1);
    DCmotor_brake(&DCmotor_2);
    __delay_ms(1000);
}
#endif
        
void hello_world_lcd(void)
{
    uint8_t idx = 0,idx2 = 0; 

    
    for(idx=0; idx<3; idx++)
        {
            lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 5+idx, "_HELLO_");
            lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 5+idx, "_WORLD_");
             __delay_ms(500);
            lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 5, "          ");
            lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 5, "          ");     
        }

         for(idx2=3 ; idx2!=0; idx2--)
        {
          lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 5+idx2-1, "_HELLO_");
          lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 5+idx2-1, "_WORLD_");
          __delay_ms(500);
          lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 5, "          ");
          lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 5, "          ");
     
        }

 
}
void init_msg_lcd(void)
{
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 1, "_INITIALIZATION_");
    __delay_ms(3000);
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 1, "                ");
    uint8_t msg1[] = " PLEASE WAIT =)  ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 1, msg1);
    uint8_t msg2[] = "loading          ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg2);
    __delay_ms(500);
    uint8_t msg3[] = "                ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg3);
    uint8_t msg4[] = "loading..        ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg4);
    __delay_ms(500);
    uint8_t msg5[] = "                ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg5);
    uint8_t msg6[] = "loading....      ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg6);
    __delay_ms(500);
    uint8_t msg7[] = "                ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg7);
    uint8_t msg8[] = "loading......    ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg8);
    __delay_ms(500);
    uint8_t msg9[] = "                ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg9);
    uint8_t msg10[] = "loading........  ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg10);
    __delay_ms(500);
    uint8_t msg11[] = "                ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg11);
    uint8_t msg12[] = "loading..........";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg12);
    __delay_ms(500);
    uint8_t msg13[] = "                ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 2, 1, msg13);
    uint8_t msg14[] = "                ";
    lcd_8bit_send_strng_pos(  &lcd_2_8bit, 1, 1, msg14);

 
}

/* Code END */