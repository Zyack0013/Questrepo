// 1. Engine Temperature Monitoring System
// Write a program to monitor engine temperatures at 10 different time intervals in degrees Celsius. Use:
// Proper variable declarations with const to ensure fixed limits like maximum temperature.
// Storage classes (static for counters and extern for shared variables).
// Decision-making statements to alert if the temperature exceeds a safe threshold.
// A loop to take 10 temperature readings into a single-dimensional array and check each value.


#include <stdio.h>

int const maxTemp = 100;
int const maxRead = 10;

void getArray(int tempRead[]);
void mTemp(int tempRead[]);

int main(){

    int tempRead[maxRead];

    printf("Enter the temperature in C : \n ");

    getArray(tempRead);

    mTemp(tempRead);

    return 0;

}

void mTemp(int tempRead[]){

    static int count=0;

    for(int i = 0; i < maxRead; i++){

        printf("Interval : %d \t--> %d\n",i+1,tempRead[i]);

        if(tempRead[i]>= maxTemp){

            count++;
            printf("Alert!!!, The temperature is higher than the thershold value : %d at %d intervel \n",tempRead[i],i+1);
        }
    }

    printf("Number of time temperature was higher than thershold value is %d\n",count);

}

void getArray(int tempRead[]){

    for(int i=0; i < maxRead; i++){

        printf("Reading : %d",i+1);
        scanf("%d",&tempRead[i]);
    }
}