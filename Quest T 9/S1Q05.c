// 5. Aircraft Sensor Data Fusion
// Pointers: Handle sensor readings and fusion results.
// Arrays: Store data from multiple sensors.
// Functions:
// void fuse_data(const double *sensor1, const double *sensor2, double *result, int size): Merges two sensor datasets into a single result array.
// void calibrate_data(double *data, int size): Adjusts sensor readings based on calibration data.
// Pass Arrays as Pointers: Pass sensor arrays as pointers to fusion and calibration functions.


#include <stdio.h> 

void getData(double data[],int size);
void fuse_data(double const *sensor1,double const *sensor2, double *result, int size);
void calibrate_data(double *data, int size);

int main() {

    int size = 5;
    double sensor1[size];
    double sensor2[size];
    double fused_result[size];

    printf("Enter sensor 1 data\n");
    getData(sensor1,size);
    printf("Enter sensor 2 data\n");
    getData(sensor2,size);

    fuse_data(sensor1,sensor2,fused_result,size);

    printf("Fused Sensor Data:\n");
    for (int i = 0; i < size; i++){

        printf("Reading %d: %.2f\n", i + 1, fused_result[i]);

    }

    calibrate_data(fused_result,size);

    printf("\nCalibrated Fused Data:\n");

    for (int i = 0; i < size; i++) {

        printf("Reading %d: %.2f\n", i + 1, fused_result[i]);
    }


    return 0;
}



void getData(double data[],int size){

    for(int i = 0;i < size;i++) {

        printf("Enter the reading %d : ",i+1);
        scanf("%lf",&data[i]);
    }

}

void fuse_data(double const *sensor1,double const *sensor2, double *result, int size){

    for(int i = 0;i < size;i++){

        result[i] = (sensor1[i] + sensor2[i])/2.0;

    }
}


void calibrate_data(double *data, int size){

    double calibration_offset = 0.8;
    for(int i = 0;i < size;i++){

        data[i] += calibration_offset;
    }


}