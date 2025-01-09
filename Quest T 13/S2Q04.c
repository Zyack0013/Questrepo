// Problem 4: Athlete Performance Tracker
// Requirements:
// Create a structure Athlete with fields:
// char athleteID[10]
// char name[50]
// char sport[30]
// float personalBest
// float lastPerformance
// Functions to:
// Add a new athlete to the system.
// Update an athlete's last performance.
// Display all athletes in a specific sport.
// Identify and display athletes who have set a new personal best in their last performance.
// Utilize dynamic memory allocation to manage athlete data in an expandable array.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Athlete {
    char athleteID[10];
    char name[50];
    char sport[30];
    float personalBest;
    float lastPerformance;
};

void addAthlete(struct Athlete **athletes, int *size, int *capacity);
void updatePerformance(struct Athlete *athletes, int size);
void displayAthletesBySport(struct Athlete *athletes, int size, const char *sport);
void identifyNewPersonalBest(struct Athlete *athletes, int size);

int main() {

    int size = 0;
    int capacity = 2;  
    struct Athlete *athletes = (struct Athlete *)malloc(capacity * sizeof(struct Athlete));

    if (athletes == NULL) {

        printf("Allocation failed!\n");
        return 1;
    }

    int choice;

    while (1) {
        printf("\n1. Add a new athlete\n");
        printf("2. Update an athlete's last performance\n");
        printf("3. Display all athletes in a specific sport\n");
        printf("4. Identify athletes with new personal best performances\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                addAthlete(&athletes, &size, &capacity);
                break;
            case 2:
                updatePerformance(athletes, size);
                break;
            case 3: {
                char sport[30];
                printf("Enter the sport to display athletes: ");
                fgets(sport, sizeof(sport), stdin);
                sport[strcspn(sport, "\n")] = '\0';  
                displayAthletesBySport(athletes, size, sport);
                break;
            }
            case 4:
                identifyNewPersonalBest(athletes, size);
                break;
            case 5:
                free(athletes);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addAthlete(struct Athlete **athletes, int *size, int *capacity) {

    if (*size == *capacity) {

        *capacity *= 2;  
        *athletes = (struct Athlete *)realloc(*athletes, *capacity * sizeof(struct Athlete));
        if (*athletes == NULL) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter athlete ID: ");
    fgets((*athletes)[*size].athleteID, sizeof((*athletes)[*size].athleteID), stdin);
    (*athletes)[*size].athleteID[strcspn((*athletes)[*size].athleteID, "\n")] = '\0';  

    printf("Enter athlete name: ");
    fgets((*athletes)[*size].name, sizeof((*athletes)[*size].name), stdin);
    (*athletes)[*size].name[strcspn((*athletes)[*size].name, "\n")] = '\0';  

    printf("Enter sport: ");
    fgets((*athletes)[*size].sport, sizeof((*athletes)[*size].sport), stdin);
    (*athletes)[*size].sport[strcspn((*athletes)[*size].sport, "\n")] = '\0';  

    printf("Enter personal best: ");
    scanf("%f", &(*athletes)[*size].personalBest);

    printf("Enter last performance: ");
    scanf("%f", &(*athletes)[*size].lastPerformance);
    getchar();  

    (*size)++;
}

void updatePerformance(struct Athlete *athletes, int size) {

    char athleteID[10];
    printf("Enter athlete ID to update performance: ");
    fgets(athleteID, sizeof(athleteID), stdin);
    athleteID[strcspn(athleteID, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < size; i++) {

        if (strcmp(athletes[i].athleteID, athleteID) == 0) {

            printf("Enter updated last performance: ");
            scanf("%f", &athletes[i].lastPerformance);
            getchar();  
            found = 1;
            break;
        }
    }

    if (!found) {

        printf("Athlete with ID %s not found.\n", athleteID);
    }
}

void displayAthletesBySport(struct Athlete *athletes, int size, const char *sport) {

    int found = 0;
    printf("\nAthletes in sport: %s\n", sport);
    for (int i = 0; i < size; i++) {

        if (strcmp(athletes[i].sport, sport) == 0) {

            printf("ID: %s, Name: %s, Personal Best: %.2f, Last Performance: %.2f\n", athletes[i].athleteID, athletes[i].name, athletes[i].personalBest, athletes[i].lastPerformance);
            found = 1;
        }
    }

    if (!found) {

        printf("No athletes found for sport %s.\n", sport);
    }
}


void identifyNewPersonalBest(struct Athlete *athletes, int size) {

    int found = 0;
    printf("\nAthletes with new personal best performances:\n");
    for (int i = 0; i < size; i++) {

        if (athletes[i].lastPerformance < athletes[i].personalBest) {

            printf("ID: %s, Name: %s, New Personal Best: %.2f (Last Performance: %.2f)\n", athletes[i].athleteID, athletes[i].name, athletes[i].lastPerformance, athletes[i].personalBest);
            found = 1;
        }
    }

    if (!found) {

        printf("No athletes have set a new personal best.\n");
    }
}
