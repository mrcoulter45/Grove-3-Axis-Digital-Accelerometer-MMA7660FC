#include "mbed.h"
#include "MMA7660FC.h"

#define ACK  1
#define NACK 0

I2C i2c(I2C_SDA, I2C_SCL);

void MMA7660Init(void){
    int response;
    //set frequency
    i2c.frequency(100000);
    //set mode reg 0x07 to active mode [2:0] = 001
    i2c.start();
    response = i2c.write(0x98);//152, device address
    response = i2c.write(0x07);//MODE reg address
    response = i2c.write(0x01);//writing a 1 to the MODE reg puts device in active mode so that 
    i2c.stop();
}

uint8_t getX(void){
    int response;
    uint8_t data;
    //read XOUT
    i2c.start();
    response = i2c.write(0x98);//152, device address
    response = i2c.write(0x00);//XOUT reg address
    i2c.start();
    response = i2c.write(0x99);//device address with bit 0 set to 1 for a read
    data = i2c.read(0);
    i2c.stop();
    return data;
}

uint8_t getY(void){
    int response;
    uint8_t data;
    //read YOUT
    i2c.start();
    response = i2c.write(0x98);//152, device address
    response = i2c.write(0x01);//YOUT reg address
    i2c.start();
    response = i2c.write(0x99);//device address with bit 0 set to 1 for a read
    data = i2c.read(NACK);
    i2c.stop();
    return data;
}

uint8_t getZ(void){
    int response;
    uint8_t data;
    //read ZOUT
    i2c.start();
    response = i2c.write(0x98);//152, device address
    response = i2c.write(0x02);//ZOUT reg address
    i2c.start();
    response = i2c.write(0x99);//device address with bit 0 set to 1 for a read
    data = i2c.read(NACK);
    i2c.stop();
    return data;
}

void MMA7660ReadAndPrintXYZ(void){
    int response;
    uint8_t data;
    //read XOUT
    i2c.start();
    response = i2c.write(0x98);//152, device address
    response = i2c.write(0x00);//XOUT reg address
    i2c.start();
    response = i2c.write(0x99);//device address with bit 0 set to 1 for a read
    data = i2c.read(0);
    i2c.stop();
    printf("X = %d, ", data);
    //read YOUT
    i2c.start();
    response = i2c.write(0x98);
    response = i2c.write(0x01);//YOUT reg address
    i2c.start();
    response = i2c.write(0x99);
    data = i2c.read(NACK);
    i2c.stop();
    printf("Y = %d, ", data);
    //read ZOUT
    i2c.start();
    response = i2c.write(0x98);
    response = i2c.write(0x02);//ZOUT reg address
    i2c.start();
    response = i2c.write(0x99);
    data = i2c.read(NACK);
    i2c.stop();
    printf("Z = %d\r\n", data);
}