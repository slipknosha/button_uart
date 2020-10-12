# button_uart

Program for measuring the time of pressing a button

The application is organized on the LL library (Low Level driver), that is very close to the registers of the microcontroller.
The program written with this library runs faster than the program used HAL library.

MCU sends strings to the serial port via the UART using DMA.

A basic timer is used to calculate the time. Timer overflow triggers an interrupt every millisecond.


USER MANUAL 

1. Buy MCU - STM32F407VG and ST-LINK-V2 or Discovery board.

![Dicovery Board](https://www.terraelectronica.ru/images/icatalog/big/0/02596927.jpg) ![ST-LINK-V2](https://arduino.ua/products_pictures/large_DPC147-11.jpg)

2. Connect the button to PA0 pin on your MCU (skip if you have Discovery)

![Pull-Down](https://i.ibb.co/ph9tXwk/Untitled-design.png)

3. Clone this repository
4. Install the STM32CubeIDE
5. Create the empty STM32 project
6. Copy folder from repo to your project
7. Build this - CTRL+B
8. Connect ST-LINK-V2 to SWD pins of MCU (or mini-USB in Discovery Board)
9. Press "Run" button
10. Enjoy!

