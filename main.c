/*
 * TMU.c
 *
 * Created: 2019-09-07 2:17:32 PM
 * Author : AbdElkader-Mina
 */ 
#include "TMU.h"
#include <util/delay.h>


void TEST(void)
{
	PORTB ^= (1<<4);
}

void Toggle(void)
{
	PORTB ^= (1<<5);

}
void abdlkader(void)
{
	PORTB ^= (1<<6);

}


Task Tasks[MaxTaskNo]={
	{0,500,TEST,1,PERIODIC,0,0},{1,1000,Toggle,1,PERIODIC,0,0},{1,2000,abdlkader,1,PERIODIC,0,0}
};


int main(void)
{
	DIO_SetPinDirection(PIN12,OUT);
	DIO_SetPinDirection(PIN14,OUT);
	DIO_SetPinDirection(PIN13,OUT);
	DIO_SetPinDirection(PIN10,IN);
	DIO_SetPinDirection(PIN20,IN);
	Set_Bit(SREG,I);
	TMU_Init(Res_One,Timer0);
	TMU_Start();
    while (1) 
    {

    	TMU_Dispatcher(1);
		if(DIO_ReadPin(PIN10))
		{
			Tasks[0].Start_Flag=1;

		}
		

		if(DIO_ReadPin(PIN20))
		{
			Tasks[1].Start_Flag=1;
		}


    }
}

