# 文件系统 (FILE SYSTEM)

!!! info
    文件系统是一种存储和组织计算机文件及其数据的方法。在这里，我们将使用 FatFs 库与 SD 卡进行接口。

## 文件系统作为中间件
在 STM32CUBEMX中，FATFS已经作为中间件集成到软件中。要启用FATFS，请转到“中间件”选项卡，并启用“FATFS”中间件，无需在 CUBE-MX 中进行其他配置。

![config_fatfs](config_fatfs.png)