/*
 * TMU.h
 *
 * Created: 2019-09-07 2:28:44 PM
 *  Author: AbdElkader-Mina
 */ 


#ifndef TMU_H_
#define TMU_H_

#include "Timer.h"

#define OK 1
#define NOT_OK 0
#define PERIODIC 0
#define ONE_SHOT 1
#define MaxTaskNo 3

#define Task_0 0
#define Task_1 1


#define Timer0	0
#define Timer1	1


uint8 TMU_Init(uint8 persicion, uint8 Timer_ID);
void TMU_Start(void);
void TMU_Stop(uint8 Task_ID);
void TMU_Dispatcher(uint8 persicion);

typedef struct{
	uint8 Task_ID;
	uint16 Delay;
	uint8 (*Call_Back)(void);
	uint8 Start_Flag;
	uint8 Status;
	uint16 Steps;
	uint16 calc;
	}Task;


#endif /* TMU_H_ */
