/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: ADC           ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX       *((volatile u8*)0x27)   //ADC Multiplexer selection register

#define ADMUX_REFS1      7                  //Reference selection bit1
#define ADMUX_REFS0      6                  //Reference selection bit0
#define ADMUX_ADLAR      5                  //ADC left adjust result


#define ADCSRA      *((volatile u8*)0x26)    //ADC control and status register  

#define ADCSRA_ADEN      7                  //ADC Enable
#define ADCSRA_ADSC      6                  //ADC Start conversion
#define ADCSRA_ADATE     5                  //ADC Auto trigger enable
#define ADCSRA_ADIF      4                  //ADC Interrupt flag
#define ADCSRA_ADIE      3                  //ADC Interrupt enable
#define ADCSRA_ADPS2     2                  //ADC prescaler bit 2
#define ADCSRA_ADPS1     1                  //ADC prescaler bit 1
#define ADCSRA_ADPS0     0                  //ADC prescaler bit 0


#define ADCH        *((volatile u8*)0x25)   //ADC high register
#define ADCL        *((volatile u8*)0x24)   //ADC Low register


#endif