/* 
 * File:   MCAL_std_types.h
 * Author: Abdulrahman
 *
 * Created on November 26, 2023, 5:40 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* lib includes START */
/* lib includes END */

/* includes START */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"
/* includes END */

/* Defines START */
#define PORT_MASK 0b11111111

typedef enum
{
    CODE_DISABLED = 0,
    CODE_ENABLED  = 1
}CODE_t;

typedef enum{
    EXCUTION_OK     = 0,
    EXCUTION_NOT_OK = 1
}EXCUTION_t;

typedef EXCUTION_t std_return;

typedef enum{
    FALSE = 0,
    TRUE  = 1
}bool_t;

typedef enum{
    LOW  = 0,
    HIGH = 1
}DIGITAL_t;

typedef enum{
    DIRECTION_OUTPUT = 0,
    DIRECTION_INPUT  = 1
}DIRECTION_t;

typedef enum{
    LOGIC_OFF = 0,
    LOGIC_ON  = 1
}LOGIC_t;

typedef enum{
    MASK_BIT_0 = 0b00000001,
    MASK_BIT_1 = 0b00000010,
    MASK_BIT_2 = 0b00000100,
    MASK_BIT_3 = 0b00001000,
    MASK_BIT_4 = 0b00010000,
    MASK_BIT_5 = 0b00100000,
    MASK_BIT_6 = 0b01000000,
    MASK_BIT_7 = 0b10000000
}MASK_BIT_X_t;

typedef enum{
    IDX_BIT_0   = 0,
    IDX_BIT_1   = 1,
    IDX_BIT_2   = 2,
    IDX_BIT_3   = 3,
    IDX_BIT_4   = 4,
    IDX_BIT_5   = 5,
    IDX_BIT_6   = 6,
    IDX_BIT_7   = 7,
    BIT_MAX_NUM = 8
}IDX_BIT_X_t;

typedef enum{
    IDX_PIN_0   = 0,
    IDX_PIN_1   = 1,
    IDX_PIN_2   = 2,
    IDX_PIN_3   = 3,
    IDX_PIN_4   = 4,
    IDX_PIN_5   = 5,
    IDX_PIN_6   = 6,
    IDX_PIN_7   = 7,
    PIN_MAX_NUM = 8
}IDX_PIN_X_t;

typedef enum{
    IDX_PORT_A   = 0,
    IDX_PORT_B   = 1,
    IDX_PORT_C   = 2,
    IDX_PORT_D   = 3,
    IDX_PORT_E   = 4,
    PORT_MAX_NUM = 5
}IDX_PORT_X_t;

typedef volatile uint8_t REGISTER_t;
REGISTER_t * TRIS_REG_ADD_arr[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
REGISTER_t * PORT_REG_ADD_arr[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
REGISTER_t * LAT_REG_ADD_arr [] = {&LATA, &LATB, &LATC, &LATD, &LATE};
/* Defines END */

/* Macros START */
/* Macros END */

/* Global Variables START */
/* Global Variables END */

/* Function Prototypes START */
/* Function Prototypes END */

/* Public Function Definitions START */
/* Public Function Definitions END */

#endif	/* MCAL_STD_TYPES_H */
