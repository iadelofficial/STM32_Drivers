 /****************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO_program.c
 *
 * Description: source file for the DIO driver program
 *
 * Author: Islam Adel
 *
 * Created on: Nov 3, 2020
 *
 *****************************************************************************/
 #include "BIT_MATH.h"
 #include "STD_TYPES.h"
 
 #include "DIO_interface.h"
 #include "DIO_config.h"
 #include "DIO_private.h"
 
 
void MGPIO_voidSetPinDirection(u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Mode )
{
	if(copy_u8PIN<=7)
	{
		/* you will work with low register */
	switch (copy_u8PORT)
	{
		case GPIOA :GPIOA_CRL &=~((0b1111)<<copy_u8PIN *4);
								GPIOA_CRL |=((copy_u8Mode)<<copy_u8PIN *4);break ;
		
	  case GPIOB :GPIOB_CRL &=~((0b1111)<<copy_u8PIN *4);
								GPIOB_CRL |=((copy_u8Mode)<<copy_u8PIN *4);break ;
		
		case GPIOC :GPIOC_CRL &=~((0b1111)<<copy_u8PIN *4);
								GPIOC_CRL |=((copy_u8Mode)<<copy_u8PIN *4);break ;
		//default :ERROR
	}
}
	elseif(15>copy_u8PIN>7)
	{
	/* you will work with high register */
	copy_u8PIN-=8;
		switch (copy_u8PORT)
	{
		case GPIOA :GPIOA_CRH &=~((0b1111)<<copy_u8PIN *4);
								GPIOA_CRH |=((copy_u8Mode)<<copy_u8PIN *4);break ;
		
	  case GPIOB :GPIOB_CRH &=~((0b1111)<<copy_u8PIN *4);
								GPIOB_CRH |=((copy_u8Mode)<<copy_u8PIN *4);break ;
		
		case GPIOC :GPIOC_CRH &=~((0b1111)<<copy_u8PIN *4);
								GPIOC_CRH |=((copy_u8Mode)<<copy_u8PIN *4);break ;
		//default:ERROR
	}
}
	else 
		//	#error "the number of pin must be between 0&15 !!" ;
	
}
/***************************************************************************************************************************/
	
void MGPIO_voidSetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Value )
{
	if (copy_u8Value== HIGH)
	{
	switch (copy_u8PORT)
	{
				case GPIOA :SET_BIT(GPIOA_ODR,copy_u8PIN);
								break ;
		
	  case GPIOB :SET_BIT(GPIOB_ODR,copy_u8PIN);
								break ;
		
		case GPIOC :SET_BIT(GPIOC_ODR,copy_u8PIN);
								break ;
	//default : error 
	
	}
}
	elseif(copy_u8Value== LOW)
{
		switch (copy_u8PORT)
	{
				case GPIOA :CLR_BIT(GPIOA_ODR,copy_u8PIN);
								break ;
		
	  case GPIOB :CLR_BIT(GPIOB_ODR,copy_u8PIN);
								break ;
		
		case GPIOC :CLR_BIT(GPIOC_ODR,copy_u8PIN);
								break ;
		//default : error 
	
	}

}
}
/****************************************************************************************************************/
u8 MGPIO_u8GetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN )
{
	switch (copy_u8PORT)
	{
				case GPIOA :return (GET_BIT(GPIOA_IDR,copy_u8PIN));
								break ;
		
	  case GPIOB :return (GET_BIT(GPIOB_IDR,copy_u8PIN));
								break ;
		
		case GPIOC :return (GET_BIT(GPIOB_IDR,copy_u8PIN));
								break ;
		//default : error 
	
	}

}