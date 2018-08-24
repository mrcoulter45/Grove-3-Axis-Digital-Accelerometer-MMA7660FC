#include "mbed.h"
#include "MMA7660FC.h"
DigitalOut led3(LED3);

int main() {
    // initialize the accelerometer
    MMA7660Init();
    while (true) {
        // read and print X, Y, Z with both Mbed I2C APIs
        uint8_t X1 = getX1();
        uint8_t X2 = getX2();
        uint8_t Y1 = getY1();
        uint8_t Y2 = getY2();
        uint8_t Z1 = getZ1();
        uint8_t Z2 = getZ2();
        printf("X1 = %d, X2 = %d, \r\n", X1, X2);
        printf("Y1 = %d, Y2 = %d, \r\n", Y1, Y2);
        printf("Z1 = %d, Z2 = %d\r\n", Z1, Z2);
        wait(0.5);
        led3 = !led3;
    }
}

