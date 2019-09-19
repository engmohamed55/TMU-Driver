/*
 * TMU.c
 *
 * Created: 2019-09-07 2:28:54 PM
 *  Author: AbdElkader-Mina
 */ 


#include "TMU.h"
#include "Timer.h"
#include <avr/interrupt.h>


volatile uint32 G_Tick=0;

extern Task Tasks[MaxTaskNo];

ISR(TIMER0_OVF_vect)
{
	G_Tick++;
	TCNT0=Res_One;
}




uint8 TMU_Init(uint8 persicion, uint8 Timer_ID)
{
	if(Timer_ID==0)
		{
			Timer_TMU(persicion);
		}
		
	else if(Timer_ID==1){}	

	else if(Timer_ID==2){}
		
	else
		{
			return NOT_OK;
		}
		return OK;
}


void TMU_Dispatcher(uint8 div)
{
		int i;
		for(i=0;i<MaxTaskNo;i++)
		{
			TMU_Start();
			if(Tasks[i].Start_Flag==1)
			{
				if(Tasks[i].Steps==G_Tick)
				{
					Tasks[i].Steps = (Tasks[i].Delay + G_Tick)/ div;
					Tasks[i].Call_Back();
					if(Tasks[i].Status==ONE_SHOT)
						{
							Tasks[i].Start_Flag=0;
						}
				}
			}
			
		}
}

void TMU_Start(void)
{
	Set_Bit(SREG,I);
	Timer_TMU_Start();
}

void TMU_Stop(uint8 ID)
{
	int i;
	for(i=0;i<MaxTaskNo;i++)
	{
		if(Tasks[i].Task_ID == ID)
		{
			Tasks[i].Start_Flag=0;
		}
	}
}
