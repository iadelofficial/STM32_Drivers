
 /****************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC_private.h
 *
 * Description: Header file for the NVIC driver privacy
 *
 * Author: Islam Adel
 *
 * Created on: Nov 11, 2020
 *
 *****************************************************************************/
#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATR_H

/*base address of NVIC peripheral=0xE000E100*/
/*ENABLE PERIPHERAL INTERRUPT */

#define NVIC_ISER0 								  *((u32*)0xE000E100 )/*enable external peripheral interruprt from 0 to 31*/
#define NVIC_ISER1  								*((u32*)0xE000E104 )/*enable  external peripheral interruprt from 32 to 59*/

/*DISABLE PERIPHERAL INTERRUPT */

#define NVIC_ICER0  								*((u32*)0xE000E180 )/*disable external peripheral interruprt from 0 to 31*/
#define NVIC_ICER1  								*((u32*)0xE000E184 )/*disable  external peripheral interruprt from 32 to 59*/

/*SET PENDING FLAG */

#define NVIC_ISPR0  								*((u32*)0xE000E200 )/*set pending flag external peripheral interruprt from 0 to 31*/
#define NVIC_ISPR1  								*((u32*)0xE000E204 )/*set pending flag external peripheral interruprt from 32 to 59*/

/*CLEAR PENDING FLAG */

#define NVIC_ICPR0  								*((u32*)0xE000E280 )/*clear pending flag external peripheral interruprt from 0 to 31*/
#define NVIC_ICPR1  								*((u32*)0xE000E284 )/*clear pending flag external peripheral interruprt from 32 to 59*/

/*ACTIVE FLAG REGISTER  *******READ ONLY ******* */

#define NVIC_IABR0  								*((volatile u32*)0xE000E300 )/* volatile because it is read only register  peripheral interruprt from 0 to 31*/
#define NVIC_IABR1  								*((volatile u32*)0xE000E304 )/* volatile because it is read only register peripheral interruprt from 32 to 59*/

/*INTERRUPT PRIORITY REGISTER */

#define NVIC_IPR  								  ((volatile u8 * )0xE000E400) /* u8 because that registers are byte accessible*/

/*base address for system control block peripheral=0xE000 ED00*/

#define SCB_AIRCR  								  *((volatile u32*)0xE000ED0C)

#endif