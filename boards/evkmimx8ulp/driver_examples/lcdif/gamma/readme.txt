Overview
========
This example demonstrates how to use the LCDIF gamma correction feature. In this
example, the gamma corretion table is set to invert the original picture. The
original picture is gradual changed gray bars, the gamma correction is continuously
enabled and disabled, so you can see the screen switch between the original
picture and the inverted picture.

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
- RK055AHD091 panel or RK055MHD091 panel

Board settings
==============
Connect the MIPI panel to MIMX8ULP-EVK board J18.

Prepare the Demo
================
1.  Connect 5V power supply and J-Link Debug Probe to the board, switch SW10 to power on the board.
2.  Connect a micro USB cable between the host PC and the J17 USB port on the target board.
3.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Build the project, this project uses RK055MHD091 panel by default, to use the RK055AHD091 panel,
    change #define USE_MIPI_PANEL MIPI_PANEL_RK055MHD091 to #define USE_MIPI_PANEL MIPI_PANEL_RK055AHD091
    in lcdif_support.h.
5.  Generate flash.bin with imx-mkimage and download it according to Getting Started doc
6.  Open two serials lines provided at J17 USB port.
    (e.g. /dev/ttyUSB0~3, /dev/ttyUSB2 for A Core, /dev/ttyUSB3 for M Core)
7.  Boot to uboot and let uboot not using diplay
    => setenv video_off yes;saveenv
    then re-power on the board
8.  Let Stop in Uboot

Running the demo
================
When the example runs, the screen shows what described in overview.
