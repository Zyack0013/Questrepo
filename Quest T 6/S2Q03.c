// 3. Altitude Monitoring for Aircraft
// Create a program to store altitude readings (in meters) from a sensor over 10 seconds.
// Use a register variable for fast access to the c altitude.
// Store the readings in a single-dimensional array.
// Implement logic to identify if the altitude deviates by more than ±50 meters between consecutive readings.


#include <stdio.h>
#include <stdlib.h>

#define READINGS 10
#define DEVIATE 50

void getReadings(int altRead[]);
void moniterRead(int altRead[]);
int main(){

    int altRead[READINGS];

    printf("Enter the Altitude reading for 10sec. \n");

    getReadings(altRead);

    moniterRead(altRead);


    return 0;
}


void getReadings(int altRead[]){

    for(int i = 0; i < READINGS; i++){

        printf("\nEnter the Altitude Rading %d : ",i+1);
        scanf("%d",&altRead[i]);

    }
}

void moniterRead(int altRead[]){


    printf("\nMonitoring Altitude Deviations:\n");
    for (int i = 1; i < READINGS; i++) {

        register int cAlt = altRead[i];

        if (abs(cAlt - altRead[i - 1]) > DEVIATE){

            printf("Warning!!! Altitude deviation exceeds threshold at second %d! ""Previous Altitude: %d meters, Current Altitude: %d meters.\n",i + 1, altRead[i - 1],cAlt);
        }
    }
}