// 15. Material Stress-Strain Analyzer
// Description:
//  Analyze the stress-strain behavior of materials under different loads.
// Specifications:
// Structure: Represents material properties (stress, strain, modulus).
// Array: Stores stress-strain data.
// Union: Handles dependent properties like yield stress or elastic modulus.
// Strings: Represent material names.
// const Pointers: Protect material properties.
// Double Pointers: Allocate stress-strain data dynamically.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    const char name[50];  
    double modulus; 
} Material;

typedef union {
    double yieldStress;   
    double elasticModulus; 
} MaterialProperties;


typedef struct {

    double stress; 
    double strain; 

} StressStrain;


void addMaterial(Material **materials, StressStrain ***data, int *count);
void simulateStressStrain(const Material *material, StressStrain **data, int *points);
void displayMaterials(Material *materials, StressStrain **data, int count);
void freeMaterials(Material **materials, StressStrain ***data, int *count);

int main() {

    Material *materials = NULL;        
    StressStrain **data = NULL;        
    int count = 0;                     
    int choice;

    while (1) {

        printf("\n--- Material Stress-Strain Analyzer ---\n");
        printf("1. Add Material\n");
        printf("2. Display Materials and Stress-Strain Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addMaterial(&materials, &data, &count);
                break;
            case 2:
                displayMaterials(materials, data, count);
                break;
            case 3:
                freeMaterials(&materials, &data, &count);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void addMaterial(Material **materials, StressStrain ***data, int *count) {
    
    *materials = realloc(*materials, (*count + 1) * sizeof(Material));
    *data = realloc(*data, (*count + 1) * sizeof(StressStrain *));
    
    if (*materials == NULL || *data == NULL) {
    
        printf("Memory allocation failed!\n");
        if (*materials) free(*materials);
        if (*data) free(*data);
        return;
    
    }

    char name[50];
    double modulus;

    printf("Enter material name: ");
    scanf("%s", name);
    printf("Enter elastic modulus (Pa): ");
    scanf("%lf", &modulus);

    strcpy((*materials)[*count].name, name);
    (*materials)[*count].modulus = modulus;

    int points = 0;
    simulateStressStrain(&(*materials)[*count], &(*data)[*count], &points);
    printf("Material added and stress-strain data simulated successfully!\n");

    (*count)++;
}

void simulateStressStrain(const Material *material, StressStrain **data, int *points) {
    
    int size = 100; 
    *data = malloc(size * sizeof(StressStrain));
    
    if (*data == NULL) {
    
        printf("Memory allocation for stress-strain data failed!\n");
        return;
    
    }

    *points = size;
    for (int i = 0; i < size; i++) {
    
        double strain = i * 0.0001; 
        double stress = material->modulus * strain; 
        (*data)[i].strain = strain;
        (*data)[i].stress = stress;
    }
}

void displayMaterials(Material *materials, StressStrain **data, int count) {

    if (count == 0) {

        printf("No materials added yet!\n");
        return;
    }

    printf("\n--- Materials and Stress-Strain Data ---\n");

    for (int i = 0; i < count; i++) {

        printf("\nMaterial %d:\n", i + 1);
        printf("Name: %s\n", materials[i].name);
        printf("Elastic Modulus: %.2e Pa\n", materials[i].modulus);

        printf("Stress-Strain Data:\n");
        printf("  Strain      Stress (Pa)\n");

        for (int j = 0; j < 10; j++) { 

            printf("  %.6f  %.6e\n", data[i][j].strain, data[i][j].stress);

        }
        printf("  ... (more data points omitted)\n");
    }
}

void freeMaterials(Material **materials, StressStrain ***data, int *count) {
    
    for (int i = 0; i < *count; i++) {

        free((*data)[i]); 

    }
    free(*data);
    free(*materials);

    *data = NULL;
    *materials = NULL;
    *count = 0;
}
