#ifndef __FATFS_TEST_H__
#define __FATFS_TEST_H__

/*
*************************************************************************
*                             ������ͷ�ļ�
*************************************************************************
*/


/* ������Ӳ��bspͷ�ļ� */
#include "stm32f10x.h"
#include "led/bsp_led.h" 
#include "./flash/bsp_spi_flash.h"
#include "ff.h"



/*
*************************************************************************
*                             ��������
*************************************************************************
*/

extern FATFS fs;													/* FatFs�ļ�ϵͳ���� */
//FIL fnew;													/* �ļ����� */
extern FRESULT res_flash;                /* �ļ�������� */
//UINT fnum;            					  /* �ļ��ɹ���д���� */
//BYTE ReadBuffer[1024];        /* �������� */
//extern BYTE WriteBuffer; 

//FATFS fs;													/* FatFs�ļ�ϵͳ���� */
//FIL fnew;													/* �ļ����� */
//FRESULT res_flash;                /* �ļ�������� */
//UINT fnum;            					  /* �ļ��ɹ���д���� */
//BYTE ReadBuffer[1024]={0};        /* �������� */
//BYTE WriteBuffer[] =              /* д������*/
//"��ӭʹ�ñ���STM32������ �����Ǹ������ӣ��½��ļ�ϵͳ�����ļ�\r\n"; 

/*
*************************************************************************
*                               ��������
*************************************************************************
*/

void FileSystem_Init(void);

void FileSystem_Test(void);




#endif /* __FATFS_TEST_H__ */




