/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Utils.h"
#include "Platform_Types.h"

#define RCC_BASE		0x40021000
#define GPIOA_BASE		0x40010800
#define AFIO_BASE		0x40010000
#define EXTI_BASE		0x40010400
#define NVIC_BASE		0xE000E100


#define RCC_APB2ENR		*((vuint32_t*)(RCC_BASE + 0x18))


#define GPIOA_CRL		*((vuint32_t*)GPIOA_BASE)
#define GPIOA_CRH		*((vuint32_t*)(GPIOA_BASE + 0x4))
#define GPIOA_ORD		*((vuint32_t*)(GPIOA_BASE + 0xC))

#define AFIO_EXTICR1	*((vuint32_t*)(AFIO_BASE + 0x8))

#define EXTI_IMR		*((vuint32_t*)(EXTI_BASE))
#define EXTI_RTSR		*((vuint32_t*)(EXTI_BASE + 0x8))
#define EXTI_PR			*((vuint32_t*)(EXTI_BASE + 0x14))

#define NVIC_ISER0		*((vuint32_t*)NVIC_BASE)

void clock_Init()
{
	SET_BIT(RCC_APB2ENR, 0);
	SET_BIT(RCC_APB2ENR, 2);
}

void EXTI_Init()
{
	// set pin 0 Port A as an Input Floating
	GPIOA_CRL &= 0xFFFFFFF0;
	GPIOA_CRL |= 0x4;

	// map port A pin 0 to EXTI0
	AFIO_EXTICR1 &= ~(0xF);

	// mask exti and rising edge trigger
	SET_BIT(EXTI_RTSR, 0);
	SET_BIT(EXTI_IMR, 0);

	// mask nvic
	SET_BIT(NVIC_ISER0, 6);
}

void GPIO_output_Init()
{
	// set pin 13 Port A as an output
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;
}

int main(void)
{
	clock_Init();
	GPIO_output_Init();
	EXTI_Init();

	/* Loop forever */
	for(;;);
}

void EXTI0_IRQHandler()
{
	SET_BIT(EXTI_PR, 0);

	TOGGLE_BIT(GPIOA_ORD, 13);
}
