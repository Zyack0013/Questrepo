// Problem 4: Engine Performance Monitoring System
// Requirements:
// Define a structure EnginePerformance with members:
// char engineID[10]
// float temperature
// float rpm
// float fuelConsumptionRate
// float oilPressure
// Functions to:
// Add performance data for a specific engine.
// Display all performance data for a specific engine ID.
// Calculate the average temperature and RPM for a specific engine.
// Identify any engine with abnormal oil pressure (above or below specified thresholds).
// Use linked lists to store and manage performance data entries.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Engine{

    char engineID[10];
    float temperature;
    float rpm;
    float fuelConsumptionRate;
    float oilPressure;

};

void addEngine(struct Engine *engines,int N);
void displayEngine(struct Engine *engines,int N);
void calculateAverage(struct Engine *engines,int N);
void findByOilPressure(struct Engine *engines,int N);



int main() {

    int N;
    printf("Enter the number of records :");
    scanf("%d",&N);
    getchar();

    struct Engine *engines = (struct Engine *)malloc(N * sizeof(struct Engine));

    if (engines==NULL) {

        printf("Allocation failed!\n");
        return 1;

    }


    int choice;

    while (1) {

        printf("\n        Welcome           \n");
        printf("1. Add performance data for a specific engine\n");
        printf("2. Display all performance data for a specific engine\n");
        printf("3. Calculate the average temperature and RPM for a specific engine.\n");
        printf("4. Identify any engine with abnormal oil pressure.\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
            addEngine(engines,N);
            break;

            case 2:    
            displayEngine(engines,N);
            break;

            case 3:
            calculateAverage(engines,N);
            break;

            case 4:
            findByOilPressure(engines,N);
            break;

            case 5:
            printf("Exiting...\n");
            free(engines);
            return 0;

            default:
            printf("Invalid choice!\n");
        }
    }



    return 0;
}


void addEngine(struct Engine *engines,int N){

    for(int i = 0;i < N;i++) {

        printf("Enter the details of Engine %d\n",i+1);

        printf("Enter Engine ID : ");
        fgets(engines[i].engineID,sizeof(engines[i].engineID),stdin);
        engines[i].engineID[strcspn(engines[i].engineID,"\n")] = '\0';

        printf("Enter the temperature : ");
        scanf("%f",&engines[i].temperature);
        getchar();

        printf("Enter the RPM : ");
        scanf("%f",&engines[i].rpm);

        printf("Enter the fuel consumption rate : ");
        scanf("%f",&engines[i].fuelConsumptionRate);

        printf("Enter the oil pressure : ");
        scanf("%f",&engines[i].oilPressure);

    }
}

void displayEngine(struct Engine *engines,int N){

    char engineId[15];
    printf("Enter the engine ID : ");
    fgets(engineId,sizeof(engineId),stdin);
    engineId[strcspn(engineId,"\n")] = '\0';

    printf("Enter the Engine ID : %s\n",engineId);

    int found = 0;

    for (int i = 0; i < N; i++) {

        if (strcasecmp(engines[i].engineID,engineId) == 0) {

            printf("Engine ID : %s\nTemperature : %.2f\nRPM : %.2f\nFuel consumption rate : %.2f\nOil pressure: %.2f\n", engines[i].engineID, engines[i].temperature, engines[i].rpm,engines[i].fuelConsumptionRate, engines[i].oilPressure);

            found = 1;
        }
    }

    if (!found){

        printf("No engines found.\n");

    }
}



void calculateAverage(struct Engine *engines,int N){

    float totalTemperature = 0, totalRPM = 0;
    int engineCount = 0;
    char engineId[15];
    printf("Enter the engine ID : ");
    fgets(engineId,sizeof(engineId),stdin);
    engineId[strcspn(engineId,"\n")] = '\0';

    for (int i = 0; i < N; i++) {

        if (strcmp(engines[i].engineID,engineId) == 0) {

            totalTemperature += engines[i].temperature;
            totalRPM += engines[i].rpm;
            engineCount++;
        }
    }

    if (engineCount > 0) {

        printf("\nAverage Temperature for Engine ID %s: %.2f\n", engineId, totalTemperature/engineCount);

        printf("Average RPM for Engine ID %s: %.2f\n", engineId, totalRPM/engineCount);

    } else {
        printf("No performance data found for Engine ID: %s\n", engineId);
    }
}



void findByOilPressure(struct Engine *engines,int N){

    float minPressure, maxPressure;

    printf("Enter minimum oil pressure: ");
    scanf("%f", &minPressure);

    printf("Enter maximum oil pressure: ");
    scanf("%f", &maxPressure);

    int found = 0;

    printf("\nEngines with Abnormal Oil Pressure:\n");

    for (int i = 0; i < N; i++) {
        if (engines[i].oilPressure < minPressure || engines[i].oilPressure > maxPressure) {
            printf("Engine ID: %s, Oil Pressure: %.2f\n", engines[i].engineID,engines[i].oilPressure);
            found = 1;
        }
    }

    if (!found) {
        printf("No engines found.\n");
    }

}