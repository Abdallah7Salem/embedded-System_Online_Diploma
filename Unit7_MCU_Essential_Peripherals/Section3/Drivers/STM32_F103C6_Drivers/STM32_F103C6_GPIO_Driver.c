/*
 * STM32_F103C6_GPIO_Driver.c
 *
 *  Created on: Nov 11, 2021
 *      Author: Abdallah
 */

#include "STM32_F103C6_GPIO_Driver.h"


uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0;  // 0, 1: MODE . 2, 3: CNF
		break;
	case GPIO_PIN_1:
		return 4;  // 4, 5: MODE . 6, 7: CNF
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;

	}

	return 0;
}


/**======================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief			-Initializes the GPIO_PortX PinY according to the specified parameters in the PinConfig
 * @parameter[in]	-GPIO_PortX: where X can be (A..E depending on device used) to select the GPIO peripheral
 * @parameter[in]   -PinConfig: pointer to a GPIO_PinConfig_t structure that contains
 * 					 the configuration information for the specified GPIO peripheral
 * @return value    -None
 * Note				-STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 					 But LQFP48 has only GPIO A,B, PART of C/D exported as external PINS from the MCU
 */
void MCAL_GPIO_Init (GPIO_TypeDef *GPIO_PortX, GPIO_PinConfig_t* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) Configure PINs from 0 >>> 7
	//Port configuration register high(GPIOx_CRH) Configure PINs from 8 >>> 15

	volatile uint32_t* ConfigRegister = NULL;
	uint8_t PIN_Config = 0;

	ConfigRegister = (PinConfig->GPIO_Pin_Number < GPIO_PIN_8)? &GPIO_PortX->CRL   : &GPIO_PortX->CRH;

	//clear MODE, CNF
	(*ConfigRegister) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_Pin_Number));

	//if Pin is output
	if ( (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) )
	{
		//Set MODE, CNF
		PIN_Config = ((((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0F);
	}
	//if Pin is input
	else  // MODE = 00: Input mode (reset state)
	{
		if ( (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLOATING) || (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG) )
		{
			//Set MODE 00, CNF
			PIN_Config = ((((PinConfig->GPIO_MODE) << 2) | 0X0) & 0x0F);
		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)  //Consider it as input floating
		{
			//Set MODE 00, CNF
			PIN_Config = ((((GPIO_MODE_INPUT_FLOATING) << 2) | 0X0) & 0x0F);
		}
		else  //PU PD Input
		{
			PIN_Config = ((((GPIO_MODE_INPUT_PUR) << 2) | 0X0) & 0x0F);

			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PUR)
			{
				//PxODR = 1 Input pull-up :Table 20. port bit configuration table
				GPIO_PortX->ODR |= PinConfig->GPIO_Pin_Number;
			}
			else
			{
				//PxODR = 1 Input pull-up :Table 20. port bit configuration table
				GPIO_PortX->ODR &= ~(PinConfig->GPIO_Pin_Number);
			}

		}

	}
	//Write on the CRL or CRH
	(*ConfigRegister) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->GPIO_Pin_Number) );
}

/**======================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief			-Reset all the GPIO Registers
 * @parameter[in]	-GPIO_PortX: where X can be (A..E depending on device used) to select the GPIO peripheral
 * @return value    -None
 * Note				-None
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIO_PortX)
{
	/*
	GPIO_PortX->BRR  = 0x00000000;
	GPIO_PortX->BSRR = 0x00000000;
	GPIO_PortX->CRH  = 0x44444444;
	GPIO_PortX->CRL  = 0x44444444;
//  GPIO_PortX->IDR  = ; (READ Only)
	GPIO_PortX->LCKR = 0x00000000;
	GPIO_PortX->ODR  = 0x00000000;
	*/

	//Or you can use the reset controller
	//APB2 peripheral reset register (RCC_APB2RSTR)
	//Set and cleared by software
	if (GPIO_PortX == GPIO_PORTA)
	{
		//Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR |= (1 << 2);
		RCC->APB2RSTR &= (1 << 2);
	}
	else if (GPIO_PortX == GPIO_PORTB)
	{
		//Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR |= (1 << 3);
		RCC->APB2RSTR &= (1 << 3);
	}
	else if (GPIO_PortX == GPIO_PORTC)
	{
		//Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR |= (1 << 4);
		RCC->APB2RSTR &= (1 << 4);
	}
	else if (GPIO_PortX == GPIO_PORTD)
	{
		//Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR |= (1 << 5);
		RCC->APB2RSTR &= (1 << 5);
	}
	else if (GPIO_PortX == GPIO_PORTE)
	{
		//Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR |= (1 << 6);
		RCC->APB2RSTR &= (1 << 6);
	}

}

/**======================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief			-Read Specific PIN
 * @parameter[in]	-GPIO_PortX: where X can be (A..E depending on device used) to select the GPIO peripheral
 * @parameter[in]   -PinNumber: Set Pin Number according @ref GPIO_PINS_define
 * @return value    -the input pin value (two values based on @ref GPIO_PIN_state)
 * Note				-None
 */
uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber)
{
	uint8_t bitStatus;

	if (((GPIO_PortX->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET )
	{
		bitStatus = GPIO_PIN_SET;
	}
	else
	{
		bitStatus = GPIO_PIN_RESET;
	}

	return bitStatus;
}

/**======================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief			-Read the input port VALUE
 * @parameter[in]	-GPIO_PortX: where X can be (A..E depending on device used) to select the GPIO peripheral
 * @return value    -the input port VALUE
 * Note				-None
 */
uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIO_PortX)
{
	uint16_t portValue;
	portValue = (uint16_t)(GPIO_PortX->IDR);

	return portValue;
}

/**======================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief			-write on specific input pin
 * @parameter[in]	-GPIO_PortX: where X can be (A..E depending on device used) to select the GPIO peripheral
 * @parameter[in]   -PinNumber: specifies the port bit to write . Set by @ref GPIO_PINS_define
 * @parameter[in]   -Value: Pin Value
 * @return value    -None
 * Note				-None
 */
void MCAL_GPIO_WritePin  (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber, uint8_t Value)
{
	if (Value != GPIO_PIN_RESET)
	{
//		GPIO_PortX->ODR |= PinNumber;
//		or
//		Bits 15:0 BSy: Port x Set bit y (y = 0 .. 15)
//		These bits are write-only and can be accessed in Word mode only.
//		0: No action on the corresponding ODRx bit
//		1: Set the corresponding ODRx bit
		GPIO_PortX->BSRR = (uint32_t)PinNumber;
	}
	else
	{
//		Bits 31:16 BRy: Port x Reset bit y (y = 0 .. 15)
//		These bits are write-only and can be accessed in Word mode only.
//		0: No action on the corresponding ODRx bit
//		1: Reset the corresponding ODRx bit
		GPIO_PortX->BRR = (uint32_t)PinNumber;
	}

}

/**======================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief			-write on output port
 * @parameter[in]	-GPIO_PortX: where X can be (A..E depending on device used) to select the GPIO peripheral
 * @return value    -None
 * Note				-None
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIO_PortX, uint16_t Value)
{
	GPIO_PortX->ODR = (uint32_t)Value;
}

/**======================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief			-Toggles the specified GPIO pin
 * @parameter[in]	-GPIO_PortX: where X can be (A..E depending on device used) to select the GPIO peripheral
 * @parameter[in]   -PinNumber: Set Pin Number according @ref GPIO_PINS_define
 * @return value    -None
 * Note				-None
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber)
{
	GPIO_PortX->ODR ^= (PinNumber);

}

/**======================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief			-The locking mechanism allows the IO configuration to be frozen
 * @parameter[in]	-GPIO_PortX: where X can be (A..E depending on device used) to select the GPIO peripheral
 * @parameter[in]   -PinNumber: Specifies the port bit to read. set by @ref GPIO_PINS_define
 * @return value    -OK if pin configuration is locked or ERROR if pin not locked (OK & ERROR are defined @ref GPIO_RETURN_LOCK
 * Note				-None
 */
uint8_t MCAL_GPIO_LockPin   (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber)
{
	/*
	 *  Bit 16 LCKK[16]: Lock key
		This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
		0: Port configuration lock key not active
		1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
		LOCK key writing sequence:
		Write 1
		Write 0
		Write 1
		Read 0
		Read 1 (this read is optional but confirms that the lock is active)
		Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
		Any error in the lock sequence will abort the lock.
		Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
		These bits are read write but can only be written when the LCKK bit is 0.
		0: Port configuration not locked
		1: Port configuration locked.
	 */

	// Set LCKK[16]
	volatile uint32_t temp = 1 << 16;
	// Set the LCKy
	temp |= PinNumber;

	//Write 1
	GPIO_PortX->LCKR = temp;
	//Write 0
	GPIO_PortX->LCKR = PinNumber;
	//Write 1
	GPIO_PortX->LCKR = temp;
	//Read 0
	temp = GPIO_PortX->LCKR;
	//Read 1
	if ((uint32_t) (GPIO_PortX->LCKR & 1 << 16))
	{
		return GPIO_RETURN_LOCK_Enabled;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}

}

