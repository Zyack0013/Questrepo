// 13. Machine Maintenance Schedule
// Input: Two integers: current usage (hours) and maintenance interval (hours).
// Output: Hours remaining for maintenance.
// Function:
// int calculate_maintenance_schedule(int current_usage, int interval);
 

#include <stdio.h>


int calculate_maintenance_schedule(int current_usage, int interval);

int main(){

    int current_usage, interval, remaining_hours;

    printf("Enter the current usage (hours): ");
    scanf("%d", &current_usage);

    printf("Enter the maintenance interval (hours): ");
    scanf("%d", &interval);

    remaining_hours = calculate_maintenance_schedule(current_usage, interval);

    
    if (remaining_hours != -1) {

        printf("Remaining hours for maintenance: %d hours\n", remaining_hours);
    }

    return 0;
}


int calculate_maintenance_schedule(int current_usage, int interval){
    
    if (current_usage < 0 || interval <= 0) {

        printf("Error: Current usage must be non-negative and interval must be positive.\n");
        return -1; 
    }

    return interval - (current_usage % interval);
}