# 灵活存储控制器 (FMC)

!!! info
    FMC 是灵活存储控制器的缩写。它是一种功能，允许 MCU 与外部存储设备（如 SDRAM、SRAM 和 NOR Flash）进行接口。

## FMC 设置

![FMC_PARA](fmc_para.png)

如图所示，在“连接”选项卡中，启用 FMC，然后在 FMC 配置区域中启用 SDRAM 设备，并根据 SDRAM 设备的数据表设置参数。

## 同步动态随机存储器(SDRAM)

SDRAM 是一种常见的外部存储设备类型，可以使用 FMC 与 MCU 进行接口。它是一种用于计算机和其他电子设备的易失性存储器。在这里，由于内置 RAM 仅为 1MB，对于某些应用程序来说不够，我们需要使用外部 SDRAM 来扩展内存容量。