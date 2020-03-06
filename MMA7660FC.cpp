#include "mbed.h"
#include "MMA7660FC.h"

I2C i2c(I2C_SDA, I2C_SCL);

void MMA7660Init(void){
    //set i2c frequency
    i2c.frequency(100000);

    //set mode reg 0x07 to active mode [2:0] = 001
    uint8_t data[2];
    data[0] = 0x07;//MODE reg address
    data[1] = 0x01;//writing a 1 to the MODE reg puts device in active mode so that the device registers can be read
    i2c.write(0x98, (char*)data, 2);//0x98, device address
}

uint8_t getX(void){
    uint8_t data[1];
    uint8_t send_data[1] = {0x00};//XOUT reg address
    //read XOUT, complete I2C transaction
    i2c.write(0x98, (char*)send_data, 1, true);
    i2c.read(0x98, (char*)data, 1, false);
    return *data;
}

uint8_t getY(void){
    uint8_t data[1];
    uint8_t send_data[1] = {0x01};//YOUT reg address
    //read YOUT
    i2c.write(0x98, (char*)send_data, 1, true);
    i2c.read(0x98, (char*)data, 1, false);
    return *data;
}

uint8_t getZ(void){
    uint8_t data[1];
    uint8_t send_data[1] = {0x02};//ZOUT reg address
    //read ZOUT
    i2c.write(0x98, (char*)send_data, 1, true);
    i2c.read(0x98, (char*)data, 1, false);
    return *data;
}

void MMA7660ReadAndPrintXYZ(void){
    uint8_t X = getX();
    uint8_t Y = getY();
    uint8_t Z = getZ();
    printf("X: %d Y: %d Z: %d\r\n", X, Y, Z);
}
