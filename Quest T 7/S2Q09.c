// 9. Inventory Management
// Input: Two integers: consumption rate (units/day) and lead time (days).
// Output: Reorder quantity (units).
// Function:
// int calculate_reorder_quantity(int consumption_rate, int lead_time);


#include <stdio.h>

// Function to calculate the reorder quantity

int calculate_reorder_quantity(int consumption_rate, int lead_time);


int main() {

    int consumption_rate, lead_time, reorder_quantity;

   
    printf("Enter the daily consumption rate (units/day): ");
    scanf("%d", &consumption_rate);

    
    printf("Enter the lead time (in days): ");
    scanf("%d", &lead_time);

    
    if (consumption_rate <= 0 || lead_time <= 0) {
        printf("Consumption rate and lead time must be positive integers.\n");
        return 1;
    }

    
    reorder_quantity = calculate_reorder_quantity(consumption_rate, lead_time);

   
    printf("Reorder Quantity: %d units\n", reorder_quantity);

    return 0;
}

int calculate_reorder_quantity(int consumption_rate, int lead_time) {
    
    return consumption_rate * lead_time;
}