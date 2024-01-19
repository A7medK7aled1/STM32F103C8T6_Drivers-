/**
 ******************************************************************************
 * @file           : Cortex_M3_RCC.c
 * @author         : Ahmed Khaled
 * @brief          : Contain the declarations to RCC
 ******************************************************************************/

#include "RCC/Cortex_M3_RCC.h"
#include "Libraries/BIT_MATH.h"



/*
 * Function: RCC_voidInitSysCLK
 * Description: Initializes the system clock by selecting the clock source from HSI, HSE, or PLL.
 * Parameters:
 *    - u8 CLK_Source: Specifies the desired clock source (HSI, HSE, or PLL).
 *                    Valid values: RCC_HSI, RCC_HSE, RCC_PLL (predefined constants).
 * Return: None
 */
void RCC_voidInitSysCLK(u8 CLK_Source)
{
	// Select the appropriate clock source based on the provided parameter
	switch(CLK_Source)
	{
	case RCC_HSE:
		// Enable HSE and wait until it is ready
		SET_BIT(RCC->CR, HSEON_BIT);
		while(GET_BIT(RCC->CR, HSERDY_BIT) != 1);		/*Wait until CLK is ready*/

		// Select HSE as the system clock source
		SET_BIT(RCC->CFGR, SW0_BIT);
		CLR_BIT(RCC->CFGR, SW1_BIT);
		break;

	case RCC_HSI:
		// Enable HSI and wait until it is ready
		SET_BIT(RCC->CR, HSION_BIT);
		while(GET_BIT(RCC->CR, HSIRDY_BIT) != 1);		/*Wait until CLK is ready*/

		// Select HSI as the system clock source
		CLR_BIT(RCC->CFGR, SW0_BIT);
		CLR_BIT(RCC->CFGR, SW1_BIT);
		break;

	case RCC_PLL:
		// Enable PLL and wait until it is ready
		SET_BIT(RCC->CR, PLLON_BIT);
		while(GET_BIT(RCC->CR, PLLRDY_BIT) != 1);		/*Wait until CLK is ready*/

		// Select PLL as the system clock source
		CLR_BIT(RCC->CFGR, SW0_BIT);
		SET_BIT(RCC->CFGR, SW1_BIT);
		break;
	}

	// Enable Clock Security System (CSS)
	SET_BIT(RCC->CR, CSS_BIT);
}



/**
 * @brief Configure the system clock prescaler values for AHB, APB1, and APB2 buses.
 *
 * This function takes a pointer to a structure of type Prescaler_State, which contains
 * the desired prescaler values for AHB, APB1, and APB2 buses. The function configures
 * the system clock prescaler accordingly.
 *
 * @param Prescaler_Val Pointer to a Prescaler_State structure containing the desired
 *                      prescaler values.
 *
 * @note The macro definitions AHB_PRESCALER_NOT_DIVIDED, AHB_PRESCALER_DIVIDED_BY_2, etc.,
 *       are used to represent possible values for the AHB bus prescaler.
 *
 * @note The macro definitions APB1_PRESCALER_DIV_NONE, APB1_PRESCALER_DIV_2, etc.,
 *       are used to represent possible values for the APB1 bus prescaler.
 *
 * @note The macro definitions APB2_PRESCALER_NOT_DIVIDED, APB2_PRESCALER_DIVIDED_BY_2, etc.,
 *       are used to represent possible values for the APB2 bus prescaler.
 *
 * @retval None
 */
void RCC_voidSysCLKPrescaler(Prescaler_State * Prescaler_Val)
{


	RCC->CFGR &=ABP1_PRE_MASK;							/* Clear existing APB1 prescaler bits*/
	RCC->CFGR |=((Prescaler_Val->APB1_Divide) <<8);		/*Set the new APB1 prescaler values*/

	RCC->CFGR &=ABP2_PRE_MASK;                         /* Clear existing APB2 prescaler bits*/
	RCC->CFGR |=((Prescaler_Val->APB2_Divide) <<11);   /*Set the new APB2 prescaler values*/

	RCC -> CFGR = ((RCC -> CFGR) & AHP_PRE_MASK) | (Prescaler_Val->AHB_Divide << 4);  /* Clear existing AHB prescaler bits and set the new AHB prescaler values*/
}


/**
 * @brief Enables the clock for a specific peripheral on a given bus.
 *
 * This function is responsible for enabling the clock for a specific peripheral
 * on the specified bus. It utilizes the RCC (Reset and Clock Control) module
 * to configure and enable the clock for the desired peripheral.
 *
 * @param Copy_u8BusID        The bus ID to which the peripheral is connected.
 *                             This parameter should be one of the predefined
 *                             constants indicating the bus (e.g., AHB_BUS, APB1_BUS).
 * @param Copy_u8PeripheralID The ID of the peripheral for which the clock needs
 *                             to be enabled. This parameter should be one of the
 *                             predefined constants indicating the peripheral
 *                             (e.g., GPIOAEN_APB2, CAN1EN_APB1).
 *
 * @note This function assumes that the RCC module is properly configured and
 *       initialized before calling this function. Also, it's essential to refer
 *       to the microcontroller's datasheet/reference manual for correct bus and
 *       peripheral IDs.
 *
 * @note Enabling the clock for a peripheral is crucial before any operations
 *       involving that peripheral (e.g., configuring GPIO pins, initializing
 *       USART) to ensure proper functionality.
 */
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	// Switch based on the bus ID to enable the peripheral on the appropriate bus.
	switch(Copy_u8BusID)
	{
	case AHB_BUS:SET_BIT(RCC->AHBENR,Copy_u8PeripheralID);break;	   // Set the corresponding bit in the AHBENR register to enable the peripheral.
	case APB1_BUS:SET_BIT(RCC->APB1ENR,Copy_u8PeripheralID);break;	   // Set the corresponding bit in the APB1ENR register to enable the peripheral.
	case APB2_BUS:SET_BIT(RCC->APB2ENR,Copy_u8PeripheralID);break;	   // Set the corresponding bit in the APB2ENR register to enable the peripheral.
	}
}


/**
 * @brief Disables the clock for a specific peripheral on a specified bus.
 *
 * This function is used to disable the clock for a peripheral on a given bus.
 *
 * @param Copy_u8BusID: The ID of the bus to which the peripheral belongs.
 *                      		(e.g., AHB_BUS, APB1_BUS, APB2_BUS)
 *
 * @param Copy_u8PeripheralID: The ID of the peripheral whose clock needs to be disabled.
 *                             (e.g., GPIOAEN_APB2, CAN1EN_APB1)
 *
 * @return None
 *
 * @note  This function assumes that the RCC (Reset and Clock Control) module is properly
 *        initialized and configured before calling this function.
 *        It disables the clock for the specified peripheral, which may impact its functionality.
 *        Use this function with caution and ensure that the peripheral is no longer needed
 *        before disabling its clock.
 */
void RCC_voidDisablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
    // Switch based on the bus ID to disable the peripheral on the appropriate bus.
    switch (Copy_u8BusID)
    {
        case AHB_BUS:
            // Clear the corresponding bit in the AHBENR register to disable the peripheral.
            CLR_BIT(RCC->AHBENR, Copy_u8PeripheralID);
            break;

        case APB1_BUS:
            // Clear the corresponding bit in the APB1ENR register to disable the peripheral.
            CLR_BIT(RCC->APB1ENR, Copy_u8PeripheralID);
            break;

        case APB2_BUS:
            // Clear the corresponding bit in the APB2ENR register to disable the peripheral.
            CLR_BIT(RCC->APB2ENR, Copy_u8PeripheralID);
            break;
    }
}
