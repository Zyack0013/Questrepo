// Problem 3: Autonomous Vehicle Sensor Data Logger
// Requirements:
// Create a structure SensorData with fields:
// int sensorID
// char timestamp[20] (format: YYYY-MM-DD HH:MM:SS)
// float speed
// float latitude
// float longitude
// Functions to:
// Log new sensor data.
// Display sensor data for a specific time range.
// Find the maximum speed recorded.
// Calculate the average speed over a specific time period.
// Store sensor data in a dynamically allocated array and resize it as needed.



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SensorData {
    int sensorID;
    char timestamp[20];  // Format: YYYY-MM-DD HH:MM:SS
    float speed;
    float latitude;
    float longitude;
};

void logSensorData(struct SensorData *data, int N);
void displaySensorDataInRange(struct SensorData *data, int N);
void findMaxSpeed(struct SensorData *data, int N);
void calculateAverageSpeed(struct SensorData *data, int N);


int main() {

    int N;
    printf("Enter the number of records :");
    scanf("%d",&N);
    getchar();

    struct SensorData *data = (struct SensorData *)malloc(N * sizeof(struct SensorData));

    int choice;

    while (1) {
        printf("\n        Welcome to the Sensor Data Logger        \n");
        printf("1. Log new sensor data\n");
        printf("2. Display sensor data for a specific time range\n");
        printf("3. Find the maximum speed recorded\n");
        printf("4. Calculate the average speed over a specific time period\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                logSensorData(data,&N);
                break;
            case 2:
                displaySensorDataInRange(data, N);
                break;
            case 3:
                findMaxSpeed(data, N);
                break;
            case 4:
                calculateAverageSpeed(data, N);
                break;
            case 5:
                printf("Exiting...\n");
                free(data);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


void logSensorData(struct SensorData *data, int N) {

    for(int i = 0;i < N;i++) {

        printf("Enter sensor ID: ");
        scanf("%d",data[i].sensorID);
        getchar();

        printf("Enter timestamp (YYYY-MM-DD HH:MM:SS): ");
        fgets(data[i].timestamp, sizeof(data[i].timestamp), stdin);
        data[i].timestamp[strcspn(data[i].timestamp, "\n")] = '\0';

        printf("Enter speed: ");
        scanf("%f",data[i].speed);

        printf("Enter latitude: ");
        scanf("%f", data[i].latitude);

        printf("Enter longitude: ");
        scanf("%f",data[i].longitude);

    }

}



void displaySensorDataInRange(struct SensorData *data, int N) {

    char startTime[20], endTime[20];
    int found = 0;

    printf("Enter start timestamp (YYYY-MM-DD HH:MM:SS): ");
    fgets(startTime, sizeof(startTime), stdin);
    startTime[strcspn(startTime, "\n")] = '\0';

    printf("Enter end timestamp (YYYY-MM-DD HH:MM:SS): ");
    fgets(endTime, sizeof(endTime), stdin);
    endTime[strcspn(endTime, "\n")] = '\0';

    printf("\nSensor data in the time range %s to %s:\n", startTime, endTime);

    for (int i = 0; i < N; i++) {

        if (strcmp(data[i].timestamp, startTime) >= 0 && strcmp(data[i].timestamp, endTime) <= 0) {
            printf("Sensor ID: %d, Timestamp: %s, Speed: %.2f, Latitude: %.2f, Longitude: %.2f\n",data[i].sensorID, data[i].timestamp, data[i].speed, data[i].latitude, data[i].longitude);
            found = 1;
        }
    }

    if (!found) {
        printf("No data found in the specified range.\n");
    }
}

void findMaxSpeed(struct SensorData *data, int N) {
    if (N == 0) {
        printf("No data available.\n");
        return;
    }

    float maxSpeed = data[0].speed;

    for (int i = 1; i < N; i++) {
        if (data[i].speed > maxSpeed) {
            maxSpeed = data[i].speed;
        }
    }

    printf("The maximum speed recorded is: %.2f\n", maxSpeed);
}


void calculateAverageSpeed(struct SensorData *data, int N) {

    if (N == 0) {
        printf("No data available.\n");
        return;
    }

    float totalSpeed = 0.0;

    for (int i = 0; i < N; i++) {
        totalSpeed += data[i].speed;
    }

    printf("The average speed is: %.2f\n", totalSpeed / N);
}
