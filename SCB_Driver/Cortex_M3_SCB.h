/**
 ******************************************************************************
 * @file           : Cortex_M3_SCB.h
 * @author         : Ahmed Khaled
 * @brief          : SCB Header File
 ******************************************************************************/

#ifndef CORTEX_M3_SCB_H_
#define CORTEX_M3_SCB_H_

/***************************************Start Include Section*****************/
#include "Libraries/STD_TYPES.h"
/***************************************End Include Section*****************/
/******************************Start Data Type Section***********************/

typedef struct {
	volatile u32 CPUID;                // CPUID Base Register
	volatile u32 ICSR;                 // Interrupt Control and State Register
	volatile u32 VTOR;                 // Vector Table Offset Register
	volatile u32 AIRCR;                // Application Interrupt and Reset Control Register
	volatile u32 SCR;                  // System Control Register
	volatile u32 CCR;                  // Configuration and Control Register
	volatile u32  SHPR1;         		// System Handler Priority Register 1
	volatile u32  SHPR2;               // System Handler Priority Register 2
	volatile u32  SHPR3;               // System Handler Priority Register 3
	volatile u32 SHCSR;                // System Handler Control and State Register
	volatile u32 CFSR;                 // Configurable Fault Status Register
} SCB_Type;


/******************************End Data Type Section***********************/

/********************************************Macro Section Start********************************/
#define SCB_BASE        (0xE000ED00U)       // SCB base address
#define SCB             ((SCB_Type *) SCB_BASE)

#define SCB_PRIORITYGROUP_0					0X00000007U			/*0 bit for pre-emption priority
																	and 4 bit for sub priority*/
#define SCB_PRIORITYGROUP_1                 0X00000006U			/*1 bit for pre-emption priority
																	and 3 bit for sub priority*/
#define SCB_PRIORITYGROUP_2                 0X00000005U			/*2 bit for pre-emption priority
																	and 2 bit for sub priority*/
#define SCB_PRIORITYGROUP_3                 0X00000004U			/*3 bit for pre-emption priority
																	and 1 bit for sub priority*/
#define SCB_PRIORITYGROUP_4                 0X00000003U			/*4 bit for pre-emption priority
																	and 0 bit for sub priority*/


#define SCB_AIRCR_PRIGROUP_POS				8U					/*SCB_AIRCR  Prigroup Position*/
#define SCB_AIRCR_VECTKEYSTAT_POS			16U					/*SCB_AIRCR  VECTKEY State Position*/
#define SCB_AIRCR_KEY_PRIGROUP_MASK			0XF8FFUL			/*Clear the VECKTKEY and PRIGROUP Positions*/
#define PRIORITY_GROUP_MASK					0x700UL				/*// Initial value with a mask that covers bits [10:8]*/

/********************************************Macro End Section**********************************/

/***********************************Software Interface Section Start*****************************/


/**
 *  brief 	 	Set Priority Grouping
 *  details		Sets the priority grouping field in the System Control Block (SCB).
 *  param [in]	 PriorityGroup: The priority grouping bits to be set.
 *         This parameter can be one of the following values:
 *           - SCB_PRIORITYGROUP_0: 0 bits for group priority, 4 bits for subpriority.
 *           - SCB_PRIORITYGROUP_1: 1 bit for group priority,  3 bits for subpriority.
 *           - SCB_PRIORITYGROUP_2: 2 bits for group priority, 2 bits for subpriority.
 *           - SCB_PRIORITYGROUP_3: 3 bits for group priority, 1 bits for subpriority.
 *           - SCB_PRIORITYGROUP_4: 4bits for group priority,  0 bits for subpriority.
 */

void SCB_SetPriorityGrouping(u32 PriorityGroup);

/**
 *  brief 	 	Get Priority Grouping
 *  details		Get the priority grouping field in the System Control Block (SCB).
 * 	return		Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
 */

u32 SCB_GetPriorityGrouping(void);




/***********************************Software Interface End Start*****************************/


#endif /* CORTEX_M3_SCB_H_ */
