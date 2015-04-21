#include "mbed.h"
#include "DHT.h"

InterruptIn movement(D8);
InterruptIn button(USER_BUTTON);
DigitalOut myled(D9);
DHT sensor(D7,DHT11);
Serial usb(USBTX,USBRX);

void entre() {
     printf("MVE\n");
} 

void sortie(){
    printf("MVS\n");
}

int main() {
    button.rise(&entre);
    movement.rise(&sortie);
    int err;
    while(1) {      
        err = sensor.readData();
        if (err == 0) {
            printf("TEMP - Temperature is %4.2f C \r\n",sensor.ReadTemperature());
        } else
            printf("TEMP - Err %i \n",err);
 
        if ( usb.readable() != 0) {
            usb.getc();
            myled = 0;
            wait(0.1);
            myled=1;
            wait(0.7);
            myled = 0;
        }
        wait(1); // 1000 ms
    }
}
