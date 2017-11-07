/**
  ******************************************************************************
  * @file    stm32l0xx_nucleo.h
  * @author  MCD Application Team
  * @version V2.1.0
  * @date    25-November-2016
  * @brief   This file contains definitions for:
  *          - LEDs and push-button available on STM32L0XX-Nucleo Kit 
  *            from STMicroelectronics
  *          - LCD, joystick and microSD available on Adafruit 1.8" TFT LCD 
  *            shield (reference ID 802)
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L0XX_NUCLEO_H
#define __STM32L0XX_NUCLEO_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32L0XX_NUCLEO
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
/** @addtogroup STM32L0XX_NUCLEO_LOW_LEVEL
  * @{
  */
      
/** @defgroup STM32L0XX_NUCLEO_LOW_LEVEL_Exported_Types Exported Types
  * @{
  */ 
   

typedef enum
{
	IO_INPUT = 0,
	IO_OUTPUT_H=1,
	IO_OUTPUT_L=2,
	IO_DUPLEX=3,
}IOInitStatus_TypeDef;

//typedef struct{
//  uint32_t RCC_APB2Periph;
//
//  GPIO_TypeDef* Port;   
//        
//  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
//                           This parameter can be a combination of @ref GPIO_pins_define */
//
//  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
//                           This parameter can be a value of @ref GPIO_mode_define */
//
//  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
//                           This parameter can be a value of @ref GPIO_pull_define */
//
//  uint32_t Speed;     /*!< Specifies the speed for the selected pins.
//                           This parameter can be a value of @ref GPIO_speed_define */
//
//  uint32_t Alternate; /*!< Peripheral to be connected to the selected pins 
//                            This parameter can be a value of @ref GPIOEx_Alternate_function_selection */
//  IOInitStatus_TypeDef InitStatus;
//}IO_Item;

typedef struct{
  uint32_t RCC_APB2Periph;

  GPIO_TypeDef* Port;   
  
  GPIO_InitTypeDef GpioInit;    
  
  IOInitStatus_TypeDef InitStatus;
}IO_Item;

typedef struct{
  const IO_Item *pIOItem; 
  const uint8_t ItemNum;
}IO_Init;

/** @addtogroup STM32L0XX_NB-IOT_UART
  * @{
  */
//#define METER_UART_PORT 
//
//#define USARTx                           USART2
//#define USARTx_CLK_ENABLE()              __HAL_RCC_USART2_CLK_ENABLE();
//#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
//#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
//
//#define USARTx_FORCE_RESET()             __HAL_RCC_USART2_FORCE_RESET()
//#define USARTx_RELEASE_RESET()           __HAL_RCC_USART2_RELEASE_RESET()
//
///* Definition for USARTx Pins */
//#define METER_UART_TX_PORT               GPIOA
//#define METER_UART_TX_PIN                GPIO_PIN_9
//#define METER_UART_TX_AF                 GPIO_AF4_USART2
//
//#define METER_UART_RX_PORT               GPIOA
//#define METER_UART_RX_PIN                GPIO_PIN_10
//#define METER_UART_RX_AF                 GPIO_AF4_USART2



#define LEDx_GPIO_CLK_ENABLE(__INDEX__)\
                                    do{                                  \
                                      if((__INDEX__) == 0){              \
                                        USARTx_TX_GPIO_CLK_ENABLE()      \
                                      }else{                             \
					USARTx_RX_GPIO_CLK_ENABLE()      \
                                      }                                  \
				    } while(0)
/** @addtogroup STM32L0XX_NUCLEO_LOW_LEVEL_LED
  * @{
  */

/**
  * @}
  */ 
  
/** @addtogroup STM32L0XX_NUCLEO_LOW_LEVEL_BUTTON
  * @{
  */  


/**
  * @brief User push-button
  */
/**
  * @}
  */ 

/** @addtogroup STM32L0XX_NUCLEO_LOW_LEVEL_BUS
  * @{
  */ 

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */ 
    
#ifdef __cplusplus
}
#endif

#endif /* __STM32L0XX_NUCLEO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
