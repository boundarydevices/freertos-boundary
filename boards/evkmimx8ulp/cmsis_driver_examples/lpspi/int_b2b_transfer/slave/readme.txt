Overview
========
The lpspi_int_b2b_transfer example shows how to use LPSPI CMSIS driver in interrupt way:

In this example , we need two boards, one board used as LPSPI master and another board used as LPSPI slave.
The file 'cmsis_lpspi_int_b2b_transfer_slave.c' includes the LPSPI slave code.
This example uses the transactional API in LPSPI driver.

1. LPSPI master send/received data to/from LPSPI slave in interrupt . 

Toolchain supported
===================
- IAR embedded Workbench  9.30.1
- GCC ARM Embedded  10.3.1

Hardware requirements
=====================
- Micro USB cable
- two MIMX8ULP-EVK/EVK9 boards
- J-Link Debug Probe
- 5V power supply
- Personal Computer

Board settings
==============
Remove R139, R159 and populate R140, R158 on both base boards.

SPI one board:
Transfer data from one board instance to another board's instance.
SPI1 pins are connected with SPI1 pins of another board
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
INSTANCE0(SPI1)     CONNECTS TO         INSTANCE0(SPI1)
Pin Name   Board Location     Pin Name  Board Location
SPI1_SCK    J23 pin 4            SPI1_SCK  J23 pin 4
SPI1_SIN    J23 pin 2            SPI1_SOUT J23 pin 3
SPI1_SOUT   J23 pin 3            SPI1_SIN  J23 pin 2
SPI1_PCS0   J23 pin 1            SPI1_PCS0 J23 pin 1
GND                             GND
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
4.  Download the program to the target board.
5.  Either cold boot your board or launch the debugger in your IDE to begin running the example.

Running the demo
================
When the demo runs successfully, the log would be seen on the terminal like:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
LPSPI CMSIS driver board to board interrupt example.

 Slave example is running...
This is LPSPI_SlaveSignalEvent_t
Slave receive data from master has completed!
This is LPSPI_SlaveSignalEvent_t
Slave transmit data to master has completed!

 Slave receive:
      1  2  3  4  5  6  7  8  9  A  B  C  D  E  F 10
     11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F 20
     21 22 23 24 25 26 27 28 29 2A 2B 2C 2D 2E 2F 30
     31 32 33 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F 40

 Slave example is running...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
