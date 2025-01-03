// 8. Rocket Thrust Calculation
// Pointers: Traverse thrust arrays.
// Arrays: Store thrust values for each stage of the rocket.
// Functions:
// double compute_total_thrust(const double *stages, int size): Calculates cumulative thrust across all stages.
// void update_stage_thrust(double *stages, int stage, double new_thrust): Updates thrust for a specific stage.
// Pass Arrays as Pointers: Use pointers for thrust arrays.



#include <stdio.h>

void getData(double data[],int size);
double compute_total_thrust(double const *stages, int size);
void update_stage_thrust(double *stages, int stage, double new_thrust);


int main() {

    int size = 4,stage=0,status;
    double stages[size];
    double new_thrust=0;

    getData(stages,size);

    double total_thrust = compute_total_thrust(stages,size);
    printf("The total thrust = %lf\n",total_thrust);

    printf("Do you like to update any stage(1-->Yes or 0-->No)\n");
    scanf("%d",&status);

    if(status){

        printf("Enter the stage(0-3) : ");
        scanf("%d",&stage);
        printf("Enter the new thrust value : ");
        scanf("%lf",&new_thrust);
        update_stage_thrust(stages,stage,new_thrust);


        printf("\nUpdated Rocket Thrust for Each Stage:\n");

        for (int i = 0; i < size; i++) {

            printf("Stage %d Thrust: %.2f \n", i+1, stages[i]);

        }

        total_thrust = compute_total_thrust(stages, size);
        printf("\nTotal Rocket Thrust After Update: %.2f\n", total_thrust);


    }else{

        return 1;
    }
    
    return 0;

}


void getData(double data[],int size){

    for(int i = 0;i < size;i++) {

        printf("Enter the initial thrust for stage %d : ",i+1);
        scanf("%lf",&data[i]);

    }

}

double compute_total_thrust(double const *stages, int size){

    double total_thrust = 0.0;

    for(int i = 0;i < size;i++){

        total_thrust += stages[i];
    }

    return total_thrust;

}

void update_stage_thrust(double *stages,int stage,double new_thrust){

    if (stage >= 0) {

        stages[stage] = new_thrust;
    }

}