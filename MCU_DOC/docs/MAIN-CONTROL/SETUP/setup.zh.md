# 初始化设置

!!! note
    '初始化设置' 是设置主控系统的第一步，使得系统能够运行基本功能。

## 硬件准备

为了编程主控板，我们需要三个组件：

- **主控板** - 嵌入 MCU 的开发板
- **USB-TTL 适配器** - 将主控板连接到计算机
- **调试器**（ST-LINK V2、J-LINK 等） - 用于编程主控板

### 组件 1 - 主控板 - FANKE743

![MAIN_CONTROL](main_control.jpg){: width="500px" height="500px" }

<div class="grid cards" markdown>

-   :shopping_cart:{ .lg .middle } __产品链接__

    ---

    产品链接


    [:octicons-arrow-right-24: <a href="https://m.tb.cn/h.glFZRKv3mP2cLID?tk=G3YX3VNEVf9" target="_blank"> Purchase Link </a>](#)

</div>

### 组件 2 - USB-TTL 适配器

![USB_TTL_ADAPTER](usb_ttl.jpg)

<div class="grid cards" markdown>

-   :shopping_cart:{ .lg .middle } __产品链接__

    ---

    产品链接


    [:octicons-arrow-right-24: <a href="[https://m.tb.cn/h.glFZRKv3mP2cLID?tk=G3YX3VNEVf9 ](https://www.waveshare.com/usb-to-ttl.htm)" target="_blank"> Purchase Link </a>](#)

</div>

### 组件 3 - 调试器

![DEBUGGER](debugger.png)

<div class="grid cards" markdown>

-   :shopping_cart:{ .lg .middle } __产品链接__

    ---

    产品链接


    [:octicons-arrow-right-24: <a href="https://item.taobao.com/item.htm?spm=a21n57.1.item.27.6054523cmH3JcG&priceTId=2100cfb417239664885743719e0be4&utparam=%7B%22aplus_abtest%22:%229e72697eebf441849f1700870339a8ad%22%7D&id=563709870959&ns=1&xxc=ad_ztc&skuId=4855986632645&pisk=f0QtthmAvJ2MWVqc51ZHoIBZO6FhkNCaIO5SoKvic9BdGp00_Fq2ktpd3dxM5d0vksBVntC4_I9fhtpcjk4l_182l82Yrzfaj-w8eOn61HNXNIibWyq31182l-hnlu4R_T3APFwvcWLBMIMXlhTXRB9eiIMfhdtIdQdylK6XlWKBNCHjhqg6RDO-prF9LfOtki9ODYeK070xkwdQQL1TzqAdRCd6e1_t0ml26hp51pelUvmvAs-AujuvC1sP3Q6sC8xNGMBp6EUnfU1dcTdF5zD9TGfCZp1-N41wWgQJ5GeEYFXORe_12jgf9FpwABKKBJp576_yRH47w6_FI17dijaXtTvC_NTYP7895dTpTZ2E5KICcNxwuAwkbssdpCL54FblyrcnELdmfWFK0m-6t3YMuVa08PTD9LV6fmo2mBRpEWFn0m-3DBpu1mmq0n3R." target="_blank"> Purchase Link </a>](#)

</div>

!!! info
    CMSIS-DAP, ST-LINK, J-LINK等调试器都可以用于编程主控板。任何一种调试器都可以用来对主控板进行编程。

## 硬件连接

![CONNECTION](connection.png)

将三个组件按照上图所示进行连接。然后将 USB-TTL 适配器连接到计算机的 USB 端口，将调试器连接到计算机的 USB 端口。

## 软件准备

### STM32CUBEMX

STM32CUBEMX 是一个图形化工具，允许非常轻松地配置 STM32 微控制器，并通过分步过程生成相应的初始化 C 代码。可以从 [官方网站](https://www.st.com/en/development-tools/stm32cubemx.html) 下载并安装 STM32CubeMX。

### KEIL MDK

KEIL MDK 是一个适用于广泛的 ARM Cortex-M 系列微控制器设备的完整软件开发环境。可以从 [官方网站](https://www.keil.com/demo/eval/arm.htm) 下载并安装 KEIL MDK。

## 软件设置