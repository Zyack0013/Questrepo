// 2. Satellite Orbit Simulation
// Pointers: Manipulate position and velocity vectors.
// Arrays: Represent the satellite's position over time as an array of 3D vectors.
// Functions:
// void update_position(double const *velocity, double *position, int size): Updates the position based on velocity.
// void simulate_orbit(double const *initialCondition, double *positions, int steps): Simulates orbit over a specified number of steps.
// Pass Arrays as Pointers: Use pointers for both velocity and position arrays.




#include <stdio.h>


void update_position(double const *velocity, double *position, int size);
void simulate_orbit(double const *initialCondition, double *positions, int steps);
void print_positions(const double *positions, int steps);

int main() {

    double initialCondition[6] = {0.0, 0.0, 0.0, 1.0, 1.5, 0.0};
    int steps = 5;
    double positions [steps * 3];

    simulate_orbit(initialCondition,positions,steps);
    print_positions(positions, steps);



    return 0;
}


void update_position(double const *velocity, double *position, int size){

    for(int i = 0;i < size; i++) {

        position[i] += velocity[i];

    }

}


void simulate_orbit(double const *initialCondition, double *positions, int steps){

    double velocity[3] = {initialCondition[3], initialCondition[4], initialCondition[5]}; 
    double position[3] = {initialCondition[0], initialCondition[1], initialCondition[2]}; 

    
    for (int step = 0; step < steps; step++) {
        
        for (int i = 0; i < 3; i++) {

            positions[step * 3 + i] = position[i];
        
        }

        update_position(velocity, position, 3);
    }


}

void print_positions(const double *positions, int steps) {

    printf("Satellite Positions:\n");
    for (int step = 0; step < steps; step++) {

        printf("Step %d: (%.2f, %.2f, %.2f)\n", step, positions[step * 3], positions[step * 3 + 1], positions[step * 3 + 2]);
        
    }
}
