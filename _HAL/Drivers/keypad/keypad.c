#include "keypad.h"

uint8_t keypad_key_values_arr[4][4] = { {'1','2','3','A'},
                                        {'4','5','6','B'},
                                        {'7','8','9','C'},
                                        {'*','0','#','D'}};

keypad_t keypad_1 = { 
                      .kpd_rows_pins_arr[0].port     = IDX_PORT_C,
                      .kpd_rows_pins_arr[0].pin_num  = IDX_PIN_0,
                      .kpd_rows_pins_arr[0].direction= DIRECTION_OUTPUT,
                      .kpd_rows_pins_arr[0].logic    = LOGIC_OFF,
                      .kpd_rows_pins_arr[0].status   = LOGIC_OFF,

                      .kpd_rows_pins_arr[1].port     = IDX_PORT_C,
                      .kpd_rows_pins_arr[1].pin_num  = IDX_PIN_1,
                      .kpd_rows_pins_arr[1].direction= DIRECTION_OUTPUT,
                      .kpd_rows_pins_arr[1].logic    = LOGIC_OFF,
                      .kpd_rows_pins_arr[1].status   = LOGIC_OFF,

                      .kpd_rows_pins_arr[2].port     = IDX_PORT_C,
                      .kpd_rows_pins_arr[2].pin_num  = IDX_PIN_2,
                      .kpd_rows_pins_arr[2].direction= DIRECTION_OUTPUT,
                      .kpd_rows_pins_arr[2].logic    = LOGIC_OFF,
                      .kpd_rows_pins_arr[2].status   = LOGIC_OFF,

                      .kpd_rows_pins_arr[3].port     = IDX_PORT_C,
                      .kpd_rows_pins_arr[3].pin_num  = IDX_PIN_3,
                      .kpd_rows_pins_arr[3].direction= DIRECTION_OUTPUT,
                      .kpd_rows_pins_arr[3].logic    = LOGIC_OFF,
                      .kpd_rows_pins_arr[3].status   = LOGIC_OFF,

                      .kpd_columns_pins_arr[0].port     = IDX_PORT_C,
                      .kpd_columns_pins_arr[0].pin_num  = IDX_PIN_4,
                      .kpd_columns_pins_arr[0].direction= DIRECTION_INPUT,
                      .kpd_columns_pins_arr[0].logic    = LOGIC_OFF,
                      .kpd_columns_pins_arr[0].status   = LOGIC_OFF,

                      .kpd_columns_pins_arr[1].port     = IDX_PORT_C,
                      .kpd_columns_pins_arr[1].pin_num  = IDX_PIN_5,
                      .kpd_columns_pins_arr[1].direction= DIRECTION_INPUT,
                      .kpd_columns_pins_arr[1].logic    = LOGIC_OFF,
                      .kpd_columns_pins_arr[1].status   = LOGIC_OFF,

                      .kpd_columns_pins_arr[2].port     = IDX_PORT_C,
                      .kpd_columns_pins_arr[2].pin_num  = IDX_PIN_6,
                      .kpd_columns_pins_arr[2].direction= DIRECTION_INPUT,
                      .kpd_columns_pins_arr[2].logic    = LOGIC_OFF,
                      .kpd_columns_pins_arr[2].status   = LOGIC_OFF,

                      .kpd_columns_pins_arr[3].port     = IDX_PORT_C,
                      .kpd_columns_pins_arr[3].pin_num  = IDX_PIN_7,
                      .kpd_columns_pins_arr[3].direction= DIRECTION_INPUT,
                      .kpd_columns_pins_arr[3].logic    = LOGIC_OFF,
                      .kpd_columns_pins_arr[3].status   = LOGIC_OFF,

};

std_return keypad_init(keypad_t * p_keypad)
{
    if (NULL == p_keypad)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {     
        uint8_t idx = 0;
        for(idx=0; idx<KPD_ROWS_NUM; idx++)
        {
        gpio_pin_direction_initialize( &(p_keypad->kpd_rows_pins_arr[idx]) );
        gpio_pin_write_logic( &(p_keypad->kpd_rows_pins_arr[idx]), LOGIC_OFF);
        }
        for(idx=0; idx<KPD_COLUMNS_NUM; idx++)
        {
        gpio_pin_direction_initialize( &(p_keypad->kpd_columns_pins_arr[idx]) );
        gpio_pin_write_logic( &(p_keypad->kpd_columns_pins_arr[idx]), LOGIC_OFF);
        }
    }
    return EXCUTION_OK;
}


std_return keypad_read(keypad_t * p_keypad, uint8_t * p_pressed_key)
{
    if (NULL == p_keypad)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        
        uint8_t idx = 0, idx2 = 0, idx3 = 0;
        LOGIC_t pin_logic = 0;
        
        for(idx=0; idx<KPD_ROWS_NUM; idx++)
        {
            for(idx2=0; idx2<KPD_ROWS_NUM; idx2++)
            {
                gpio_pin_write_logic( &(p_keypad->kpd_rows_pins_arr[idx2]), LOGIC_OFF);
            }
            
            gpio_pin_write_logic( &(p_keypad->kpd_rows_pins_arr[idx]), LOGIC_ON);
 
            for(idx3=0; idx3<KPD_COLUMNS_NUM; idx3++)
            {
                gpio_pin_read_logic(&(p_keypad->kpd_columns_pins_arr[idx3]),&pin_logic);
                
                if(LOGIC_ON == pin_logic)
                {
                   *p_pressed_key = keypad_key_values_arr[idx][idx3];
                }
                
            }
            
        }
        
    }
    return EXCUTION_OK;
}

