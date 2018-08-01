#include "mbed.h"
#include "MMA7660FC.h"

// main() runs in its own thread in the OS
int main() {
    // initialize the accelerometer
    MMA7660Init();
    while (true) {
        // read and print X, Y, Z
        uint8_t X = getX();
        uint8_t Y = getY();
        uint8_t Z = getZ();
        printf("X = %d, ", X);
        printf("Y = %d, ", Y);
        printf("Z = %d\r\n ", Z);
        wait(0.2);
    }
}

