#include <stdio.h>
#include <wiringPi.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include "Libraries/SensorLib2.h"

int main()
{
    MUX *mux= initMUX();
    TOF *tof5=newTOF(1,mux,5);
    TOF *tof6=newTOF(1,mux,6);

    TOF *tof0=newTOF(0,mux,0);
    TOF *tof1=newTOF(0,mux,1);
    TOF *tof2=newTOF(0,mux,2);
    TOF *tof3=newTOF(0,mux,3);
    TOF *tof4=newTOF(0,mux,4);

    printf("Initialized tof\n");

    while(1) {
        int distance0 = getDistance(tof0);
	int distance1 = getDistance(tof1);
	int distance2 = getDistance(tof2);
	int distance3 = getDistance(tof3);
	int distance4 = getDistance(tof4);
	int distance5 = getDistance(tof5);
	int distance6 = getDistance(tof6);




	printf("0 : %i  ",distance0);
	printf("1 : %i  ",distance1);
	printf("2 : %i  ",distance2);
	printf("3 : %i  ",distance3);
	printf("4 : %i  ",distance4);
	printf("5 : %i  ",distance5);
	printf("6 : %i\n",distance6);
    }
}
