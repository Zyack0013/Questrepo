// 4. Flight Control System (PID Controller)
// Pointers: Traverse and manipulate error values in arrays.
// Arrays: Store historical error values for proportional, integral, and derivative calculations.
// Functions:
// double compute_pid(const double *errors, int size, const double *gains): Calculates control output using PID logic.
// void update_errors(double *errors, double new_error): Updates the error array with the latest value.
// Pass Arrays as Pointers: Use pointers for the errors array and the gains array.



#include <stdio.h>


double compute_pid(double const *errors, int size,double const *gains);
void update_errors(double *errors, int size, double new_error);


int main() {
    
    double errors[3] = {0.0, 0.0, 0.0};  
    
    
    double gains[3] = {2.0, 0.5, 1.0}; 
    
    int size = 3;  
    double new_error;
    
    
    for (int i = 0; i < 5; i++) {
        printf("\nStep %d\n", i + 1);

        
        printf("Enter new error: ");
        scanf("%lf", &new_error);

        
        update_errors(errors, size, new_error);

        
        double control_output = compute_pid(errors, size, gains);

        
        printf("Errors (P: %.2f, I: %.2f, D: %.2f)\n", errors[0], errors[1], errors[2]);
        printf("Control Output: %.2f\n", control_output);
    }

    return 0;
}


double compute_pid(double const *errors, int size,double const *gains) {

    double output = 0.0;

    for (int i = 0; i < size; i++) {

        output += errors[i] * gains[i]; 
    }
    return output;
}


void update_errors(double *errors, int size, double new_error) {
    
    for (int i = size - 1; i > 0; i--) {
        errors[i] = errors[i - 1];
    }
    
    errors[0] = new_error;
}
