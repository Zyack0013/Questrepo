// 9. Wave Interference Analyzer
// Description:
//  Analyze interference patterns produced by waves from multiple sources.
// Specifications:
// Structure: Represents wave properties (amplitude, wavelength, and phase).
// Array: Stores wave interference data at discrete points.
// Union: Handles either amplitude or phase information.
// Strings: Represent wave source labels.
// const Pointers: Protect wave properties.
// Double Pointers: Manage dynamic allocation of wave sources.



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14

typedef struct {

    const char *label;      
    double amplitude;       
    double wavelength;      
    double phase;   

} Wave;

void addWave(Wave **waves, int *size);
void analyzeInterference(Wave *waves, int size);
void displayWaves(Wave *waves, int size);
void freeWaves(Wave **waves, int *size);

int main() {

    Wave *waves = NULL; 
    int size = 0;       
    int choice;

    while (1) {

        printf("\n--- Wave Interference Analyzer ---\n");
        printf("1. Add Wave Source\n");
        printf("2. Analyze Interference\n");
        printf("3. Display Wave Sources\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addWave(&waves, &size);
                break;
            case 2:
                analyzeInterference(waves, size);
                break;
            case 3:
                displayWaves(waves, size);
                break;
            case 4:
                freeWaves(&waves, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
                break;
        }
    }
    return 0;
}

void addWave(Wave **waves, int *size) {

    *waves = realloc(*waves, (*size + 1) * sizeof(Wave));

    if (*waves == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

    Wave *newWave = &(*waves)[*size];
    char label[50];
    printf("Enter the label for the wave source (e.g., 'Source A'): ");
    fgets(label, sizeof(label), stdin);
    label[strcspn(label, "\n")] = '\0'; 
    newWave->label = strdup(label);

    printf("Enter the amplitude of the wave: ");
    scanf("%lf", &newWave->amplitude);
    printf("Enter the wavelength of the wave: ");
    scanf("%lf", &newWave->wavelength);
    printf("Enter the phase of the wave (in radians): ");
    scanf("%lf", &newWave->phase);
    getchar(); 
    (*size)++;
    printf("Wave source added successfully!\n");
}

void analyzeInterference(Wave *waves, int size) {
    
    if (size == 0) {

        printf("No wave sources available for analysis.\n");
        return;
    }

    double position;
    printf("Enter the position to analyze interference (x-coordinate): ");
    scanf("%lf", &position);

    double totalAmplitude = 0.0;
    for (int i = 0; i < size; i++) {

        double k = 2 * PI / waves[i].wavelength; 
        double phase = k * position + waves[i].phase; 
        totalAmplitude += waves[i].amplitude * cos(phase); 
    }

    printf("Total interference amplitude at position %.2lf: %.2lf\n", position, totalAmplitude);
}


void displayWaves(Wave *waves, int size) {

    if (size == 0) {

        printf("No wave sources to display.\n");
        return;
    }

    printf("\n--- Wave Sources ---\n");
    for (int i = 0; i < size; i++) {

        printf("\nWave %d:\n", i + 1);
        printf("Label: %s\n", waves[i].label);
        printf("Amplitude: %.2lf\n", waves[i].amplitude);
        printf("Wavelength: %.2lf\n", waves[i].wavelength);
        printf("Phase: %.2lf radians\n", waves[i].phase);
    }
}

void freeWaves(Wave **waves, int *size) {

    for (int i = 0; i < *size; i++) {

        free((void *)(*waves)[i].label);

    }
    free(*waves);
    *waves = NULL;
    *size = 0;
}
