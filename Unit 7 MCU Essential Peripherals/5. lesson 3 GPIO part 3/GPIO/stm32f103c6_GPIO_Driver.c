/*
 * stm32f103c6_GPIO_Driver.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Ahmed
 */

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"

#include "stm32f103c6_GPIO_Driver.h"

/*
 * =====================================================================================
 * ================================= APIs Function Definition ==========================
 * =====================================================================================
 */

/**================================================================
 * @Fn				- MCAL_GPIO_Init
 * @brief			- This is used to configure and initialize a pin or a port in GPIO.
 * @param [in] 		- GPIOx: This specifies which port is used for configuration at @ref GPIOx_define.
 * @param [in] 		- pinConfig: This carries the configuration for the pin or port at @ref GPIO_PIN_define.
 * @retval 			- None.
 * Note				- None.
 */

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *pinConfig)
{
	uint16_t pins = pinConfig->GPIO_PinNumber;
	uint32_t crlConfig = 0;
	uint32_t crhConfig = 0;

	uint32_t crlMask = 0;
	uint32_t crhMask = 0;

	if(pinConfig->GPIO_PinMode == GPIO_MODE_INPUT_PDR)
	{
		pinConfig->GPIO_PinMode = GPIO_MODE_INPUT_PUR;
	}


	uint8_t i = 0;
	while(pins)
	{
		if(pins&1)
		{
			if(i < 8)
			{
				crlConfig |= (pinConfig->GPIO_PinMode << (i*4));
				crlMask |= (0xF << (i*4));
			}
			else
			{
				crhConfig |= (pinConfig->GPIO_PinMode << ((i-8)*4));
				crhMask |= (0xF << ((i-8)*4));
			}
		}
		pins >>= 1;
		i++;
	}




	switch(pinConfig->GPIO_PinMode)
	{
	case GPIO_MODE_INPUT_PDR:
		CLEAR_REG(GPIOx->ODR, pinConfig->GPIO_PinNumber);
		break;

	case GPIO_MODE_INPUT_PUR:
		SET_REG(GPIOx->ODR, pinConfig->GPIO_PinNumber);
		break;
	}

	/*	CNF		MODE
	 * 	00		01			General Purpose Output Push Pull 10MHz
	 *  00		10			General Purpose Output Push Pull 2MHz
	 *  00		11			General Purpose Output Push Pull 50MHz
	 *
	 *  01		01			General Purpose Output Open Drain 10MHz
	 *  01		10			General Purpose Output Open Drain 2MHz
	 *  01		11			General Purpose Output Open Drain 50MHz
	 *
	 *  10		01			Alternative Function Output Push Pull 10MHz
	 *  10		10			Alternative Function Output Push Pull 2MHz
	 *  10		11			Alternative Function Output Push Pull 50MHz
	 *
	 *  11		01			Alternative Function Output Open Drain 10MHz
	 *  11		10			Alternative Function Output Open Drain 2MHz
	 *  11		11			Alternative Function Output Open Drain 50MHz
	 *
	 *  00		00			Input Analog
	 *  01		00			Input Floating
	 *  10		00			Input PUR
	 *  10		00			Input PDR
	 *
	 *
	 */

	WRITE_REG(GPIOx->CRL, crlMask, crlConfig);
	WRITE_REG(GPIOx->CRH, crhMask, crhConfig);
}




/**================================================================
 * @Fn				- MCAL_GPIO_writePin
 * @brief			- This is used to write a value to a pin in GPIO if the pin is in OUTPUT mode.
 * @param [in] 		- GPIOx: This specifies which port is used for configuration at @ref GPIOx_define.
 * @param [in] 		- pinNumber: This is used to determine the pin number in the port at @ref GPIO_PIN_define.
 * @param [in] 		- value: The value needed to be written on the pin at @ref GPIO_STATE_define.
 * @retval 			- None.
 * Note				- None.
 */
void MCAL_GPIO_writePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint16_t value)
{
	switch(value)
	{
	case GPIO_STATE_LOW:
		CLEAR_BIT(GPIOx->ODR, PinNumber);
		break;

	case GPIO_STATE_HIGH:
		SET_BIT(GPIOx->ODR, PinNumber);
		break;
	}
}


/**================================================================
 * @Fn				- MCAL_GPIO_writePins
 * @brief			- This is used to write a value to a pin in GPIO if the pin is in OUTPUT mode.
 * @param [in] 		- GPIOx: This specifies which port is used for configuration at @ref GPIOx_define.
 * @param [in] 		- PinNumber: This is used to determine the pins in the port at @ref GPIO_PIN_define.
 * @param [in] 		- value: The value needed to be written on the pins at @ref GPIO_STATE_define.
 * @retval 			- None.
 * Note				- None.
 */
void MCAL_GPIO_writePins(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint16_t value)
{
	uint16_t temp = GPIOx->ODR;
	WRITE_REG(temp, PinNumber, value);
	GPIOx->ODR = temp;
}


/**================================================================
 * @Fn				- MCAL_GPIO_writePort
 * @brief			- This is used to write a value to a port GPIO if the port is in OUTPUT mode.
 * @param [in] 		- GPIOx: This specifies which port is used for configuration at @ref GPIOx_define.
 * @param [in] 		- value: The value needed to be written on the pin at @ref GPIO_STATE_define.
 * @retval 			- None.
 * Note				- None.
 */
void MCAL_GPIO_writePort(GPIO_TypeDef *GPIOx, uint16_t value)
{
	GPIOx->ODR = value;
}




/**================================================================
 * @Fn				- MCAL_GPIO_readPin
 * @brief			- This is used to read a value from a pin in GPIO.
 * @param [in] 		- GPIOx: This specifies which port is used for configuration at @ref GPIOx_define.
 * @param [in] 		- pinNumber: This is used to determine the pin number in the port at @ref GPIO_PIN_define.
 * @retval 			- None.
 * Note				- None.
 */
uint8_t MCAL_GPIO_readPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	switch(READ_REG(GPIOx->IDR, PinNumber))
	{
	case GPIO_STATE_LOW:
		return GPIO_STATE_LOW;

	default:
		return GPIO_STATE_HIGH;
	}
}



/**================================================================
 * @Fn				- MCAL_GPIO_readPort
 * @brief			- This is used to read a value from a port in GPIO.
 * @param [in] 		- GPIOx: This specifies which port is used for configuration at @ref GPIOx_define.
 * @retval 			- None.
 * Note				- None.
 */
uint16_t MCAL_GPIO_readPort(GPIO_TypeDef *GPIOx)
{
	return (uint16_t)GPIOx->IDR;
}



/**================================================================
 * @Fn				- MCAL_GPIO_togglePin
 * @brief			- This is used to toggle the state of the pin in GPIO if the pin is in OUTPUT mode.
 * @param [in] 		- GPIOx: This specifies which port is used for configuration at @ref GPIOx_define.
 * @param [in] 		- pinNumber: This is used to determine the pin number in the port at @ref GPIO_PIN_define.
 * @retval 			- None.
 * Note				- None.
 */
void MCAL_GPIO_togglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}



/**================================================================
 * @Fn				- MCAL_GPIO_togglePort
 * @brief			- This is used to toggle the state of the port in GPIO if the port is in OUTPUT mode.
 * @param [in] 		- GPIOx: This specifies which port is used for configuration at @ref GPIOx_define.
 * @retval 			- None.
 * Note				- None.
 */
void MCAL_GPIO_togglePort(GPIO_TypeDef *GPIOx)
{
	GPIOx->ODR ^= 0xFF;
}
