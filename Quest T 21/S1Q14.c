// 14. Projectile Motion Simulator
// Description:
//  Simulate and analyze projectile motion under varying conditions.
// Specifications:
// Structure: Stores projectile properties (mass, velocity, and angle).
// Array: Stores motion trajectory data.
// Union: Handles either velocity or displacement parameters.
// Strings: Represent trajectory descriptions.
// const Pointers: Protect projectile properties.
// Double Pointers: Manage trajectory records dynamically.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

typedef struct {
    double mass;       
    double velocity;   
    double angle;      
} Projectile;


typedef union {
    double velocity;         
    double displacement;     
} MotionData;


void addTrajectoryRecord(Projectile **projectiles, MotionData ***trajectories, int *count);
void simulateProjectile(const Projectile *projectile, MotionData **trajectory, int *points);
void displayTrajectories(Projectile *projectiles, MotionData **trajectories, int count);
void freeTrajectories(Projectile **projectiles, MotionData ***trajectories, int *count);

int main() {

    Projectile *projectiles = NULL;      
    MotionData **trajectories = NULL;    
    int count = 0;                       
    int choice;

    while (1) {
        printf("\n--- Projectile Motion Simulator ---\n");
        printf("1. Add Projectile\n");
        printf("2. Display Trajectories\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addTrajectoryRecord(&projectiles, &trajectories, &count);
                break;
            case 2:
                displayTrajectories(projectiles, trajectories, count);
                break;
            case 3:
                freeTrajectories(&projectiles, &trajectories, &count);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
        }
    }
    return 0;
}


void addTrajectoryRecord(Projectile **projectiles, MotionData ***trajectories, int *count) {
    
    *projectiles = realloc(*projectiles, (*count + 1) * sizeof(Projectile));
    *trajectories = realloc(*trajectories, (*count + 1) * sizeof(MotionData *));
    
    if (*projectiles == NULL || *trajectories == NULL) {
    
        printf("Memory allocation failed!\n");
        return;
    }

    double mass, velocity, angle;
    printf("Enter mass of the projectile (kg): ");
    scanf("%lf", &mass);
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &velocity);
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &angle);


    (*projectiles)[*count] = (Projectile){.mass = mass, .velocity = velocity, .angle = angle};

    
    int points = 0;
    simulateProjectile(&(*projectiles)[*count], &(*trajectories)[*count], &points);
    printf("Projectile added and trajectory simulated successfully!\n");

    (*count)++;
}


void simulateProjectile(const Projectile *projectile, MotionData **trajectory, int *points) {

    const double g = 9.81; 
    const double angleRad = projectile->angle * PI / 180.0;

    double timeOfFlight = (2 * projectile->velocity * sin(angleRad)) / g;
    double maxRange = (projectile->velocity * projectile->velocity * sin(2 * angleRad)) / g;
    double maxHeight = (projectile->velocity * projectile->velocity * sin(angleRad) * sin(angleRad)) / (2 * g);

    printf("Time of Flight: %.2f s\n", timeOfFlight);
    printf("Maximum Range: %.2f m\n", maxRange);
    printf("Maximum Height: %.2f m\n", maxHeight);

    
    int size = (int)(timeOfFlight / 0.1) + 1;
    *trajectory = malloc(size * sizeof(MotionData));
    
    if (*trajectory == NULL) {
    
        printf("Memory allocation for trajectory failed!\n");
        return;
    }

    *points = 0;
    for (double t = 0; t <= timeOfFlight; t += 0.1) {

        double x = projectile->velocity * cos(angleRad) * t;
        double y = (projectile->velocity * sin(angleRad) * t) - (0.5 * g * t * t);
        if (y < 0) y = 0;

        (*trajectory)[*points].displacement = sqrt(x * x + y * y); 
        (*points)++;
    }
}


void displayTrajectories(Projectile *projectiles, MotionData **trajectories, int count) {

    if (count == 0) {
        printf("No projectiles added yet!\n");
        return;
    }

    printf("\n--- Projectile Trajectories ---\n");

    for (int i = 0; i < count; i++) {

        printf("\nProjectile %d:\n", i + 1);
        printf("Mass: %.2f kg\n", projectiles[i].mass);
        printf("Initial Velocity: %.2f m/s\n", projectiles[i].velocity);
        printf("Launch Angle: %.2f degrees\n", projectiles[i].angle);

        printf("Trajectory (displacement at intervals):\n");

        for (int j = 0; j < sizeof(trajectories[i]) / sizeof(MotionData); j++) {
            
            printf("  Point %d: %.2f m\n", j + 1, trajectories[i][j].displacement);
        }
    }
}


void freeTrajectories(Projectile **projectiles, MotionData ***trajectories, int *count) {

    for (int i = 0; i < *count; i++) {

        free((*trajectories)[i]); 
    }
    free(*trajectories);
    free(*projectiles);

    *trajectories = NULL;
    *projectiles = NULL;
    *count = 0;
}
