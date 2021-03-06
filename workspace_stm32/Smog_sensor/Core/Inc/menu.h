/*
 * menu.h
 *
 *  Created on: 30 sie 2021
 *      Author: Programista
 */

#ifndef INC_MENU_H_
#define INC_MENU_H_

#include "stm32f0xx_hal.h"

#define FALSE   0
#define TRUE    (!FALSE)

uint8_t DrawSecondScreen(uint8_t input);
uint8_t DrawMainScreen(uint8_t input);
uint8_t StateMachine(uint8_t state, uint8_t stimuli);


// Menu state machine states
#define ST_MAIN_SCREEN                        10
#define ST_SECOND_SCREEN                    11



//Button definitions

#define KEY_NULL     (uint8_t)0
#define ENC_SW_ON    (uint8_t)4




typedef struct
{
    uint8_t state;
    uint8_t input;
    uint8_t nextstate;
} MENU_NEXTSTATE;


typedef struct
{
    uint8_t state;
    //char  *pText;
    uint8_t (*pFunc)(uint8_t input);
} MENU_STATE;


MENU_NEXTSTATE menu_nextstate[4];
MENU_STATE menu_state[3];






#endif /* INC_MENU_H_ */
