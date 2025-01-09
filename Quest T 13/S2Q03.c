// Problem 3: Sports Event Medal Tally
// Requirements:
// Define a structure CountryMedalTally with members:
// char country[30]
// int gold
// int silver
// int bronze
// Functions to:
// Add a new country's medal tally.
// Update the medal count for a country.
// Display the medal tally for all countries.
// Find and display the country with the highest number of gold medals.
// Use an array to store the medal tally, and resize the array dynamically as new countries are added.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct CountryMedalTally {

    char country[30];
    int gold;
    int silver;
    int bronze;
};

void addCountry(struct CountryMedalTally **countries, int *size, int *capacity);
void updateMedals(struct CountryMedalTally *countries, int size);
void displayTally(struct CountryMedalTally *countries, int size);
void findCountryWithMostGold(struct CountryMedalTally *countries, int size);

int main() {
    int size = 0;
    int capacity = 2;  
    struct CountryMedalTally *countries = (struct CountryMedalTally *)malloc(capacity * sizeof(struct CountryMedalTally));

    if (countries == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;
    while (1) {

        printf("\n1. Add a new country's medal tally\n");
        printf("2. Update medal count for a country\n");
        printf("3. Display medal tally for all countries\n");
        printf("4. Find the country with the most gold medals\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                addCountry(&countries, &size, &capacity);
                break;
            case 2:
                updateMedals(countries, size);
                break;
            case 3:
                displayTally(countries, size);
                break;
            case 4:
                findCountryWithMostGold(countries, size);
                break;
            case 5:
                free(countries);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


void addCountry(struct CountryMedalTally **countries, int *size, int *capacity) {

    if (*size == *capacity) {

        *capacity *= 2; 
        *countries = (struct CountryMedalTally *)realloc(*countries, *capacity * sizeof(struct CountryMedalTally));
        if (*countries == NULL) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter country name: ");
    fgets((*countries)[*size].country, sizeof((*countries)[*size].country), stdin);
    (*countries)[*size].country[strcspn((*countries)[*size].country, "\n")] = '\0';  

    printf("Enter gold medal count: ");
    scanf("%d", &(*countries)[*size].gold);
    printf("Enter silver medal count: ");
    scanf("%d", &(*countries)[*size].silver);
    printf("Enter bronze medal count: ");
    scanf("%d", &(*countries)[*size].bronze);
    getchar();  

    (*size)++;
}


void updateMedals(struct CountryMedalTally *countries, int size) {

    char countryName[30];
    printf("Enter the country name to update medals: ");
    fgets(countryName, sizeof(countryName), stdin);
    countryName[strcspn(countryName, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < size; i++) {

        if (strcmp(countries[i].country, countryName) == 0) {

            printf("Enter updated gold medal count: ");
            scanf("%d", &countries[i].gold);
            printf("Enter updated silver medal count: ");
            scanf("%d", &countries[i].silver);
            printf("Enter updated bronze medal count: ");
            scanf("%d", &countries[i].bronze);
            getchar();  
            found = 1;
            break;
        }
    }

    if (!found) {

        printf("Country not found!\n");
    }
}


void displayTally(struct CountryMedalTally *countries, int size) {

    if (size == 0) {
        
        printf("No data available!\n");
        return;
    }

    printf("\nCountry Medal Tally:\n");

    for (int i = 0; i < size; i++) {

        printf("Country: %s\n", countries[i].country);
        printf("Gold: %d | Silver: %d | Bronze: %d\n\n", countries[i].gold, countries[i].silver, countries[i].bronze);
    }
}


void findCountryWithMostGold(struct CountryMedalTally *countries, int size) {

    if (size == 0) {

        printf("No data available!\n");
        return;
    }

    int maxGold = countries[0].gold;
    char countryWithMaxGold[30];
    strcpy(countryWithMaxGold, countries[0].country);

    for (int i = 1; i < size; i++) {

        if (countries[i].gold > maxGold) {

            maxGold = countries[i].gold;
            strcpy(countryWithMaxGold, countries[i].country);
        }
    }

    printf("Country with the most gold medals: %s (%d gold medals)\n", countryWithMaxGold, maxGold);
}
