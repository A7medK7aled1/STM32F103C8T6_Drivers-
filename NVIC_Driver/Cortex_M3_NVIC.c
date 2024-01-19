/**
 ******************************************************************************
 * @file           : NVIC.c
 * @author         : Ahmed Khaled
 * @brief          : NVIC Source File
 ******************************************************************************/
#include "NVIC/Cortex_M3_NVIC.h"
#include "Libraries/BIT_MATH.h"



/**
 *  brief 	 	Enable Interrupt
 *  details		Enable a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  note		IRQn must not be negative
 */
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	/* Check if the provided IRQn is a valid positive value */
	if((u32)IRQn >= 0)
	{
		/* Set the specific bit in the selected NVIC_ISER register to enable the interrupt */
		SET_BIT(NVIC->NVIC_ISER[((u32)IRQn >> 5 )],((u32)IRQn &0X1F));
	}

}


/**
 *  brief 	 	Disable Interrupt
 *  details		Disable a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  note		IRQn must not be negative
 */

void NVIC_DisableIRQ(IRQn_Type IRQn)
{

	/* Check if the provided IRQn is a valid positive value */
	if((u32)IRQn >= 0)
	{
		/* Set the specific bit in the selected NVIC_ICER register to disable the interrupt */
		SET_BIT(NVIC->NVIC_ICER[((u32)IRQn >> 5 )],((u32)IRQn &0X1F));
	}

}


/**
 *  brief 	 	Set Pending Interrupt
 *  details		Sets the pending bit of a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  note		IRQn must not be negative
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{

	/* Check if the provided IRQn is a valid positive value */
	if((u32)IRQn >= 0)
	{
		/* Set the specific bit in the selected NVIC_ISPR register to enable pending the interrupt */
		SET_BIT(NVIC->NVIC_ISPR[((u32)IRQn >> 5 )],((u32)IRQn &0X1F));
	}

}

/**
 *  brief 	 	Clear Pending Interrupt
 *  details		Clear the pending bit of a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  note		IRQn must not be negative
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{

	/* Check if the provided IRQn is a valid positive value */
	if((u32)IRQn >= 0)
	{
		/* Set the specific bit in the selected NVIC_ICPR register to disable pending the interrupt */
		SET_BIT(NVIC->NVIC_ICPR[((u32)IRQn >> 5 )],((u32)IRQn &0X1F));
	}

}


/**
 *  brief 	 	Get Active Interrupt
 *  details		Reads the active register in the NVIC and return the active bit of a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  return		0  Interrupt state is not active
 *  return 		1  Interrupt state is active
 *  note		IRQn must not be negative
 */
u32 NVIC_GetActive(IRQn_Type IRQn)
{
	/* Get the specific bit in the selected NVIC_ISER register to enable pending the interrupt */
	return GET_BIT(NVIC->NVIC_IABR[((u32)IRQn >> 5 )],((u32)IRQn &0X1F));
}


/**
 * @brief  Sets the priority for the specified interrupt.
 * @param  IRQn: The interrupt number to set the priority for.
 *         This parameter can be an enumerator of type IRQn_Type.
 * @param  Priority: The priority value to be set for the specified interrupt.
 *         This parameter should be of type u32.
 *         The valid range of priority values depends on the microcontroller architecture.
 *         A lower numerical value indicates a higher priority.
 *         Consult the microcontroller reference manual for specific priority range details.
 */
void NVIC_SetPriority(IRQn_Type IRQn, u32 Priority)
{
	// Check if the provided IRQn is valid
	if((u32)IRQn >= 0)
	{
		// Set priority for the specified interrupt by updating NVIC_IP register

		NVIC->NVIC_IP[(u32)IRQn] = (u8)(Priority << 4)   & (u32) 0XFF;

	}
	else
	{
		/*Nothing*/

	}
}


/**
 * @brief Retrieves the priority level of a specific interrupt request.
 *
 * @detail  This function returns the priority level assigned to the specified interrupt
 * request. The priority level is a 32-bit value, where lower numeric values
 * indicate higher priority.
 *
 * @param IRQn The interrupt request number for which the priority is to be retrieved.
 * @return The priority level of the specified interrupt request.
 */
u32 NVIC_GetPriority(IRQn_Type IRQn)
{
	// Check if the provided IRQn is valid
	if(IRQn >= 0)
	{
        // Retrieve and return the priority for the specified interrupt

		return ((NVIC->NVIC_IP[(u32)IRQn]) >> 4);
	}
	else
	{
		/*Nothing*/
	}
	return 0 ;
}
