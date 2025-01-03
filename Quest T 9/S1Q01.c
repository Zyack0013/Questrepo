// 1. Flight Trajectory Calculation
// Pointers: Use to traverse the trajectory array.
// Arrays: Store trajectory points (x, y, z) at discrete time intervals.
// Functions:
// void calculate_trajectory(const double *parameters, double *trajectory, int size): Takes the initial velocity, angle, and an array to store trajectory points.
// void print_trajectory(const double *trajectory, int size): Prints the stored trajectory points.
// Pass Arrays as Pointers: Pass the trajectory array as a pointer to the calculation function.



#include <stdio.h>
#include <math.h>

#define G 9.81
#define PI 3.14


void calculate_trajectory(double const *parameters, double *trajectory, int size);
void print_trajectory(double const *trajectory, int size);

int main() {

    double parameters[2];
    int timeIntervals = 10;

    double trajectory [timeIntervals * 3];



    printf("Enter initial velocity (m/s) : ");
    scanf("%lf", &parameters[0]);
    printf("Enter launch angle (degrees) : ");
    scanf("%lf", &parameters[1]);

    calculate_trajectory(parameters,trajectory,timeIntervals);


    printf("\nFlight Trajectory \n");
    print_trajectory(trajectory,timeIntervals);



    return 0;
}

void calculate_trajectory(double const *parameters, double *trajectory, int size){

    double velocity = parameters[0];
    double angle = parameters[1];
    double angleRad = angle * PI / 180.0;
    double timeStep = 2.0 * velocity * sin(angleRad) / G / size; 

    for (int i = 0; i < size; i++) {

        double t = i * timeStep;  

        double x = velocity * cos(angleRad) * t;
        double y = velocity * sin(angleRad) * t - 0.5 * G * t * t;
        double z = 0; 
        
        trajectory[i * 3] = x;
        trajectory[i * 3 + 1] = y;
        trajectory[i * 3 + 2] = z;
    }



}

void print_trajectory(double const *trajectory, int size){

    for (int i = 0; i < size; i++) {

        printf("At point %d: x = %.2f, y = %.2f, z = %.2f\n",i + 1, trajectory[i * 3], trajectory[i * 3 + 1], trajectory[i * 3 + 2]);
    }


}