#include "LCD.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//lcd_4bit_t lcd_1_4bit = {
//.lcd_reg_select_pin.port       = IDX_PORT_C,
//.lcd_reg_select_pin.pin_num    = IDX_PIN_6,
//.lcd_reg_select_pin.direction  = DIRECTION_OUTPUT,
//.lcd_reg_select_pin.logic      = LOGIC_OFF,
//.lcd_reg_select_pin.status     = LOGIC_OFF,
//.lcd_enable_pin.port           = IDX_PORT_C,
//.lcd_enable_pin.pin_num        = IDX_PIN_7,
//.lcd_enable_pin.direction      = DIRECTION_OUTPUT,
//.lcd_enable_pin.logic          = LOGIC_OFF,
//.lcd_enable_pin.status         = LOGIC_OFF,
//.lcd_data_pin[0].port           = IDX_PORT_D,
//.lcd_data_pin[0].pin_num        = IDX_PIN_4,
//.lcd_data_pin[0].direction      = DIRECTION_OUTPUT,
//.lcd_data_pin[0].logic          = LOGIC_ON,
//.lcd_data_pin[0].status         = LOGIC_ON,
//.lcd_data_pin[1].port           = IDX_PORT_D,
//.lcd_data_pin[1].pin_num        = IDX_PIN_5,
//.lcd_data_pin[1].direction      = DIRECTION_OUTPUT,
//.lcd_data_pin[1].logic          = LOGIC_OFF,
//.lcd_data_pin[1].status         = LOGIC_OFF,
//.lcd_data_pin[2].port           = IDX_PORT_D,
//.lcd_data_pin[2].pin_num        = IDX_PIN_6,
//.lcd_data_pin[2].direction      = DIRECTION_OUTPUT,
//.lcd_data_pin[2].logic          = LOGIC_OFF,
//.lcd_data_pin[2].status         = LOGIC_OFF,
//.lcd_data_pin[3].port           = IDX_PORT_D,
//.lcd_data_pin[3].pin_num        = IDX_PIN_7,
//.lcd_data_pin[3].direction      = DIRECTION_OUTPUT,
//.lcd_data_pin[3].logic          = LOGIC_OFF,
//.lcd_data_pin[3].status         = LOGIC_OFF
//};

lcd_8bit_t lcd_2_8bit = {
.lcd_reg_select_pin.port       = IDX_PORT_C,
.lcd_reg_select_pin.pin_num    = IDX_PIN_6,
.lcd_reg_select_pin.direction  = DIRECTION_OUTPUT,
.lcd_reg_select_pin.logic      = LOGIC_OFF,
.lcd_reg_select_pin.status     = LOGIC_OFF,
.lcd_enable_pin.port           = IDX_PORT_C,
.lcd_enable_pin.pin_num        = IDX_PIN_7,
.lcd_enable_pin.direction      = DIRECTION_OUTPUT,
.lcd_enable_pin.logic          = LOGIC_OFF,
.lcd_enable_pin.status         = LOGIC_OFF,
.lcd_data_pin[0].port           = IDX_PORT_D,
.lcd_data_pin[0].pin_num        = IDX_PIN_0,
.lcd_data_pin[0].direction      = DIRECTION_OUTPUT,
.lcd_data_pin[0].logic          = LOGIC_OFF,
.lcd_data_pin[0].status         = LOGIC_OFF,
.lcd_data_pin[1].port           = IDX_PORT_D,
.lcd_data_pin[1].pin_num        = IDX_PIN_1,
.lcd_data_pin[1].direction      = DIRECTION_OUTPUT,
.lcd_data_pin[1].logic          = LOGIC_OFF,
.lcd_data_pin[1].status         = LOGIC_OFF,
.lcd_data_pin[2].port           = IDX_PORT_D,
.lcd_data_pin[2].pin_num        = IDX_PIN_2,
.lcd_data_pin[2].direction      = DIRECTION_OUTPUT,
.lcd_data_pin[2].logic          = LOGIC_OFF,
.lcd_data_pin[2].status         = LOGIC_OFF,
.lcd_data_pin[3].port           = IDX_PORT_D,
.lcd_data_pin[3].pin_num        = IDX_PIN_3,
.lcd_data_pin[3].direction      = DIRECTION_OUTPUT,
.lcd_data_pin[3].logic          = LOGIC_OFF,
.lcd_data_pin[3].status         = LOGIC_OFF,
.lcd_data_pin[4].port           = IDX_PORT_D,
.lcd_data_pin[4].pin_num        = IDX_PIN_4,
.lcd_data_pin[4].direction      = DIRECTION_OUTPUT,
.lcd_data_pin[4].logic          = LOGIC_OFF,
.lcd_data_pin[4].status         = LOGIC_OFF,
.lcd_data_pin[5].port           = IDX_PORT_D,
.lcd_data_pin[5].pin_num        = IDX_PIN_5,
.lcd_data_pin[5].direction      = DIRECTION_OUTPUT,
.lcd_data_pin[5].logic          = LOGIC_OFF,
.lcd_data_pin[5].status         = LOGIC_OFF,
.lcd_data_pin[6].port           = IDX_PORT_D,
.lcd_data_pin[6].pin_num        = IDX_PIN_6,
.lcd_data_pin[6].direction      = DIRECTION_OUTPUT,
.lcd_data_pin[6].logic          = LOGIC_OFF,
.lcd_data_pin[6].status         = LOGIC_OFF,
.lcd_data_pin[7].port           = IDX_PORT_D,
.lcd_data_pin[7].pin_num        = IDX_PIN_7,
.lcd_data_pin[7].direction      = DIRECTION_OUTPUT,
.lcd_data_pin[7].logic          = LOGIC_OFF,
.lcd_data_pin[7].status         = LOGIC_OFF,
};

static std_return lcd_4bit_send_enable(  lcd_4bit_t *    p_lcd);
static std_return lcd_8bit_send_enable(  lcd_8bit_t *    p_lcd);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
std_return lcd_4bit_init(    lcd_4bit_t *    p_lcd)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        uint8_t idx = 0;
        gpio_pin_direction_initialize(&(p_lcd->lcd_reg_select_pin));   
        gpio_pin_write_logic(&(p_lcd->lcd_reg_select_pin),p_lcd->lcd_reg_select_pin.logic);
        gpio_pin_direction_initialize(&(p_lcd->lcd_enable_pin));
        gpio_pin_write_logic(&(p_lcd->lcd_enable_pin),p_lcd->lcd_enable_pin.logic);
        for (idx=0; idx<4; idx++)
        {
            gpio_pin_direction_initialize(&(p_lcd->lcd_data_pin[idx]));   
            gpio_pin_write_logic(&(p_lcd->lcd_data_pin[idx]),p_lcd->lcd_data_pin[idx].logic);
        }
        /*INIT CONFIGURATION*/
        __delay_ms(20);
        lcd_4bit_send_cmd(p_lcd, LCD_8_BIT_MODE_2_LINE);
        __delay_ms(5);
        lcd_4bit_send_cmd(p_lcd, LCD_8_BIT_MODE_2_LINE);
        __delay_us(150);
        lcd_4bit_send_cmd(p_lcd, LCD_8_BIT_MODE_2_LINE);
        lcd_4bit_send_cmd(p_lcd, LCD_CLEAR);
        lcd_4bit_send_cmd(p_lcd, LCD_RETURN_HOME);
        lcd_4bit_send_cmd(p_lcd, LCD_ENTRY_MODE);
        lcd_4bit_send_cmd(p_lcd, LCD_CURSOR_OFF_DISPLAY_ON);
        lcd_4bit_send_cmd(p_lcd, LCD_4_BIT_MODE_2_LINE);
        lcd_4bit_send_cmd(p_lcd, LCD_DDRAMSTART_START);
    }
    
    return EXCUTION_OK;
}
//------------------------------------------------------------------------------
std_return lcd_4bit_send_cmd(  lcd_4bit_t *   p_lcd, const uint8_t d_cmd)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        gpio_pin_write_logic(&(p_lcd->lcd_reg_select_pin),LOGIC_OFF);
        
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[0]),  ((d_cmd >> 4) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[1]),  ((d_cmd >> 5) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[2]),  ((d_cmd >> 6) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[3]),  ((d_cmd >> 7) & 0x01) );
        lcd_4bit_send_enable(p_lcd);
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[0]),  ((d_cmd >> 0) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[1]),  ((d_cmd >> 1) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[2]),  ((d_cmd >> 2) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[3]),  ((d_cmd >> 3) & 0x01) );
        lcd_4bit_send_enable(p_lcd);
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_4bit_send_char(  lcd_4bit_t *   p_lcd, const uint8_t d_data)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        gpio_pin_write_logic(&(p_lcd->lcd_reg_select_pin),LOGIC_ON);
        
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[0]),  ((d_data >> 4) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[1]),  ((d_data >> 5) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[2]),  ((d_data >> 6) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[3]),  ((d_data >> 7) & 0x01) );
        lcd_4bit_send_enable(p_lcd);
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[0]),  ((d_data >> 0) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[1]),  ((d_data >> 1) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[2]),  ((d_data >> 2) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[3]),  ((d_data >> 3) & 0x01) );
        lcd_4bit_send_enable(p_lcd);
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_4bit_send_char_pos(  lcd_4bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column,const uint8_t d_data)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        lcd_4bit_set_cursor(p_lcd, d_row, d_column);
        lcd_4bit_send_char(p_lcd, d_data);   
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_4bit_send_strng(  lcd_4bit_t *   p_lcd, const uint8_t * p_strng)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_4bit_send_strng_pos(  lcd_4bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column, const uint8_t * p_strng)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_4bit_send_custom_char_pos(  lcd_4bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column, const uint8_t _char[], uint8_t mem_pos)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
std_return lcd_8bit_init(  lcd_8bit_t *   p_lcd)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        uint8_t idx = 0;
        gpio_pin_direction_initialize(&(p_lcd->lcd_reg_select_pin));   
        gpio_pin_write_logic(&(p_lcd->lcd_reg_select_pin),p_lcd->lcd_reg_select_pin.logic);
        gpio_pin_direction_initialize(&(p_lcd->lcd_enable_pin));
        gpio_pin_write_logic(&(p_lcd->lcd_enable_pin),p_lcd->lcd_enable_pin.logic);
        for (idx=0; idx<8; idx++)
        {
            gpio_pin_direction_initialize(&(p_lcd->lcd_data_pin[idx]));   
            gpio_pin_write_logic(&(p_lcd->lcd_data_pin[idx]),p_lcd->lcd_data_pin[idx].logic);
        }
        
        /*INIT CONFIGURATION*/
        __delay_ms(20);
        lcd_8bit_send_cmd(p_lcd, LCD_8_BIT_MODE_2_LINE);
        __delay_ms(5);
        lcd_8bit_send_cmd(p_lcd, LCD_8_BIT_MODE_2_LINE);
        __delay_us(150);
        lcd_8bit_send_cmd(p_lcd, LCD_8_BIT_MODE_2_LINE);
        lcd_8bit_send_cmd(p_lcd, LCD_CLEAR);
        lcd_8bit_send_cmd(p_lcd, LCD_RETURN_HOME);
        lcd_8bit_send_cmd(p_lcd, LCD_ENTRY_MODE);
        lcd_8bit_send_cmd(p_lcd, LCD_CURSOR_OFF_DISPLAY_ON);
        lcd_8bit_send_cmd(p_lcd, LCD_8_BIT_MODE_2_LINE);
        lcd_8bit_send_cmd(p_lcd, LCD_DDRAMSTART_START);
    }
    
    return EXCUTION_OK;   
}
//------------------------------------------------------------------------------
std_return lcd_8bit_send_cmd(  lcd_8bit_t *   p_lcd, const uint8_t d_cmd)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        gpio_pin_write_logic(&(p_lcd->lcd_reg_select_pin),LOGIC_OFF);
        
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[0]),  ((d_cmd >> 0) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[1]),  ((d_cmd >> 1) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[2]),  ((d_cmd >> 2) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[3]),  ((d_cmd >> 3) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[4]),  ((d_cmd >> 4) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[5]),  ((d_cmd >> 5) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[6]),  ((d_cmd >> 6) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[7]),  ((d_cmd >> 7) & 0x01) );
        lcd_8bit_send_enable(p_lcd);
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_8bit_send_char(  lcd_8bit_t *   p_lcd, const uint8_t d_data)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        gpio_pin_write_logic(&(p_lcd->lcd_reg_select_pin),LOGIC_ON);
        
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[0]),  ((d_data >> 0) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[1]),  ((d_data >> 1) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[2]),  ((d_data >> 2) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[3]),  ((d_data >> 3) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[4]),  ((d_data >> 4) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[5]),  ((d_data >> 5) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[6]),  ((d_data >> 6) & 0x01) );
        gpio_pin_write_logic(&(p_lcd->lcd_data_pin[7]),  ((d_data >> 7) & 0x01) );
        lcd_8bit_send_enable(p_lcd);
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_8bit_send_char_pos(  lcd_8bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column,const uint8_t d_data)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        lcd_8bit_set_cursor(p_lcd, d_row, d_column);
        lcd_8bit_send_char(p_lcd, d_data);
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_8bit_send_strng(  lcd_8bit_t *   p_lcd, const uint8_t * p_strng)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        while( '\0' != *p_strng)
        {
        lcd_8bit_send_char(p_lcd, *p_strng);
        p_strng++;
        }
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_8bit_send_strng_pos(  lcd_8bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column, const uint8_t * p_strng)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        lcd_8bit_set_cursor(p_lcd, d_row, d_column);
        while( '\0' != *p_strng)
        {
        lcd_8bit_send_char(p_lcd, *p_strng);
        p_strng++;
        }
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_8bit_send_custom_char_pos(  lcd_8bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column, const uint8_t *_char, uint8_t mem_pos)
{
    if (NULL == p_lcd)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        lcd_8bit_send_cmd(  p_lcd, (LCD_CGRAM_START + mem_pos*8) );
        uint8_t idx=0;
        for(idx=0; idx<8; idx++)
        {
            lcd_8bit_send_char(  p_lcd, _char[idx]);
        }
        lcd_8bit_send_char_pos(  p_lcd, d_row, d_column, mem_pos );
//        lcd_8bit_send_char_pos(  p_lcd, d_row, d_column, 'X' );
    }
    
    return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
std_return convert_uint8_to_strng(uint8_t d_input, uint8_t * d_strng)
{
    if (NULL == d_strng)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        memset(d_strng, '\0', 4);
        sprintf(d_strng, "%i", d_input);
    }
 return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return convert_uint16_to_strng(uint16_t d_input, uint8_t * d_strng)
{
    if (NULL == d_strng)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        memset(d_strng, '\0', 6);
        sprintf(d_strng, "%u", d_input);
    }
 return EXCUTION_OK;     
}
//------------------------------------------------------------------------------
std_return convert_uint32_to_strng(uint32_t d_input, uint8_t * d_strng)
{
    if (NULL == d_strng)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        memset(d_strng, '\0', 11);
        sprintf(d_strng, "%u", d_input);
    }
 return EXCUTION_OK;    
}
//------------------------------------------------------------------------------
std_return lcd_4bit_set_cursor(  lcd_4bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column)
{
    lcd_4bit_send_cmd(p_lcd, LCD_DDRAMSTART_START);
    
    switch (d_row)
    {
        case (ROW1): lcd_4bit_send_cmd(p_lcd, (0x80+(d_column-1)) );      break;
        case (ROW2): lcd_4bit_send_cmd(p_lcd, (0x80+0x40+(d_column-1)) ); break;
        default    :                                                      break; 
    }
    return EXCUTION_OK;
}
//------------------------------------------------------------------------------
std_return lcd_8bit_set_cursor(  lcd_8bit_t *   p_lcd, const uint8_t d_row, const uint8_t d_column)
{
    lcd_8bit_send_cmd(p_lcd, LCD_DDRAMSTART_START);
    
    switch (d_row)
    {
        case (ROW1): lcd_8bit_send_cmd(p_lcd, (0x80+(d_column-1)) );      break;
        case (ROW2): lcd_8bit_send_cmd(p_lcd, (0x80+0x40+(d_column-1)) ); break;
        default    :                                                      break; 
    }
    return EXCUTION_OK;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
static std_return lcd_4bit_send_enable(  lcd_4bit_t *    p_lcd)
{
    gpio_pin_write_logic(&(p_lcd->lcd_enable_pin),LOGIC_ON);
    __delay_us(10);
    gpio_pin_write_logic(&(p_lcd->lcd_enable_pin),LOGIC_OFF);
     return EXCUTION_OK; 
}
//------------------------------------------------------------------------------
static std_return lcd_8bit_send_enable(  lcd_8bit_t *    p_lcd)
{
    gpio_pin_write_logic(&(p_lcd->lcd_enable_pin),LOGIC_ON);
    __delay_us(10);
    gpio_pin_write_logic(&(p_lcd->lcd_enable_pin),LOGIC_OFF);
     return EXCUTION_OK; 
}