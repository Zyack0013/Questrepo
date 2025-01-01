// 8. Tool Wear Rate Calculation
// Input: A floating-point number for operating time (hours) and an integer for material type (e.g., 1 for metal, 2 for plastic).
// Output: Wear rate (percentage).
// Function:
// float calculate_wear_rate(float time, int material_type);



#include <stdio.h>

float calculate_wear_rate(float time, int material_type);

int main() {


    float time;
    int material_type;
    float wear_rate;

    
    printf("Enter the operating time (in hours): ");
    scanf("%f", &time);

    
    printf("Enter the material type (1 for metal, 2 for plastic): ");
    scanf("%d", &material_type);

    
    wear_rate = calculate_wear_rate(time, material_type);

    
    if (wear_rate != -1) {
        printf("The tool wear rate is: %.2f%%\n", wear_rate);
    }

    return 0;
}


float calculate_wear_rate(float time, int material_type){

    float wear_rate = 0.0;
    float coefficient = 0.0;

    
    if (material_type == 1) {

        coefficient = 2.0; 

    } else 
    if (material_type == 2) {

        coefficient = 1.0; 

    } else {
        printf("Invalid material type. Enter 1 for metal or 2 for plastic.\n");
        return -1; 
    }

    wear_rate = time * coefficient;

    
    if (wear_rate > 100.0) {
        wear_rate = 100.0;
    }

    return wear_rate;
}