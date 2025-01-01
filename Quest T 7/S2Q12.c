// 12. Paint Coverage Estimation
// Input: Two floating-point numbers: surface area (m²) and paint coverage per liter (m²/liter).
// Output: Required paint (liters).
// Function:
// float calculate_paint(float area, float coverage);




#include <stdio.h>



float calculate_paint(float area, float coverage);

int main() {

    float area, coverage, required_paint;

    
    printf("Enter the surface area (m²): ");
    scanf("%f", &area);

    printf("Enter the paint coverage per liter (m²/liter): ");
    scanf("%f", &coverage);

    
    if (area <= 0 || coverage <= 0) {

        return 1; 
    }

    
    required_paint = calculate_paint(area, coverage);

   
    if (required_paint != -1) {
        printf("Required paint: %.2f liters\n", required_paint);
    }

    return 0;
}

float calculate_paint(float area, float coverage){

    if (area <= 0) {
        printf("Error: Surface area must be greater than zero.\n");
        return -1; 
    }
    if (coverage <= 0) {

        printf("Error: Paint coverage per liter must be greater than zero.\n");
        return -1; 
    }

    
    return area / coverage;
}