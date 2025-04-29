Dual Axis Solar Tracker System using an Arduino and servo motors. The system uses 4 Light Dependent Resistors (LDRs) to find the optimal position of the sun by comparing light intensity from different directions and adjusting two servo motors (for horizontal and vertical movement).

# Hardware Required:
Arduino UNO

2x Servo motors (e.g., SG90 or MG995)

4x LDRs

4x 10k ohm resistors

Breadboard and jumper wires

# Circuit Design Summary:
LDRs are placed in four quadrants (Top-Left, Top-Right, Bottom-Left, Bottom-Right)

Each LDR forms a voltage divider with a resistor and connects to Arduino analog pins.

Servo1 controls horizontal rotation (left/right)

Servo2 controls vertical rotation (up/down)

## Notes:
Calibrate the threshold for your environment.

alignment with Moon requires additional data input from third party sources.

