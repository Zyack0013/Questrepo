// 2. Electromagnetic Field Calculator
// Description:
//  Calculate the electromagnetic field intensity at various points in space.
// Specifications:
// Structure: Stores field parameters (electric field, magnetic field, and position).
// Array: Holds field values at discrete points.
// Union: Represents either electric or magnetic field components.
// Strings: Represent coordinate systems (Cartesian, cylindrical, spherical).
// const Pointers: Prevent modification of field parameters.
// Double Pointers: Manage memory for field grid allocation dynamically.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef union {
    
    float electricField; 
    float magneticField; 
} FieldComponent;

typedef struct {

    const char *coordinateSystem; 
    float position[3];            
    FieldComponent field;
    char fieldType[10];
} FieldPoint;


void addFieldPoint(FieldPoint **grid, int *size);
void displayFieldPoints(FieldPoint *grid, int size);
void freeFieldGrid(FieldPoint **grid, int *size);

int main() {
    FieldPoint *fieldGrid = NULL;
    int size = 0;                
    int choice;

    while (1) {
        printf("\n--- Electromagnetic Field Calculator ---\n");
        printf("1. Add Field Point\n");
        printf("2. Display Field Points\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
                addFieldPoint(&fieldGrid, &size);
                break;
            case 2:
                displayFieldPoints(fieldGrid, size);
                break;
            case 3:
                freeFieldGrid(&fieldGrid, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}


void addFieldPoint(FieldPoint **grid, int *size) {

    *grid = realloc(*grid, (*size + 1) * sizeof(FieldPoint));

    if (*grid == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

    FieldPoint *newPoint = &(*grid)[*size];
    char coordinateSystem[20];
    printf("Enter the coordinate system (Cartesian, Cylindrical, Spherical): ");
    fgets(coordinateSystem, sizeof(coordinateSystem), stdin);
    coordinateSystem[strcspn(coordinateSystem, "\n")] = '\0'; 
    newPoint->coordinateSystem = strdup(coordinateSystem);

    printf("Enter the position coordinates:\n");
    if (strcmp(coordinateSystem, "Cartesian") == 0) {

        printf("x: ");
        scanf("%f", &newPoint->position[0]);
        printf("y: ");
        scanf("%f", &newPoint->position[1]);
        printf("z: ");
        scanf("%f", &newPoint->position[2]);

    } else 
    if (strcmp(coordinateSystem, "Cylindrical") == 0) {

        printf("r: ");
        scanf("%f", &newPoint->position[0]);
        printf("θ (in radians): ");
        scanf("%f", &newPoint->position[1]);
        printf("z: ");
        scanf("%f", &newPoint->position[2]);

    } else 
    if (strcmp(coordinateSystem, "Spherical") == 0) {

        printf("r: ");
        scanf("%f", &newPoint->position[0]);
        printf("θ (in radians): ");
        scanf("%f", &newPoint->position[1]);
        printf("φ (in radians): ");
        scanf("%f", &newPoint->position[2]);
    } else {

        printf("Invalid coordinate system! Defaulting to Cartesian (0, 0, 0).\n");
        newPoint->position[0] = newPoint->position[1] = newPoint->position[2] = 0.0f;

    }
    getchar(); 

    printf("Enter the type of field (Electric/Magnetic): ");
    fgets(newPoint->fieldType, sizeof(newPoint->fieldType), stdin);
    newPoint->fieldType[strcspn(newPoint->fieldType, "\n")] = '\0'; 

    if (strcmp(newPoint->fieldType, "Electric") == 0) {

        printf("Enter the electric field intensity (in V/m): ");
        scanf("%f", &newPoint->field.electricField);

    } else 
    if (strcmp(newPoint->fieldType, "Magnetic") == 0) {

        printf("Enter the magnetic field intensity (in T): ");
        scanf("%f", &newPoint->field.magneticField);

    } else {

        printf("Invalid field type! Defaulting to Electric field = 0.0 V/m.\n");
        newPoint->field.electricField = 0.0f;
        strcpy(newPoint->fieldType, "Electric");

    }
    getchar(); 

    (*size)++;
    printf("Field point added successfully!\n");
}


void displayFieldPoints(FieldPoint *grid, int size) {

    if (size == 0) {

        printf("No field points available to display.\n");
        return;
    }

    printf("\n--- Field Point Details ---\n");

    for (int i = 0; i < size; i++) {

        printf("\nField Point %d:\n", i + 1);
        printf("Coordinate System: %s\n", grid[i].coordinateSystem);
        printf("Position: ");

        if (strcmp(grid[i].coordinateSystem, "Cartesian") == 0) {

            printf("(x: %.2f, y: %.2f, z: %.2f)\n",grid[i].position[0], grid[i].position[1], grid[i].position[2]);

        } else 
        if (strcmp(grid[i].coordinateSystem, "Cylindrical") == 0) {

            printf("(r: %.2f, θ: %.2f, z: %.2f)\n",grid[i].position[0], grid[i].position[1], grid[i].position[2]);

        } else 
        if (strcmp(grid[i].coordinateSystem, "Spherical") == 0) {

            printf("(r: %.2f, θ: %.2f, φ: %.2f)\n",grid[i].position[0], grid[i].position[1], grid[i].position[2]);

        }

        if (strcmp(grid[i].fieldType, "Electric") == 0) {
        
            printf("Field Type: Electric\n");
            printf("Electric Field Intensity: %.2f V/m\n", grid[i].field.electricField);
        
        } else 
        if (strcmp(grid[i].fieldType, "Magnetic") == 0) {
        
            printf("Field Type: Magnetic\n");
            printf("Magnetic Field Intensity: %.2f T\n", grid[i].field.magneticField);
        
        }
    }
}


void freeFieldGrid(FieldPoint **grid, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*grid)[i].coordinateSystem);

    }

    free(*grid);
    *grid = NULL;
    *size = 0;
}
