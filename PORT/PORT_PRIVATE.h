/*************************************************************/
/*************       Author: Habeba Hamada    ****************/
/*************       LAYER: MCAL               ****************/
/*************       Component: PORT          ****************/
/*************       Version: 1.00            ****************/
/*************************************************************/

#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_

//for Direction
#define INIT_OUTPUT 1
#define INIT_INPUT  0

//for Output Configuration
#define INIT_LOW  0
#define INIT_HIGH 1

//for Input Configuration
#define INIT_PULL_UP   1
#define INIT_NORMAL_IN 0

#define  CONC(b7,b6,b5,b4,b3,b2,b1,b0)           CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define  CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0

#define   PORTA_DIR    CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define   PORTB_DIR    CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define   PORTC_DIR    CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define   PORTD_DIR    CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)


#define   PORTA_INITVAL    CONC(PORTA_PIN7_INITVAL,PORTA_PIN6_INITVAL,PORTA_PIN5_INITVAL,PORTA_PIN4_INITVAL,PORTA_PIN3_INITVAL,PORTA_PIN2_INITVAL,PORTA_PIN1_INITVAL,PORTA_PIN0_INITVAL)
#define   PORTB_INITVAL    CONC(PORTB_PIN7_INITVAL,PORTB_PIN6_INITVAL,PORTB_PIN5_INITVAL,PORTB_PIN4_INITVAL,PORTB_PIN3_INITVAL,PORTB_PIN2_INITVAL,PORTB_PIN1_INITVAL,PORTB_PIN0_INITVAL)
#define   PORTC_INITVAL    CONC(PORTC_PIN7_INITVAL,PORTC_PIN6_INITVAL,PORTC_PIN5_INITVAL,PORTC_PIN4_INITVAL,PORTC_PIN3_INITVAL,PORTC_PIN2_INITVAL,PORTC_PIN1_INITVAL,PORTC_PIN0_INITVAL)
#define   PORTD_INITVAL    CONC(PORTD_PIN7_INITVAL,PORTD_PIN6_INITVAL,PORTD_PIN5_INITVAL,PORTD_PIN4_INITVAL,PORTD_PIN3_INITVAL,PORTD_PIN2_INITVAL,PORTD_PIN1_INITVAL,PORTD_PIN0_INITVAL)

#endif