# SETUP

!!! note
    'SETUP' serves as the first step to set up the main control system, which enables many fundamental functions to facilitate the operation of the system.

## HARDWARE PREPARATION

To program the main control board, we need three components:

- **The main control board** -  the development board that embeds the MCU
- **A USB-TTL adapter** - to connect the main control board to the computer
- **A DEBUGGER** (ST-LINK V2, J-LINK, etc.) - to program the main control board

### COMPONENT 1 - The Main Control Board - FANKE743

![MAIN_CONTROL](main_control.jpg){: width="500px" height="500px" }

<div class="grid cards" markdown>

-   :shopping_cart:{ .lg .middle } __product link__

    ---

    Product link


    [:octicons-arrow-right-24: <a href="https://m.tb.cn/h.glFZRKv3mP2cLID?tk=G3YX3VNEVf9" target="_blank"> Purchase Link </a>](#)

</div>

### COMPONENT 2 - USB-TTL Adapter

![USB_TTL_ADAPTER](usb_ttl.jpg)

<div class="grid cards" markdown>

-   :shopping_cart:{ .lg .middle } __product link__

    ---

    Product link


    [:octicons-arrow-right-24: <a href="[https://m.tb.cn/h.glFZRKv3mP2cLID?tk=G3YX3VNEVf9 ](https://www.waveshare.com/usb-to-ttl.htm)" target="_blank"> Purchase Link </a>](#)

</div>

### COMPONENT 3 - Debugger

![DEBUGGER](debugger.png)

<div class="grid cards" markdown>

-   :shopping_cart:{ .lg .middle } __product link__

    ---

    Product link


    [:octicons-arrow-right-24: <a href="https://www.aliexpress.com/item/1005005273159580.html?spm=a2g0o.productlist.main.1.4cb12067ieXeqH&algo_pvid=22385ace-f6bf-43ed-a7b0-693d70dfbe53&algo_exp_id=22385ace-f6bf-43ed-a7b0-693d70dfbe53-0&pdp_npi=4%40dis%21SGD%212.73%212.73%21%21%212.01%212.01%21%40213bd97f17239667324781421ec645%2112000032440955298%21sea%21SG%210%21ABX&curPageLogUid=TbhcGoAFyvod&utparam-url=scene%3Asearch%7Cquery_from%3A" target="_blank"> Purchase Link </a>](#)

</div>

!!! info
    CMSIS-DAP, ST-LINK, and J-LINK are the most commonly used debuggers. Any of these debuggers can be used to program the main control board.

## HARDWARE CONNECTION

![CONNECTION](connection.png)

Connect the three components as shown in the figure above. Then connect the USB-TTL adapter and the debugger to the computer.

## SOFTWARE SETUP