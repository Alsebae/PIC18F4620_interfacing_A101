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
    //push_button_init(&push_btn_1);
    //led_init(&led_1);
    //relay_init(&relay_1);    
    //relay_init(&relay_2);   
    DCmotor_init(&DCmotor_1);
    DCmotor_init(&DCmotor_2);
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
/* Code END */