// Problem 2: Car Rental Reservation System
// Requirements:
// Define a structure CarRental with members:
// char carID[10]
// char customerName[50]
// char rentalDate[11] (format: YYYY-MM-DD)
// char returnDate[11]
// float rentalPricePerDay
// Write functions to:
// Book a car for a customer by inputting necessary details.
// Calculate the total rental price based on the number of rental days.
// Display all current rentals.
// Search for rentals by customer name.
// Implement error handling for invalid dates and calculate the number of rental days.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Car {
    char carID[10];
    char customerName[50];
    char rentalDate[11];
    char returnDate[11];
    float rentalPricePerDay;
};

void bookCar(struct Car *cars, int N);
void calculateRent(struct Car *cars, int N);
void displayRentals(struct Car *cars, int N);
void findByName(struct Car *cars, int N);
int calculateRentalDays(const char *startDate, const char *endDate);

int main() {
    int N;
    printf("Enter the number of records: ");
    scanf("%d", &N);
    getchar();

    struct Car *cars = (struct Car *)malloc(N * sizeof(struct Car));

    if (cars == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }

    int choice;

    while (1) {
        printf("\n        Welcome           \n");
        printf("1. Book a car\n");
        printf("2. Calculate the total rental price\n");
        printf("3. Display all current rentals\n");
        printf("4. Search for rentals by customer name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                bookCar(cars, N);
                break;
            case 2:
                calculateRent(cars, N);
                break;
            case 3:
                displayRentals(cars, N);
                break;
            case 4:
                findByName(cars, N);
                break;
            case 5:
                printf("Exiting...\n");
                free(cars);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void bookCar(struct Car *cars, int N) {

    for (int i = 0; i < N; i++) {

        printf("Enter the details of Record %d\n", i + 1);

        printf("Enter Car ID: ");
        fgets(cars[i].carID, sizeof(cars[i].carID), stdin);
        cars[i].carID[strcspn(cars[i].carID, "\n")] = '\0';

        printf("Enter customer name: ");
        fgets(cars[i].customerName, sizeof(cars[i].customerName), stdin);
        cars[i].customerName[strcspn(cars[i].customerName, "\n")] = '\0';

        printf("Enter rental date (YYYY-MM-DD): ");
        fgets(cars[i].rentalDate, sizeof(cars[i].rentalDate), stdin);
        cars[i].rentalDate[strcspn(cars[i].rentalDate, "\n")] = '\0';

        printf("Enter return date (YYYY-MM-DD): ");
        fgets(cars[i].returnDate, sizeof(cars[i].returnDate), stdin);
        cars[i].returnDate[strcspn(cars[i].returnDate, "\n")] = '\0';

        printf("Enter the rental price per day: ");
        scanf("%f", &cars[i].rentalPricePerDay);
        getchar();
    }
}

int calculateRentalDays(const char *startDate, const char *endDate) {

    int startYear,startMonth,startDay;
    int endYear,endMonth,endDay;

    sscanf(startDate,"%d-%d-%d",&startYear,&startMonth,&startDay);

    sscanf(endDate,"%d-%d-%d",&endYear,&endMonth,&endDay);

    int startDays = startYear*365 + startMonth*30 + startDay;

    int endDays = endYear*365 + endMonth*30 + endDay;

    return endDays - startDays;
    
}

void calculateRent(struct Car *cars, int N) {

    char carId[10];
    printf("Enter the car ID: ");
    fgets(carId, sizeof(carId), stdin);
    carId[strcspn(carId, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(cars[i].carID, carId) == 0) {

            int days = calculateRentalDays(cars[i].rentalDate, cars[i].returnDate);

            if (days == -1) {
                printf("Invalid dates for Car ID %s.\n", carId);
                return;
            }

            float totalPrice = days * cars[i].rentalPricePerDay;
            printf("Total rental price for Car ID %s: %.2f (for %d days)\n", carId, totalPrice, days);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Car ID not found.\n");
    }
}

void displayRentals(struct Car *cars, int N) {
    
    if (N == 0) {
        printf("No rentals to display.\n");
        return;
    }

    printf("\nCurrent Rentals:\n");
    for (int i = 0; i < N; i++) {
        printf("Car ID: %s\n", cars[i].carID);
        printf("Customer Name: %s\n", cars[i].customerName);
        printf("Rental Date: %s, Return Date: %s\n", cars[i].rentalDate, cars[i].returnDate);
        printf("Rental Price per Day: %.2f\n", cars[i].rentalPricePerDay);
        printf("----------------------------\n");
    }
}

void findByName(struct Car *cars, int N) {

    char customerName[50];

    printf("Enter customer name to search: ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < N; i++) {

        if (strstr(cars[i].customerName, customerName)) {

            printf("Car ID: %s\n", cars[i].carID);
            printf("Customer Name: %s\n", cars[i].customerName);
            printf("Rental Date: %s, Return Date: %s\n", cars[i].rentalDate, cars[i].returnDate);
            printf("Rental Price per Day: %.2f\n", cars[i].rentalPricePerDay);
            printf("----------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No rentals found for customer name: %s.\n", customerName);
    }
}
