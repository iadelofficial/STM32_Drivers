 /****************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO_private.h
 *
 * Description: Header file for the DIO driver privacy
 *
 * Author: Islam Adel
 *
 * Created on: Nov 3, 2020
 *
 *****************************************************************************/
#ifndef _DIO_PRIVATE_H
#define _DIO_PRIVATE_H

/*Register Definations */

#define GPIOA_BASE_ADDRESS 0x40010800 
/* BASE ADDRESS OFF PORT A = 0x40010800 */
/*so address any register in PORTA = base address of PORTA +offset value of that register */
/* use volatile keyword to prevent compiler from appling any optimizations on this variable*/
/*we use volatile with memory mapped hw peripheral register */

/*CRL IS THE 1TH REGISTER WITH OFFSET 0X00*/
#define GPIOA_CRL *((volatile uint32 *)(GPIOA_BASE_ADDRESS+0X00))

/*CRH IS THE 2TH REGISTER WITH OFFSET 0X04*/
#define GPIOA_CRH *((volatile uint32 *)(GPIOA_BASE_ADDRESS+0X04))
	
/*IDR IS THE 3TH REGISTER WITH OFFSET 0X08*/
#define GPIOA_IDR *((volatile uint32 *)(GPIOA_BASE_ADDRESS+0X08))
	
/*ODR IS THE 4TH REGISTER WITH OFFSET 0X0C*/
#define GPIOA_ODR *((volatile uint32 *)(GPIOA_BASE_ADDRESS+0X0C))
		
/*BSRR IS THE 5TH REGISTER WITH OFFSET 0X10*/
#define GPIOA_BSRR *((volatile uint32 *)(GPIOA_BASE_ADDRESS+0X10))
		
/*BRR IS THE 4TH REGISTER WITH OFFSET 0X14*/
#define GPIOA_BRR *((volatile uint32 *)(GPIOA_BASE_ADDRESS+0X14))
		
/*LCKR IS THE 4TH REGISTER WITH OFFSET 0X18*/
#define GPIOA_LCKR  *((volatile uint32 *)(GPIOA_BASE_ADDRESS+0X18))

/*******************************************************************************************************************/
/*******************************************************************************************************************/
#define GPIOB_BASE_ADDRESS 0x40010C00 
/* BASE ADDRESS OFF PORT B = 0x40010C00 */
/*so address any register in PORTB = base address of PORTB +offset value of that register */

/*CRL IS THE 1TH REGISTER WITH OFFSET 0X00*/
#define GPIOB_CRL *((volatile uint32 *)(GPIOB_BASE_ADDRESS+0X00))

/*CRH IS THE 2TH REGISTER WITH OFFSET 0X04*/
#define GPIOB_CRH *((volatile uint32 *)(GPIOB_BASE_ADDRESS+0X04))
	
/*IDR IS THE 3TH REGISTER WITH OFFSET 0X08*/
#define GPIOB_IDR *((volatile uint32 *)(GPIOB_BASE_ADDRESS+0X08))
	
/*ODR IS THE 4TH REGISTER WITH OFFSET 0X0C*/
#define GPIOB_ODR *((volatile uint32 *)(GPIOB_BASE_ADDRESS+0X0C))
		
/*BSRR IS THE 5TH REGISTER WITH OFFSET 0X10*/
#define GPIOB_BSRR *((volatile uint32 *)(GPIOB_BASE_ADDRESS+0X10))
		
/*BRR IS THE 4TH REGISTER WITH OFFSET 0X14*/
#define GPIOB_BRR *((volatile uint32 *)(GPIOB_BASE_ADDRESS+0X14))
		
/*LCKR IS THE 4TH REGISTER WITH OFFSET 0X18*/
#define GPIOB_LCKR  *((volatile uint32 *)(GPIOB_BASE_ADDRESS+0X18))
	
/*******************************************************************************************************************/
/*******************************************************************************************************************/
#define GPIOC_BASE_ADDRESS 0x40011000 
/* BASE ADDRESS OFF PORT C = 0x40011000 */
/*so address any register in PORTC = base address of PORTC +offset value of that register */

/*CRL IS THE 1TH REGISTER WITH OFFSET 0X00*/
#define GPIOC_CRL *((volatile uint32 *)(GPIOC_BASE_ADDRESS+0X00))


/*CRH IS THE 2TH REGISTER WITH OFFSET 0X04*/
#define GPIOC_CRH *((volatile uint32 *)(GPIOC_BASE_ADDRESS+0X04))
	
/*IDR IS THE 3TH REGISTER WITH OFFSET 0X08*/
#define GPIOC_IDR *((volatile uint32 *)(GPIOC_BASE_ADDRESS+0X08))
	
/*ODR IS THE 4TH REGISTER WITH OFFSET 0X0C*/
#define GPIOC_ODR *((volatile uint32 *)(GPIOC_BASE_ADDRESS+0X0C))
		
/*BSRR IS THE 5TH REGISTER WITH OFFSET 0X10*/
#define GPIOC_BSRR *((volatile uint32 *)(GPIOC_BASE_ADDRESS+0X10))
		
/*BRR IS THE 4TH REGISTER WITH OFFSET 0X14*/
#define GPIOC_BRR *((volatile uint32 *)(GPIOC_BASE_ADDRESS+0X14))
		
/*LCKR IS THE 4TH REGISTER WITH OFFSET 0X18*/
#define GPIOC_LCKR  *((volatile uint32 *)(GPIOC_BASE_ADDRESS+0X18))

#endif