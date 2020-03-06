#include "mbed.h"
#include "platform/mbed_thread.h"
#include "MMA7660FC.h"

int main()
{
    DigitalOut led3(LED3);
    MMA7660Init();

    while (true) {
        MMA7660ReadAndPrintXYZ();
        led3 = !led3;
        thread_sleep_for(200);
    }
}
