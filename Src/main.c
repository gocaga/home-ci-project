/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#define RCC_BASE_ADDR         0x40023800UL
#define RCC_CFGR_REG_OFFSET   0x08UL
#define RCC_CFGR_REG_ADDR     (RCC_BASE_ADDR + RCC_CFGR_REG_OFFSET)
#define GPIOA_BASE_ADDR       0x40020000UL

int main(void)
{
    uint32_t* pRccCfgReg = (uint32_t*) RCC_CFGR_REG_ADDR;

    // 1. Configure the RCC_CFGR register
    *pRccCfgReg &= ~(0x3 << 21); //Clear bits 21 and 22

    //Configure MC01 pre-scaller to 4 so that clock generated is 4Mhz
    *pRccCfgReg |= (1 << 25); //Datasheet Err: This is swapped in register description
    *pRccCfgReg |= (1 << 26); //Datasheet Err: This is swapped in register description

    // 2. Configure PA8 to AF0 mode to behave as MC01 signal
    // a. Enable the peripheral clock for GPIOA peripheral
    uint32_t* pRCCAhb1Enr = (uint32_t*) (RCC_BASE_ADDR + 0x30);
    *pRCCAhb1Enr |= (1 << 0);

    // b. Configure the mode of GPIOA pin 8 as alternative function mode
    uint32_t* pGPIOModeReg = (uint32_t*) (GPIOA_BASE_ADDR + 0x00);
    *pGPIOModeReg &= ~(0x3 << 16); //clear
    *pGPIOModeReg |= (0x2 << 16);  //set

    // c. Configure the alternate function register to set the mode 0 for PA8
    uint32_t* pGPIOAAltFunHighReg = (uint32_t*) (GPIOA_BASE_ADDR + 0X24);
    *pGPIOAAltFunHighReg &= ~(0XF << 0);

    /* Loop forever */
    for (;;);
}
