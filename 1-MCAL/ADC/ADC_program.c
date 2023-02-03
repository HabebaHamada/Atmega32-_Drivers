/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: ADC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/


#include"STD_TYPES.h"
#include"BIT_Manipulation.h"
#include"ADC_register.h"
#include"ADC_private.h"
#include"ADC_config.h"
#include"ADC_interface.h"


static u8* ADC_pu8Reading=NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;

void ADC_voidInit(void)
{
	/*Reference Voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLEAR_BIT(ADMUX,ADMUX_REFS1);
	
	/*Activate Left adjust result*/
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*Set Prescaler*/
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	
	/*ADC Enable Peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	/*Clear the Mux bits in ADMUX register*/
	ADMUX &= 0b11100000;
	
	/*Set the Required channel into the Mux bits*/
	ADMUX |= Copy_u8Channel;
	
	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	
	/*Polling until the conversion complete flag is set*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	
	/*Clear the conversion complete flag by writing One to it*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	
	/*Return the reading*/
	return ADCH;
}
u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel ,u8* Copy_u8Reading)
{
	u32 Local_u32Counter=0;
	u8  Local_u8ErrorState=OK;
	
	/*Clear the Mux bits in ADMUX register*/
	ADMUX &= 0b11100000;
	
	/*Set the Required channel into the Mux bits*/
	ADMUX |= Copy_u8Channel;
	
	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	
	while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)&&(Local_u32Counter!=ADC_u32TIMEOUT))
	{
		Local_u32Counter++;	
	}
	
	if (Local_u32Counter==ADC_u32TIMEOUT)
	{
		//Loop is broken because timeout is reached
		Local_u8ErrorState=NOK
	} 
	else
	{
		//Loop is broken because flag is raised
		/*Clear the conversion complete flag by writing One to it*/
		SET_BIT(ADCSRA,ADCSRA_ADIF);
		
		/*Return the reading*/
		
       Copy_u8Reading=ADCH;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionSAsynch(u8 Copy_u8Channel ,u8* Copy_u8Reading ,void(*Copy_pvNotificationFunc)(void))
{
	u8  Local_u8ErrorState=OK;
	if((Copy_u8Reading==NULL)||(Copy_pvNotificationFunc==NULL))
	{
		Local_u8ErrorState=NULL;
		
	}
	else
	{
		ADC_pu8Reading=Copy_u8Reading;
		ADC_pvCallBackNotificationFunc= Copy_pvNotificationFunc;
		
		/*Clear the Mux bits in ADMUX register*/
		ADMUX &= 0b11100000;
		
		/*Set the Required channel into the Mux bits*/
		ADMUX |= Copy_u8Channel;
		
		/*Start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		
		/*ADC Interrupt enable*/
		SET_BIT(ADCSRA,ADCSRA_ADIE);

	}
	return Local_u8ErrorState;

}

u8 ADC_u8StartChainAsynch(Chain_t *Copy_Chain)
{
	u8  Local_u8ErrorState=OK;
	if (Copy_Chain==NULL)    /*Check NULL pointer*/
	{
		Local_u8ErrorState=NULL;
	} 
	else
	{
	}
	
	
	return Local_u8ErrorState;
}


void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	/*Read ADC result*/
	*ADC_pu8Reading=ADCH;
	
	/*Invoke the callback Notification function*/
	ADC_pvCallBackNotificationFunc();
}

s32 map(s32 Input);  //Mapping function

void DAC_voidSetAnalogVolt(u8 Copy_u8Volt,u8 Copy_u8Port);