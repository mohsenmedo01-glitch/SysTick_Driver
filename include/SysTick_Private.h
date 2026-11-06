#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define STK_BASE_ADDRESS       0xE000E010

#define STK_CTRL       *((volatile u32*)0xE000E010)
#define STK_LOAD       *((volatile u32*)0xE000E014)
#define STK_VAL        *((volatile u32*)0xE000E018)
#define STK_CALIB      *((volatile u32*)0xE000E01C)

/* STK_CTRL Bits */
#define STK_COUNTFLAG               16
#define STK_CLKSOURCE               2
#define STK_TICKINT                 1
#define STK_COUNTER_En_Dis          0 


/* STK_LOAD Bits */
#define STK_RELOAD          0   /* Bits 23:0 */


/* STK_VAL Bits */
#define STK_CURRENT         0   /* Bits 23:0 */


/* STK_CALIB Bits */
#define STK_NOREF           31
#define STK_SKEW            30
#define STK_TENMS           0   /* Bits 23:0 */


#endif
