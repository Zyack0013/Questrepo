// 12. Kinematics Equation Solver
// Description:
//  Solve complex kinematics problems for objects in motion.
// Specifications:
// Structure: Represents object properties (initial velocity, acceleration, displacement).
// Array: Stores time-dependent motion data.
// Union: Handles either velocity or displacement equations.
// Strings: Represent motion descriptions.
// const Pointers: Protect object properties.
// Double Pointers: Dynamically allocate memory for motion data.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct {
    
    const char *description;   
    double initialVelocity;    
    double acceleration;       
    double displacement;       
} Motion;


typedef union {
    double velocity;           
    double displacement;       
} MotionData;


void addMotion(Motion **motions, MotionData **data, int *size);
void solveKinematics(Motion *motions, MotionData *data, int size);
void freeMotions(Motion **motions, MotionData **data, int *size);

int main() {

    Motion *motions = NULL;
    MotionData *data = NULL;
    int size = 0;                
    int choice;

    while (1) {
        printf("\n--- Kinematics Equation Solver ---\n");
        printf("1. Add Motion Parameters\n");
        printf("2. Solve Kinematics Equations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
                addMotion(&motions, &data, &size);
                break;
            case 2:
                solveKinematics(motions, data, size);
                break;
            case 3:
                freeMotions(&motions, &data, &size);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}


void addMotion(Motion **motions, MotionData **data, int *size) {
    
    *motions = realloc(*motions, (*size + 1) * sizeof(Motion));
    *data = realloc(*data, (*size + 1) * sizeof(MotionData));
    
    if (*motions == NULL || *data == NULL) {
    
        printf("Memory allocation failed!\n");
        return;
    }

    Motion *newMotion = &(*motions)[*size];
    MotionData *newData = &(*data)[*size];

    char description[100];
    printf("Enter motion description: ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = '\0'; 
    newMotion->description = strdup(description);

    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &newMotion->initialVelocity);
    printf("Enter the acceleration (m/s^2): ");
    scanf("%lf", &newMotion->acceleration);
    printf("Enter the displacement (m): ");
    scanf("%lf", &newMotion->displacement);

    
    int choice;
    printf("Do you want to calculate (1) Velocity or (2) Displacement? ");
    scanf("%d", &choice);
    getchar(); 
    
    if (choice == 1) {
    
        double time;
        printf("Enter the time (s): ");
        scanf("%lf", &time);
        newData->velocity = newMotion->initialVelocity + newMotion->acceleration * time;
    
    } else 
    if (choice == 2) {

        double time;
        printf("Enter the time (s): ");
        scanf("%lf", &time);
        newData->displacement = newMotion->initialVelocity * time + 0.5 * newMotion->acceleration * pow(time, 2);

    } else {

        printf("Invalid choice! Defaulting to velocity calculation.\n");
        newData->velocity = newMotion->initialVelocity;
    }

    (*size)++;
    printf("Motion parameters added successfully!\n");
}


void solveKinematics(Motion *motions, MotionData *data, int size) {

    if (size == 0) {

        printf("No motion data available to solve.\n");
        return;
    }

    printf("\n--- Kinematics Solutions ---\n");
    for (int i = 0; i < size; i++) {

        printf("\nMotion %d:\n", i + 1);
        printf("Description: %s\n", motions[i].description);
        printf("Initial Velocity: %.2f m/s\n", motions[i].initialVelocity);
        printf("Acceleration: %.2f m/s^2\n", motions[i].acceleration);
        printf("Displacement: %.2f m\n", motions[i].displacement);


        printf("Union Data: ");

        if (data[i].velocity != 0) {

            printf("Velocity: %.2f m/s\n", data[i].velocity);

        } else {

            printf("Displacement: %.2f m\n", data[i].displacement);
        }
    }
}


void freeMotions(Motion **motions, MotionData **data, int *size) {

    for (int i = 0; i < *size; i++) {
        free((void *)(*motions)[i].description); 
    }
    free(*motions);
    free(*data);
    *motions = NULL;
    *data = NULL;
    *size = 0;
}
