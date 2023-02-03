/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: GIE          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

#define Status_Register   SREG
#define  SREG    *((volatile u8*)0x5F)

//Global Interrupt Enable
#define  SREG_I     7

#endif