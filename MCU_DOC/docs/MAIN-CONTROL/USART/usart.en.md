# USART

USART can be used for many different purposes, and for now, only USART1 is used for serial communication.

## USART1 CIRCUIT
![USART1_CIRCUIT](usart_circuit.png)

As can be seen from the circuit design, the RX and TX for USART1 are PA9 and PA10, respectively. However, the default choices are not, so we need to change them manually at the pin configuration at the right hand side of the screen.

## USART1 CONFIGURATION

### PARAMETER SETUP
![PARAMETER](config_usart_para.png)

Select 'Parameter Settings' to setup parameters for USART1. Let's keep the default settings for now.

### DMA SETUP

!!! info
    DMA stands for Direct Memory Access. It is a feature that allows peripherals to access memory without involving the CPU. This can greatly reduce the CPU load and improve the system performance.

![DMA](config_usart_dma.png)

Let's create two DMA channels for USART1. One for transmitting data and the other for receiving data.

### NVIC SETUP

!!! info
    NVIC stands for Nested Vectored Interrupt Controller. It is a feature that allows the MCU to prioritize interrupts and manage them efficiently.

![NVIC](config_usart_nvic.png)

Here, let's enable the USART1 global interrupt. Note that for DMA, the interrupts are by default enabled once you enable the DMA channels.