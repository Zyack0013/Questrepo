// 4. Satellite Orbit Analyzer
// Design a program to analyze the position of a satellite based on 10 periodic readings.
// Use const for defining the orbit radius and limits.
// Store position data in an array and calculate deviations using loops.
// Alert the user with a decision-making statement if deviations exceed specified bounds.




#include <stdio.h>
#include <stdlib.h>

#define MAXREAD 10
#define ORBITRADIUS 1000
#define DEVIATE 50

void getRead(int pos[]);
void analyze(int pos[]);

int main(){

    int pos[MAXREAD];

    printf("Enter the readings(10 readings) : " );
    getRead(pos);

    analyze(pos);

    return 0;
}

void getRead(int pos[]){

    for(int i = 0; i < MAXREAD; i++){

        printf("Reading At %d : ",i+1);
        scanf("%d",&pos[i]);

    }
}

void analyze(int pos[]){

    int count=0;

    for(int i = 0; i < MAXREAD; i++){

        int deviation = abs(pos[i] - ORBITRADIUS);

        if(deviation > DEVIATE){

            printf("Alert!!!!!, Deviation at %d is %d has exceed the limit(%d)\n",i+1,deviation,DEVIATE);
            count++;
        }
    }

    if (count == 0) {
        printf("\nNo issues in deviation limits.\n");
    } else {
        printf("\nDeviations exceeded %d times the limit.\n",count);
    }


}