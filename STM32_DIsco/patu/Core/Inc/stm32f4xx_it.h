/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.h
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
 ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
<<<<<<<< HEAD:STM32_DIsco/patu/Core/Inc/stm32f4xx_it.h
 /* USER CODE BEGIN Includes from demo */
 #include "main.h"
 #include "stm32469i_discovery.h"
 #include "stm32469i_discovery_audio.h"
 /* USER CODE END Includes from demo */
========

>>>>>>>> 4dfa1c8c6a4915b9bf21197640e1812902df8a12:STM32_DIsco/stm32f04Disc_Acc_EulerCalibrated/Core/Inc/stm32f4xx_it.h
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
<<<<<<<< HEAD:STM32_DIsco/patu/Core/Inc/stm32f4xx_it.h
void DebugMon_Handler(void);
void TIM6_DAC_IRQHandler(void);
void OTG_FS_IRQHandler(void);
void LTDC_IRQHandler(void);
void DMA2D_IRQHandler(void);
void DSI_IRQHandler(void);
/* USER CODE BEGIN EFP */
/* USER CODE BEGIN EFP from demo*/
#define PDM_OUT_Pin GPIO_PIN_3
#define PDM_OUT_GPIO_Port GPIOC
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void EXTI0_IRQHandler(void);
void I2S3_IRQHandler(void);
void I2S2_IRQHandler(void);
void TIMx_IRQHandler(void);
/* USER CODE END EFP from demo*/
========
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void EXTI0_IRQHandler(void);
/* USER CODE BEGIN EFP */

>>>>>>>> 4dfa1c8c6a4915b9bf21197640e1812902df8a12:STM32_DIsco/stm32f04Disc_Acc_EulerCalibrated/Core/Inc/stm32f4xx_it.h
/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */
