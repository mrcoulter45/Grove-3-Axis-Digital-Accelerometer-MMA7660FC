#include "mbed.h"

/*
 * This function must be run in main.cpp first before
 * any other functions to initialize the accelerometer
 */
void MMA7660Init(void);

// returns accelerometer X value using Mbed I2C API
uint8_t getX(void);

// returns accelerometer Y value using Mbed I2C API
uint8_t getY(void);

// returns accelerometer Z value using Mbed I2C API
uint8_t getZ(void);

// reads and prints X, Y, Z values to serial
void MMA7660ReadAndPrintXYZ(void);
