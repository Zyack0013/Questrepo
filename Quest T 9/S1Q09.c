// 9. Wing Stress Analysis
// Pointers: Access stress values at various points.
// Arrays: Store stress values for discrete wing sections.
// Functions:
// void compute_stress_distribution(double const *forces, double *stress, int size): Computes stress values based on applied forces.
// void display_stress(double const *stress, int size): Displays the stress distribution.
// Pass Arrays as Pointers: Pass stress arrays to computation functions.


#include <stdio.h>


void compute_stress_distribution(double const *forces, double *stress, int size);
void display_stress(double const *stress, int size);

int main() {
    
    double forces[] = {500.0, 600.0, 700.0, 550.0, 450.0};  
    int size = sizeof(forces) / sizeof(forces[0]);

    double stress[size]; 

    
    compute_stress_distribution(forces, stress, size);

    
    display_stress(stress, size);

    return 0;
}


void compute_stress_distribution(double const *forces, double *stress, int size) {
    
    double const area = 10.0;  

    for (int i = 0; i < size; i++) {
        stress[i] = forces[i] / area;
    }
}


void display_stress(double const *stress, int size) {

    printf("Wing Stress Distribution :\n");
    for (int i = 0; i < size; i++) {

        printf("Section %d: Stress = %.2f Pa\n", i+1, stress[i]);
    }
}
