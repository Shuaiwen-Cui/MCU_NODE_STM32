# ARCHITECTURE

## HARDWARE ARCHITECTURE

MAIN CONTROL + PERCEPTION + COMMUNICATION + INTERFACING

### MAIN CONTROL

- STM32H743IIT6 (ARM Cortex-M7 480MHz)
- RAM 1MB
- FLASH 2MB
- SDRAM 32MB
- QSPI FLASH 8MB (TO BE DEVELOPED)
- TF CARD 32GB

### PERCEPTION

- IMU
    - MPU6050
- ACC
    - ADXL362
    - ADXL355
- T&H
    - DHT11

### COMMUNICATION
- WIFI
    - ESP8266
- BLUETOOTH
    - HC-05
- CELLULAR
    - SIM7600G-H

### INTERFACING
- OLED
    - CH1116

## SOFTWARE ARCHITECTURE

PHYSICAL LAYER -> DRIVER LAYER -> MIDWARE LAYER -> APPLICATION LAYER

## DEV TOOLCHAIN

INITIALIZATION: STM32CUBEMX

PROGRAMMING: KEIL5/VSCODE


## DEV REFERENCE LINKS

<div class="grid cards" markdown>

-   :fontawesome-brands-bilibili:{ .lg .middle } __KEYSKING TUTORIALS🎯✅🏆__

    Upside: Simple, intuitive, animated explanation, highly recommended for beginners.

    Downside: Chinese only. The contents are too few to cover all aspects of STM32 development, can only be used for basic learning. The uploader is constantly updating the content, so it is recommended to subscribe to the channel.

    ---

    [:octicons-arrow-right-24: <a href="https://www.bilibili.com/video/BV12v4y1y7uV/?spm_id_from=333.788&vd_source=5a427660f0337fedc22d4803661d493f" target="_blank"> Portal </a>](#)

</div>

<div class="grid cards" markdown>

-   :fontawesome-brands-bilibili:{ .lg .middle } __YUANYE IOT STM32🏆__

    Upside: This is a video tutorial series using CUBEMX for beginners. 

    Downside: Chinese only. Currently, there are few tutorials online that use CUBEMX completely, and this series is a good choice.

    ---

    [:octicons-arrow-right-24: <a href="https://space.bilibili.com/1341140649/channel/series" target="_blank"> Portal </a>](#)

</div>

<div class="grid cards" markdown>

-   :fontawesome-solid-blog:{ .lg .middle } __STM32 FULL STACK🎯🏆__

    Upside: Well-rounded, comprehensive, and detailed tutorial.

    Downside: Chinese only. 

    ---

    [:octicons-arrow-right-24: <a href="https://blog.csdn.net/Mculover666/article/details/126943245" target="_blank"> Portal </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __STM32 Z小旋🎯🏆__

    ---

    [:octicons-arrow-right-24: <a href="https://blog.csdn.net/as480133937/category_9188655.html" target="_blank"> Portal </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __STM32CubeMX+STM32F4 Series Tutorial🎯🏆__

    ---

    [:octicons-arrow-right-24: <a href="https://www.cnblogs.com/lc-guo/p/17937268" target="_blank"> Portal </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __STM32CubeMX Auto Configuration🎯🏆__

    ---

    [:octicons-arrow-right-24: <a href="https://blog.csdn.net/weixin_42880082/category_12054555.html" target="_blank"> Portal </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __STM32CubeMX Tutorial🎯🏆__

    ---

    [:octicons-arrow-right-24: <a href="https://leung-manwah.blog.csdn.net/category_10508589.html" target="_blank"> Portal </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __PERIPHERAL DEVELOPMENT🎯🏆__

    ---

    COMMON PERIPHERALS

    [:octicons-arrow-right-24: <a href="https://blog.csdn.net/qq_45217381/category_12355452.html" target="_blank"> Portal </a>](#)

</div>