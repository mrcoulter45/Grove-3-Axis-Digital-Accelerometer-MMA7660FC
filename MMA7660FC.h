#include "mbed.h"

/*
 * This function must be run in main.cpp first before 
 * any other functions to initialize the accelerometer
 */
void MMA7660Init(void);

// returns X value using complete transaction API
uint8_t getX1(void);

// returns X value using single byte transaction API
uint8_t getX2(void);

// returns Y value using complete transaction API
uint8_t getY1(void);

// returns Y value using single byte transaction API
uint8_t getY2(void);

// returns Z value using complete transaction API
uint8_t getZ1(void);

// returns Z value using single byte transaction API
uint8_t getZ2(void);

// reads and prints X, Y, Z values to serial
void MMA7660ReadAndPrintXYZ(void);
