# FMC

!!! info
    FMC stands for Flexible Memory Controller. It is a feature that allows the MCU to interface with external memory devices such as SDRAM, SRAM, and NOR Flash. 

## FMC SETUP
![FMC_PARA](fmc_para.png)

As shown, in the 'Connectivity' tab, enable FMC, and then enable the SDRAM device in FMC configuration zone, and set the parameters according to the datasheet of the SDRAM device.

## SDRAM

SDRAM is one of the most common types of external memory devices that can be interfaced with the MCU using the FMC. It is a type of volatile memory that is used in computers and other electronic devices. Here, since the built-in RAM is only 1MB, and not enough for some applications, we need to use external SDRAM to expand the memory capacity.

## GENERATE AND UPDATE CODE
Finally, let's generate the code to save the current progress and to make it ready for following programming steps. Click the 'Generate Code' button at the top right corner of the screen.