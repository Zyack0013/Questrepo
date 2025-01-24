// 5. Optics Simulation Tool
// Description:
//  Simulate light rays passing through different optical elements.
// Specifications:
// Structure: Represents optical properties (refractive index, focal length).
// Array: Stores light ray paths.
// Union: Handles lens or mirror parameters.
// Strings: Represent optical element types.
// const Pointers: Protect optical properties.
// Double Pointers: Manage arrays of optical elements dynamically.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    double focalLength;      
    double curvatureRadius;  
} OpticalParameter;

typedef struct {
    const char *elementType;      
    double refractiveIndex;       
    OpticalParameter parameter;   
    char parameterType[20];       
    double *rayPaths;             
    int numRays;                  
} OpticalElement;

void addOpticalElement(OpticalElement **elements, int *size);
void displayOpticalElements(OpticalElement *elements, int size);
void freeOpticalElements(OpticalElement **elements, int *size);

int main() {
    OpticalElement *opticalElements = NULL; 
    int size = 0;                           
    int choice;

    while (1) {
        printf("\n--- Optics Simulation Tool ---\n");
        printf("1. Add Optical Element\n");
        printf("2. Display Optical Elements\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addOpticalElement(&opticalElements, &size);
                break;
            case 2:
                displayOpticalElements(opticalElements, size);
                break;
            case 3:
                freeOpticalElements(&opticalElements, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addOpticalElement(OpticalElement **elements, int *size) {

    *elements = realloc(*elements, (*size + 1) * sizeof(OpticalElement));
 
    if (*elements == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    OpticalElement *newElement = &(*elements)[*size];
    char elementType[20];
    printf("Enter the optical element type (e.g., 'lens', 'mirror'): ");
    fgets(elementType, sizeof(elementType), stdin);
    elementType[strcspn(elementType, "\n")] = '\0'; 
    newElement->elementType = strdup(elementType);

    if (strcmp(elementType, "lens") == 0) {

        printf("Enter the refractive index of the lens: ");
        scanf("%lf", &newElement->refractiveIndex);

    } else {
        newElement->refractiveIndex = 0; 
    }

    printf("Enter the parameter type ('focal length' or 'curvature radius'): ");
    getchar();
    fgets(newElement->parameterType, sizeof(newElement->parameterType), stdin);
    newElement->parameterType[strcspn(newElement->parameterType, "\n")] = '\0'; 

    if (strcmp(newElement->parameterType, "focal length") == 0) {

        printf("Enter the focal length: ");
        scanf("%lf", &newElement->parameter.focalLength);

    } else 
    if (strcmp(newElement->parameterType, "curvature radius") == 0) {

        printf("Enter the radius of curvature: ");
        scanf("%lf", &newElement->parameter.curvatureRadius);

    } else {

        printf("Invalid parameter type! Defaulting to focal length = 0.0.\n");
        newElement->parameter.focalLength = 0.0;
        strcpy(newElement->parameterType, "focal length");
    }

    printf("Enter the number of light rays passing through the element: ");
    scanf("%d", &newElement->numRays);
    getchar(); 

    newElement->rayPaths = malloc(newElement->numRays * sizeof(double));

    if (newElement->rayPaths == NULL) {

        printf("Memory allocation for ray paths failed!\n");
        return;
    }

    printf("Enter the ray path values:\n");

    for (int i = 0; i < newElement->numRays; i++) {

        printf("Ray %d: ", i + 1);
        scanf("%lf", &newElement->rayPaths[i]);

    }
    getchar(); 

    (*size)++;
    printf("Optical element added successfully!\n");
}

void displayOpticalElements(OpticalElement *elements, int size) {

    if (size == 0) {

        printf("No optical elements available to display.\n");
        return;
    }

    printf("\n--- Optical Element Details ---\n");

    for (int i = 0; i < size; i++) {

        printf("\nOptical Element %d:\n", i + 1);
        printf("Element Type: %s\n", elements[i].elementType);

        if (strcmp(elements[i].elementType, "lens") == 0) {
            printf("Refractive Index: %.2lf\n", elements[i].refractiveIndex);
        }

        printf("Parameter Type: %s\n", elements[i].parameterType);

        if (strcmp(elements[i].parameterType, "focal length") == 0) {

            printf("Focal Length: %.2lf\n", elements[i].parameter.focalLength);
        } else 
        if (strcmp(elements[i].parameterType, "curvature radius") == 0) {

            printf("Curvature Radius: %.2lf\n", elements[i].parameter.curvatureRadius);
        }

        printf("Ray Paths:\n");
        for (int j = 0; j < elements[i].numRays; j++) {
            printf("  Ray %d: %.2lf\n", j + 1, elements[i].rayPaths[j]);
        }
    }
}

void freeOpticalElements(OpticalElement **elements, int *size) {
   
   for (int i = 0; i < *size; i++) {

        free((void *)(*elements)[i].elementType);
        free((*elements)[i].rayPaths);
    }
    
    free(*elements);
    *elements = NULL;
    *size = 0;
}
