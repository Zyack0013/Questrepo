// Problem 2: Experimental Data Logger
// Requirements:
// Create a structure Experiment with members:
// char experimentID[10]
// char researcher[50]
// char startDate[11] (format: YYYY-MM-DD)
// char endDate[11]
// float results[10] (store up to 10 result readings)
// Functions to:
// Log a new experiment.
// Update the result readings of an experiment.
// Display all experiments conducted by a specific researcher.
// Calculate and display the average result for a specific experiment.
// Use a dynamically allocated array for storing experiments and manage resizing as more data is logged.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Experiment {
    
    char experimentID[10];
    char researcher[50];
    char startDate[11];
    char endDate[11];
    float results[10];  
};

void logExperiment(struct Experiment **experiments, int *size, int *capacity);
void updateExperimentResults(struct Experiment *experiments, int size);
void displayExperimentsByResearcher(struct Experiment *experiments, int size, const char *researcher);
void calculateAverageResult(struct Experiment *experiments, int size);
void displayAllExperiments(struct Experiment *experiments, int size);

int main() {
    int size = 0;
    int capacity = 2;  
    struct Experiment *experiments = (struct Experiment *)malloc(capacity * sizeof(struct Experiment));

    if (experiments == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;

    while (1) {

        printf("\n1. Log a new experiment\n");
        printf("2. Update the result readings of an experiment\n");
        printf("3. Display all experiments by a specific researcher\n");
        printf("4. Calculate and display the average result of a specific experiment\n");
        printf("5. Display all experiments\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                logExperiment(&experiments, &size, &capacity);
                break;
            case 2:
                updateExperimentResults(experiments, size);
                break;
            case 3: {
                char researcher[50];
                printf("Enter researcher name: ");
                fgets(researcher, sizeof(researcher), stdin);
                researcher[strcspn(researcher, "\n")] = '\0'; 
                displayExperimentsByResearcher(experiments, size, researcher);
                break;
            }
            case 4:
                calculateAverageResult(experiments, size);
                break;
            case 5:
                displayAllExperiments(experiments, size);
                break;
            case 6:
                free(experiments);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void logExperiment(struct Experiment **experiments, int *size, int *capacity) {

    if (*size == *capacity) {

        *capacity *= 2;  
        *experiments = (struct Experiment *)realloc(*experiments, *capacity * sizeof(struct Experiment));

        if (*experiments == NULL) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter experiment ID: ");
    fgets((*experiments)[*size].experimentID, sizeof((*experiments)[*size].experimentID), stdin);
    (*experiments)[*size].experimentID[strcspn((*experiments)[*size].experimentID, "\n")] = '\0';  

    printf("Enter researcher's name: ");
    fgets((*experiments)[*size].researcher, sizeof((*experiments)[*size].researcher), stdin);
    (*experiments)[*size].researcher[strcspn((*experiments)[*size].researcher, "\n")] = '\0';  

    printf("Enter start date (YYYY-MM-DD): ");
    fgets((*experiments)[*size].startDate, sizeof((*experiments)[*size].startDate), stdin);
    (*experiments)[*size].startDate[strcspn((*experiments)[*size].startDate, "\n")] = '\0';  

    printf("Enter end date (YYYY-MM-DD): ");
    fgets((*experiments)[*size].endDate, sizeof((*experiments)[*size].endDate), stdin);
    (*experiments)[*size].endDate[strcspn((*experiments)[*size].endDate, "\n")] = '\0';  

    printf("Enter up to 10 result readings (enter -1 to stop):\n");

    for (int i = 0; i < 10; i++) {

        printf("Result %d: ", i + 1);
        scanf("%f", &(*experiments)[*size].results[i]);

        if ((*experiments)[*size].results[i] == -1) {

            break;
        }
    }
    getchar(); 

    (*size)++;
}


void updateExperimentResults(struct Experiment *experiments, int size) {

    char experimentID[10];
    printf("Enter experiment ID to update: ");
    fgets(experimentID, sizeof(experimentID), stdin);
    experimentID[strcspn(experimentID, "\n")] = '\0';  

    int found = 0;

    for (int i = 0; i < size; i++) {

        if (strcmp(experiments[i].experimentID, experimentID) == 0) {

            printf("Enter new result readings for experiment %s (enter -1 to stop):\n", experimentID);

            for (int j = 0; j < 10; j++) {

                printf("Result %d: ", j + 1);
                scanf("%f", &experiments[i].results[j]);

                if (experiments[i].results[j] == -1) {
                    break;
                }
            }
            getchar();  
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Experiment with ID %s not found.\n", experimentID);
    }
}

void displayExperimentsByResearcher(struct Experiment *experiments, int size, const char *researcher) {

    int found = 0;
    printf("\nExperiments conducted by researcher: %s\n", researcher);

    for (int i = 0; i < size; i++) {

        if (strcmp(experiments[i].researcher, researcher) == 0) {

            printf("Experiment ID: %s, Start Date: %s, End Date: %s\n",experiments[i].experimentID, experiments[i].startDate, experiments[i].endDate);

            for (int j = 0; j < 10; j++) {

                if (experiments[i].results[j] == -1) break;
                printf("Result %d: %.2f\n", j + 1, experiments[i].results[j]);
            }
            found = 1;
        }
    }

    if (!found) {
        printf("No experiments found for researcher %s.\n", researcher);
    }
}

void calculateAverageResult(struct Experiment *experiments, int size) {
    
    char experimentID[10];
    printf("Enter experiment ID to calculate average result: ");
    fgets(experimentID, sizeof(experimentID), stdin);
    experimentID[strcspn(experimentID, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(experiments[i].experimentID, experimentID) == 0) {

            float sum = 0;
            int count = 0;

            for (int j = 0; j < 10; j++) {

                if (experiments[i].results[j] == -1) break;
                sum += experiments[i].results[j];
                count++;
            }
            if (count > 0) {

                printf("Average result for experiment %s: %.2f\n", experimentID, sum / count);
            } else {

                printf("No results found for experiment %s.\n", experimentID);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Experiment with ID %s not found.\n", experimentID);
    }
}

void displayAllExperiments(struct Experiment *experiments, int size) {

    printf("\nAll Experiments:\n");

    for (int i = 0; i < size; i++) {

        printf("Experiment ID: %s, Researcher: %s, Start Date: %s, End Date: %s\n",experiments[i].experimentID, experiments[i].researcher, experiments[i].startDate, experiments[i].endDate);
        for (int j = 0; j < 10; j++) {

            if (experiments[i].results[j] == -1) break;
            printf("Result %d: %.2f\n", j + 1, experiments[i].results[j]);
        }
    }
}
