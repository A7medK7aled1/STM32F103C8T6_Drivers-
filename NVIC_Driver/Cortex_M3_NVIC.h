/**
 ******************************************************************************
 * @file           : NVIC.h
 * @author         : Ahmed Khaled
 * @brief          : NVIC Header File
 ******************************************************************************/

#ifndef NVIC_H_
#define NVIC_H_



/************************************Start Include Section*******************/
#include "Libraries/STD_TYPES.h"
/***************************************End Include Section*****************/
/******************************Start Data Type Section***********************/

typedef struct {
    volatile u32 NVIC_ISER[8U];      // Interrupt Set Enable Register
    u32 RESERVED0[24U];         // Reserved space
    volatile u32 NVIC_ICER[8U];      // Interrupt Clear Enable Register
    u32 RSERVED1[24U];          // Reserved space
    volatile u32 NVIC_ISPR[8U];      // Interrupt Set Pending Register
    u32 RESERVED2[24U];         // Reserved space
    volatile u32 NVIC_ICPR[8U];      // Interrupt Clear Pending Register
    u32 RESERVED3[24U];         // Reserved space
    volatile u32 NVIC_IABR[8U];      // Interrupt Active Bit Register
    u32 RESERVED4[56U];         // Reserved space
    volatile u8 NVIC_IP[240U];       // Interrupt Priority Register (8-bit wide)
    u32 RESERVED5[644U];        // Reserved space
    volatile u32 NVIC_STIR;         // Software Triggered Interrupt Register
} NVIC_Type;

#define NVIC_BASE_ADDRESS  0xE000E100   // Base address of NVIC in memory

#define NVIC  ((NVIC_Type *) NVIC_BASE_ADDRESS)


/*******Vector Table STM32F103C8T6***********/


typedef enum {
    NonMaskableInt_IRQn         = -14, /*!< 2 Non Maskable Interrupt                                          */
    MemoryManagement_IRQn      = -12, /*!< 4 Cortex-M3 Memory Management Interrupt                         */
    BusFault_IRQn               = -11, /*!< 5 Cortex-M3 Bus Fault Interrupt                                  */
    UsageFault_IRQn             = -10, /*!< 6 Cortex-M3 Usage Fault Interrupt                                */
    SVCall_IRQn                 = -5,  /*!< 11 Cortex-M3 SV Call Interrupt                                   */
    DebugMonitor_IRQn           = -4,  /*!< 12 Cortex-M3 Debug Monitor Interrupt                             */
    PendSV_IRQn                 = -2,  /*!< 14 Cortex-M3 Pend SV Interrupt                                   */
    SysTick_IRQn                = -1,  /*!< 15 Cortex-M3 System Tick Interrupt                               */
    WWDG_IRQn                   = 0,   /*!< Window WatchDog Interrupt                                        */
    PVD_IRQn                    = 1,   /*!< PVD through EXTI Line detection Interrupt                        */
    TAMPER_IRQn                 = 2,   /*!< Tamper Interrupt                                                 */
    RTC_IRQn                    = 3,   /*!< RTC global Interrupt                                             */
    FLASH_IRQn                  = 4,   /*!< FLASH global Interrupt                                           */
    RCC_IRQn                    = 5,   /*!< RCC global Interrupt                                             */
    EXTI0_IRQn                  = 6,   /*!< EXTI Line0 Interrupt                                             */
    EXTI1_IRQn                  = 7,   /*!< EXTI Line1 Interrupt                                             */
    EXTI2_IRQn                  = 8,   /*!< EXTI Line2 Interrupt                                             */
    EXTI3_IRQn                  = 9,   /*!< EXTI Line3 Interrupt                                             */
    EXTI4_IRQn                  = 10,  /*!< EXTI Line4 Interrupt                                             */
    DMA1_Channel1_IRQn          = 11,  /*!< DMA1 Channel 1 global Interrupt                                  */
    DMA1_Channel2_IRQn          = 12,  /*!< DMA1 Channel 2 global Interrupt                                  */
    DMA1_Channel3_IRQn          = 13,  /*!< DMA1 Channel 3 global Interrupt                                  */
    DMA1_Channel4_IRQn          = 14,  /*!< DMA1 Channel 4 global Interrupt                                  */
    DMA1_Channel5_IRQn          = 15,  /*!< DMA1 Channel 5 global Interrupt                                  */
    DMA1_Channel6_IRQn          = 16,  /*!< DMA1 Channel 6 global Interrupt                                  */
    DMA1_Channel7_IRQn          = 17,  /*!< DMA1 Channel 7 global Interrupt                                  */
    ADC1_2_IRQn                 = 18,  /*!< ADC1 and ADC2 global Interrupt                                   */
    USB_HP_CAN1_TX_IRQn         = 19,  /*!< USB High Priority or CAN1 TX Interrupts                          */
    USB_LP_CAN1_RX0_IRQn        = 20,  /*!< USB Low Priority or CAN1 RX0 Interrupts                          */
    CAN1_RX1_IRQn               = 21,  /*!< CAN1 RX1 Interrupt                                              */
    CAN1_SCE_IRQn               = 22,  /*!< CAN1 SCE Interrupt                                              */
    EXTI9_5_IRQn                = 23,  /*!< EXTI Line[9:5] Interrupts                                        */
    TIM1_BRK_IRQn               = 24,  /*!< TIM1 Break Interrupt                                            */
    TIM1_UP_IRQn                = 25,  /*!< TIM1 Update Interrupt                                           */
    TIM1_TRG_COM_IRQn           = 26,  /*!< TIM1 Trigger and Commutation Interrupt                          */
    TIM1_CC_IRQn                = 27,  /*!< TIM1 Capture Compare Interrupt                                  */
    TIM2_IRQn                   = 28,  /*!< TIM2 global Interrupt                                           */
    TIM3_IRQn                   = 29,  /*!< TIM3 global Interrupt                                           */
    TIM4_IRQn                   = 30,  /*!< TIM4 global Interrupt                                           */
    I2C1_EV_IRQn                = 31,  /*!< I2C1 Event Interrupt                                            */
    I2C1_ER_IRQn                = 32,  /*!< I2C1 Error Interrupt                                            */
    I2C2_EV_IRQn                = 33,  /*!< I2C2 Event Interrupt                                            */
    I2C2_ER_IRQn                = 34,  /*!< I2C2 Error Interrupt                                            */
    SPI1_IRQn                   = 35,  /*!< SPI1 global Interrupt                                           */
    SPI2_IRQn                   = 36,  /*!< SPI2 global Interrupt                                           */
    USART1_IRQn                 = 37,  /*!< USART1 global Interrupt                                         */
    USART2_IRQn                 = 38,  /*!< USART2 global Interrupt                                         */
    USART3_IRQn                 = 39,  /*!< USART3 global Interrupt                                         */
    EXTI15_10_IRQn              = 40,  /*!< EXTI Line[15:10] Interrupts                                      */
    RTCAlarm_IRQn               = 41,  /*!< RTC Alarm through EXTI Line Interrupt                           */
    USBWakeUp_IRQn              = 42,  /*!< USB Wakeup from suspend through EXTI Line Interrupt              */
    TIM8_BRK_IRQn               = 43,  /*!< TIM8 Break Interrupt                                            */
    TIM8_UP_IRQn                = 44,  /*!< TIM8 Update Interrupt                                           */
    TIM8_TRG_COM_IRQn           = 45,  /*!< TIM8 Trigger and Commutation Interrupt                          */
    TIM8_CC_IRQn                = 46,  /*!< TIM8 Capture Compare Interrupt                                  */
    ADC3_IRQn                   = 47,  /*!< ADC3 global Interrupt                                           */
    FSMC_IRQn                   = 48,  /*!< FSMC global Interrupt                                           */
    SDIO_IRQn                   = 49,  /*!< SDIO global Interrupt                                           */
    TIM5_IRQn                   = 50,  /*!< TIM5 global Interrupt                                           */
    SPI3_IRQn                   = 51,  /*!< SPI3 global Interrupt                                           */
    UART4_IRQn                  = 52,  /*!< UART4 global Interrupt                                          */
    UART5_IRQn                  = 53,  /*!< UART5 global Interrupt                                          */
    TIM6_IRQn                   = 54,  /*!< TIM6 global Interrupt                                           */
    TIM7_IRQn                   = 55,  /*!< TIM7 global Interrupt                                           */
    DMA2_Channel1_IRQn          = 56,  /*!< DMA2 Channel 1 global Interrupt                                  */
    DMA2_Channel2_IRQn          = 57,  /*!< DMA2 Channel 2 global Interrupt                                  */
    DMA2_Channel3_IRQn          = 58,  /*!< DMA2 Channel 3 global Interrupt                                  */
    DMA2_Channel4_5_IRQn        = 59   /*!< DMA2 Channel 4 and Channel 5 global Interrupt                    */
} IRQn_Type;


/******************************End Data Type Section***********************/


/***************Start Software Interface Section**************************/


/**
 *  brief 	 	Enable Interrupt
 *  details		Enable a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  note		IRQn must not be negative
 */
void NVIC_EnableIRQ(IRQn_Type IRQn);


/**
 *  brief 	 	Disable Interrupt
 *  details		Disable a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  note		IRQn must not be negative
 */

void NVIC_DisableIRQ(IRQn_Type IRQn);


/**
 *  brief 	 	Set Pending Interrupt
 *  details		Sets the pending bit of a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  note		IRQn must not be negative
 */
void NVIC_SetPendingIRQ(IRQn_Type IRQn);

/**
 *  brief 	 	Clear Pending Interrupt
 *  details		Clear the pending bit of a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  note		IRQn must not be negative
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);


/**
 *  brief 	 	Get Active Interrupt
 *  details		Reads the active register in the NVIC and return the active bit of a device specific interrupt in the NVIC
 *  param [in]	IRQn Device specific interrupt number
 *  return		0  Interrupt state is not active
 *  return 		1  Interrupt state is active
 *  note		IRQn must not be negative
 */
u32 NVIC_GetActive(IRQn_Type IRQn);


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
void NVIC_SetPriority(IRQn_Type IRQn, u32 Priority);


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
u32 NVIC_GetPriority(IRQn_Type IRQn);
#endif /* NVIC_H_ */
