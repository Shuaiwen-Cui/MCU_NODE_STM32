# MCU_NODE_STM32

## PROJECT INTRODUCTION - 项目介绍
Make an edge intelligence node based on STM32, this project is tightly coupled with [TinySHM](https://github.com/Shuaiwen-Cui/TinySHM.git), which serves as a middleware framework for edge intelligence enabled SHM. 

基于 STM32 的边缘智能节点项目，该项目与 [TinySHM](https://github.com/Shuaiwen-Cui/TinySHM.git) 紧密结合，TinySHM 作为一种中间件框架，用于支持边缘智能的结构健康监测 (SHM)。

Please check the link on the right-hand side for more information.

有关更多信息，请查看右侧的链接。

## CODE TREE - 代码结构
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
        -NODE-FULL-X (Sep 26, 2024): FULL FEATURE VERSION (CUBEMX + KEIL), MAIN CONTROL BOARD + PERIPHERALS (LATEST), X STANDS FOR THE ADDED PERIPHERALS
```
