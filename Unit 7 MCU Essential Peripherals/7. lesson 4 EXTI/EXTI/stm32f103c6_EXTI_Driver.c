/*
 * stm32f103c6_EXTI_Driver.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Ahmed
 */


// =============================================
// ================== Includes =================
// =============================================

#include "stm32f103c6_EXTI_Driver.h"
#include "stm32f103c6_GPIO_Driver.h"
#include "Platform_Types.h"


/*
 * =====================================================================================
 * ================================= Generic Macros ====================================
 * =====================================================================================
 */

/*
 * =====================================================================================
 * ================================= Private Functions =================================
 * =====================================================================================
 */

static void _Update(EXTI_Config_t *config)
{
	// configure GPIO
	GPIO_PinConfig_t EXTI_pin;
	EXTI_pin.GPIO_PinMode 	= GPIO_MODE_INPUT_FLOATING;
	EXTI_pin.GPIO_PinNumber = config->EXTI_LineNumber;

	switch(config->EXTI_PortNumber)
	{
	case EXTI_PORT_A:
		MCAL_GPIO_Init(GPIOA, &EXTI_pin);
		break;

	case EXTI_PORT_B:
		MCAL_GPIO_Init(GPIOB, &EXTI_pin);
		break;

	case EXTI_PORT_C:
		MCAL_GPIO_Init(GPIOC, &EXTI_pin);
		break;
	}



	// select the EXTI line.
	switch(config->EXTI_LineNumber)
	{
	case EXTI_LINE_0:
	case EXTI_LINE_1:
	case EXTI_LINE_2:
	case EXTI_LINE_3:
		AFIO->EXTICR1 |= (config->EXTI_PortNumber << (config->EXTI_LineNumber * 4));
		break;

	case EXTI_LINE_4:
	case EXTI_LINE_5:
	case EXTI_LINE_6:
	case EXTI_LINE_7:
		AFIO->EXTICR2 |= (config->EXTI_PortNumber << ((config->EXTI_LineNumber - 4) * 4));
		break;

	case EXTI_LINE_8:
	case EXTI_LINE_9:
	case EXTI_LINE_10:
	case EXTI_LINE_11:
		AFIO->EXTICR3 |= (config->EXTI_PortNumber << ((config->EXTI_LineNumber - 8) * 4));
		break;

	case EXTI_LINE_12:
	case EXTI_LINE_13:
	case EXTI_LINE_14:
	case EXTI_LINE_15:
		AFIO->EXTICR4 |= (config->EXTI_PortNumber << ((config->EXTI_LineNumber - 12) * 4));
	}

	// set the trigger type.
	switch(config->EXTI_TriggerType)
	{
	case EXTI_TRIGGER_RISING:
		SET_BIT(EXTI->RTSR, config->EXTI_LineNumber);
		CLEAR_BIT(EXTI->FTSR, config->EXTI_LineNumber);
		break;

	case EXTI_TRIGGER_FALLING:
		CLEAR_BIT(EXTI->RTSR, config->EXTI_LineNumber);
		SET_BIT(EXTI->FTSR, config->EXTI_LineNumber);
		break;

	case EXTI_TRIGGER_BOTH:
		SET_BIT(EXTI->RTSR, config->EXTI_LineNumber);
		SET_BIT(EXTI->FTSR, config->EXTI_LineNumber);
		break;
	}

	// set mask bit.
	WRITE_REG(EXTI->IMR, 1 << config->EXTI_LineNumber, config->EXTI_Enable << config->EXTI_LineNumber);
//	SET_BIT(EXTI->IMR, config->EXTI_LineNumber);

	// set NVIC mask bit
	switch(config->EXTI_LineNumber)
	{
	case EXTI_LINE_0:
	case EXTI_LINE_1:
	case EXTI_LINE_2:
	case EXTI_LINE_3:
	case EXTI_LINE_4:
		WRITE_REG(NVIC->ISER0, 1 << (config->EXTI_LineNumber + 6), config->EXTI_Enable << (config->EXTI_LineNumber + 6));
//		SET_BIT(NVIC->ISER0, (config->EXTI_LineNumber + 6));
		break;


	case EXTI_LINE_5:
	case EXTI_LINE_6:
	case EXTI_LINE_7:
	case EXTI_LINE_8:
	case EXTI_LINE_9:
		WRITE_REG(NVIC->ISER0, 1 << 23, config->EXTI_Enable << 23);
//		SET_BIT(NVIC->ISER0, 23);
		break;


	case EXTI_LINE_10:
	case EXTI_LINE_11:
	case EXTI_LINE_12:
	case EXTI_LINE_13:
	case EXTI_LINE_14:
	case EXTI_LINE_15:
		WRITE_REG(NVIC->ISER1, 1 << 8, config->EXTI_Enable << 8);
//		SET_BIT(NVIC->ISER1, 8);
	}
}

/*
 * =====================================================================================
 * ================================= APIs Function Definition ==========================
 * =====================================================================================
 */

/**================================================================
 * @Fn				- MCAL_EXTI_Init
 * @brief			- This is used to configure External Interrupt.
 * @param [in] 		- config: This carries the configuration of the EXTI.
 * @retval 			- None.
 * Note				- None.
 */
void MCAL_EXTI_Init(EXTI_Config_t *config)
{
	_Update(config);
}

/**================================================================
 * @Fn				- MCAL_EXTI_DeInit
 * @brief			- This is used to reset the EXTI registers and NVIC.
 * @param [in] 		- config: This carries the configuration of the EXTI.
 * @retval 			- None.
 * Note				- None.
 */
void MCAL_EXTI_DeInit(void)
{
	// reset value
	EXTI->IMR 	= 0x00000000;
	EXTI->EMR	= 0x00000000;
	EXTI->RTSR 	= 0x00000000;
	EXTI->FTSR 	= 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR 	= 0xFFFFFFFF;

	// disable NVIC
	CLEAR_BIT(NVIC->ISER0, 6);
	CLEAR_BIT(NVIC->ISER0, 7);
	CLEAR_BIT(NVIC->ISER0, 8);
	CLEAR_BIT(NVIC->ISER0, 9);
	CLEAR_BIT(NVIC->ISER0, 10);

	CLEAR_BIT(NVIC->ISER0, 23);
	CLEAR_BIT(NVIC->ISER1, 8);
}

/**================================================================
 * @Fn				- MCAL_EXTI_Update
 * @brief			- This is used to update External Interrupt.
 * @param [in] 		- config: This carries the configuration of the EXTI.
 * @retval 			- None.
 * Note				- None.
 */
void MCAL_EXTI_Update(EXTI_Config_t *config)
{
	_Update(config);
}

/*
 * =====================================================================================
 * ================================= ISR ===============================================
 * =====================================================================================
 */

void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI->PR, 0);
	MCAL_EXTI0_CallBack();
}

void EXTI1_IRQHandler(void)
{
	SET_BIT(EXTI->PR, 1);
	MCAL_EXTI1_CallBack();
}

void EXTI2_IRQHandler(void)
{
	SET_BIT(EXTI->PR, 1);
	MCAL_EXTI2_CallBack();
}

void EXTI3_IRQHandler(void)
{
	SET_BIT(EXTI->PR, 3);
	MCAL_EXTI3_CallBack();
}

void EXTI4_IRQHandler(void)
{
	SET_BIT(EXTI->PR, 4);
	MCAL_EXTI4_CallBack();
}

void EXTI9_5_IRQHandler(void)
{
	if(READ_BIT(EXTI->IMR, 5))
	{
		SET_BIT(EXTI->PR, 5);
		MCAL_EXTI5_CallBack();
	}
	if(READ_BIT(EXTI->IMR, 6))
	{
		SET_BIT(EXTI->PR, 6);
		MCAL_EXTI6_CallBack();
	}
	if(READ_BIT(EXTI->IMR, 7))
	{
		SET_BIT(EXTI->PR, 7);
		MCAL_EXTI7_CallBack();
	}
	if(READ_BIT(EXTI->IMR, 8))
	{
		SET_BIT(EXTI->PR, 8);
		MCAL_EXTI8_CallBack();
	}
	if(READ_BIT(EXTI->IMR, 9))
	{
		SET_BIT(EXTI->PR, 9);
		MCAL_EXTI9_CallBack();
	}
}

void EXTI15_10_IRQHandler(void)
{
	if(READ_BIT(EXTI->IMR, 10))
	{
		SET_BIT(EXTI->PR, 10);
		MCAL_EXTI10_CallBack();
	}
	if(READ_BIT(EXTI->IMR, 11))
	{
		SET_BIT(EXTI->PR, 11);
		MCAL_EXTI11_CallBack();
	}
	if(READ_BIT(EXTI->IMR, 12))
	{
		SET_BIT(EXTI->PR, 12);
		MCAL_EXTI12_CallBack();
	}
	if(READ_BIT(EXTI->IMR, 13))
	{
		SET_BIT(EXTI->PR, 13);
		MCAL_EXTI13_CallBack();
	}
	if(READ_BIT(EXTI->IMR, 14))
	{
		SET_BIT(EXTI->PR, 14);
		MCAL_EXTI14_CallBack();
	}
	if(READ_BIT(EXTI->IMR, 15))
	{
		SET_BIT(EXTI->PR, 15);
		MCAL_EXTI15_CallBack();
	}
}


__attribute__((weak)) void MCAL_EXTI0_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI1_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI2_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI3_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI4_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI5_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI6_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI7_CallBack(void)
{
	while(1);

}

__attribute__((weak)) void MCAL_EXTI8_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI9_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI10_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI11_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI12_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI13_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI14_CallBack(void)
{
	while(1);
}

__attribute__((weak)) void MCAL_EXTI15_CallBack(void)
{
	while(1);
}

