/**
 ******************************************************************************
 * @file           : Cortex_M3_SCB.h
 * @author         : Ahmed Khaled
 * @brief          : SCB Source File
 ******************************************************************************/


#include "SCB/Cortex_M3_SCB.h"


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

void SCB_SetPriorityGrouping(u32 PriorityGroup)
{
	/* Initialize a variable to hold the value to be written to AIRCR register */
	u32 Register_Value = 0;
	/*Clear all unnecessary bits in PriorityGroup*/
	u32 PriorityGroupTemp = ((u32) PriorityGroup & (u32) 0X07);

	Register_Value = SCB->AIRCR;

	Register_Value &= SCB_AIRCR_KEY_PRIGROUP_MASK;
	/*
	 * Set the key value in the position and set the PriorityGroup in the position.
	 * The key value is 0x05FA, and it is left-shifted to its position.
	 */
	Register_Value =  Register_Value | ((u32)0X05FA << SCB_AIRCR_VECTKEYSTAT_POS) | (PriorityGroupTemp << SCB_AIRCR_PRIGROUP_POS);

	/*
	 * Access the AIRCR register with the right value.
	 * This is where the actual configuration of the priority grouping takes place.
	 */
	SCB->AIRCR = Register_Value;
}





/**
 *  brief 	 	Get Priority Grouping
 *  details		Get the priority grouping field in the System Control Block (SCB).
 * 	return		Priority grouping field (SCB->AIRCR [10:8] PRIGROUP field).
 */

u32 SCB_GetPriorityGrouping(void)
{
    u32 Register_Val = PRIORITY_GROUP_MASK;  				// Initial value with a mask that covers bits [10:8] in case the configuration changes.
    Register_Val &= SCB->AIRCR; 							// Perform a bitwise AND operation to isolate the relevant bits.
    return (Register_Val >> SCB_AIRCR_PRIGROUP_POS); 		// Right-shift to obtain the actual priority grouping field.
}

