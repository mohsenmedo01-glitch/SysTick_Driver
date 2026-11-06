// #include "SysTick_Interface.h"
#include "STD_TYPES.h"
#include "STD_TYPES.h"
#include "SysTick_Private.h"
#include "SysTick_Private.h"
#include "SysTick_Config.h"
#include "SysTick_Config.h"
#include "SysTick_Interface.h"
#include "rcc/RCC_Interface.h"
#include "gpio/Interface.h"
int main(void)
{

    //Mcal_SysTick_Reset();

    while (1)
    {
        Mcal_Rcc_Peripheral_EN_Clock(RCC_AHB1_GPIOCEN ,RCC_AHB1) ;
        Mcal_GPIO_enuSetPinValue(GPIO_C,GPIO_PIN_14,GPIO_HIGH);
        Mcal_STK_Delay(5, AHB);
        Mcal_GPIO_enuSetPinValue(GPIO_C,GPIO_PIN_14,GPIO_LOW);

        /* Your code */

        
    }
}