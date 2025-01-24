// 8. Gravitational Field Simulation
// Description:
//  Simulate the gravitational field of massive objects in a system.
// Specifications:
// Structure: Contains object properties (mass, position, field strength).
// Array: Stores field values at different points.
// Union: Handles either mass or field strength as parameters.
// Strings: Represent object labels (e.g., "Planet A," "Star B").
// const Pointers: Protect object properties.
// Double Pointers: Dynamically allocate memory for gravitational field data.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define G 6.67430e-11

typedef union {
    double mass;         
    double fieldStrength; 
} GravitationalParameter;

typedef struct {
    const char *label;   
    double position[3];  
    GravitationalParameter parameter; 
    char parameterType[10]; 

} MassiveObject;

void addObject(MassiveObject **objects, int *size);
void simulateField(MassiveObject *objects, int size);
void displayObjects(MassiveObject *objects, int size);
void freeObjects(MassiveObject **objects, int *size);

int main() {
    MassiveObject *objects = NULL; 
    int size = 0;                  
    int choice;

    while (1) {

        printf("\n--- Gravitational Field Simulation ---\n");
        printf("1. Add Massive Object\n");
        printf("2. Simulate Gravitational Field\n");
        printf("3. Display Objects\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
                addObject(&objects, &size);
                break;
            case 2:
                simulateField(objects, size);
                break;
            case 3:
                displayObjects(objects, size);
                break;
            case 4:
                freeObjects(&objects, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
                break;
        }
    }
    return 0;
}


void addObject(MassiveObject **objects, int *size) {

    *objects = realloc(*objects, (*size + 1) * sizeof(MassiveObject));

    if (*objects == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

    MassiveObject *newObject = &(*objects)[*size];
    char label[50];
    printf("Enter the label for the object (e.g., 'Planet A'): ");
    fgets(label, sizeof(label), stdin);
    label[strcspn(label, "\n")] = '\0'; 
    newObject->label = strdup(label);

    printf("Enter the position of the object (x, y, z): ");
    scanf("%lf %lf %lf", &newObject->position[0], &newObject->position[1], &newObject->position[2]);
    getchar(); 

    printf("Enter the parameter type ('mass' or 'field'): ");
    fgets(newObject->parameterType, sizeof(newObject->parameterType), stdin);
    newObject->parameterType[strcspn(newObject->parameterType, "\n")] = '\0'; 

    if (strcmp(newObject->parameterType, "mass") == 0) {

        printf("Enter the mass of the object (in kg): ");
        scanf("%lf", &newObject->parameter.mass);
        getchar(); 
    } else 
    if (strcmp(newObject->parameterType, "field") == 0) {

        printf("Enter the gravitational field strength (in N/kg): ");
        scanf("%lf", &newObject->parameter.fieldStrength);
        getchar(); 
    } else {

        printf("Invalid parameter type! Defaulting to mass = 0.0.\n");
        newObject->parameter.mass = 0.0;
        strcpy(newObject->parameterType, "mass");
    }

    (*size)++;
    printf("Massive object added successfully!\n");
}


void simulateField(MassiveObject *objects, int size) {

    if (size == 0) {

        printf("No objects available for simulation.\n");
        return;
    }

    double x, y, z;
    printf("Enter the point of interest (x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);

    double totalFieldStrength = 0.0;

    for (int i = 0; i < size; i++) {

        double dx = x - objects[i].position[0];
        double dy = y - objects[i].position[1];
        double dz = z - objects[i].position[2];
        double distanceSquared = dx * dx + dy * dy + dz * dz;

        if (distanceSquared == 0.0) {

            printf("Point coincides with object %s. Ignoring...\n", objects[i].label);
            continue;
        }

        if (strcmp(objects[i].parameterType, "mass") == 0) {

            double field = G * objects[i].parameter.mass / distanceSquared;
            totalFieldStrength += field;
        } else 
        if (strcmp(objects[i].parameterType, "field") == 0) {
        
            totalFieldStrength += objects[i].parameter.fieldStrength;
        
        }
    }

    printf("Total gravitational field strength at point (%.2lf, %.2lf, %.2lf): %.2e N/kg\n", x, y, z, totalFieldStrength);
}

void displayObjects(MassiveObject *objects, int size) {
 
    if (size == 0) {
  
        printf("No massive objects to display.\n");
        return;
    }

    printf("\n--- Massive Objects ---\n");
 
    for (int i = 0; i < size; i++) {
   
        printf("\nObject %d:\n", i + 1);
        printf("Label: %s\n", objects[i].label);
        printf("Position: (%.2lf, %.2lf, %.2lf)\n", objects[i].position[0], objects[i].position[1], objects[i].position[2]);

        if (strcmp(objects[i].parameterType, "mass") == 0) {
    
            printf("Mass: %.2e kg\n", objects[i].parameter.mass);
      
        } else 
        if (strcmp(objects[i].parameterType, "field") == 0) {

            printf("Gravitational Field Strength: %.2e N/kg\n", objects[i].parameter.fieldStrength);
        }
    }
}

void freeObjects(MassiveObject **objects, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*objects)[i].label);

    }
    
    free(*objects);
    *objects = NULL;
    *size = 0;
}
