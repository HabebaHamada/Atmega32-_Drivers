/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: ADC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef struct
{
	u8* Channel;
	u16* Result;
	u8 chain_Size;
	void (*NotificationFunc)(void);
	
	
}Chain_t;

void ADC_voidInit(void);

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel ,u8* Copy_u8Reading);

u8 ADC_u8StartConversionSAsynch(u8 Copy_u8Channel ,u8* Copy_u8Reading ,void(*Copy_pvNotificationFunc)(void));

u8 ADC_u8StartChainAsynch(Chain_t *Copy_Chain);



#endif