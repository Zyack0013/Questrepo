// 1. Particle Motion Simulator
// Description:
//  Simulate the motion of particles in a two-dimensional space under the influence of forces.
// Specifications:
// Structure: Represents particle properties (mass, position, velocity).
// Array: Stores the position and velocity vectors of multiple particles.
// Union: Handles force types (gravitational, electric, or magnetic).
// Strings: Define force types applied to particles.
// const Pointers: Protect particle properties.
// Double Pointers: Dynamically allocate memory for the particle system.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIMENSION 2 
#define TIME_STEP 0.1 


typedef union {

    float gravitationalForce; 
    float electricForce;      
    float magneticForce;      

} ForceType;


typedef struct {

    const char *id;
    float mass;              
    float position[DIMENSION]; 
    float velocity[DIMENSION]; 
    ForceType force;         
    char forceType[20];   

} Particle;

void addParticle(Particle **particles, int *particleCount);
void simulateMotion(Particle *particles, int particleCount, float duration);
void displayParticles(Particle *particles, int particleCount);
void freeParticles(Particle **particles, int particleCount);

int main() {

    Particle *particles = NULL; 
    int particleCount = 0;
    int choice;
    float duration;

    while (1) {

        printf("\nParticle Motion Simulator\n");
        printf("1. Add Particle\n");
        printf("2. Simulate Motion\n");
        printf("3. View Particles\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
                addParticle(&particles, &particleCount);
                break;
            case 2:
                printf("Enter simulation duration (in seconds): ");
                scanf("%f", &duration);
                simulateMotion(particles, particleCount, duration);
                break;
            case 3:
                displayParticles(particles, particleCount);
                break;
            case 4:
                freeParticles(&particles, particleCount);
                printf("Exiting the simulator.\n");
                return 0;
            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}

void addParticle(Particle **particles, int *particleCount) {

    *particles = realloc(*particles, (*particleCount + 1) * sizeof(Particle));

    if (*particles == NULL) {

        printf("Memory allocation failed!\n");
        return;

    }

    Particle *newParticle = &((*particles)[*particleCount]);

    char id[20];
    printf("Enter Particle ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    newParticle->id = strdup(id);

    printf("Enter Particle Mass (kg): ");
    scanf("%f", &newParticle->mass);

    printf("Enter Initial Position (x, y): ");
    scanf("%f %f", &newParticle->position[0], &newParticle->position[1]);

    printf("Enter Initial Velocity (vx, vy): ");
    scanf("%f %f", &newParticle->velocity[0], &newParticle->velocity[1]);

    getchar(); 

    printf("Enter Force Type (Gravitational, Electric, Magnetic): ");
    fgets(newParticle->forceType, sizeof(newParticle->forceType), stdin);
    newParticle->forceType[strcspn(newParticle->forceType, "\n")] = '\0';

    if (strcmp(newParticle->forceType, "Gravitational") == 0) {
 
        printf("Enter Gravitational Force (N): ");
        scanf("%f", &newParticle->force.gravitationalForce);
 
    } else 
    if (strcmp(newParticle->forceType, "Electric") == 0) {
    
        printf("Enter Electric Force (N): ");
        scanf("%f", &newParticle->force.electricForce);
    
    } else 
    if (strcmp(newParticle->forceType, "Magnetic") == 0) {
 
        printf("Enter Magnetic Force (N): ");
        scanf("%f", &newParticle->force.magneticForce);
   
    } else {
 
        printf("Unknown force type! Defaulting force to 0.\n");
 
    }

    getchar(); 
    (*particleCount)++;
    printf("Particle added successfully!\n");
}

void simulateMotion(Particle *particles, int particleCount, float duration) {

    if (particleCount == 0) {
    
        printf("No particles available for simulation.\n");
        return;
    
    }

    int steps = duration / TIME_STEP; 

    for (int step = 0; step < steps; step++) {

        for (int i = 0; i < particleCount; i++) {

            Particle *p = &particles[i];

            float forceMagnitude = 0.0;


            if (strcmp(p->forceType, "Gravitational") == 0) {
              
                forceMagnitude = p->force.gravitationalForce;
            
            } else 
            if (strcmp(p->forceType, "Electric") == 0) {
               
                forceMagnitude = p->force.electricForce;
            
            } else 
            if (strcmp(p->forceType, "Magnetic") == 0) {
               
                forceMagnitude = p->force.magneticForce;
            }

            for (int j = 0; j < DIMENSION; j++) {

                float acceleration = forceMagnitude / p->mass; 
                p->velocity[j] += acceleration * TIME_STEP;
                p->position[j] += p->velocity[j] * TIME_STEP;
            }
        }
    }

    printf("Simulation completed for %.2f seconds.\n", duration);
}


void displayParticles(Particle *particles, int particleCount) {

    if (particleCount == 0) {

        printf("No particles available.\n");
        return;
    }

    printf("\nParticle Details:\n");

    for (int i = 0; i < particleCount; i++) {

        printf("\nParticle %d:\n", i + 1);
        printf("ID: %s\n", particles[i].id);
        printf("Mass: %.2f kg\n", particles[i].mass);
        printf("Position: (%.2f, %.2f)\n", particles[i].position[0], particles[i].position[1]);
        printf("Velocity: (%.2f, %.2f)\n", particles[i].velocity[0], particles[i].velocity[1]);
        printf("Force Type: %s\n", particles[i].forceType);
    }
}


void freeParticles(Particle **particles, int particleCount) {

    if (*particles != NULL) {

        for (int i = 0; i < particleCount; i++) {

            free((void *)(*particles)[i].id); 

        }

        free(*particles);
        *particles = NULL;
    }
}
