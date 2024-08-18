# 安全数字存储卡(SDCARD)

!!! info
    SDCARD是Secure Digital Memory Card的缩写。它是一种用于计算机和其他电子设备的非易失性存储卡。在这里，我们将使用SDMMC外设与SD卡进行接口。

## SDCARD电路
![SDCARD_CIRCUIT](sdcard_circuit.png)

## SDCARD配置

要启用SDCARD，我们需要为此开发板启用SDMMC。对于其他一些开发板，您可能需要启用SDMMC外设。

对于SDMMC配置，请参考SDMMC选项卡。

## SDCARD GPIO
![SDCARD_GPIO](sdcard_gpio.png)

对于SD卡，我们可以使用默认的GPIO引脚。但是，您可以根据自己的需求更改GPIO引脚。