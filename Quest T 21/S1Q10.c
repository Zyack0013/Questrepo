// 10. Magnetic Material Property Database
// Description:
//  Create a database to store and retrieve properties of magnetic materials.
// Specifications:
// Structure: Represents material properties (permeability, saturation).
// Array: Stores data for multiple materials.
// Union: Handles temperature-dependent properties.
// Strings: Represent material names.
// const Pointers: Protect material data.
// Double Pointers: Allocate material records dynamically.
 

 #include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    const char *name;         
    double permeability;      
    double saturation;        
    
} Material;

typedef union {
    double CurieTemperature;  
    double Resistivity;       
} TempProperty;

void addMaterial(Material **materials, TempProperty **properties, int *size);
void displayMaterials(Material *materials, TempProperty *properties, int size);
void freeMaterials(Material **materials, TempProperty **properties, int *size);

int main() {

    Material *materials = NULL;
    TempProperty *properties = NULL; 
    int size = 0;                     
    int choice;

    while (1) {
        printf("\n--- Magnetic Material Property Database ---\n");
        printf("1. Add Material\n");
        printf("2. Display Materials\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
                addMaterial(&materials, &properties, &size);
                break;
            case 2:
                displayMaterials(materials, properties, size);
                break;
            case 3:
                freeMaterials(&materials, &properties, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}


void addMaterial(Material **materials, TempProperty **properties, int *size) {
    
    *materials = realloc(*materials, (*size + 1) * sizeof(Material));
    *properties = realloc(*properties, (*size + 1) * sizeof(TempProperty));
    
    if (*materials == NULL || *properties == NULL) {
    
        printf("Memory allocation failed!\n");
        return;
    }

    Material *newMaterial = &(*materials)[*size];
    TempProperty *newProperty = &(*properties)[*size];

    char name[50];
    printf("Enter the material name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 
    newMaterial->name = strdup(name);

    printf("Enter the permeability of the material: ");
    scanf("%lf", &newMaterial->permeability);
    printf("Enter the saturation of the material: ");
    scanf("%lf", &newMaterial->saturation);

    printf("Enter the Curie temperature of the material: ");
    scanf("%lf", &newProperty->CurieTemperature);
    getchar(); 

    (*size)++;
    printf("Material added successfully!\n");
}

void displayMaterials(Material *materials, TempProperty *properties, int size) {

    if (size == 0) {

        printf("No materials to display.\n");
        return;
    }

    printf("\n--- Material Database ---\n");
    for (int i = 0; i < size; i++) {
        printf("\nMaterial %d:\n", i + 1);
        printf("Name: %s\n", materials[i].name);
        printf("Permeability: %.2lf\n", materials[i].permeability);
        printf("Saturation: %.2lf\n", materials[i].saturation);
        printf("Curie Temperature: %.2lf°C\n", properties[i].CurieTemperature);
    }
}

void freeMaterials(Material **materials, TempProperty **properties, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*materials)[i].name); 
    }
    free(*materials);
    free(*properties);
    *materials = NULL;
    *properties = NULL;
    *size = 0;
}
