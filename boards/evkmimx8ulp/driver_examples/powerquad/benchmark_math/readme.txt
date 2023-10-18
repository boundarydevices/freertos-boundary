Overview
========
This example shows the PowerQuad based CMSIS DSP function performance.
It could be compared with the project powerquad_benckmark_sw_math to show the PowerQuad performance improvement.

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

Prepare the Demo
================
1.  Connect 5V power supply and J-Link Debug Probe to the board, switch SW10 to power on the board.
2.  Connect a micro USB cable between the host PC and the J17 USB port on the cpu board.
3.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Download the program to the target board.
5.  Launch the debugger in your IDE to begin running the example.

Running the demo
================
NOTE: Depending on the toolchain configuration, the benchmark result might be different.
~~~~~~~~~~~~~~~~~~~~~
CMSIS DSP benchmark math test start.
arm_sqrt_q15Test: xxx
arm_sqrt_q31Test: xxx
arm_sin_q15Test: xxx
arm_sin_q31Test: xxx
arm_sin_f32Test: xxx
arm_cos_q15Test: xxx
arm_cos_q31Test: xxx
arm_cos_f32Test: xxx

CMSIS DSP benchmark math test succeeded.
~~~~~~~~~~~~~~~~~~~~~
