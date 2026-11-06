
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SysTick_Private.h"
#include "SysTick_Config.h"
#include "SysTick_Interface.h"

Std_ReturnType Mcal_SysTick_Clk(RCC_CLK_TYPE_t copy_clk_type)
{
    Std_ReturnType Local_status = C_NOT_OK;

    switch (copy_clk_type)
    {
        case AHB_8:

            CLR_BIT(STK_CTRL, STK_CLKSOURCE);
            Local_status = C_OK;

            break;

        case AHB:

            SET_BIT(STK_CTRL, STK_CLKSOURCE);
            Local_status = C_OK;

            break;

        default:

            Local_status = C_NOT_OK;

            break;
    }

    return Local_status;
}

u32 Mcal_SysTick_Remain_count(void){

    return STK_VAL;
} 

Std_ReturnType Mcal_SysTick_Reset()
{
    Std_ReturnType Local_status = C_NOT_OK;
    CLR_BIT(STK_CTRL, STK_COUNTER_En_Dis );     // Make Counter disabled 
    STK_VAL = RESET_COUNTER;      //= any value make the register =0 and reset the counter
    STK_LOAD=RESET_LOAD;
    Local_status=C_OK; 
    return Local_status;
}

Std_ReturnType Mcal_STK_Delay(u32 Copy_u32Delay_Seconds,RCC_CLK_TYPE_t copy_clk_type)
{
    Std_ReturnType Local_status = C_NOT_OK;

    u32 Local_u32RequiredOverflows;
    u32 Local_u32Counter;

    /* Convert Seconds to Milliseconds */
    Local_u32RequiredOverflows = Copy_u32Delay_Seconds * SECONDS;

    /* Reset SysTick */
    Mcal_SysTick_Reset();

    /* Select Clock Source */
    Local_status = Mcal_SysTick_Clk(copy_clk_type);

    if (Local_status == C_OK)
    {
        /* Set Reload Value */
        if (copy_clk_type == AHB)
        {
            STK_LOAD = STK_LOAD_AHB;
        }
        else
        {
            STK_LOAD = STK_LOAD_AHB_8;
        }

        /* Clear Current Value */
        STK_VAL = 0U;

        /* Enable SysTick */
        SET_BIT(STK_CTRL, STK_COUNTER_En_Dis);

        /* Wait for Required Overflows */
        for (Local_u32Counter = 0U;
            Local_u32Counter < Local_u32RequiredOverflows;
            Local_u32Counter++)
        {
            while (GET_BIT(STK_CTRL, STK_COUNTFLAG) == 0U)
            {
                /* Waiting for Overflow */
            }
        }

        /* Reset SysTick */
        Mcal_SysTick_Reset();
    }

    return Local_status;
}