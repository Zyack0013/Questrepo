// 13. Spectral Line Database
// Description:
//  Develop a database to store and analyze spectral lines of elements.
// Specifications:
// Structure: Represents line properties (wavelength, intensity, and element).
// Array: Stores spectral line data.
// Union: Handles either intensity or wavelength information.
// Strings: Represent element names.
// const Pointers: Protect spectral line data.
// Double Pointers: Allocate spectral line records dynamically.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    const char *element;       
    double wavelength;
    double intensity;          
} SpectralLine;


typedef union {
    double wavelength;         
    double intensity;          
} LineData;


void addSpectralLine(SpectralLine **lines, LineData **data, int *size);
void displaySpectralLines(SpectralLine *lines, LineData *data, int size);
void freeSpectralLines(SpectralLine **lines, LineData **data, int *size);

int main() {
    SpectralLine *lines = NULL;    
    LineData *data = NULL;         
    int size = 0;
    int choice;

    while (1) {
        printf("\n--- Spectral Line Database ---\n");
        printf("1. Add Spectral Line\n");
        printf("2. Display Spectral Lines\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addSpectralLine(&lines, &data, &size);
                break;
            case 2:
                displaySpectralLines(lines, data, size);
                break;
            case 3:
                freeSpectralLines(&lines, &data, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}


void addSpectralLine(SpectralLine **lines, LineData **data, int *size) {
    
    *lines = realloc(*lines, (*size + 1) * sizeof(SpectralLine));
    *data = realloc(*data, (*size + 1) * sizeof(LineData));

    if (*lines == NULL || *data == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

    SpectralLine *newLine = &(*lines)[*size];
    LineData *newData = &(*data)[*size];

    char element[100];
    printf("Enter element name: ");
    fgets(element, sizeof(element), stdin);
    element[strcspn(element, "\n")] = '\0'; 
    newLine->element = strdup(element);

    printf("Enter wavelength (nm): ");
    scanf("%lf", &newLine->wavelength);
    printf("Enter intensity: ");
    scanf("%lf", &newLine->intensity);

    
    int choice;
    printf("Do you want to store (1) Wavelength or (2) Intensity? ");
    scanf("%d", &choice);
    getchar(); 
    
    if (choice == 1) {
        newData->wavelength = newLine->wavelength;
    } else 
    if (choice == 2) {
    
        newData->intensity = newLine->intensity;
    } else {
    
        printf("Invalid choice! Defaulting to wavelength.\n");
        newData->wavelength = newLine->wavelength;
    
    }

    (*size)++;
    printf("Spectral line added successfully!\n");
}

void displaySpectralLines(SpectralLine *lines, LineData *data, int size) {

    if (size == 0) {

        printf("No spectral lines in the database.\n");
        return;
    }

    printf("\n--- Spectral Line Data ---\n");

    for (int i = 0; i < size; i++) {

        printf("\nSpectral Line %d:\n", i + 1);
        printf("Element: %s\n", lines[i].element);
        printf("Wavelength: %.2f nm\n", lines[i].wavelength);
        printf("Intensity: %.2f\n", lines[i].intensity);

        
        printf("Stored Data: ");

        if (data[i].wavelength != 0) {

            printf("Wavelength: %.2f nm\n", data[i].wavelength);

        } else {

            printf("Intensity: %.2f\n", data[i].intensity);

        }
    }
}

void freeSpectralLines(SpectralLine **lines, LineData **data, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*lines)[i].element); 
    }
    free(*lines);
    free(*data);
    *lines = NULL;
    *data = NULL;
    *size = 0;
}
