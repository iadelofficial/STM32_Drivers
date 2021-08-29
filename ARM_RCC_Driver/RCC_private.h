 /****************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_private.h
 *
 * Description: Header file for the RCC driver privacy
 *
 * Author: Islam Adel
 *
 * Created on: Nov 1, 2020
 *
 *****************************************************************************/
 
#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

/*Register Definations */
/*base address of RCC peripheral =0x40021000*/
/*so address any register in RCC = base address of Rcc +offset value of that register */
/*RCC_CR is the first register in RCC so his address = 0x40021000+0x00 */

#define RCC_CR *((volatile uint32 *)0x40021000)
	
/* use volatile keyword to prevent compiler from appling any optimizations on this variable*/
/*we use volatile with memory mapped hw peripheral register */
/*RCC_CFGR is the 2th register in RCC so his address = 0x40021000+0x04 */

#define RCC_CFGR *((volatile uint32 *)0x40021004)
	
/*RC & CFGR are responsible for choosing a clock for processor {HSI || HSE || PLL} */
	
/*RCC_CIR is the 3th register in RCC so his address = 0x40021000+0x08 */

#define RCC_CIT *((volatile uint32 *)0x40021008)
	
/*RCC_APB2RSTR is the 4th register in RCC so his address = 0x40021000+0x0C */

#define RCC_APB2RSTR *((volatile uint32 *)0x4002100C)
	
/*RCC_PB1RSTR is the 5th register in RCC so his address = 0x40021000+0x10 */

#define RCC_PB1RSTR *((volatile uint32 *)0x40021010)	
	
/*RCC_AHBENR is the 6th register in RCC so his address = 0x40021000+0x14 */

#define RCC_AHBENR *((volatile uint32 *)0x40021014)
	
/*RCC_APB2ENR is the 7th register in RCC so his address = 0x40021000+0x18 */

#define RCC_APB2ENR *((volatile uint32 *)0x40021018)	
	
/*RCC_APB1ENR is the 8th register in RCC so his address = 0x40021000+0x1C */

#define RCC_APB1ENR *((volatile uint32 *)0x4002101C)	
	
/* AHBENR & APB2ENR & APB1ENR are responsible for enable and disable clock of any peripherals */
	
/*RCC_BDCR is the 9th register in RCC so his address = 0x40021000+0x20 */

#define RCC_BDCR *((volatile uint32 *)0x40021020)
	
/*RCC_CSR is the 10th register in RCC so his address = 0x40021000+0x24 */

#define RCC_CSR *((volatile uint32 *)0x40021024)
	
/*CLOCK SYSTEM MACROS*/
#define RCC_HSE_CRYSTAL				0
#define RCC_HSE_RC						1
#define RCC_HSI								2
#define RCC_PLL								3

/*pll input macros*/
#define RCC_PLL_IN_HSI_DEV_2	5
#define RCC_PLL_IN_HSE_DEV_2	6
#define RCC_PLL_IN_HSE				7
	


#endif