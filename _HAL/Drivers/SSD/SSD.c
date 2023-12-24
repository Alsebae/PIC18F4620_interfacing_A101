#include "SSD.h"
#if 0
//-----------------------------------------------------------------------------
std_return SSD_init(SSD_t * p_SSD)
{
    if (NULL == p_SSD)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        uint8_t idx = 0;
        for (idx = 0; idx<SSD_pin_num; idx++)
        {
            gpio_pin_direction_initialize(&p_SSD->SSD_pins_arr[idx]);
            gpio_pin_write_logic(&p_SSD->SSD_pins_arr[idx], LOGIC_OFF);
            
        }
    }
    return EXCUTION_OK;
}
//-----------------------------------------------------------------------------
std_return SSD_write_number(SSD_t * p_SSD, uint8_t d_number)
{
    if ((NULL == p_SSD) || (d_number >99))
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        //writing the ones;
        gpio_pin_write_logic(&SSD1_D1_enable_pin, LOGIC_ON);
        gpio_pin_write_logic(&p_SSD->SSD_pins_arr[SSD_pin_A], ((uint8_t)(d_number%10) >> 0)  & 0b00000001);
        gpio_pin_write_logic(&p_SSD->SSD_pins_arr[SSD_pin_B], ((uint8_t)(d_number%10) >> 1)  & 0b00000001);
        gpio_pin_write_logic(&p_SSD->SSD_pins_arr[SSD_pin_C], ((uint8_t)(d_number%10) >> 2)  & 0b00000001);
        gpio_pin_write_logic(&p_SSD->SSD_pins_arr[SSD_pin_D], ((uint8_t)(d_number%10) >> 3)  & 0b00000001);
        gpio_pin_write_logic(&SSD1_D2_enable_pin, LOGIC_OFF);
        __delay_ms(1);
        //writing the tens;
        gpio_pin_write_logic(&SSD1_D2_enable_pin, LOGIC_ON);
        gpio_pin_write_logic(&p_SSD->SSD_pins_arr[SSD_pin_A], ((uint8_t)(d_number/10.0f) >> 0)  & 0b00000001);
        gpio_pin_write_logic(&p_SSD->SSD_pins_arr[SSD_pin_B], ((uint8_t)(d_number/10.0f) >> 1)  & 0b00000001);
        gpio_pin_write_logic(&p_SSD->SSD_pins_arr[SSD_pin_C], ((uint8_t)(d_number/10.0f) >> 2)  & 0b00000001);
        gpio_pin_write_logic(&p_SSD->SSD_pins_arr[SSD_pin_D], ((uint8_t)(d_number/10.0f) >> 3)  & 0b00000001);
        gpio_pin_write_logic(&SSD1_D1_enable_pin, LOGIC_OFF);
        __delay_ms(1);
        
    }
    return EXCUTION_OK;
}
//-----------------------------------------------------------------------------
#endif