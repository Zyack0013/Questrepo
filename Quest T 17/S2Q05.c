// Problem 5: Player Performance Tracking
// Description: Implement a linked list to track player performance over the season.Operations:
// Create a performance record list.
// Insert a new performance entry.
// Delete an outdated or erroneous entry.
// Display all performance records.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PlayerPerformance {
    
    int playerID;
    char playerName[50];
    int matchesPlayed;
    int goalsScored;
    int assists;
    struct PlayerPerformance *next;
} PlayerPerformance;

PlayerPerformance *performanceList = NULL; 
static int totalRecords = 0;

void createPerformanceRecord(int count);
void insertNewPerformanceEntry();
void deletePerformanceEntry(int playerID);
void displayPerformanceRecords();

int main() {

    int choice, count, playerID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a performance record list.\n");
        printf("2. Insert a new performance entry.\n");
        printf("3. Delete an outdated or erroneous entry.\n");
        printf("4. Display all performance records.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of player performance records to add: ");
            scanf("%d", &count);
            getchar();
            createPerformanceRecord(count);
            printf("\nTotal performance records: %d\n", totalRecords);
            break;

            case 2:
            insertNewPerformanceEntry();
            printf("\nTotal performance records: %d\n", totalRecords);
            break;

            case 3:
            displayPerformanceRecords();
            printf("Enter the player ID to delete: ");
            scanf("%d", &playerID);
            deletePerformanceEntry(playerID);
            printf("\nTotal performance records: %d\n", totalRecords);
            break;

            case 4:
            displayPerformanceRecords();
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

void createPerformanceRecord(int count) {

    if (count <= 0) {

        printf("Invalid number of records.\n");
        return;
    }

    PlayerPerformance *temp, *last = performanceList;

    while (last != NULL && last->next != NULL) {

        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (PlayerPerformance *)malloc(sizeof(PlayerPerformance));

        if (temp == NULL) {

            printf("Memory allocation failed for record %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Player Performance %d:\n", i + 1);
        printf("Enter the Player ID: ");
        scanf("%d", &temp->playerID);
        getchar();

        printf("Enter Player Name: ");
        fgets(temp->playerName, sizeof(temp->playerName), stdin);
        temp->playerName[strcspn(temp->playerName, "\n")] = '\0';

        printf("Enter Matches Played: ");
        scanf("%d", &temp->matchesPlayed);
        getchar();

        printf("Enter Goals Scored: ");
        scanf("%d", &temp->goalsScored);
        getchar();

        printf("Enter Assists: ");
        scanf("%d", &temp->assists);
        getchar();

        temp->next = NULL;

        if (performanceList == NULL) {

            performanceList = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalRecords++;
    }

    printf("%d player performance records added successfully.\n", count);
}

void insertNewPerformanceEntry() {

    PlayerPerformance *temp, *last = performanceList;

    temp = (PlayerPerformance *)malloc(sizeof(PlayerPerformance));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Player ID: ");
    scanf("%d", &temp->playerID);
    getchar();

    PlayerPerformance *check = performanceList;

    while (check != NULL) {

        if (check->playerID == temp->playerID) {

            printf("Error: Player ID %d already exists.\n", temp->playerID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter Player Name: ");
    fgets(temp->playerName, sizeof(temp->playerName), stdin);
    temp->playerName[strcspn(temp->playerName, "\n")] = '\0';

    printf("Enter Matches Played: ");
    scanf("%d", &temp->matchesPlayed);
    getchar();

    printf("Enter Goals Scored: ");
    scanf("%d", &temp->goalsScored);
    getchar();

    printf("Enter Assists: ");
    scanf("%d", &temp->assists);
    getchar();

    temp->next = NULL;

    if (performanceList == NULL) {

        performanceList = temp;

    } else {
        while (last->next != NULL) {

            last = last->next;

        }
        last->next = temp;
    }

    totalRecords++;
    printf("Player ID %d performance record added successfully.\n", temp->playerID);
}

void deletePerformanceEntry(int playerID) {

    if (performanceList == NULL) {

        printf("No performance records available.\n");
        return;
    }

    PlayerPerformance *temp = performanceList, *prev = NULL;

    if (temp != NULL && temp->playerID == playerID) {
        performanceList = temp->next;
        free(temp);
        printf("Player ID %d performance record deleted successfully.\n", playerID);
        totalRecords--;
        return;
    }

    while (temp != NULL && temp->playerID != playerID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Player ID %d not found.\n", playerID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Player ID %d performance record deleted successfully.\n", playerID);
    totalRecords--;
}

void displayPerformanceRecords() {

    if (performanceList == NULL) {

        printf("No performance records available.\n");
        return;
    }

    PlayerPerformance *temp = performanceList;
    int i = 1;
    printf("\n\t\tPlayer Performance Records\t\t\n");
    printf("SLNO.\tPlayer ID\tPlayer Name\t\tMatches Played\tGoals Scored\tAssists\n");
    printf("----------------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%d\t\t%d\t\t%d\n", i++, temp->playerID, temp->playerName, temp->matchesPlayed, temp->goalsScored, temp->assists);
        temp = temp->next;
    }

    printf("----------------------------------------------------------------------\n");
}
