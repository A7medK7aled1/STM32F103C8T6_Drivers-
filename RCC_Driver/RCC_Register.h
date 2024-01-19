/**
 ******************************************************************************
 * @file           : Cortex_M3_RCC.h
 * @author         : Ahmed Khaled
 * @brief          : Contain the declarations to RCC Registers
 ******************************************************************************/

#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_


/***********************Includes Start******************/
#include "Libraries/STD_TYPES.h"
/***********************Includes End********************/

/***********************Data Type Start******************/
typedef struct {
    volatile u32 CR;          // Offset: 0x00 - Clock Control Register
    volatile u32 CFGR;        // Offset: 0x04 - Clock Configuration Register
    volatile u32 CIR;         // Offset: 0x08 - Clock Interrupt Register
    volatile u32 APB2RSTR;    // Offset: 0x0C - APB2 Peripheral Reset Register
    volatile u32 APB1RSTR;    // Offset: 0x10 - APB1 Peripheral Reset Register
    volatile u32 AHBENR;      // Offset: 0x14 - AHB Peripheral Clock Enable Register
    volatile u32 APB2ENR;     // Offset: 0x18 - APB2 Peripheral Clock Enable Register
    volatile u32 APB1ENR;     // Offset: 0x1C - APB1 Peripheral Clock Enable Register
    volatile u32 BDCR;        // Offset: 0x20 - Backup Domain Control Register
    volatile u32 CSR;         // Offset: 0x24 - Control/Status Register
} RCC_TypeDef;
/***********************Data Type End******************/

/***********************Macros Start******************/
// RCC register base address
#define RCC_BASE					0X40021000UL

// RCC peripheral instance
#define RCC							((RCC_TypeDef *) RCC_BASE)

// Bit positions for various control bits related to High-Speed External (HSE) and High-Speed Internal (HSI) oscillators
#define HSEON_BIT					16U
#define HSERDY_BIT					17U
#define HSION_BIT					0U
#define HSIRDY_BIT					1U

// Bit positions for control bits related to the Phase-Locked Loop (PLL)
#define PLLON_BIT					24U
#define PLLRDY_BIT					25U

// Bit position for control bit related to Clock Security System (CSS)
#define CSS_BIT						19

// Bit positions for the SW (System Clock Switch) control bits
#define SW0_BIT							0
#define SW1_BIT							1U

//RCC Masks

// Mask to clear the bits responsible for APB1 prescaler in the RCC_CFGR register
#define ABP1_PRE_MASK                0XFFFFF8FFUL

// Mask to clear the bits responsible for APB2 prescaler in the RCC_CFGR register
#define ABP2_PRE_MASK                0XFFFFC7FFUL

// Mask to clear the bits responsible for AHB prescaler in the RCC_CFGR register
#define AHP_PRE_MASK                 0XFFFFFF0FUL


/***********************Macros End******************/

/***********************Macros Functions Start******************/

/***********************Macros Functions End******************/








#endif /* CORTEX_M3_RCC_H_ */
