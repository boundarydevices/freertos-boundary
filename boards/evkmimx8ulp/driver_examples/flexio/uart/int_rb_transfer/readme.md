Overview
========
The flexio_uart_interrupt_ring_buffer example shows how to use flexio uart driver in interrupt way with
RX ring buffer enabled:

In this example, a flexio simulated uart connect to PC through USB-Serial, the board will
send back all characters that PC send to the board.

Note: The example echo every 8 characters, so input 8 characters every time.

SDK version
===========
- Version: 2.16.000

Toolchain supported
===================
- IAR embedded Workbench  9.60.1
- GCC ARM Embedded  13.2.1

Hardware requirements
=====================
- Micro USB cable
- MIMX8ULP-EVK/EVK9 board
- J-Link Debug Probe
- 5V power supply
- Personal Computer

Board settings
==============
The example requires connecting the FLEXIO0 pins with the USB2COM pins
The connection should be set as follows:
- PTA8(J20,10) on base board, TX of USB2COM connected
- PTA9(J20,9) on base board, RX of USB2COM connected
- GND(J20,7)  on base board, Ground of USB2COM connected

#### Please note this application can't support running with Linux BSP! ####

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
5.  Either press the reset button on your board or launch the debugger in your IDE to begin running the example

Running the demo
================
When the demo runs successfully, the log would be seen on the UART Terminal port which connected to the USB2COM like:

~~~~~~~~~~~~~~~~~~~~~
FLEXIO UART RX ring buffer example
Send back received data
Echo every 8 bytes
~~~~~~~~~~~~~~~~~~~~~