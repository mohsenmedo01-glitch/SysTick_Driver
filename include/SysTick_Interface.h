                                    /*     author : Mohamed Junior          */
                                /*          Date 20/10/2026            */
#ifndef SysTick_INTERFACE_H_
#define SysTick_INTERFACE_H_
#include "STD_TYPES.h"
RCC_CLK_MODE_t;
typedef enum {
    AHB_8,
    AHB

}RCC_CLK_TYPE_t;

#endif

Std_ReturnType Mcal_SysTick_Clk(RCC_CLK_TYPE_t copy_clk_type);
Std_ReturnType Mcal_STK_Delay(u32 Copy_u32Seconds , RCC_CLK_TYPE_t copy_clk_type);
