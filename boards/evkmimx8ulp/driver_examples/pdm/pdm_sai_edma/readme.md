Overview
========
The pdm sai edma example shows how to use pdm driver with edma:

In this example, pdm gathers one channel's audio data though edma, then sai sends it to codec.

SDK version
===========
- Version: 2.15.000

Toolchain supported
===================
- IAR embedded Workbench  9.40.1
- GCC ARM Embedded  12.2

Hardware requirements
=====================
- Micro USB cable
- MIMX8ULP-EVK  board
- J-Link Debug Probe
- 5V power supply
- Personal Computer
- Microphone

Board settings
==============
populate J20, J21
Connect microphone module to EVK board:
3V->J20-8
GND->J20-7
CLK->J21-4
DATA->J21-3

#### Please note this application can't support running with Linux BSP! ####

Prepare the Demo
================
1.  Connect 5V power supply and JLink Plus to the board, switch SW10 to power on the board
2.  Connect a micro USB cable between the host PC and the J17 USB port on the target board.
3.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Download the program to the target board.
5.  Launch the debugger in your IDE to begin running the demo.


Running the demo
================
When the demo runs successfully, you can hear the sound gathered from microphone and the log would be seen on the OpenSDA terminal like:

~~~~~~~~~~~~~~~~~~~
PDM SAI Edma example started!
~~~~~~~~~~~~~~~~~~~
