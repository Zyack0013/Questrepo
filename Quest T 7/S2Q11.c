// 11. Assembly Line Efficiency
// Input: Two integers: output rate (units/hour) and downtime (minutes).
// Output: Efficiency (percentage).
// Function:
// float calculate_efficiency(int output_rate, int downtime);


#include <stdio.h>


float calculate_efficiency(int output_rate, int downtime);


int main() {

    int output_rate, downtime;
    float efficiency;

    
    printf("Enter the output rate (units per hour): ");
    scanf("%d", &output_rate);

    printf("Enter the downtime (minutes): ");
    scanf("%d", &downtime);

    
    if (output_rate <= 0 || downtime < 0 || downtime > 60) {

        return 1; 
    }


    efficiency = calculate_efficiency(output_rate, downtime);

    
    if (efficiency != -1) {

        printf("Assembly Line Efficiency: %.2f%%\n", efficiency);
    }

    return 0;
}


float calculate_efficiency(int output_rate, int downtime){

    if (output_rate <= 0) {

        printf("Error: Output rate must be greater than zero.\n");
        return -1; 
    }
    if (downtime < 0 || downtime > 60) {

        printf("Error: Downtime should be between 0 and 60 minutes.\n");
        return -1; 
    }

    int total_time = 60;

    
    int operating_time = total_time - downtime;

    return ((float)(output_rate * operating_time) / total_time) * 100;

}