// 13. Aircraft Fuel Efficiency
// Pointers: Traverse fuel consumption arrays.
// Arrays: Store fuel consumption at different time intervals.
// Functions:
// double compute_efficiency(const double *fuel_data, int size): Calculates overall fuel efficiency.
// void update_fuel_data(double *fuel_data, int interval, double consumption): Updates fuel data for a specific interval.
// Pass Arrays as Pointers: Pass fuel data arrays as pointers.


#include <stdio.h>

void getData(double data[],int size);
double compute_efficiency(double const *fuel_data, int size);
void update_fuel_data(double *fuel_data, int interval, double consumption);

int main() {

    int size,status,interval;

    printf("Enter the number of time intervals : ");
    scanf("%d",&size);

    double fuel_data[size],fuel_efficiency=0.0,consumption;

    getData(fuel_data,size);

    fuel_efficiency = compute_efficiency(fuel_data,size);

    printf("The fuel efficiency is %.2f\n",fuel_efficiency);

    

    printf("Do you like to update any stage(1-->Yes or 0-->No)\n");
    scanf("%d",&status);

    if(status){

        printf("Enter the interval(0-4) : ");
        scanf("%d",&interval);
        printf("Enter the new value : ");
        scanf("%lf",&consumption);

        update_fuel_data(fuel_data,interval,consumption);

        printf("Updated Fuel Data:\n");

        for (int i = 0; i < size; i++) {

            printf("Interval %d: %.2f\n",i+1, fuel_data[i]);

        }



    }else{

        printf("Exiting......!");
        return 1;
    }


    return 0;
}



void getData(double data[],int size){

    for(int i = 0;i < size;i++) {

        printf("Enter the value at interval %d : ",i+1);
        scanf("%lf",&data[i]);
    }

}

double compute_efficiency(double const *fuel_data, int size){

    double total_fuel = 0.0,fuel_efficiency=0.0;

    for(int i = 0;i < size;i++){

        total_fuel += fuel_data[i];
    }

    fuel_efficiency = total_fuel / size;

    return fuel_efficiency;

}

void update_fuel_data(double *fuel_data, int interval, double consumption){

    if(interval > 0){

        fuel_data[interval] = consumption; 
    }


}