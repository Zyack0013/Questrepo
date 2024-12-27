// 2. Fuel Efficiency Calculator
// Develop a program that calculates and displays fuel efficiency based on distances covered in 10 different trips.
// Use an array to store distances.
// Implement a loop to take inputs and calculate efficiency for each trip using a predefined fuel consumption value.
// Use volatile for sensor data inputs and conditionals to check for low efficiency (< 10 km/L).




#include <stdio.h>

#define MAXTRIPS 10
#define FUEL 4.0


void getDistance(float distance[]);
int main(){

    float distance[MAXTRIPS];
    volatile float fuel= FUEL;

    printf("Enter the Distance of each trip in km : \n");
    getDistance(distance);

    printf("\nTrip No. | Distance  | Fuel Efficiency \n");

    for(int i = 0; i < MAXTRIPS; i++){

        float fuelEff = distance[i]/fuel;
        printf("%d  |  %.2fkm  |  %.2fkm/l\n",i+1,distance[i],fuelEff);
        
        if(fuelEff < 10){

            printf("Low efficiency (< 10 km/L) ");
        }
    }

    return 0;
}

void getDistance(float distance[]){

    for(int i = 0; i < MAXTRIPS; i++){

        printf("Enter the Trip %d distance : ",i+1);
        scanf("%f",&distance[i]);
    }
}