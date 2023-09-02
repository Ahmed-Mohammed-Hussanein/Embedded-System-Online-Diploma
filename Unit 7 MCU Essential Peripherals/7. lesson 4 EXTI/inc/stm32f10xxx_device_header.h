/*
 * stm32f10xxx_device_header.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Ahmed
 */

#ifndef STM32F10XXX_DEVICE_HEADER_H_
#define STM32F10XXX_DEVICE_HEADER_H_

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"
#include "Utils.h"

// ==========================================================
// ================== Memory Base Addresses =================
// ==========================================================
#define FLASH_BASE				0x08000000
#define SYSTEM_MEMORY_BASE		0x1FFFF000
#define SRAM_BASE				0x20000000

// ==============================================================
// ================== Peripheral Base Addresses =================
// ==============================================================

#define NVIC_BASE				0xE000E100

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* AFIO -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define	AFIO_BASE				0x40010000

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* EXTI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define EXTI_BASE				0x40010400

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* GPIO -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define	GPIOA_BASE				0x40010800
#define	GPIOB_BASE				0x40010C00
#define	GPIOC_BASE				0x40011000
#define	GPIOD_BASE				0x40011400
#define	GPIOE_BASE				0x40011800

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* RCC -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define RCC_BASE				0x40021000




// =========================================================
// ================== Peripheral Registers =================
// =========================================================

typedef struct
{
	vuint32_t		ISER0;
	vuint32_t 		ISER1;
	vuint32_t		ISER2;
	vuint32_t		reserved1[116];
	vuint32_t		ICER0;
	vuint32_t		ICER1;
	vuint32_t		ICER2;
	vuint32_t		reserved2[116];
	vuint32_t		ISPR0;
	vuint32_t		ISPR1;
	vuint32_t		ISPR2;
	vuint32_t		reserved3[116];
	vuint32_t		ICPR0;
	vuint32_t		ICPR1;
	vuint32_t		ICPR2;
	vuint32_t		reserved4[116];
	vuint32_t		IABR0;

} NVIC_TypeDef;


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* EXTI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{
	vuint32_t		IMR;
	vuint32_t 		EMR;
	vuint32_t		RTSR;
	vuint32_t		FTSR;
	vuint32_t		SWIER;
	vuint32_t		PR;

} EXTI_TypeDef;


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* AFIO -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{
	vuint32_t		EVCR;
	vuint32_t 		MAPR;
	vuint32_t		EXTICR1;
	vuint32_t		EXTICR2;
	vuint32_t		EXTICR3;
	vuint32_t		EXTICR4;
	vuint32_t		reserved;
	vuint32_t 		MAPR2;

} AFIO_TypeDef;


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* GPIO -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{
	vuint32_t		CRL;
	vuint32_t 		CRH;
	vuint32_t		IDR;
	vuint32_t		ODR;
	vuint32_t		BSRR;
	vuint32_t		BRR;
	vuint32_t 		LCKR;

} GPIO_TypeDef;


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* RCC -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{
	vuint32_t 	CR;
	vuint32_t 	CFGR;
	vuint32_t 	CIR;
	vuint32_t 	APB2RSTR;
	vuint32_t 	APB1RSTR;
	vuint32_t 	AHBENR;
	vuint32_t 	APB2ENR;
	vuint32_t 	APB1ENR;
	vuint32_t 	BDCR;
	vuint32_t 	CSR;

} RCC_TypeDef;


// =========================================================
// ================== Peripheral Instances =================
// =========================================================

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* EXTI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define EXTI		((EXTI_TypeDef*)EXTI_BASE)


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* AFIO -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define AFIO		((AFIO_TypeDef*)AFIO_BASE)


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* GPIO -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define GPIOA		((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB		((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC		((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD		((GPIO_TypeDef*)GPIOD_BASE)
#define	GPIOE		((GPIO_TypeDef*)GPIOE_BASE)




// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* RCC -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define	RCC			((RCC_TypeDef*)RCC_BASE)


// =========================================================
// ================== Generic Macros =======================
// =========================================================
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1<<6)

#define RCC_GPIOA_CLK_DS()	(RCC->APB2ENR &= ~(1<<2))
#define RCC_GPIOB_CLK_DS()	(RCC->APB2ENR &= ~(1<<3))
#define RCC_GPIOC_CLK_DS()	(RCC->APB2ENR &= ~(1<<4))
#define RCC_GPIOD_CLK_DS()	(RCC->APB2ENR &= ~(1<<5))
#define RCC_GPIOE_CLK_DS()	(RCC->APB2ENR &= ~(1<<6))

#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= 1<<0)
#define RCC_AFIO_CLK_DS()	(RCC->APB2ENR &= ~(1<<0))

#define NVIC						((NVIC_TypeDef*)NVIC_BASE)


#endif /* STM32F10XXX_DEVICE_HEADER_H_ */
