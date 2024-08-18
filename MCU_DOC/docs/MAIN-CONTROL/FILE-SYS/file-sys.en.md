# FILE SYSTEM

!!! info
    File system is a method of storing and organizing computer files and their data. Here, we will use the FatFs library to interface with the SD card.

## FILE SYSTEM AS A MIDDLEWARE
In STM32CUBEMX, FATFS is already incorporated into the software as a middleware. To enable FATFS, go to the 'Middleware' tab and enable the 'FATFS' middleware and nothing more to configure in the CUBE-MX.、

![config_fatfs](config_fatfs.png)

## GENERATE AND UPDATE CODE
Finally, let's generate the code to save the current progress and to make it ready for following programming steps. Click the 'Generate Code' button at the top right corner of the screen.