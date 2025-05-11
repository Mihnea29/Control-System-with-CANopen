/*
 * UART_Queue.c
 *
 *  Created on: May 9, 2025
 *      Author: mihneadorcu
 */
#include "UART_Queue.h"

extern volatile uint8_t uart_tx_busy;
#define MAX_UART_QUEUE 32

extern UART_HandleTypeDef huart6;

UartMessage_t uartQueue[MAX_UART_QUEUE];
volatile uint8_t uartQueueHead = 0;
volatile uint8_t uartQueueTail = 0;
volatile uint8_t uartQueueCount = 0;

// Function to add message to queue
uint8_t EnqueueUartMessage(const char* message, uint16_t length)
{
    if(uartQueueCount >= MAX_UART_QUEUE) {
        return 0; // Queue full
    }

    if(length >= UART_BUFFER_SIZE) {
        length = UART_BUFFER_SIZE - 1; // Truncate if too long
    }

    memcpy(uartQueue[uartQueueTail].buffer, message, length);
    uartQueue[uartQueueTail].buffer[length] = '\0'; // Null terminate
    uartQueue[uartQueueTail].length = length;

    uartQueueTail = (uartQueueTail + 1) % MAX_UART_QUEUE;
    uartQueueCount++;

    return 1; // Success
}

// Function to process the next message in the queue
void ProcessUartQueue(void)
{
    if(uart_tx_busy == 0 && uartQueueCount > 0)
    {
        uart_tx_busy = 1;

        HAL_UART_Transmit_IT(&huart6,
                          (uint8_t*)uartQueue[uartQueueHead].buffer,
                          uartQueue[uartQueueHead].length);

        uartQueueHead = (uartQueueHead + 1) % MAX_UART_QUEUE;
        uartQueueCount--;
    }
}
