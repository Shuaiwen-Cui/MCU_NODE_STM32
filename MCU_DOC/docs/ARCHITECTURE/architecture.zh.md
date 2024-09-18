# 架构

## 硬件架构

主控 + 感知 + 通信 + 交互


### 主控

- STM32H743IIT6 (ARM Cortex-M7 480MHz)
- RAM 1MB
- FLASH 2MB
- SDRAM 32MB
- QSPI FLASH 8MB（待开发）
- TF CARD 32GB

### 感知
- IMU
    - MPU6050
- ACC
    - ADXL362
    - ADXL355
- T&H
    - DHT11

### 通信
- WIFI
    - ESP8266
- BLUETOOTH
    - HC-05
- CELLULAR
    - SIM7600G-H

### 交互
- OLED
    - CH1116

## 软件架构

物理层 -> 驱动层 -> 中间件层 -> 应用层 

## 开发工具链

初始化： STM32CUBEMX

代码编辑： KEIL5/STM32CUBEIDE/VSCODE

## 开发参考连接


<div class="grid cards" markdown>

-   :fontawesome-brands-bilibili:{ .lg .middle } __KEYSKING TUTORIALS🎯✅🏆__

    优点：简单，直观，动画讲解，非常适合初学者。

    缺点：仅支持中文。内容较少，无法覆盖STM32开发的所有方面，仅适用于基础学习。上传者不断更新内容，建议订阅频道。

    ---

    [:octicons-arrow-right-24: <a href="https://www.bilibili.com/video/BV12v4y1y7uV/?spm_id_from=333.788&vd_source=5a427660f0337fedc22d4803661d493f" target="_blank"> 传送门 </a>](#)

</div>

<div class="grid cards" markdown>

-   :fontawesome-brands-bilibili:{ .lg .middle } __原野物联网STM32开发板🎯🏆__

    优点：这是一个使用CUBEMX的视频教程系列，适合初学者。目前网上完全使用CUBEMX的教程较少，这个系列是一个很好的选择。

    缺点：仅支持中文。

    ---

    [:octicons-arrow-right-24: <a href="https://space.bilibili.com/1341140649/channel/series" target="_blank"> 传送门 </a>](#)

</div>

<div class="grid cards" markdown>

-   :fontawesome-solid-blog:{ .lg .middle } __STM32 FULL STACK🎯🏆__

    优点：全面，细致，详细的教程。

    缺点：仅支持中文。

    ---

    [:octicons-arrow-right-24: <a href="https://blog.csdn.net/Mculover666/article/details/126943245" target="_blank"> 传送门 </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __STM32 Z小旋🎯🏆__

    ---

    [:octicons-arrow-right-24: <a href="https://blog.csdn.net/as480133937/category_9188655.html" target="_blank"> 传送门 </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __STM32CubeMX+STM32F4系列教程🎯🏆__

    ---

    [:octicons-arrow-right-24: <a href="https://www.cnblogs.com/lc-guo/p/17937268" target="_blank"> 传送门 </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __STM32CubeMX自动配置工程系列🎯🏆__

    ---

    [:octicons-arrow-right-24: <a href="https://blog.csdn.net/weixin_42880082/category_12054555.html" target="_blank"> 传送门 </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __STM32CubeMX教程🎯🏆__

    ---

    [:octicons-arrow-right-24: <a href="https://leung-manwah.blog.csdn.net/category_10508589.html" target="_blank"> 传送门 </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __边缘智能开发-专栏索引__

    ---

    [:octicons-arrow-right-24: <a href="https://zhuanlan.zhihu.com/p/696554081" target="_blank"> 传送门 </a>](#)

-   :fontawesome-solid-blog:{ .lg .middle } __外设开发🎯🏆__

    ---

    常见外设

    [:octicons-arrow-right-24: <a href="https://blog.csdn.net/qq_45217381/category_12355452.html" target="_blank"> 传送门 </a>](#)

</div>
