/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GIE          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "STD_TYPES"
#include "BIT_Manipulation"

#include"GIE_register.h"
#include"GIE_interface.h"

void GIE_voidEnable(void)
{
	SET_BIT(Status_Register,SREG_I);
}
void GIE_voidDisable(void)
{
	CLEAR_BIT(Status_Register,SREG_I);
}