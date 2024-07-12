#pragma once
#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>

void Serial_Init(void) {
	// 开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	// 初始化引脚，发送数据引脚
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		// 复用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	// A9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// 50Hz翻转速度
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// 初始化串口配置
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600; // 串口波特率
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 不使用流控
	USART_InitStructure.USART_Mode = USART_Mode_Tx; // 串口模式，发送
	USART_InitStructure.USART_Parity = USART_Parity_No; // 无校验
	USART_InitStructure.USART_StopBits = USART_StopBits_1; // 选择一位停止位
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; // 不需要校验位,八位字长
	USART_Init(USART1, &USART_InitStructure);

	// USART1使能
	USART_Cmd(USART1, ENABLE);
}

// 发送函数
void USART_SendByte(uint8_t Byte) {
	USART_SendData(USART1, Byte);
	// 等待写入完成，写入完成之后会将标志位自动清0
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

// 发送数组函数
void USART_SendArray(uint8_t* Array, uint16_t Length) {
	uint8_t i = 0;
	for (i = 0; i < Length; i++) {
		USART_SendData(USART1, Array[i]);
		// 等待写入完成，写入完成之后会将标志位自动清0
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	}
}

// 发送字符串函数
void USART_SendString(uint8_t* String) {
	uint8_t i = 0;
	for (i = 0; String[i] != '\0'; i++) {
		USART_SendData(USART1, String[i]);
		// 等待写入完成，写入完成之后会将标志位自动清0
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	}
}

// 返回X的Y次方
uint32_t Serial_Pow(uint32_t X, uint32_t Y) {
	uint32_t Result = 1;
	while (Y--) {
		Result *= X;
	}
	return Result;
}
// 发送数字函数
void USART_SendNum(uint32_t Num, uint16_t Length) {
	uint8_t i = 0;
	for (i = 0; i < Length; i++) {
		USART_SendByte(Num / Serial_Pow(10, Length - i - 1) % 10 + 0x30);
		// 等待写入完成，写入完成之后会将标志位自动清0
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	}
}

//重定向fputc函数，fputc是printf函数的底层，printf通过不停的调用fputc来达到输出的效果
//重定向到串口
int fputc(int ch, FILE* f) {
	USART_SendByte(ch);
	return ch;
}

// 封装使用sprintf输出到串口
void Serial_Printf(char* format, ...)
{
	char String[100];
	va_list arg;							// 可变参数列表
	va_start(arg, format);		// 从format开始接收可变参数
	vsprintf(String, format, arg);
	va_end(arg);
	USART_SendString((uint8_t*)String);
}


