/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: Timer           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


#define TCCR0             *((volatile u8*)0x53)

#define TCCR0_WGM00       6
#define TCCR0_WGM00       3				         
#define TCCR0_CS02        2
#define TCCR0_CS01        1
#define TCCR0_CS00        0

#define OCR0              *((volatile u8*)0x5c)

#define TIMSK             *((volatile u8*)0x59)
#define TIMSK_OCIE0       1

#endif
