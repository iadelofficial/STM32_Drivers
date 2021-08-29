
 /****************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC_interface.h
 *
 * Description: Header file for the NVIC driver interface
 *
 * Author: Islam Adel
 *
 * Created on: Nov 11, 2020
 *
 *****************************************************************************/
#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

/*FUNCTIONS PROTOTYPES*/

 void				MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
 void		  	MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
 void 			MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
 void 			MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
 u8 				MNVIC_voidCGetActiveFlag(u8 Copy_u8IntNumber);
 void 			MNVIC_voidSetPriority(s8 Copy_s8IntID,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority,u32 Copy_u32Group);

/*********************************************************************************************/
/*MACROSE FOR 3BITS OF SCB tha SELECT THE GROUPS AND SUB_GROUPS */

/* OPTIONS FOE GROUP & SUB_GROUP PRIORITIES:*/


#define GROUP3					0X05FA0300/*ALL 4 BITS FOR GROUP IN PIR ***** so here you have 16 group priorities & 0 sub_group priorities  */
#define GROUP4					0X05FA0400/*    3 BITS FOR GROUP AND 1 BIT FOR SUB_GROUP IN PTR ***** so here you have 8 group priorities & 2 sub_group priorities  */
#define GROUP5 					0X05FA0500/*    2 BITS FOR GROUP AND 2 BIT FOR SUB_GROUP IN PTR ***** so here you have 4 group priorities & 4 sub_group priorities  */
#define GROUP6 					0X05FA0600/*    1 BITS FOR GROUP AND 3 BIT FOR SUB_GROUP IN PTR ***** so here you have 2 group priorities & 8 sub_group priorities  */
#define GROUP7  				0X05FA0700/*ALL 4 BITS FOR SUB_GROUP IN PIR ***** so here you have 0 group priorities & 16 sub_group priorities  */


#endif