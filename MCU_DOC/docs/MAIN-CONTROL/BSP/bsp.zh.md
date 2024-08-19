# 板级支持包（BSP）

## BSP 简介
为了方便主控板的开发和移植，我准备了一个 BSP，其中包含一系列有用的驱动程序和库。BSP 基于 STM32Cube HAL 库，兼容 STM32H7 系列微控制器，如果你愿意，你可以修改它以适应其他系列。BSP 包括以下模块：

- bsp_init：所有 BSP 模块的控制模块。
- iled：LED 驱动程序。
- iusart：USART 驱动程序，主要用于串行通信。
- isdram：SDRAM 低级驱动程序。
- imemory：内存管理模块。
- isdcard：SD 卡驱动程序。
- ifile：文件系统模块。
- ...

!!! 提示
    教程是按照逐节方式编写的，但在实践中，用户可以在 STM32CUBEMX 中一次性设置所有所需的配置，然后继续进行 Keil 或 VSCode 编程。用户可以从库中移植 BSP（下方附有链接），并相应地将其合并到其项目中。

<div class="grid cards" markdown>

-   :simple-github:{ .lg .middle } __MCU_BSP__

    ---

    基于 STM32 的 MCU BSP


    [:octicons-arrow-right-24: <a href="https://github.com/Shuaiwen-Cui/MCU_BSP.git" target="_blank"> Github Repo </a>](#)

</div>

## 设置 Keil 以获得更好的体验

打开 'Options for Target' 并进行以下设置：

### 使用 AC6 编译器
![AC6](keil.png){: width="800px" }

由于这是一个新项目，一切都是从 AC6 编译器开始的。我们可以使用 AC6 进行编译和调试，这比 AC5 编译器快得多。

### 重置并运行
![RESET](keil_reset_run.png){: width="800px" }

选择 'Debug' 选项卡，在右上角选择 'Settings'。在 'Flash and Download' 选项卡中，选择 'Reset and Run'，以在将程序下载到板上后自动重置并运行程序。这对编程和调试非常方便。

## 如何将 BSP 集成到您的项目中

### 步骤 1：下载 BSP

将 BSP git 仓库克隆到本地工作空间。

```bash
git clone https://github.com/Shuaiwen-Cui/MCU_BSP.git
```

### 步骤 2：将 BSP 移动到您的项目中

只选择 ''STM32-HAL-CUBEMX' 文件夹并将其移动到您的项目目录中。

### 步骤 3：将 BSP 包含到您的项目中
![INCLUDE](include.png){: width="800px" }

打开 Keil，选择 'Options for Target' -> 'C/C++' -> 'Include Paths'，将 BSP 模块的各自路径添加到您的项目包含路径中。

### 步骤 4：将 BSP 模块添加到您的项目中
![ITEMS](items.png){: width="800px" }

打开 'Manage Project Items'，将各自模块添加到您的项目中。

!!! 提示
    当您添加文件时，将文件类型更改为 'All Types'，以便将 '*.h' 和 '*.c' 文件一起合并到项目中，以方便使用。

### 步骤 5：包含头文件并调用 BSP_Init() 函数以初始化 BSP

在您的主函数中包含 'bsp_init.h' 头文件，并在主函数中调用 'BSP_Init()' 函数以初始化 BSP。

!!! tip
    当修改代码的时候，请在'USER CODE BEGIN'和'USER CODE END'之间进行修改，以避免在重新生成代码时丢失您的修改。

## BSP 模块介绍

!!! note
    为了高效管理BSP模块，我创建了一个名为'bsp_init'的控制模块。'bsp_init'模块负责初始化所有BSP模块并设置必要的配置。'bsp_init'模块是主函数中第一个被调用的用户模块。

让我们来看看'bsp_init'模块：

### **bsp_init.h**

```c
/**
 * @file bsp_init.h
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief This file contains the headers of the BSP initialization functions.
 * @version 1.0
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef BSP_INIT_H
#define BSP_INIT_H

#define BSP_INIT_SUCCESS 0
#define BSP_INIT_FAIL 1

#define BSP_INIT_TEST // test required for the BSP initialization, comment this out to disable the test

/**
 * @name Modules To Be Enabled
 * @brief This section is to determine the modules to be included in the project
 * ! This is where you configure the modules to be included in the project
 * @param MODULE_ENABLE_LED //! Enable LED module
 * @param MODULE_ENABLE_KEY //! Enable Key module (No use in this project, do not enable it)
 * @param MODULE_ENABLE_USART1 //! Enable USART1 module for serial communication
 * @param MODULE_ENABLE_SDRAM //! Enable SDRAM module to use external RAM for computation
 * @param MODULE_ENABLE_MEMORY //! Enable Memory module - for memory management on SDRAM
 * @param MODULE_ENABLE_SDCARD //! Enable SD Card module test - for SD Card basic io. !!! This module can not be used together with MODULE_ENABLE_FILE
 * @param MODULE_ENABLE_FILE //! Enable File module test - for file operations on SD Card !!! This module can not be used together with MODULE_ENABLE_SDCARD
 */

#define MODULE_ENABLE_LED // Enable LED module
// #define MODULE_ENABLE_KEY  // Enable Key module
#define MODULE_ENABLE_USART1 // Enable USART1 module
#define MODULE_ENABLE_SDRAM  // Enable SDRAM module
#define MODULE_ENABLE_MEMORY // Enable Memory module - for memory management on SDRAM
// #define MODULE_ENABLE_SDCARD // Enable SD Card module
#define MODULE_ENABLE_FILE   // Enable File module - for file operations on SD Card

/**
 * @name Include Files
 *
 */
#include <stdio.h>
#ifdef MODULE_ENABLE_LED

#include "iled.h"

#endif

#ifdef MODULE_ENABLE_KEY

#include "ikey.h"

#endif

#ifdef MODULE_ENABLE_USART1 //! Note - Do rember to check the MicroLib option in the project settings

#include <stdio.h>
#include "iusart.h"

#endif

#ifdef MODULE_ENABLE_SDRAM

#include "isdram.h"

#endif

#ifdef MODULE_ENABLE_MEMORY

#include "imemory.h"

#endif

#ifdef MODULE_ENABLE_SDCARD

#include "isdcard.h"

#endif

#ifdef MODULE_ENABLE_FILE

#include "ifile.h"

#endif

/**
 * @name Function Prototypes
 *
 */

// The BSP initialization function - including all the initialization functions
int BSP_Init();

#ifdef MODULE_ENABLE_USART1
// IO retargetting
int fputc(int ch, FILE *f);
int fgetc(FILE *f);
#endif

#endif /* BSP_INIT_H */
```
### **bsp_init.c**

```c
/**
 * @file bsp_init.c
 * @author SHUAIWEN CUI (SHUAIWEN001 AT e DOT ntu DOT edu DOT sg)
 * @brief
 * @version 1.0
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_init.h"

/**
 * @name VARIABLES
 * 
 */
// The gap between the initialization of each module, in ms.
int Init_Gap = 500;

/**
 * @name BSP_Init
 * @brief board support package initialization
 * @param None
 * @retval 0
 *
 */
int BSP_Init(void)
{
    // Variables
    int i;
#ifdef MODULE_ENABLE_LED
    // BSP Initialization - LED - flash once to indicate OK
    LED(0); // for deployment, switch off the LED to save power
#ifdef BSP_INIT_TEST // for debugging, flash the LED to indicate status
    LED(1);
    HAL_Delay(200);
    LED(0);
    HAL_Delay(200);
    LED(1);
#endif
#endif

#ifdef MODULE_ENABLE_KEY
    // BSP Initialization - Key
    // nothing required
#endif

    HAL_Delay(2*Init_Gap); // to give the user enough time to connect to the serial terminal

#ifdef MODULE_ENABLE_USART1
#ifdef BSP_INIT_TEST
    // Initialization - Count Down
    for (i = 0; i < 5; i++)
    {
        printf("[INITIALIZATION] Count Down for Upcoming Testing: %d \n\r", 5 - i);
        HAL_Delay(1000);
    }
    printf("\n\r");
#endif
    // BSP Initialization - Serial Communication
    MCU_serial_init();
    printf("[INITIALIZATION] Serial Communication - SUCCESS\n\r\n\r");
    // MCU_printf("Serial Communication - SUCCESS\n\r"); // not working
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_SDRAM
    // BSP Initialization - SDRAM
    printf("[INITIALIZATION] SDRAM Initialization - START\n\r");
    SDRAM_InitSequence();
    printf("[INITIALIZATION] SDRAM Initialization - FINISHED\r\n\n\r");
#ifdef BSP_INIT_TEST
    if (SDRAM_Test() == 0)
    {
        printf("[INITIALIZATION] SDRAM TEST - SUCCESS\r\n\n\r");
    }
    else
    {
        printf("[INITIALIZATION] SDRAM TEST - FAIL\r\n\n\r");
    }
#endif
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_MEMORY
    // BSP Initialization - Memory Management
    printf("[INITIALIZATION] Memory Management Initialization - START\n\r");
    memory_init();
    printf("[INITIALIZATION] Memory Management Initialization - FINISHED\n\r\n\r");
#ifdef BSP_INIT_TEST
    printf("[INITIALIZATION] Memory Management Test - START\n\r");
    if (memory_management_test() == 0)
    {
        printf("[INITIALIZATION] Memory Management Test - SUCCESS\n\r\n\r");
    }
    else
    {
        printf("[INITIALIZATION] Memory Management Test - FAIL\n\r\n\r");
    }
#endif
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_SDCARD

    // BSP Initialization - SD Card
    printf("[INITIALIZATION] SD Card Initialization - START.\n\r");
    SD_Init();
#ifdef BSP_INIT_TEST
    // SD Card Test
    printf("[INITIALIZATION] SD Card Test - START.\n\r");
    SD_Test();
    printf("[INITIALIZATION] SD Card Test - FINISHED.\n\r");
#endif
    printf("[INITIALIZATION] SD CARD Initialization - FINISHED.\n\r");
#endif

    HAL_Delay(Init_Gap);

#ifdef MODULE_ENABLE_FILE // the test is kept outside the test zone, as sd card hard conenction is not quite stable, and we need the test to ensure the connection is okay

    printf("[INITIALIZATION] SD Card File IO Initialization and Test - START.\n\r");
    printf("\n\r");

    // mount the file system
    printf("[INITIALIZATION] Mounting the file system.\n\r");
    Mount_FatFs();
    printf("\n\r");

    // get disk information
    printf("[INITIALIZATION] Getting disk information.\n\r");
    FatFs_GetDiskInfo();
    printf("\n\r");

    // scan the directory
    printf("[INITIALIZATION] Scanning the directory.\n\r");
    FatFs_ScanDir("0:/");
    printf("\n\r");

    // write a text file
    printf("[INITIALIZATION] Writing a text file.\n\r");
    FatFs_WriteTXTFile("test.txt", 2016, 11, 15);
    printf("\n\r");

    // read a text file
    printf("[INITIALIZATION] Reading a text file.\n\r");
    FatFs_ReadTXTFile("test.txt");
    printf("\n\r");

    // get file information
    printf("[INITIALIZATION] Getting file information.\n\r");
    FatFs_GetFileInfo("test.txt");
    printf("\n\r");

    // delete a file
    printf("[INITIALIZATION] Deleting a file.\n\r");
    FatFs_DeleteFile("test.txt");
    printf("\n\r");

#ifdef BSP_INIT_TEST

#endif
    printf("[INITIALIZATION] SD Card File IO Initialization and Test - FINISHED.\n\r\n\r");
    HAL_Delay(Init_Gap);

#endif


#ifdef MODULE_ENABLE_USART1
    printf("[INITIALIZATION] BSP Initialization - FINISHED\n\r");
    printf("\n\r");
#endif

    return BSP_INIT_SUCCESS;
}

#ifdef MODULE_ENABLE_USART1

// MicroLib needed for retargetting
// retarget fputc for printf
int fputc(int ch, FILE *f)
{
    uint8_t temp = (uint8_t)ch;
    HAL_UART_Transmit(&huart1, &temp, 1, HAL_MAX_DELAY);
    return ch;
}

// retarget fgetc for scanf
int fgetc(FILE *f)
{
    while (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == RESET)
        ;                                      // Wait until the data is received
    return (int)(huart1.Instance->RDR & 0xFF); // Read the received data
}
#endif
```

### BSP_INIT 模块说明

如您所见，几乎所有的 BSP 模块都在此模块中进行了配置。您可以通过注释相应的模块来决定是否激活或停用该模块：

- MODULE_ENABLE_LED：启用 LED 模块。
- MODULE_ENABLE_KEY：启用按键模块。注意，该模块在本项目中未使用，因为此开发板上没有可编程按键。不要启用此模块。
- MODULE_ENABLE_USART1：启用 USART1 模块进行串行通信。如果启用了此模块，模块中定义的 printf 和 scanf 的重定向函数将自动激活。
- MODULE_ENABLE_SDRAM：启用 SDRAM 模块以使用外部 RAM 进行计算。
- MODULE_ENABLE_MEMORY：启用内存模块以在 SDRAM 上进行内存管理。
- MODULE_ENABLE_SDCARD：启用 SD 卡模块测试 SD 卡的基本 IO。注意，该模块不能与 MODULE_ENABLE_FILE 一起使用。
- MODULE_ENABLE_FILE：启用文件模块测试 SD 卡上的文件操作。注意，该模块不能与 MODULE_ENABLE_SDCARD 一起使用。

### BSP_INIT 模块配置推荐
以下表格为 BSP_INIT 模块的推荐配置：

| 模块名称 | 配置 |
| --- | --- |
| MODULE_ENABLE_LED | ✅启用 |
| MODULE_ENABLE_KEY | ❌禁用 |
| MODULE_ENABLE_USART1 | ✅启用 |
| MODULE_ENABLE_SDRAM | ✅启用 |
| MODULE_ENABLE_MEMORY | ✅启用 |
| MODULE_ENABLE_SDCARD | ❌禁用 |
| MODULE_ENABLE_FILE | ✅启用 |

### 模块测试
为了方便评估已配置的模块，在 .h 文件中定义了一个宏 'BSP_INIT_TEST'。该测试用于测试各模块的初始化。如果您想禁用测试以节省时间，可以在 .h 文件中注释掉 'BSP_INIT_TEST'。