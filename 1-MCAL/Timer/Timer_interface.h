/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: Timer           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidInit();

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));


#endif
