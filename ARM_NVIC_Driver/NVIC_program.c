
 /****************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC_program.c
 *
 * Description: Source file for the NVIC driver program
 *
 * Author: Islam Adel
 *
 * Created on: Nov 11, 2020
 *
 *****************************************************************************/
 #include "BIT_MATH.h"
 #include "STD_TYPES.h"
 
 #include "NVIC_interface.h"
 #include "NVIC_config.h"
 #include "NVIC_private.h"
 
 void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
 {
	 if(Copy_u8IntNumber>=0&&Copy_u8IntNumber<32)
	 {
		 NVIC_ISER0=(1<<Copy_u8IntNumber);/* put zero in bit has no effect */
	 }
	 else if (Copy_u8IntNumber<=59)
	 {
		 Copy_u8IntNumber-=32;
		 NVIC_ISER1=(1<<Copy_u8IntNumber);/* put zero in bit has no effect */
	 }
	 else 
	 {
		 /* return error !!!*/
	 }
 }
	 
 void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
 {
	 if(Copy_u8IntNumber>=0&&Copy_u8IntNumber<32)
	 {
		 NVIC_ICER0=(1<<Copy_u8IntNumber);/* put zero in bit has no effect */
	 }
	 else if (Copy_u8IntNumber<=59)
	 {
		 Copy_u8IntNumber-=32;
		 NVIC_ICER1=(1<<Copy_u8IntNumber);/* put zero in bit has no effect */
	 }
	 else 
	 {
		 /* return error !!!*/
	 }
 }
 void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
 {
	 if(Copy_u8IntNumber>=0&&Copy_u8IntNumber<32)
	 {
		 NVIC_ISPR0=(1<<Copy_u8IntNumber);/* put zero in bit has no effect */
	 }
	 else if (Copy_u8IntNumber<=59)
	 {
		 Copy_u8IntNumber-=32;
		 NVIC_ISPR1=(1<<Copy_u8IntNumber);/* put zero in bit has no effect */
	 }
	 else 
	 {
		 /* return error !!!*/
	 }
 }
 void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
 {
	 if(Copy_u8IntNumber>=0&&Copy_u8IntNumber<32)
	 {
		 NVIC_ICPR0=(1<<Copy_u8IntNumber);/* put zero in bit has no effect */
	 }
	 else if (Copy_u8IntNumber<=59)
	 {
		 Copy_u8IntNumber-=32;
		 NVIC_ICPR1=(1<<Copy_u8IntNumber);/* put zero in bit has no effect */
	 }
	 else 
	 {
		 /* return error !!!*/
	 }
 
 
 
 }
u8 MNVIC_voidCGetActiveFlag(u8 Copy_u8IntNumber)
 {
	 u8 Local_u8Result ;
	 if(Copy_u8IntNumber>=0&&Copy_u8IntNumber<32)
	 {
		 Local_u8Result=GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	 }
	 else if (Copy_u8IntNumber<=59)
	 {
		 Copy_u8IntNumber-=32;
		 Local_u8Result=GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	 }
	 else 
	 {
		 /* return error !!!*/
	 }
 
 return Local_u8Result;
 
 }
 void MNVIC_voidSetPriority(s8 Copy_s8IntID,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority,u32 Copy_u32Group)
 {
	 SCB_AIRCR=Copy_u32Group;
	 u8 Local_Priority =((Copy_u8SubGroupPriority | (Copy_u8GroupPriority<<((Copy_u32Group-0X05FA0300)/256)))<<4);
	 /*from the previouse line we creat the value of register that will put in the interruot register you want */ 
	 /*core peripheral */
	 	if (Copy_s8IntID<0)
	 
	 
	 /*external peripheral */
	  if(Copy_s8IntID>=0)
	 {
		 NVIC_IPR[Copy_s8IntID]=Local_Priority;
	 
	 }
 
 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 