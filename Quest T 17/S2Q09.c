// Problem 9: Player Injury Tracker
// Description: Use a linked list to track injuries of players.Operations:
// Create an injury tracker list.
// Insert a new injury report.
// Delete a resolved or erroneous injury report.
// Display all current injury reports.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct InjuryReport {

    int reportID;
    char playerName[50];
    char injuryType[100];
    char injuryDate[20];
    int recoveryDays;
    struct InjuryReport *next;

} InjuryReport;

InjuryReport *injuryReports = NULL;  
static int totalReports = 0;

void createInjuryTrackerList(int count);
void insertInjuryReport();
void deleteInjuryReport(int reportID);
void displayInjuryReports();

int main() {

    int choice, count, reportID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create an injury tracker list.\n");
        printf("2. Insert a new injury report.\n");
        printf("3. Delete a resolved or erroneous injury report.\n");
        printf("4. Display all current injury reports.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of injury reports to add: ");
            scanf("%d", &count);
            getchar();
            createInjuryTrackerList(count);
            printf("\nTotal injury reports: %d\n", totalReports);
            break;

            case 2:
            insertInjuryReport();
            printf("\nTotal injury reports: %d\n", totalReports);
            break;

            case 3:
            displayInjuryReports();
            printf("Enter the report ID to delete: ");
            scanf("%d", &reportID);
            deleteInjuryReport(reportID);
            printf("\nTotal injury reports: %d\n", totalReports);
            break;

            case 4:
            displayInjuryReports();
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

void createInjuryTrackerList(int count) {

    if (count <= 0) {

        printf("Invalid number of injury reports.\n");
        return;
    }

    InjuryReport *temp, *last = injuryReports;

    while (last != NULL && last->next != NULL) {

        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (InjuryReport *)malloc(sizeof(InjuryReport));

        if (temp == NULL) {

            printf("Memory allocation failed for injury report %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Injury Report %d:\n", i + 1);
        printf("Enter Report ID: ");
        scanf("%d", &temp->reportID);
        getchar();

        printf("Enter Player Name: ");
        fgets(temp->playerName, sizeof(temp->playerName), stdin);
        temp->playerName[strcspn(temp->playerName, "\n")] = '\0';

        printf("Enter Injury Type: ");
        fgets(temp->injuryType, sizeof(temp->injuryType), stdin);
        temp->injuryType[strcspn(temp->injuryType, "\n")] = '\0';

        printf("Enter Injury Date (DD/MM/YYYY): ");
        scanf("%s", temp->injuryDate);

        printf("Enter Recovery Days: ");
        scanf("%d", &temp->recoveryDays);

        temp->next = NULL;

        if (injuryReports == NULL) {

            injuryReports = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalReports++;
    }

    printf("%d injury reports added.\n", count);
}

void insertInjuryReport() {

    InjuryReport *temp, *last = injuryReports;

    temp = (InjuryReport *)malloc(sizeof(InjuryReport));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Report ID: ");
    scanf("%d", &temp->reportID);
    getchar();

    InjuryReport *check = injuryReports;

    while (check != NULL) {

        if (check->reportID == temp->reportID) {

            printf("Error: Report ID %d already exists.\n", temp->reportID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter Player Name: ");
    fgets(temp->playerName, sizeof(temp->playerName), stdin);
    temp->playerName[strcspn(temp->playerName, "\n")] = '\0';

    printf("Enter Injury Type: ");
    fgets(temp->injuryType, sizeof(temp->injuryType), stdin);
    temp->injuryType[strcspn(temp->injuryType, "\n")] = '\0';

    printf("Enter Injury Date (DD/MM/YYYY): ");
    scanf("%s", temp->injuryDate);

    printf("Enter Recovery Days: ");
    scanf("%d", &temp->recoveryDays);

    temp->next = NULL;

    if (injuryReports == NULL) {

        injuryReports = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalReports++;
    printf("Injury report with ID %d added.\n", temp->reportID);
}

void deleteInjuryReport(int reportID) {

    if (injuryReports == NULL) {

        printf("No injury reports available.\n");
        return;
    }

    InjuryReport *temp = injuryReports, *prev = NULL;

    if (temp != NULL && temp->reportID == reportID) {

        injuryReports = temp->next;
        free(temp);
        printf("Injury report with ID %d deleted.\n", reportID);
        totalReports--;
        return;
    }

    while (temp != NULL && temp->reportID != reportID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Injury report with ID %d not found.\n", reportID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Injury report with ID %d deleted.\n", reportID);
    totalReports--;

}

void displayInjuryReports() {

    if (injuryReports == NULL) {

        printf("No injury reports available.\n");
        return;
    }

    InjuryReport *temp = injuryReports;
    int i = 1;
    printf("\n\t\tCurrent Injury Reports\t\t\n");
    printf("SLNO.\tReport ID\tPlayer Name\t\tInjury Type\t\tRecovery Days\tDate\n");
    printf("-------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s%-20s%-10d%s\n", i++, temp->reportID, temp->playerName, temp->injuryType, temp->recoveryDays, temp->injuryDate);
        temp = temp->next;
    }

    printf("-------------------------------------------------------------\n");
}
