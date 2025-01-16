// Problem 6: Event Registration System
// Description: Use a linked list to manage athlete registrations for sports events.Operations:
// Create a registration list.
// Insert a new registration.
// Delete a canceled registration.
// Display all current registrations.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AthleteRegistration {
    
    int athleteID;
    char athleteName[50];
    char eventName[50];
    char registrationDate[20];
    struct AthleteRegistration *next;
} AthleteRegistration;

AthleteRegistration *registrationList = NULL;  
static int totalRegistrations = 0;

void createRegistrationList(int count);
void insertNewRegistration();
void deleteRegistration(int athleteID);
void displayRegistrations();

int main() {

    int choice, count, athleteID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a registration list.\n");
        printf("2. Insert a new registration.\n");
        printf("3. Delete a canceled registration.\n");
        printf("4. Display all current registrations.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of athlete registrations to add: ");
            scanf("%d", &count);
            getchar();
            createRegistrationList(count);
            printf("\nTotal athlete registrations: %d\n", totalRegistrations);
            break;

            case 2:
            insertNewRegistration();
            printf("\nTotal athlete registrations: %d\n", totalRegistrations);
            break;

            case 3:
            displayRegistrations();
            printf("Enter the athlete ID to delete: ");
            scanf("%d", &athleteID);
            deleteRegistration(athleteID);
            printf("\nTotal athlete registrations: %d\n", totalRegistrations);
            break;

            case 4:
            displayRegistrations();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}

void createRegistrationList(int count) {

    if (count <= 0) {
        printf("Invalid number of registrations.\n");
        return;
    }

    AthleteRegistration *temp, *last = registrationList;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (AthleteRegistration *)malloc(sizeof(AthleteRegistration));

        if (temp == NULL) {

            printf("Memory allocation failed for registration %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Athlete Registration %d:\n", i + 1);
        printf("Enter the Athlete ID: ");
        scanf("%d", &temp->athleteID);
        getchar();

        printf("Enter Athlete Name: ");
        fgets(temp->athleteName, sizeof(temp->athleteName), stdin);
        temp->athleteName[strcspn(temp->athleteName, "\n")] = '\0';

        printf("Enter Event Name: ");
        fgets(temp->eventName, sizeof(temp->eventName), stdin);
        temp->eventName[strcspn(temp->eventName, "\n")] = '\0';

        printf("Enter Registration Date (dd/mm/yyyy): ");
        fgets(temp->registrationDate, sizeof(temp->registrationDate), stdin);
        temp->registrationDate[strcspn(temp->registrationDate, "\n")] = '\0';

        temp->next = NULL;

        if (registrationList == NULL) {

            registrationList = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalRegistrations++;
    }

    printf("%d athlete registrations added successfully.\n", count);
}

void insertNewRegistration() {

    AthleteRegistration *temp, *last = registrationList;

    temp = (AthleteRegistration *)malloc(sizeof(AthleteRegistration));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Athlete ID: ");
    scanf("%d", &temp->athleteID);
    getchar();

    AthleteRegistration *check = registrationList;

    while (check != NULL) {

        if (check->athleteID == temp->athleteID) {

            printf("Error: Athlete ID %d already registered.\n", temp->athleteID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter Athlete Name: ");
    fgets(temp->athleteName, sizeof(temp->athleteName), stdin);
    temp->athleteName[strcspn(temp->athleteName, "\n")] = '\0';

    printf("Enter Event Name: ");
    fgets(temp->eventName, sizeof(temp->eventName), stdin);
    temp->eventName[strcspn(temp->eventName, "\n")] = '\0';

    printf("Enter Registration Date (dd/mm/yyyy): ");
    fgets(temp->registrationDate, sizeof(temp->registrationDate), stdin);
    temp->registrationDate[strcspn(temp->registrationDate, "\n")] = '\0';

    temp->next = NULL;

    if (registrationList == NULL) {

        registrationList = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalRegistrations++;
    printf("Athlete ID %d registered successfully.\n", temp->athleteID);
}

void deleteRegistration(int athleteID) {

    if (registrationList == NULL) {

        printf("No registrations available.\n");
        return;
    }

    AthleteRegistration *temp = registrationList, *prev = NULL;

    if (temp != NULL && temp->athleteID == athleteID) {
        registrationList = temp->next;
        free(temp);
        printf("Athlete ID %d registration canceled successfully.\n", athleteID);
        totalRegistrations--;
        return;
    }

    while (temp != NULL && temp->athleteID != athleteID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Athlete ID %d not found.\n", athleteID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Athlete ID %d registration canceled successfully.\n", athleteID);
    totalRegistrations--;
}

void displayRegistrations() {

    if (registrationList == NULL) {

        printf("No registrations available.\n");
        return;
    }

    AthleteRegistration *temp = registrationList;
    int i = 1;
    printf("\n\t\tAthlete Registration List\t\t\n");
    printf("SLNO.\tAthlete ID\tAthlete Name\t\tEvent Name\t\tRegistration Date\n");
    printf("----------------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%-20s\t%-15s\n", i++, temp->athleteID, temp->athleteName, temp->eventName, temp->registrationDate);
        temp = temp->next;
    }

    printf("----------------------------------------------------------------------\n");
}
