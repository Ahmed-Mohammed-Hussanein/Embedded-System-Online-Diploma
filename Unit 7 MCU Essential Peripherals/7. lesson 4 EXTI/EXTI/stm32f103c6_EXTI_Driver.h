/*
 * stm32f103c6_EXTI_Driver.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Ahmed
 */

#ifndef INC_STM32F103C6_EXTI_DRIVER_H_
#define INC_STM32F103C6_EXTI_DRIVER_H_

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"
#include "Utils.h"

#include "stm32f10xxx_device_header.h"
#include "stm32f103c6_GPIO_Driver.h"

// ==========================================================
// ================== User Type Definitions =================
// ==========================================================

typedef struct
{
	uint8_t EXTI_LineNumber;					/* This is used to select EXTI line number.
												There are 16 GPIO Line for external interrupt.
												This parameter must be a value of @ref EXTI_LINE_define. */

	uint8_t EXTI_PortNumber;					/* This is used to select PORT for EXTI line number.
												This parameter must be a value of @ref EXTI_PORT_define. */


	uint8_t EXTI_TriggerType;					/* This is used to select Trigger Type.
												This is either rising or falling or both.
												This parameter must be a value of @ref EXTI_TRIGGER_define. */

	uint8_t EXTI_Enable;						/* This is used to enable or disable the EXTI
												This parameter must be a value of @ref EXTI_define. */

} EXTI_Config_t;


// ===================================================================
// ================== Macros Configuration Reference =================
// ===================================================================

// @ref EXTI_LINE_define.
#define EXTI_LINE_0								GPIO_PIN_0
#define EXTI_LINE_1								GPIO_PIN_1
#define EXTI_LINE_2								GPIO_PIN_2
#define EXTI_LINE_3								GPIO_PIN_3
#define EXTI_LINE_4								GPIO_PIN_4
#define EXTI_LINE_5								GPIO_PIN_5
#define EXTI_LINE_6								GPIO_PIN_6
#define EXTI_LINE_7								GPIO_PIN_7
#define EXTI_LINE_8								GPIO_PIN_8
#define EXTI_LINE_9								GPIO_PIN_9
#define EXTI_LINE_10							GPIO_PIN_10
#define EXTI_LINE_11							GPIO_PIN_11
#define EXTI_LINE_12							GPIO_PIN_12
#define EXTI_LINE_13							GPIO_PIN_13
#define EXTI_LINE_14							GPIO_PIN_14
#define EXTI_LINE_15							GPIO_PIN_15


// @ref EXTI_PORT_define.
#define EXTI_PORT_A								0x0
#define EXTI_PORT_B								0x1
#define EXTI_PORT_C								0x2

// @ref EXTI_TRIGGER_define.
#define EXTI_TRIGGER_RISING						0x0
#define EXTI_TRIGGER_FALLING					0x1
#define EXTI_TRIGGER_BOTH						0x2

// @ref EXTI_define.
#define EXTI_DISABLE							0
#define EXTI_ENABLE								1



// ===================================================
// ================== APIs Functions =================
// ===================================================
void MCAL_EXTI_Init(EXTI_Config_t *config);
void MCAL_EXTI_Update(EXTI_Config_t *config);
void MCAL_EXTI_DeInit(void);


void MCAL_EXTI0_CallBack(void);
void MCAL_EXTI1_CallBack(void);
void MCAL_EXTI2_CallBack(void);
void MCAL_EXTI3_CallBack(void);
void MCAL_EXTI4_CallBack(void);
void MCAL_EXTI5_CallBack(void);
void MCAL_EXTI6_CallBack(void);
void MCAL_EXTI7_CallBack(void);
void MCAL_EXTI8_CallBack(void);
void MCAL_EXTI9_CallBack(void);
void MCAL_EXTI10_CallBack(void);
void MCAL_EXTI11_CallBack(void);
void MCAL_EXTI12_CallBack(void);
void MCAL_EXTI13_CallBack(void);
void MCAL_EXTI14_CallBack(void);
void MCAL_EXTI15_CallBack(void);


#endif /* INC_STM32F103C6_EXTI_DRIVER_H_ */
