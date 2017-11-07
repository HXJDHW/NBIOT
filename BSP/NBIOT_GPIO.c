#include "NBIOT_GPIO.h"


void USART_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    /* GPIO Ports Clock Enable */
    USARTx_RX_GPIO_CLK_ENABLE();
    USARTx_TX_GPIO_CLK_ENABLE();
    
    /* Enable USARTx clock */
    USARTx_CLK_ENABLE();

    /*Configure TX GPIO pins : PA10 */
    GPIO_InitStruct.Pin = USARTx_TX_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP; //复用推挽输出
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;//高速
    GPIO_InitStruct.Alternate = USARTx_TX_AF; //USART2连接到该引脚
    HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);

    /*Configure RX GPIO pins : PA9 */
    GPIO_InitStruct.Pin = USARTx_RX_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_INPUT; //输入
    GPIO_InitStruct.Alternate = USARTx_RX_AF;//USART2连接到该引脚 
    HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);
}

void USART_GPIO_DeInit(void)
{
    /*##-1- Reset peripherals */
    USARTx_FORCE_RESET();
    USARTx_RELEASE_RESET();

    /*##-2- Disable peripherals and GPIO Clocks */
    /* Configure UART Tx as alternate function  */
    HAL_GPIO_DeInit(USARTx_TX_GPIO_PORT, USARTx_TX_PIN);
    /* Configure UART Rx as alternate function  */
    HAL_GPIO_DeInit(USARTx_RX_GPIO_PORT, USARTx_RX_PIN);
}
