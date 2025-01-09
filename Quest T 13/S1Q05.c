// Problem 5: Vehicle Service History Tracker
// Requirements:
// Create a structure ServiceRecord with the following:
// char serviceID[10]
// char vehicleID[15]
// char serviceDate[11]
// char description[100]
// float serviceCost
// Functions to:
// Add a new service record for a vehicle.
// Display all service records for a given vehicle ID.
// Calculate the total cost of services for a vehicle.
// Sort and display service records by service date.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ServiceRecord{

    char serviceID[10];
    char vehicleID[15];
    char serviceDate[11];
    char description[100];
    float serviceCost;

};

void addServiceRecord(struct ServiceRecord *record,int N);
void displayServiceRecord(struct ServiceRecord *record,int N);
void calculateTotalCost(struct ServiceRecord *record,int N);
void sortByDate(struct ServiceRecord *record,int N);

int main() {

    int N;
    printf("Enter the number of records :");
    scanf("%d",&N);
    getchar();

    struct ServiceRecord *records = (struct ServiceRecord *)malloc(N * sizeof(struct ServiceRecord));

    if (records==NULL) {

        printf("Allocation failed!\n");
        return 1;

    }

    int choice;

    while (1) {

        printf("\n        Welcome           \n");
        printf("1. Add Service Record\n");
        printf("2. Display Service Record\n");
        printf("3. Calculate the total cost of services for a vehicle.\n");
        printf("4. Sort and display service records by service date.\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
            addServiceRecord(records,N);
            break;
            case 2:    
            displayServiceRecord(records,N);
            break;

            case 3:
            calculateTotalCost(records,N);
            break;

            case 4:
            sortByDate(records,N);
            break;

            case 5:
            printf("Exiting...\n");
            free(records);
            return 0;

            default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addServiceRecord(struct ServiceRecord *record,int N) {

    for(int i = 0;i < N;i++) {

        printf("Enter the details of Record %d\n",i+1);

        printf("Enter service ID : ");
        fgets(record[i].serviceID,sizeof(record[i].serviceID),stdin);
        record[i].serviceID[strcspn(record[i].serviceID,"\n")] = '\0';

        printf("Enter vehicle ID : ");
        fgets(record[i].vehicleID,sizeof(record[i].vehicleID),stdin);
        record[i].vehicleID[strcspn(record[i].vehicleID,"\n")] = '\0';

        printf("Enter service date : ");
        fgets(record[i].serviceDate,sizeof(record[i].serviceDate),stdin);
        record[i].serviceDate[strcspn(record[i].serviceDate,"\n")] = '\0';
        getchar();

        printf("Enter a short description : ");
        fgets(record[i].description,sizeof(record[i].description),stdin);
        record[i].description[strcspn(record[i].description,"\n")] = '\0';

        printf("Enter the service cost : ");
        scanf("%f",&record[i].serviceCost);
        getchar();


    }

}


void displayServiceRecord(struct ServiceRecord *record,int N){

    char vehicleId[15];
    printf("Enter the vehicles ID : ");
    fgets(vehicleId,sizeof(vehicleId),stdin);
    vehicleId[strcspn(vehicleId,"\n")] = '\0';

    printf("service records of vehicle ID : %s\n",vehicleId);

    int found = 0;

    for (int i = 0; i < N; i++) {

        if (strcasecmp(record[i].vehicleID,vehicleId) == 0) {

            printf("Service ID : %s\nVehicle ID : %s\nService Date : %s\nDescription: %s\nService cost: %.2f\n", record[i].serviceID, record[i].vehicleID, record[i].serviceDate,record[i].description, record[i].serviceCost);

            found = 1;
        }
    }

    if (!found){

        printf("No vehicles found.\n");

    }


}

void calculateTotalCost(struct ServiceRecord *record,int N) {

    float totalCost = 0.0;
    char vehicleId[15];
    
    printf("Enter the vehicles ID : ");
    fgets(vehicleId,sizeof(vehicleId),stdin);
    vehicleId[strcspn(vehicleId,"\n")] = '\0';

   
    for (int i = 0; i < N; i++) {
        if (strcmp(record[i].vehicleID,vehicleId) == 0) {

            totalCost += record[i].serviceCost;

        }
    }

    printf("Total Service Cost -> Vehicle ID %s : %.2f\n",vehicleId,totalCost);

}

void sortByDate(struct ServiceRecord *record,int N){

    struct ServiceRecord temp;

    for (int i = 0; i < N - 1; i++) {

        for (int j = 0; j < N - i - 1; j++) {

            if (strcmp(record[j].serviceDate,record[j + 1].serviceDate) > 0) {
               
                temp = record[j];
                record[j] = record[j + 1];
                record[j + 1] = temp;

            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("Service ID: %s, Vehicle ID: %s, Date: %s, Description: %s, Cost: %.2f\n",record[i].serviceID, record[i].vehicleID, record[i].serviceDate,record[i].description,record[i].serviceCost);
    }
}