# button_uart

Program for measuring the time of pressing a button

The application is organized on the LL library (Low Level driver), that is very close to the registers of the microcontroller.
The program written with this library runs faster than the program used HAL library.

MCU sends strings to the serial port via the UART using DMA.

A basic timer is used to calculate the time. Timer overflow triggers an interrupt every millisecond.


USER MANUAL 

1. Buy MCU - STM32F407VG and ST-LINK-V2 or Discovery board.

![Dicovery Board](https://www.terraelectronica.ru/images/icatalog/big/0/02596927.jpg) ![ST-LINK-V2](https://arduino.ua/products_pictures/large_DPC147-11.jpg)

2. Buy USB_TO_TTL module(using for UART)

![usb_to_ttl](https://cdn.instructables.com/ORIG/F7K/G2CM/JQMOIAOC/F7KG2CMJQMOIAOC.jpg?auto=webp&frame=1&fit=bounds&md=b7d65f3903e278b1f75925aabfb9b7c5)

3. Connect the button to PA0 pin on your MCU (skip if you have Discovery)

![Pull-Down](https://i.ibb.co/ph9tXwk/Untitled-design.png)

4. Clone this repository
5. Install the STM32CubeIDE
6. Install PuTTy
7. Create the empty STM32 project
8. Copy folder from repo to your project
9. Build this - CTRL+B
10. Connect ST-LINK-V2 to SWD pins of MCU (or mini-USB in Discovery Board) 
11. Connect PA2(TX) pin to RX on USB_TO_TTL module and USB side connect to PC

![myBoard](https://i.ibb.co/k48Rgmr/photo-2020-10-12-09-47-25.jpg)

12. Open the PuTTy and choose serial, 115200 boud
13. Press "Run" button in STM32CubeIDE
14. Enjoy!

![output](https://i.ibb.co/DRkgPPG/image.png)
