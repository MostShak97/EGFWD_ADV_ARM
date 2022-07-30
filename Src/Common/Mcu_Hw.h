/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND0  :3;
    uint32 VECPEND1  :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define NVIC_EN0                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define SYSTEM_CONTROL_BASE_ADDRESS            0x400FE000
#define RCGTIMER                               *((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS+0x604))
#define TIMER0_BASE_ADDRESS                    0x40030000
#define GPTMCFG                                *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x000))
#define GPTMTAMR                               *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x004))
#define GPTMCTL                                *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x00C))
#define GPTMIMR                                *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x018))
#define GPTMICR                                *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x024))
#define GPTMTAILR                              *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x028))
#define GPTMTAR                                *((volatile uint32*)(TIMER0_BASE_ADDRESS+0x048))
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
