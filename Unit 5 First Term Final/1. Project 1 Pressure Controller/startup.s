.global _reset
.type _reset, %function
.weak _reset


.section .text
.syntax unified
_reset:
	ldr r0, =_stack_top
	mov sp, r0
	bl _init
	bl main

stop:
	b stop

.type _init, %function
.weak _init
_init:
	ldr r0, =_eText
	ldr r1, =_sData
	ldr r2, =_eData

	DATALOOP:
		ldrb r3, [r0], #1
		strb r3, [r1], #1
		cmp r2, r1
		bne DATALOOP

	MOV r0, #0
	ldr r1, =_sBSS
	ldr r2, =_eBSS

	BSSLOOP:
		strb r0, [r1], #1
		cmp r2, r1
		bne BSSLOOP

	MOV pc, lr


.thumb_func
.type Default_Handler, %function
.weak Default_Handler
Default_Handler:
	b Default_Handler





.section .vectors
.word 		_stack_top
.word		_reset
.word		NMI_Handler
.word		HardFault_Handler
.word		MemManage_Handler
.word		BusFault_Handler
.word		UsageFault_Handler
.word		0
.word		0
.word		0
.word		0
.word		SVCall_Handler
.word		DebugMonitor_Handler
.word		0
.word		PendSV_Handler
.word		SysTick_Handler
.word		WWDG_Handler
.word		PVD_Handler
.word		TAMPER_Handler
.word		RTC_Handler
.word		FLASH_Handler
.word		RCC_Handler
.word		EXTI0_Handler
.word		EXTI1_Handler
.word		EXTI2_Handler
.word		EXTI3_Handler
.word		EXTI4_Handler
.word		DMA1_Channel1_Handler
.word		DMA1_Channel2_Handler
.word		DMA1_Channel3_Handler
.word		DMA1_Channel4_Handler
.word		DMA1_Channel5_Handler
.word		DMA1_Channel6_Handler
.word		DMA1_Channel7_Handler
.word		ADC1_2_Handler
.word		USB_HP_CAN_TX_Handler
.word		USB_LP_CAN_RX0_Handler
.word		CAN_RX1_Handler
.word		CAN_SCE_Handler
.word		EXTI9_5_Handler
.word		TIM1_BRK_Handler
.word		TIM1_UP_Handler
.word		TIM1_TRG_COM_Handler
.word		TIM1_CC_Handler
.word		TIM2_Handler
.word		TIM3_Handler
.word		TIM4_Handler
.word		I2C1_EV_Handler
.word		I2C1_ER_Handler
.word		I2C2_EV_Handler
.word		I2C2_ER_Handler
.word		SPI1_Handler
.word		SPI2_Handler
.word		USART1_Handler
.word		USART2_Handler
.word		USART3_Handler
.word		EXTI15_10_Handler
.word		RTCAlarm_Handler
.word		USBWakeup_Handler
.word		TIM8_BRK_Handler
.word		TIM8_UP_Handler
.word		TIM8_TRG_COM_Handler
.word		TIM8_CC_Handler
.word		ADC3_Handler
.word		FSMC_Handler
.word		SDIO_Handler
.word		TIM5_Handler
.word		SPI3_Handler
.word		UART4_Handler
.word		UART5_Handler
.word		TIM6_Handler
.word		TIM7_Handler
.word		DMA2_Channel1_Handler
.word		DMA2_Channel2_Handler
.word		DMA2_Channel3_Handler
.word		DMA2_Channel4_5_Handler


.weak			NMI_Handler
.thumb_set 		NMI_Handler, Default_Handler

.weak			HardFault_Handler
.thumb_set 		HardFault_Handler, Default_Handler

.weak			MemManage_Handler
.thumb_set 		MemManage_Handler, Default_Handler

.weak			BusFault_Handler
.thumb_set 		BusFault_Handler, Default_Handler

.weak			UsageFault_Handler
.thumb_set 		UsageFault_Handler, Default_Handler

.weak			SVCall_Handler
.thumb_set 		SVCall_Handler, Default_Handler

.weak			DebugMonitor_Handler
.thumb_set 		DebugMonitor_Handler, Default_Handler

.weak			PendSV_Handler
.thumb_set 		PendSV_Handler, Default_Handler

.weak			SysTick_Handler
.thumb_set 		SysTick_Handler, Default_Handler

.weak			WWDG_Handler
.thumb_set 		WWDG_Handler, Default_Handler

.weak			PVD_Handler
.thumb_set 		PVD_Handler, Default_Handler

.weak			TAMPER_Handler
.thumb_set 		TAMPER_Handler, Default_Handler

.weak			RTC_Handler
.thumb_set 		RTC_Handler, Default_Handler

.weak			FLASH_Handler
.thumb_set 		FLASH_Handler, Default_Handler

.weak			RCC_Handler
.thumb_set 		RCC_Handler, Default_Handler

.weak			EXTI0_Handler
.thumb_set 		EXTI0_Handler, Default_Handler

.weak			EXTI1_Handler
.thumb_set 		EXTI1_Handler, Default_Handler

.weak			EXTI2_Handler
.thumb_set 		EXTI2_Handler, Default_Handler

.weak			EXTI3_Handler
.thumb_set 		EXTI3_Handler, Default_Handler

.weak			EXTI4_Handler
.thumb_set 		EXTI4_Handler, Default_Handler

.weak			DMA1_Channel1_Handler
.thumb_set 		DMA1_Channel1_Handler, Default_Handler

.weak			DMA1_Channel2_Handler
.thumb_set 		DMA1_Channel2_Handler, Default_Handler

.weak			DMA1_Channel3_Handler
.thumb_set 		DMA1_Channel3_Handler, Default_Handler

.weak			DMA1_Channel4_Handler
.thumb_set 		DMA1_Channel4_Handler, Default_Handler

.weak			DMA1_Channel5_Handler
.thumb_set 		DMA1_Channel5_Handler, Default_Handler

.weak			DMA1_Channel6_Handler
.thumb_set 		DMA1_Channel6_Handler, Default_Handler

.weak			DMA1_Channel7_Handler
.thumb_set 		DMA1_Channel7_Handler, Default_Handler

.weak			ADC1_2_Handler
.thumb_set 		ADC1_2_Handler, Default_Handler

.weak			USB_HP_CAN_TX_Handler
.thumb_set 		USB_HP_CAN_TX_Handler, Default_Handler

.weak			USB_LP_CAN_RX0_Handler
.thumb_set 		USB_LP_CAN_RX0_Handler, Default_Handler

.weak			CAN_RX1_Handler
.thumb_set 		CAN_RX1_Handler, Default_Handler

.weak			CAN_SCE_Handler
.thumb_set 		CAN_SCE_Handler, Default_Handler

.weak			EXTI9_5_Handler
.thumb_set 		EXTI9_5_Handler, Default_Handler

.weak			TIM1_BRK_Handler
.thumb_set 		TIM1_BRK_Handler, Default_Handler

.weak			TIM1_UP_Handler
.thumb_set 		TIM1_UP_Handler, Default_Handler

.weak			TIM1_TRG_COM_Handler
.thumb_set 		TIM1_TRG_COM_Handler, Default_Handler

.weak			TIM1_CC_Handler
.thumb_set 		TIM1_CC_Handler, Default_Handler

.weak			TIM2_Handler
.thumb_set 		TIM2_Handler, Default_Handler

.weak			TIM3_Handler
.thumb_set 		TIM3_Handler, Default_Handler

.weak			TIM4_Handler
.thumb_set 		TIM4_Handler, Default_Handler

.weak			I2C1_EV_Handler
.thumb_set 		I2C1_EV_Handler, Default_Handler

.weak			I2C1_ER_Handler
.thumb_set 		I2C1_ER_Handler, Default_Handler

.weak			I2C2_EV_Handler
.thumb_set 		I2C2_EV_Handler, Default_Handler

.weak			I2C2_ER_Handler
.thumb_set 		I2C2_ER_Handler, Default_Handler

.weak			SPI1_Handler
.thumb_set 		SPI1_Handler, Default_Handler

.weak			SPI2_Handler
.thumb_set 		SPI2_Handler, Default_Handler

.weak			USART1_Handler
.thumb_set 		USART1_Handler, Default_Handler

.weak			USART2_Handler
.thumb_set 		USART2_Handler, Default_Handler

.weak			USART3_Handler
.thumb_set 		USART3_Handler, Default_Handler

.weak			EXTI15_10_Handler
.thumb_set 		EXTI15_10_Handler, Default_Handler

.weak			RTCAlarm_Handler
.thumb_set 		RTCAlarm_Handler, Default_Handler

.weak			USBWakeup_Handler
.thumb_set 		USBWakeup_Handler, Default_Handler

.weak			TIM8_BRK_Handler
.thumb_set 		TIM8_BRK_Handler, Default_Handler

.weak			TIM8_UP_Handler
.thumb_set 		TIM8_UP_Handler, Default_Handler

.weak			TIM8_TRG_COM_Handler
.thumb_set 		TIM8_TRG_COM_Handler, Default_Handler

.weak			TIM8_CC_Handler
.thumb_set 		TIM8_CC_Handler, Default_Handler

.weak			ADC3_Handler
.thumb_set 		ADC3_Handler, Default_Handler

.weak			FSMC_Handler
.thumb_set 		FSMC_Handler, Default_Handler

.weak			SDIO_Handler
.thumb_set 		SDIO_Handler, Default_Handler

.weak			TIM5_Handler
.thumb_set 		TIM5_Handler, Default_Handler

.weak			SPI3_Handler
.thumb_set 		SPI3_Handler, Default_Handler

.weak			UART4_Handler
.thumb_set 		UART4_Handler, Default_Handler

.weak			UART5_Handler
.thumb_set 		UART5_Handler, Default_Handler

.weak			TIM6_Handler
.thumb_set 		TIM6_Handler, Default_Handler

.weak			TIM7_Handler
.thumb_set 		TIM7_Handler, Default_Handler

.weak			DMA2_Channel1_Handler
.thumb_set 		DMA2_Channel1_Handler, Default_Handler

.weak			DMA2_Channel2_Handler
.thumb_set 		DMA2_Channel2_Handler, Default_Handler

.weak			DMA2_Channel3_Handler
.thumb_set 		DMA2_Channel3_Handler, Default_Handler

.weak			DMA2_Channel4_5_Handler
.thumb_set 		DMA2_Channel4_5_Handler, Default_Handler
