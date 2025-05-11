/*
 * UART_Queue.h
 *
 *  Created on: May 9, 2025
 *      Author: mihneadorcu
 */
#include "main.h"

#ifndef SRC_UART_QUEUE_H_
#define SRC_UART_QUEUE_H_
#define UART_BUFFER_SIZE 512
typedef struct {
    char buffer[UART_BUFFER_SIZE];
    uint16_t length;
} UartMessage_t;

uint8_t EnqueueUartMessage(const char* message, uint16_t length);

void ProcessUartQueue(void);

#endif /* SRC_UART_QUEUE_H_ */
