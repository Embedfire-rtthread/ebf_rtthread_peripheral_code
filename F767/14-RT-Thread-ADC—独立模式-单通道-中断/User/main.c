/**
  *********************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2018-xx-xx
  * @brief   RT-Thread 3.0 + STM32 固件库例程
  *********************************************************************
  * @attention
  *
  * 实验平台:野火 STM32F767 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  **********************************************************************
  */ 
 
/*
*************************************************************************
*                             包含的头文件
*************************************************************************
*/ 
#include "board.h"
#include "rtthread.h"

/*
*************************************************************************
*                               变量
*************************************************************************
*/
/* 定义线程控制块 */
static rt_thread_t test_thread = RT_NULL;

/* 定义信号量控制块 */
rt_sem_t test_sem = RT_NULL;

// ADC1转换的电压值通过MDA方式传到SRAM
extern __IO uint16_t ADC_ConvertedValue;

// 局部变量，用于保存转换计算后的电压值 	 
float ADC_Vol; 

extern ADC_HandleTypeDef ADC_Handle;
/*
*************************************************************************
*                             函数声明
*************************************************************************
*/
static void test_thread_entry(void* parameter);


/*
*************************************************************************
*                             main 函数
*************************************************************************
*/
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
    /* 
	 * 开发板硬件初始化，RTT系统初始化已经在main函数之前完成，
	 * 即在component.c文件中的rtthread_startup()函数中完成了。
	 * 所以在main函数中，只需要创建线程和启动线程即可。
	 */
	  /* 创建一个信号量 */
	test_sem = rt_sem_create("test_sem",/* 消息队列名字 */
                     0,     /* 信号量初始值，默认有一个信号量 */
                     RT_IPC_FLAG_FIFO); /* 信号量模式 FIFO(0x00)*/
  if (test_sem != RT_NULL)
    rt_kprintf("信号量创建成功！\n\n");
  
	test_thread =                          /* 线程控制块指针 */
    rt_thread_create( "test",              /* 线程名字 */
                      test_thread_entry,   /* 线程入口函数 */
                      RT_NULL,             /* 线程入口函数参数 */
                      512,                 /* 线程栈大小 */
                      3,                   /* 线程的优先级 */
                      20);                 /* 线程时间片 */
                   
    /* 启动线程，开启调度 */
   if (test_thread != RT_NULL)
        rt_thread_startup(test_thread);
    else
        return -1;
}

/*
*************************************************************************
*                             线程定义
*************************************************************************
*/

static void test_thread_entry(void* parameter)
{	
  Rheostat_Init();
  while (1)
  {
    rt_sem_take(test_sem,	            /* 获取串口中断的信号量 */
                RT_WAITING_FOREVER); 	/* 等待时间：RT_WAITING_FOREVER */
    ADC_Vol =(float) ADC_ConvertedValue/4096*(float)3.3; // 读取转换的AD值
    printf("\r\n The current AD value = 0x%04X \r\n", ADC_ConvertedValue); 
    printf("\r\n The current AD value = %f V \r\n",ADC_Vol);     
    
    rt_thread_delay(500);   /* 延时500个tick */
  }
}

/********************************END OF FILE****************************/
