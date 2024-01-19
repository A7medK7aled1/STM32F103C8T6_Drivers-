/**
 ******************************************************************************
 * @file           : Cortex_M3_RCC.h
 * @author         : Ahmed Khaled
 * @brief          : Contain the declarations to RCC function and Macros
 ******************************************************************************/

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_


/***********************Include Start******************/
#include "Libraries/STD_TYPES.h"

/***********************Include End*******************/

/***********************Macros Start******************/
#define RCC_HSI				                0			/* RCC_HSI: Internal High-Speed Clock.*/
#define RCC_HSE				                1			/* RCC_HSE: External High-Speed Clock.*/
#define RCC_PLL				                2			/* RCC_PLL: Phase-Locked*/


#define AHB_BUS								0
#define APB1_BUS							1
#define APB2_BUS							2

// AHB_PRESCALER_NOT_DIVIDED: No prescaler, AHB operates at its maximum frequency.
#define AHB_PRESCALER_NOT_DIVIDED           0b000
// AHB_PRESCALER_DIVIDED_BY_2: AHB clock is divided by 2.
#define AHB_PRESCALER_DIVIDED_BY_2          0b1000
// AHB_PRESCALER_DIVIDED_BY_4: AHB clock is divided by 4.
#define AHB_PRESCALER_DIVIDED_BY_4          0b1001
// AHB_PRESCALER_DIVIDED_BY_8: AHB clock is divided by 8.
#define AHB_PRESCALER_DIVIDED_BY_8          0b1010
// AHB_PRESCALER_DIVIDED_BY_16: AHB clock is divided by 16.
#define AHB_PRESCALER_DIVIDED_BY_16         0b1011
// AHB_PRESCALER_DIVIDED_BY_64: AHB clock is divided by 64.
#define AHB_PRESCALER_DIVIDED_BY_64         0b1100
// AHB_PRESCALER_DIVIDED_BY_128: AHB clock is divided by 128.
#define AHB_PRESCALER_DIVIDED_BY_128        0b1101
// AHB_PRESCALER_DIVIDED_BY_256: AHB clock is divided by 256.
#define AHB_PRESCALER_DIVIDED_BY_256        0b1110
// AHB_PRESCALER_DIVIDED_BY_512: AHB clock is divided by 512.
#define AHB_PRESCALER_DIVIDED_BY_512        0b1111

#define APB1_PRESCALER_DIV_NONE             0b000   // HCLK not divided
#define APB1_PRESCALER_DIV_2                0b100   // HCLK divided by 2
#define APB1_PRESCALER_DIV_4                0b101   // HCLK divided by 4
#define APB1_PRESCALER_DIV_8                0b110   // HCLK divided by 8
#define APB1_PRESCALER_DIV_16               0b111   // HCLK divided by 16


// Define macros for APB2 high-speed prescaler
#define APB2_PRESCALER_NOT_DIVIDED          0b000    // HCLK not divided
#define APB2_PRESCALER_DIVIDED_BY_2         0b100    // HCLK divided by 2
#define APB2_PRESCALER_DIVIDED_BY_4         0b101    // HCLK divided by 4
#define APB2_PRESCALER_DIVIDED_BY_8         0b110    // HCLK divided by 8
#define APB2_PRESCALER_DIVIDED_BY_16        0b111    // HCLK divided by 16



//Peripheral IDs
// Enable/disable Ethernet MAC receiver on the AHB bus
#define ETHMACRXEN_AHB     					16

// Enable/disable Ethernet MAC transmitter on the AHB bus
#define ETHMACTXEN_AHB     					15

// Enable/disable Ethernet MAC on the AHB bus
#define ETHMACEN_AHB     					14

// Enable/disable USB OTG full-speed on the AHB bus
#define OTGFSEN_AHB     					12

// Enable/disable CRC (Cyclic Redundancy Check) on the AHB bus
#define CRCEN_AHB     						6

// Enable/disable Flash Interface on the AHB bus
#define FLITFEN_AHB     					4

// Enable/disable SRAM Interface on the AHB bus
#define SRAMEN_AHB     						2

// Enable/disable DMA2 on the AHB bus
#define DMA2EN_AHB     						1

// Enable/disable DMA1 on the AHB bus
#define DMA1EN_AHB     						0


// Enable/disable Alternate Function I/O (AFIO) on the APB bus
#define AFIOEN_APB                          0

// Enable/disable GPIO Port A on the APB2 bus
#define GPIOA_APB2                          1

// Enable/disable GPIO Port B on the APB2 bus
#define GPIOB_APB2                          2

// Enable/disable GPIO Port C on the APB2 bus
#define GPIOC_APB2                          3

// Enable/disable ADC1 on the APB2 bus
#define ADC1EN_APB2                         9

// Enable/disable ADC2 on the APB2 bus
#define ADC2EN_APB2                         10

// Enable/disable Timer 1 on the APB2 bus
#define TIM1EN_APB2                         11

// Enable/disable SPI1 on the APB2 bus
#define SPI1EN_APB2                         12

// Enable/disable USART1 on the APB2 bus
#define USART1EN_APB2                       14// Incomplete definition, it seems like there is a missing value



// Enable/disable Timer 2 on the APB1 bus
#define TIM2EN_APB1                          0

// Enable/disable Timer 3 on the APB1 bus
#define TIM3EN_APB1                          1

// Enable/disable Timer 4 on the APB1 bus
#define TIM4EN_APB1                          2

// Enable/disable Timer 5 on the APB1 bus
#define TIM5EN_APB1                          3

// Enable/disable Timer 6 on the APB1 bus
#define TIM6EN_APB1                          4

// Enable/disable Timer 7 on the APB1 bus
#define TIM7EN_APB1                          5

// Enable/disable Window Watchdog on the APB1 bus
#define WWDGEN_APB1                          11

// Enable/disable SPI2 on the APB1 bus
#define SPI2EN_APB1                          14

// Enable/disable SPI3 on the APB1 bus
#define SPI3EN_APB1                          15

// Enable/disable USART2 on the APB1 bus
#define USART2EN_APB1                        17

// Enable/disable USART3 on the APB1 bus
#define USART3EN_APB1                        18

// Enable/disable USART4 on the APB1 bus
#define USART4EN_APB1                        19

// Enable/disable USART5 on the APB1 bus
#define USART5EN_APB1                        20

// Enable/disable I2C1 on the APB1 bus
#define I2C1EN_APB1                          21

// Enable/disable I2C2 on the APB1 bus
#define I2C2EN_APB1                          22

// Enable/disable CAN1 on the APB1 bus
#define CAN1EN_APB1                          25

// Enable/disable CAN2 on the APB1 bus
#define CAN2EN_APB1                          26

// Enable/disable Backup interface on the APB1 bus
#define BKPEN_APB1                           27

// Enable/disable Power control on the APB1 bus
#define PWREN_APB1                           28

// Enable/disable DAC on the APB1 bus
#define DACEN_APB1                           29



/***********************Macros End******************/

/***********************Data Type Start******************/

typedef struct{

	u8 AHB_Divide;
	u8 APB1_Divide;
	u8 APB2_Divide;

}Prescaler_State;
/***********************Software Interface Start******************/

/*
 * Function: RCC_voidInitSysCLK
 * Description: Initializes the system clock by selecting the clock source from HSI, HSE, or PLL.
 * Parameters:
 *    - u8 CLK_Source: Specifies the desired clock source (HSI, HSE, or PLL).
 *                    Valid values: RCC_HSI, RCC_HSE, RCC_PLL (predefined constants).
 * Return: None
 */
void RCC_voidInitSysCLK(u8 CLK_Source);


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
void RCC_voidSysCLKPrescaler(Prescaler_State * Prescaler_Val);



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
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

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
void RCC_voidDisablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);



/***********************Software Interface End******************/



#endif /* RCC_RCC_INTERFACE_H_ */
