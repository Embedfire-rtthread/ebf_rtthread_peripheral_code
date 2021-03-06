#ifndef __BOARD_H__
#define __BOARD_H__

/*
*************************************************************************
*                             包含的头文件
*************************************************************************
*/
/* STM32 固件库头文件 */
#include "stm32f4xx.h"

#include <rthw.h>
#include <rtthread.h>

/* 开发板硬件bsp头文件 */
#include "bsp_led.h"
#include "bsp_debug_usart.h"
#include "./flash/bsp_spi_flash.h"
#include "ff.h"
#include "FatFs_test.h"
/*
*************************************************************************
*                               函数声明
*************************************************************************
*/
void rt_hw_board_init(void);
void SysTick_Handler(void);
	

#endif /* __BOARD_H__ */
