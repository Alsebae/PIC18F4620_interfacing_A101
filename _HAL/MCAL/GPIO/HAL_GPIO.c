/* 
 * File:   HAL_GPIO.c
 * Author: Abdulrahman
 *
 * Created on November 26, 2023, 4:16 PM
 */

/* lib includes START */
/* lib includes END */

/* includes START */
#include "HAL_GPIO.h"
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

//___________________________________________________________________________
/**
 * @brief  : A function to set a single bit in a one byte variable.
 * @param  : p_byte       : Address of the byte of interest. 
 * @param  : d_MASK_BIT_X : Mask of the bit to be set. @ref:MASK_BIT_X_t.
 * @return : std_return   : EXCUTION_OK or EXCUTION_NOT_OK.
 */
std_return set_bit_uint8(REGISTER_t * p_reg, IDX_BIT_X_t d_IDX_BIT_X){
    
    if (NULL == p_reg){
        return EXCUTION_NOT_OK;
    }
    else{
        switch(d_IDX_BIT_X)
        {
            case(IDX_BIT_0):
                *p_reg |= (MASK_BIT_0);
                break;
            case(IDX_BIT_1):
                *p_reg |= (MASK_BIT_1);
                break;
            case(IDX_BIT_2):
                *p_reg |= (MASK_BIT_2);
                break;
            case(IDX_BIT_3):
                *p_reg |= (MASK_BIT_3);
                break;
            case(IDX_BIT_4):
                *p_reg |= (MASK_BIT_4);
                break;
            case(IDX_BIT_5):
                *p_reg |= (MASK_BIT_5);
                break;
            case(IDX_BIT_6):
                *p_reg |= (MASK_BIT_6);
                break;
            case(IDX_BIT_7):
                *p_reg |= (MASK_BIT_7);
                break;
            default:
                return EXCUTION_NOT_OK;
                break;
        }
    }
    return EXCUTION_OK;
}		
//___________________________________________________________________________
/**
 * @brief  : A function to clear a single bit in a one byte variable.
 * @param  : p_byte       : Address of the byte of interest. 
 * @param  : d_MASK_BIT_X : Mask of the bit to be set. @ref:MASK_BIT_X_t.
 * @return : std_return   : EXCUTION_OK or EXCUTION_NOT_OK.
 */
std_return clear_bit_uint8(REGISTER_t * p_reg, IDX_BIT_X_t d_IDX_BIT_X){
    
     if (NULL == p_reg){
        return EXCUTION_NOT_OK;
    }
    else{
        switch(d_IDX_BIT_X)
        {
            case(0):
                *p_reg &= ~(MASK_BIT_0);
                break;
            case(1):
                *p_reg &= ~(MASK_BIT_1);
                break;
            case(2):
                *p_reg &= ~(MASK_BIT_2);
                break;
            case(IDX_BIT_3):
                *p_reg &= ~(MASK_BIT_3);
                break;
            case(IDX_BIT_4):
                *p_reg &= ~(MASK_BIT_4);
                break;
            case(IDX_BIT_5):
                *p_reg &= ~(MASK_BIT_5);
                break;
            case(IDX_BIT_6):
                *p_reg &= ~(MASK_BIT_6);
                break;
            case(IDX_BIT_7):
                *p_reg &= ~(MASK_BIT_7);
                break;
            default:
                return EXCUTION_NOT_OK;
                break;
        }
    }
    return EXCUTION_OK;
}
//___________________________________________________________________________
/**
 * @brief  : A function to toggle a single bit in a one byte variable.
 * @param  : p_byte       : Address of the byte of interest. 
 * @param  : d_MASK_BIT_X : Mask of the bit to be set. @ref:MASK_BIT_X_t.
 * @return : std_return   : EXCUTION_OK or EXCUTION_NOT_OK.
 */
std_return toggle_bit_uint8(REGISTER_t * p_reg, IDX_BIT_X_t d_IDX_BIT_X){
    
    if (NULL == p_reg){
        return EXCUTION_NOT_OK;
    }
    else{
        switch(d_IDX_BIT_X)
        {
            case(IDX_BIT_0):
                *p_reg ^= (MASK_BIT_0);
                break;
            case(IDX_BIT_1):
                *p_reg ^= (MASK_BIT_1);
                break;
            case(IDX_BIT_2):
                *p_reg ^= (MASK_BIT_2);
                break;
            case(IDX_BIT_3):
                *p_reg ^= (MASK_BIT_3);
                break;
            case(IDX_BIT_4):
                *p_reg ^= (MASK_BIT_4);
                break;
            case(IDX_BIT_5):
                *p_reg ^= (MASK_BIT_5);
                break;
            case(IDX_BIT_6):
                *p_reg ^= (MASK_BIT_6);
                break;
            case(IDX_BIT_7):
                *p_reg ^= (MASK_BIT_7);
                break;
            default:
                return EXCUTION_NOT_OK;
                break;
        }
    }
    return EXCUTION_OK;
}
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_pin_direction_initialize(const pin_config_t * p_pin_config){
    
    if((NULL == p_pin_config) || (p_pin_config->port > PORT_MAX_NUM-1)){
        return EXCUTION_NOT_OK;
    }
    else{
        switch(p_pin_config->direction)
        {
           case(DIRECTION_OUTPUT):
               clear_bit_uint8(TRIS_REG_ADD_arr[p_pin_config->port], (IDX_BIT_X_t)p_pin_config->pin_num);
               break;
           
           case(DIRECTION_INPUT):
               set_bit_uint8(TRIS_REG_ADD_arr[p_pin_config->port], (IDX_BIT_X_t)p_pin_config->pin_num);
               break;
           
           default:
               return EXCUTION_NOT_OK;
               break;
           
        }   
    }
    return EXCUTION_OK;
}		
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_pin_write_logic(       pin_config_t * p_pin_config,
                                 const LOGIC_t        d_logic_desired)
{
    if((NULL == p_pin_config) ||
       (p_pin_config->port > PORT_MAX_NUM-1) ||
       ((d_logic_desired != LOGIC_ON) && (d_logic_desired != LOGIC_OFF)))
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        switch(d_logic_desired)
        {
           case(LOGIC_ON):
               p_pin_config->logic = d_logic_desired;
               set_bit_uint8(LAT_REG_ADD_arr[p_pin_config->port], (IDX_BIT_X_t)p_pin_config->pin_num);
               break;
           
           case(LOGIC_OFF):
               p_pin_config->logic = d_logic_desired;
               clear_bit_uint8(LAT_REG_ADD_arr[p_pin_config->port], (IDX_BIT_X_t)p_pin_config->pin_num);
               break;
           
           default:
               return EXCUTION_NOT_OK;
               break;
           
        }   
    }
    return EXCUTION_OK;
}	
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_pin_get_direction_status(pin_config_t * p_pin_config,
                                         DIRECTION_t * p_direction)
{
    MASK_BIT_X_t bit_mask = 0b00000000;
    
    if(NULL == p_pin_config)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        switch(p_pin_config->pin_num)
        {
            case(IDX_BIT_0):
                bit_mask = MASK_BIT_0;
                break;
            case(IDX_BIT_1):
                bit_mask = MASK_BIT_1;
                break;
            case(IDX_BIT_2):
                bit_mask = MASK_BIT_2;
                break;
            case(IDX_BIT_3):
                bit_mask = MASK_BIT_3;
                break;
            case(IDX_BIT_4):
                bit_mask = MASK_BIT_4;
                break;
            case(IDX_BIT_5):
                bit_mask = MASK_BIT_5;
                break;
            case(IDX_BIT_6):
                bit_mask = MASK_BIT_6;
                break;
            case(IDX_BIT_7):
                bit_mask = MASK_BIT_7;
                break;
            default:
                return EXCUTION_NOT_OK;
                break;
        }
        
        *p_direction = ((*(TRIS_REG_ADD_arr[p_pin_config->port]) & bit_mask) == bit_mask);
    }
    return EXCUTION_OK;
}
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_pin_initialize(pin_config_t * p_pin_config)
{
    
    
    if(NULL == p_pin_config)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        switch(p_pin_config->direction)
        {
            case(DIRECTION_INPUT):
                gpio_pin_direction_initialize(p_pin_config);
                break;
            case(DIRECTION_OUTPUT):
                gpio_pin_direction_initialize(p_pin_config);
                gpio_pin_write_logic(p_pin_config,p_pin_config->logic);
                break;
            default:
                return EXCUTION_NOT_OK;
                break;
        }
    }
    return EXCUTION_OK;
}
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_pin_read_logic(const pin_config_t * p_pin_config,
                                     LOGIC_t      * p_logic)
{
    MASK_BIT_X_t bit_mask = 0b00000000;
    
    if(NULL == p_pin_config)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        {
        switch(p_pin_config->pin_num)
        {
            case(IDX_BIT_0):
                bit_mask = MASK_BIT_0;
                break;
            case(IDX_BIT_1):
                bit_mask = MASK_BIT_1;
                break;
            case(IDX_BIT_2):
                bit_mask = MASK_BIT_2;
                break;
            case(IDX_BIT_3):
                bit_mask = MASK_BIT_3;
                break;
            case(IDX_BIT_4):
                bit_mask = MASK_BIT_4;
                break;
            case(IDX_BIT_5):
                bit_mask = MASK_BIT_5;
                break;
            case(IDX_BIT_6):
                bit_mask = MASK_BIT_6;
                break;
            case(IDX_BIT_7):
                bit_mask = MASK_BIT_7;
                break;
            default:
                return EXCUTION_NOT_OK;
                break;
        }
        
        *p_logic = ((*(PORT_REG_ADD_arr[p_pin_config->port]) & bit_mask) == bit_mask);
    }
    }
    return EXCUTION_OK;
}
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_pin_toggle_logic(pin_config_t * p_pin_config)
{
    MASK_BIT_X_t bit_mask = 0b00000000;
    
    if(NULL == p_pin_config)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
        {
        switch(p_pin_config->pin_num)
        {
            case(IDX_BIT_0):
                bit_mask = MASK_BIT_0;
                break;
            case(IDX_BIT_1):
                bit_mask = MASK_BIT_1;
                break;
            case(IDX_BIT_2):
                bit_mask = MASK_BIT_2;
                break;
            case(IDX_BIT_3):
                bit_mask = MASK_BIT_3;
                break;
            case(IDX_BIT_4):
                bit_mask = MASK_BIT_4;
                break;
            case(IDX_BIT_5):
                bit_mask = MASK_BIT_5;
                break;
            case(IDX_BIT_6):
                bit_mask = MASK_BIT_6;
                break;
            case(IDX_BIT_7):
                bit_mask = MASK_BIT_7;
                break;
            default:
                return EXCUTION_NOT_OK;
                break;
        }
        
        *(LAT_REG_ADD_arr[p_pin_config->port]) ^= bit_mask;
        if (((*(LAT_REG_ADD_arr[p_pin_config->port]) & bit_mask) == bit_mask))
            p_pin_config->logic = LOGIC_ON;
        else if(((*(LAT_REG_ADD_arr[p_pin_config->port]) & bit_mask) == 0b00000000))
            p_pin_config->logic = LOGIC_ON;
        else
            return EXCUTION_NOT_OK;
    }
    }
    return EXCUTION_OK;
}

//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_port_direction_initialize(IDX_PORT_X_t p_port_idx, uint8_t d_port_direction_mask)
{
    *(TRIS_REG_ADD_arr[p_port_idx]) = d_port_direction_mask;
    return EXCUTION_OK;
}
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_port_get_direction_status(IDX_PORT_X_t p_port_idx, uint8_t * p_port_direction)
{
    if(NULL == p_port_direction)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
    *p_port_direction = *(TRIS_REG_ADD_arr[p_port_idx]);    
    }
    
    return EXCUTION_OK;
}
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_port_write_logic(IDX_PORT_X_t p_port_idx, uint8_t d_port_logic)
{
    *(LAT_REG_ADD_arr[p_port_idx]) = d_port_logic;
    
    return EXCUTION_OK;
}
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_port_read_logic(IDX_PORT_X_t p_port_idx, uint8_t * p_port_logic)
{
    if(NULL == p_port_logic)
    {
        return EXCUTION_NOT_OK;
    }
    else
    {
    *p_port_logic = *(LAT_REG_ADD_arr[p_port_idx]);    
    }
    
    return EXCUTION_OK;
}
//___________________________________________________________________________
/**
 * 
 * @param p_pin_config
 * @return 
 */
std_return gpio_port_toggle_logic(IDX_PORT_X_t p_port_idx)
{
    *(LAT_REG_ADD_arr[p_port_idx]) ^= 0b11111111;    
    return EXCUTION_OK;
}

/* Code END */




