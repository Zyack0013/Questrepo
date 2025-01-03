// 12. Aerospace Material Thermal Analysis
// Pointers: Access temperature arrays for computation.
// Arrays: Store temperature values at discrete points.
// Functions:
// void simulate_heat_transfer(const double *material_properties, double *temperatures, int size): Simulates heat transfer across the material.
// void display_temperatures(const double *temperatures, int size): Outputs temperature distribution.
// Pass Arrays as Pointers: Use pointers for temperature arrays.


#include <stdio.h>


void simulate_heat_transfer(const double *material_properties, double *temperatures, int size);
void display_temperatures(const double *temperatures, int size);

int main() {
    
    double material_properties[3] = {200.0, 900.0, 0.5}; 
    
    int size = 5;
       
    double temperatures[5] = {300.0, 310.0, 315.0, 325.0, 330.0}; 
    
    simulate_heat_transfer(material_properties, temperatures, size);
    
    display_temperatures(temperatures, size);
    
    return 0;
}


void simulate_heat_transfer(const double *material_properties, double *temperatures, int size) {

    double conductivity = material_properties[0];
    double heat_capacity = material_properties[1];
    double density = material_properties[2];
    
    
    for (int i = 1; i < size - 1; i++) {
        
        temperatures[i] = temperatures[i] + conductivity * (temperatures[i - 1] - 2 * temperatures[i] + temperatures[i + 1]) / (heat_capacity * density);
    }
}


void display_temperatures(const double *temperatures, int size) {

    printf("Temperature Distribution:\n");

    for (int i = 0; i < size; i++) {
        
        printf("Point %d: %.2f\n", i, temperatures[i]);
    }
}


