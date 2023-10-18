Overview
========
The WDOG32 Example project is to demonstrate usage of the KSDK wdog32 driver.
In this example, fast testing is first implemented to test the wdog32.
After this, refreshing the watchdog in None-window mode and window mode is executed.
Note wdog32 is disabled in SystemInit function which means wdog32 is disabled
after chip emerges from reset.



Toolchain supported
===================
- IAR embedded Workbench  9.30.1
- GCC ARM Embedded  10.3.1

Hardware requirements
=====================
- Micro USB cable
- MIMX8ULP-EVK/EVK9 board
- J-Link Debug Probe
- 5V power supply
- Personal Computer

Board settings
==============
No special settings are required.

#### Please note this application can't support running with Linux BSP! ####

Prepare the Demo
================
1.  Build the project and generate the flash.bin file of single boot.
    Refer to the 'Getting Started with MCUXpresso SDK for EVK-MIMX8ULP.pdf'.
2.  Connect a type-c USB cable between the host PC and the USB0 port on the target board. 
2.  Connect 5V power supply to the board.
3.  Download flash.bin into emmc with uuu.
    Refer to 'Getting Started with MCUXpresso SDK for EVK-MIMX8ULP.pdf' 
4.  Open a serial terminal with the following settings: 
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
5.  Switch the SW1 to re-power the board.

Running the demo
================
When the example runs successfully, the following message is displayed in the terminal:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
High Byte test success

----- Refresh test start -----
----- None-window mode -----
Refresh wdog32 0 time
Refresh wdog32 1 time
Refresh wdog32 2 time
Refresh wdog32 3 time
Refresh wdog32 4 time
Refresh wdog32 5 time
Refresh wdog32 6 time
Refresh wdog32 7 time
Refresh wdog32 8 time
Refresh wdog32 9 time
----- Window mode -----
Refresh wdog32 0 time
Refresh wdog32 1 time
Refresh wdog32 2 time
----- Refresh test success  -----

----- End of WDOG32 example  -----
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
