/*
 * 立创开发板软硬件资料与相关扩展板软硬件资料官网全部开源
 * 开发板官网：www.lckfb.com
 * 技术支持常驻论坛，任何技术问题欢迎随时交流学习
 * 立创论坛：https://oshwhub.com/forum
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养中国工程师为己任
 * 

 Change Logs:
 * Date           Author       Notes
 * 2024-03-07     LCKFB-LP    first version
 */
#include "bsp_uart.h"
#include <stdio.h>
#include <rtthread.h>

void thread01_entry(void* parameter);
static rt_thread_t thread01 = RT_NULL;

int main(void)
{
	
	
	uart1_init(115200U);

	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	thread01 = rt_thread_create("thread01",thread01_entry,RT_NULL,512,3,20);
	rt_thread_startup(thread01);

}
void thread01_entry(void* parameter){
	while(1){
		GPIO_SetBits(GPIOB, GPIO_Pin_2);
		rt_thread_delay(1000);
		GPIO_ResetBits(GPIOB, GPIO_Pin_2);
		rt_thread_delay(1000);
	}
}
//int main(void)
//{
//	
//	board_init();
//	
//	uart1_init(115200U);

//	GPIO_InitTypeDef  GPIO_InitStructure;
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	
//	while(1)
//	{
//		GPIO_SetBits(GPIOB, GPIO_Pin_2);
//		printf("LED On!\r\n");
//		delay_ms(200);
//		
//		GPIO_ResetBits(GPIOB, GPIO_Pin_2);
//		printf("LED Off!\r\n");
//		delay_ms(200);
//	}
//	

//}
