// Problem 1: Vehicle vehicle Management System
// Requirements:
// Create a structure Vehicle with the following members:
// char registrationNumber[15]
// char model[30]
// int yearOfManufacture
// float mileage
// float fuelEfficiency
// Implement functions to:
// Add a new vehicle to the vehicle.
// Update the mileage and fuel efficiency for a vehicle.
// Display all vehicles manufactured after a certain year.
// Find the vehicle with the highest fuel efficiency.
// Use dynamic memory allocation to manage the vehicle of vehicles.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Vehicle {

    char registrationNumber[15];
    char model[30];
    int yearOfManufacture;
    float mileage;
    float fuelEfficiency;

};

void addVehicle(struct Vehicle *vehicle,int N);
void updateVehicle(struct Vehicle *vehicle,int N);
void displayVehicle(struct Vehicle *vehicle,int N,int year);
void findVehicel(struct Vehicle *vehicle,int N);


int main() {
    
    int N;
    printf("Enter the number of Vehicle : ");
    scanf("%d",&N);

    struct Vehicle *vehicles = (struct Vehicle *)malloc(N * sizeof(struct Vehicle));
    

    if (vehicles==NULL) {

        printf("Allocation failed!\n");
        return 1;

    }

    int choice,year;

    while (1) {

        printf("\n        welcome           \n");
        printf("1. Add Vehicle\n");
        printf("2. Update Mileage and Fuel Efficiency\n");
        printf("3. Display Vehicles Manufactured After Year\n");
        printf("4. Find Vehicle with Highest Fuel Efficiency\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
            addVehicle(vehicles,N);
            break;
            case 2:    
            updateVehicle(vehicles,N);
            break;

            case 3:
            printf("Enter the year: ");
            scanf("%d",&year);
            displayVehicle(vehicles,N,year);
            break;

            case 4:
            findVehicel(vehicles,N);
            break;

            case 5:
            printf("Exiting...\n");
            free(vehicles);
            return 0;

            default:
            printf("Invalid choice!\n");
        }
    }


    return 0;
}

void addVehicle(struct Vehicle *vehicle,int N){

    for(int i = 0;i < N;i++) {

        printf("Enter the details of Vechile %d\n",i+1);

        printf("Enter registration number : ");
        fgets(vehicle[i].registrationNumber,sizeof(vehicle[i].registrationNumber),stdin);
        vehicle[i].registrationNumber[strcspn(vehicle[i].registrationNumber,"\n")] = '\0';

        printf("Enter model name : ");
        fgets(vehicle[i].model,sizeof(vehicle[i].model),stdin);
        vehicle[i].model[strcspn(vehicle[i].model,"\n")] = '\0';

        printf("Enter year Of Manufacture : ");
        scanf("%d",&vehicle[i].yearOfManufacture);

        printf("Enter the mileage : ");
        scanf("%f",&vehicle[i].mileage);

        printf("Enter the fuel Efficiency : ");
        scanf("%f",&vehicle[i].fuelEfficiency);

    }
}


void updateVehicle(struct Vehicle *vehicle,int N){

    char registrationNumber[15];
    printf("Enter the Registration Number of the vehicle to update: ");
    scanf("%s", registrationNumber);

    for (int i = 0; i < N; i++) {

        if (strcmp(vehicle[i].registrationNumber, registrationNumber) == 0) {

            printf("Enter new Mileage : ");
            scanf("%f",&vehicle[i].mileage);

            printf("Enter new Fuel Efficiency : ");
            scanf("%f",&vehicle[i].fuelEfficiency);

            printf("Vehicle updated successfully!\n");
            return;
        }
    }

    printf("Vehicle Not Found!!!\n");

}

void displayVehicle(struct Vehicle *vehicle,int N,int year){

    printf("Vehicles manufactured after %d:\n",year);

    int found = 0;

    for (int i = 0; i < N; i++) {

        if (vehicle[i].yearOfManufacture > year) {
            printf("Registration Number: %s, Model: %s, Year: %d, Mileage: %.2f, Fuel Efficiency: %.2f\n",
                   vehicle[i].registrationNumber, vehicle[i].model, vehicle[i].yearOfManufacture,
                   vehicle[i].mileage, vehicle[i].fuelEfficiency);
            found = 1;
        }
    }

    if (!found){
        printf("No vehicles found.\n");
    }
}


void findVehicel(struct Vehicle *vehicle,int N){


    if (N == 0) {

        printf("No vehicles!\n");
        return;
    }

    int maxIndex = 0;

    for (int i = 1; i < N; i++) {
        if (vehicle[i].fuelEfficiency > vehicle[maxIndex].fuelEfficiency) {
            maxIndex = i;
        }
    }

    printf("Vehicle\n");

    printf("Registration Number: %s, Model: %s, Year: %d, Mileage: %.2f, Fuel Efficiency: %.2f\n",
           vehicle[maxIndex].registrationNumber, vehicle[maxIndex].model, vehicle[maxIndex].yearOfManufacture,
           vehicle[maxIndex].mileage, vehicle[maxIndex].fuelEfficiency);
}