 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_program.c
 *
 * Description: Source file for the RCC driver 
 *
 * Author: Islam Adel
 *
 * Created on: Nov 1, 2020
 *
 *****************************************************************************/
 #include "common_macros.h"
 #include "stdd_types.h"
 
 
 #include "RCC_interface.h"
 #include "RCC_private.h"
 #include "RCC_config.h"
 void RCC_VoidInitSystemClock(void);
 void RCC_VoidEnableClock(uint8 Copy_uint8BusId,uint8 Copy_uint8PerId);
void RCC_VoidDisableClock(uint8 Copy_uint8BusId,uint8 Copy_uint8PerId);
 
 
 /*initializaation system clock */
 
 void RCC_VoidInitSystemClock(void)
 {
	 #if (RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL)
	 /*code for initialize high speed external crystal clock  RCC_HSE_CRYSTAL */
			RCC_CR   =0X00010000;/*ENABLE HSE BIT & CTRYSTAL MODE "WITH NO bypass"*/
			RCC_CFGR = 0X00000001;

	 #elif(RCC_CLOCK_TYPE==RCC_HSE_RC)
	 /*code for initialize high speed external RC clock  RCC_HSE_RC */
			RCC_CR   =0X00050000;/*ENABLE HSE BIT &RC MODE "WITH bypass" */
			RCC_CFGR = 0X00000001;
	
	 #elif(RCC_CLOCK_TYPE==RCC_HSI)
	 /*code for initialize high speed internal clock RCC_HSI*/
			RCC_CR=0X00000081;/*ENABLE HSI BIT & adjust trimming value =0 */
			RCC_CFGR = 0X00000000;
	
	 #elif(RCC_CLOCK_TYPE==RCC_PLL)
				/*code for RCC_PLL */
			/* chose the prescaler of PLL before enable pll */
			switch(RCC_PLL_MUL_VAL)
			{
			case 2 : RCC_CFGR =0x00000000; break;
			case 3 : RCC_CFGR =0x00040000; break;
			case 4 : RCC_CFGR =0x00080000; break;
			case 5 : RCC_CFGR =0x000C0000; break;
			case 6 : RCC_CFGR =0x00100000; break;
			case 7 : RCC_CFGR =0x00140000; break;
			case 8 : RCC_CFGR =0x00180000; break;
			case 9 : RCC_CFGR =0x001C0000; break;
			case 10: RCC_CFGR =0x00200000; break;
			case 11: RCC_CFGR =0x00240000; break;
			case 12: RCC_CFGR =0x00280000; break;
			case 13: RCC_CFGR =0x002C0000; break;
			case 14: RCC_CFGR =0x00300000; break;
			case 15: RCC_CFGR =0x00340000; break;
			case 16: RCC_CFGR =0x00380000; break;
			/*default return error */

			}

				#if   ( RCC_PLL_INPUT ==RCC_PLL_IN_HSI_DEV_2)
					RCC_CR=0X01000081;/*ENABLE HSI BIT & adjust trimming value =0 & enable PLL*/
					/* enter the internal clock divided by 2 with prescaler that you choose*/

				#elif (RCC_PLL_INPUT ==RCC_PLL_IN_HSE_CRYSTAL_DEV_2)
					RCC_CR   =0X01010000;/*ENABLE HSE BIT & CTRYSTAL MODE "WITH NO bypass &enable PLL"*/
					RCC_CFGR |=0x00030002;/* enter the external crystal clock divided by 2 with prescaler that you choose */
	 
				#elif (RCC_PLL_INPUT ==RCC_PLL_IN_CRYSTAL_HSE)
					RCC_CR   =0X01010000;/*ENABLE HSE BIT & CTRYSTAL MODE "WITH NO bypass &enable PLL "*/
					RCC_CFGR |=0x00010002;/* enter the external crystal clock  with prescaler that you choose */

				#elif (RCC_PLL_INPUT ==RCC_PLL_IN_HSE_RC_DEV_2)
					RCC_CR   =0X01050000;/*ENABLE HSE BIT &RC MODE "WITH bypass &enable PLL " */
					RCC_CFGR |=0x00030002;/* enter the external RC clock divided by 2 with prescaler that you choose */

				#elif (RCC_PLL_INPUT ==RCC_PLL_IN_RC_HSE)
					RCC_CR   =0X01050000;/*ENABLE HSE BIT &RC MODE "WITH bypass &enable PLL" */
					RCC_CFGR |=0x00010002;/* enter the external RC clock  with prescaler that you choose */


				#else 
							#error ("you chosed  wrong PLL INPUT !!")
				#endif 			
 
 #endif
 }
 
  /* function to enable clock of a specific peripheral on specific bus */
 
 void RCC_VoidEnableClock(uint8 Copy_uint8BusId,uint8 Copy_uint8PerId)
 {
	 /* peripheral id must be less than 32 because any register is 32 bits*/
	 
	 if (Copy_uint8PerId<=31)
	 {
		 switch (Copy_uint8BusId)
		 {
			 case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_uint8PerId);
													break;
			 case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_uint8PerId);
													break ;
			 case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_uint8PerId);
													break ;
			// default       :  /* retuen ERROR !!  */
				//									break;
	
		 }
	 
	 }
	 else 
	 {
		 /* Return an ERROR !!!*/
		 
	 }
	 
	 /* function to disable clock of a specific peripheral on specific bus */
 }
void RCC_VoidDisableClock(uint8 Copy_uint8BusId,uint8 Copy_uint8PerId)


	 /* peripheral id must be less than 32 because any register is 32 bits*/
{	 
	 if (Copy_uint8PerId<=31)
	 {
		 switch (Copy_uint8BusId)
		 {
			 case RCC_AHB  : CLEAR_BIT(RCC_AHBENR,Copy_uint8PerId);
													break;
			 case RCC_APB1 : CLEAR_BIT(RCC_APB1ENR,Copy_uint8PerId);
													break ;
			 case RCC_APB2 : CLEAR_BIT(RCC_APB2ENR,Copy_uint8PerId);
													break ;
			default       :  /* retuen ERROR !!  */
												break;
	
		 }
	 
	 }
	 else 
	 {
		 /* Return an ERROR !!!*/
		 
	 }
 
 
}

