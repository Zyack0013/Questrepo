// 15. Turbulence Detection in Aircraft
// Pointers: Traverse acceleration arrays.
// Arrays: Store acceleration data from sensors.
// Functions:
// void detect_turbulence(const double *accelerations, int size, double *output): Detects turbulence based on frequency analysis.
// void log_turbulence(double *turbulence_log, const double *detection_output, int size): Logs detected turbulence events.
// Pass Arrays as Pointers: Pass acceleration and log arrays to functions.


#include <stdio.h>

void getData(double data[],int size);
void detect_turbulence(double const *accelerations, int size, double *output);
void log_turbulence(double *turbulence_log,double const *detection_output, int size);

int main() {

    int size;

    printf("Enter the number of sensor : ");
    scanf("%d",&size);

    double accelerations[size],detection_output[size],turbulence_log[size];

    getData(accelerations,size);

    detect_turbulence(accelerations,size,detection_output);

    log_turbulence(turbulence_log,detection_output,size);



    return 0;
}

void getData(double data[],int size){

    for(int i = 0;i < size;i++) {

        printf("Enter the value at sensor %d : ",i+1);
        scanf("%lf",&data[i]);
    }

}

void detect_turbulence(double const *accelerations, int size, double *output){

    double turbulence_thershold = 0.75;
    
    for(int i = 0;i < size;i++){

        if(accelerations[i]>turbulence_thershold){

            output[i] = 1.0;
        }else {

            output[i] = 0.0;
        }

    }

}

void log_turbulence(double *turbulence_log, double const *detection_output, int size){

    for(int i = 0;i < size;i++){

        if(detection_output[i] == 1.0){

            turbulence_log[i]= 1.0;
            printf("Turbulence detected at sensor %d\n",i+1);

        }else {

            turbulence_log[i] = 0.0;
        }
    }


}