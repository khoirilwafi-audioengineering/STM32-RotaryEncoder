/* code program untuk interface rotary encoder */

#include "main.h"

static uint8_t Prev = 0;
static uint8_t Memo = 0;

int8_t read_encoder()
{
	static int8_t valid[] = {0,1,1,0,1,0,0,1,1,0,0,1,0,1,1,0};
	
	Prev <<= 2;
	
	if(HAL_GPIO_ReadPin(ENA_GPIO_Port, ENA_Pin) == 1){ Prev |= 0x02; }
	if(HAL_GPIO_ReadPin(ENB_GPIO_Port, ENB_Pin) == 1){ Prev |= 0x01; }
	
	Prev &= 0x0f;
	
	if(valid[Prev])
	{
    Memo <<= 4;
    Memo |= Prev;
    if((Memo & 0xff) == 0x2b){return -1;}
    if((Memo & 0xff) == 0x17){return  1;}
  }
	
   return 0;
}
