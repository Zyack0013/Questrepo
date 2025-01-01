// 6. Energy Cost Estimation
// Input: Three floating-point numbers: power rating (kW), operating hours, and cost per kWh.
// Output: The total energy cost.
// Function:
// float calculate_energy_cost(float power_rating, float hours, float cost_per_kwh);


#include <stdio.h>


float calculate_energy_cost(float power_rating, float hours, float cost_per_kwh);

int main(){

    float power_rating, hours, cost_per_kwh, total_cost;

    
    printf("Enter the power rating of the machine (in kW): ");
    scanf("%f", &power_rating);


    printf("Enter the operating hours: ");
    scanf("%f", &hours);


    printf("Enter the cost per kWh: ");
    scanf("%f", &cost_per_kwh);


    total_cost = calculate_energy_cost(power_rating, hours, cost_per_kwh);

    
    if (total_cost != -1) {
        printf("The total energy cost is: %.2f\n", total_cost);
    }

    return 0;
}

float calculate_energy_cost(float power_rating, float hours, float cost_per_kwh) {

    if (power_rating < 0 || hours < 0 || cost_per_kwh < 0) {

        printf("Invalid input. Power rating, hours, and cost per kWh must all be non-negative.\n");
        return -1; 
    }
    return power_rating * hours * cost_per_kwh;
}