# 同步动态随机存储器(SDRAM)
!!! info
    SDRAM 是同步动态随机存储器的缩写。它是一种用于计算机和其他电子设备的易失性存储器。在这里，由于内置 RAM 仅为 1MB，对于某些应用程序来说不够，我们需要使用外部 SDRAM 来扩展内存容量。

## SDRAM 电路
![SDRAM_CIRCUIT](sdram_circuit.png)

请仔细将引脚设计与CUBEMX中的引脚设置进行比较，确保引脚配置与硬件连接一致。在我们的案例中，只有PH2, PH3, PH5不一致，所以我们可以在右侧的芯片视图中手动设置，并按照设计将其设置为各自的功能。

## SDRAM 参数
![SDRAM_PARA](sdram_para.png)

我们使用的 SDRAM 模块是 WINBOND W9825G6KH-6I。您可以在[这里](http://www.cuishuaiwen.com:7500/DEV/FK-STM32H743/w9825g6kh.pdf)找到数据表。参数是根据数据表计算的。

## GPIO 配置
![SDRAM_GPIO](sdram_gpio.png)

检查引脚配置。将 CUBEMX 中的设置与引脚设计进行比较。

## 生成与更新代码
接下来，我们生成代码以保存当前进度，并使其准备好进行后续的编程步骤。点击屏幕右上角的“生成代码”按钮。