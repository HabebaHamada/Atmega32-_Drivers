/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: HAL               ****************/
/*************       Component: CLCD          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "DIO_INTERFACE.h"

#include "LED_Interface.h"


void LED_ON(LED_Object Copy_LED,u8 Copy_u8LED_Status)
{
	DIO_u8WritePinValue(Copy_LED.LED_Pin, Copy_LED.LED_Port,(Copy_u8LED_Status) ^ (Copy_LED.Connection_Type));
	
}