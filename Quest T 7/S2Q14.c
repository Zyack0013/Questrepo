// 14. Cycle Time Optimization
// Input: Two integers: machine speed (units/hour) and number of operations per cycle.
// Output: Optimal cycle time (seconds).
// Function:
// float calculate_cycle_time(int speed, int operations);


#include <stdio.h>


float calculate_cycle_time(int speed, int operations);

int main(){

    int speed, operations;
    float cycle_time;


    printf("Enter machine speed (units/hour): ");
    scanf("%d", &speed);

    printf("Enter number of operations per cycle: ");
    scanf("%d", &operations);

    
    cycle_time = calculate_cycle_time(speed, operations);

    
    if (cycle_time != -1.0f) {
        printf("Optimal cycle time: %.2f seconds\n", cycle_time);
    }

    return 0;
}



float calculate_cycle_time(int speed, int operations){
    
    if (speed <= 0 || operations <= 0) {
        printf("Error: Machine speed and operations must be positive values.\n");
        return -1.0f; 
    }

    return 3600.0f / (speed * operations);
}
