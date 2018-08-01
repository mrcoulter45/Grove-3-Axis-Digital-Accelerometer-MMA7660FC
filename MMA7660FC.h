#include "mbed.h"

/*
 * this function must be run in main first before 
 * any other functions to initialize the accelerometer
 */
void MMA7660Init(void);

// returns X value
uint8_t getX(void);

// returns Y value
uint8_t getY(void);

// returns Z value
uint8_t getZ(void);

// reads and prints X, Y, Z values to serial
void MMA7660ReadAndPrintXYZ(void);
