# MCU_NODE_STM32

## PROJECT INTRODUCTION
Make an edge intelligence node based on STM32, this project is tightly coupled with [TinySHM](https://github.com/Shuaiwen-Cui/TinySHM.git), which serves as a middleware framework for edge intelligence enabled SHM. 

Please check the link on the right-hand side for more information.

## CODE TREE
```bash
.
README.md: README FILE
MCU_DOC: ONLINE DOCUMENTATION, PLEASE CHECK THE LINK ON THE RIGHT-HAND SIDE: https://shuaiwen-cui.github.io/MCU_NODE_STM32/
DEPRECATED: DEPRECATED CODE
STABLE-RELEASE: STABLE RELEASE
    -NODE-CORE-BUILT (Sep 20, 2024): BUILT VERSION (CUBEMX + KEIL) FOR THE MAIN CONTROL
ONGOING-DEV: ONGOING CODE, STABLE FEATURE WILL BE RELEASED
    -BASELINE: BASELINE CODE
    -DISCARDED: DISCARDED CODE
        - CUBEIDE VERSION: NOT WORKING
    -FRONTIER: FRONTIER CODE
        -NODE-FULL: FULL FEATURE VERSION (CUBEMX + KEIL), MAIN CONTROL BOARD + PERIPHERALS
        -NODE-FULL-X: FULL FEATURE VERSION (CUBEMX + KEIL), MAIN CONTROL BOARD + PERIPHERALS (LATEST), X STANDS FOR THE ADDED PERIPHERALS
```

## 项目介绍
基于 STM32 的边缘智能节点项目，该项目与 [TinySHM](https://github.com/Shuaiwen-Cui/TinySHM.git) 紧密结合，TinySHM 作为一种中间件框架，用于支持边缘智能的结构健康监测 (SHM)。

有关更多信息，请查看右侧的链接。

## 代码树
```bash
.
README.md: README 文件
MCU_DOC: 在线文档，请查看右侧的链接：https://shuaiwen-cui.github.io/MCU_NODE_STM32/
DEPRECATED: 已弃用代码
STABLE-RELEASE: 稳定版本
    -NODE-CORE-BUILT (2024年9月20日): 主控制器的构建版本 (CUBEMX + KEIL)
ONGOING-DEV: 正在开发的代码，稳定功能将在未来发布
    -BASELINE: 基线代码
    -DISCARDED: 已弃用的代码
        - CUBEIDE 版本: 无法工作
    -FRONTIER: 前沿代码
        -NODE-FULL: 全功能版本 (CUBEMX + KEIL)，主控制板 + 外围设备
        -NODE-FULL-X: 全功能版本 (CUBEMX + KEIL)，主控制板 + 外围设备 (最新)，X 代表新增的外围设备
```