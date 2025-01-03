// 11. Satellite Attitude Control
// Pointers: Manipulate quaternion arrays.
// Arrays: Store quaternion values for attitude control.
// Functions:
// void update_attitude(double const *quaternion, double *new_attitude): Updates the satellite's attitude.
// void normalize_quaternion(double *quaternion): Ensures quaternion normalization.
// Pass Arrays as Pointers: Pass quaternion arrays as pointers.


#include <stdio.h>
#include <math.h>


void update_attitude(double const *quaternion, double *new_attitude);
void normalize_quaternion(double *quaternion);
double calculate_norm(double const *quaternion);

int main() {
    
    double quaternion[4] = {1.0, 0.0, 0.0, 0.0};
    double new_attitude[4];  
    
    printf("Initial Attitude: (%.2f, %.2f, %.2f, %.2f)\n", quaternion[0], quaternion[1], quaternion[2], quaternion[3]);

    
    update_attitude(quaternion, new_attitude);
    printf("Updated Attitude: (%.2f, %.2f, %.2f, %.2f)\n", new_attitude[0], new_attitude[1], new_attitude[2], new_attitude[3]);

    
    normalize_quaternion(new_attitude);
    printf("Normalized Attitude: (%.2f, %.2f, %.2f, %.2f)\n", new_attitude[0], new_attitude[1], new_attitude[2], new_attitude[3]);

    return 0;
}

double calculate_norm(double const *quaternion) {

    return sqrt(quaternion[0] * quaternion[0] + quaternion[1] * quaternion[1] + quaternion[2] * quaternion[2] + quaternion[3] * quaternion[3]);

}

void update_attitude(double const *quaternion, double *new_attitude) {
    

    new_attitude[0] = quaternion[0]; 
    new_attitude[1] = -quaternion[1]; 
    new_attitude[2] = -quaternion[2]; 
    new_attitude[3] = -quaternion[3]; 
    
}


void normalize_quaternion(double *quaternion) {

    double norm = calculate_norm(quaternion);
    
    if (norm == 0.0) {

        printf("Warning: Quaternion has zero norm, cannot normalize.\n");
        return;
    }

    
    quaternion[0] /= norm;
    quaternion[1] /= norm;
    quaternion[2] /= norm;
    quaternion[3] /= norm;
}
