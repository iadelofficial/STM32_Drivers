 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_config.h
 *
 * Description: Header file for the RCC driver confgiration
 *
 * Author: Islam Adel
 *
 * Created on: Nov 1, 2020
 *
 *****************************************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/*OPTIONS:   			RCC_HSE_CRYSTAL
									RCC_HSE_RC
									RCC_HSI
									RCC_PLL
									*/
									
#define RCC_CLOCK_TYPE 			RCC_HSE_CRYSTAL

/*IF YOU CHODE INPUT CLOCK SOURCE AS PLL*/ 
#if (RCC_CLOCK_TYPE == RCC_PLL)
/*OPTIONS:				RCC_PLL_IN_HSI_DEV_2
									RCC_PLL_IN_HSE_CRYSTAL_DEV_2
									RCC_PLL_IN_HSE_CRYSTAL_
									RCC_PLL_IN_HSE_RC_DEV_2
									RCC_PLL_IN_HSE_RC
									*/
#define RCC_PLL_INPUT  			RCC_PLL_IN_HSE_RC_DEV_2

/*OPTIONS : FROM 2 TO -> 16*/

#define RCC_PLL_MUL_VAL			4
#endif




#endif
