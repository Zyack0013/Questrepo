// Problem 15: Championship Points Tracker
// Description: Implement a linked list to track championship points for teams.Operations:
// Create a points tracker list.
// Insert a new points entry.
// Delete an incorrect or outdated points entry.
// Display all current points standings.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Team {

    int teamID;
    char teamName[50];
    int points;
    struct Team *next;
    
} Team;

Team *pointsTracker = NULL;
static int totalTeams = 0;

void createPointsTracker(int count);
void insertPointsEntry();
void deletePointsEntry(int teamID);
void displayPointsStandings();
void freePointsTracker();
int isDuplicateTeamID(int teamID);

int main() {

    int choice, count, teamID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a points tracker list.\n");
        printf("2. Insert a new points entry.\n");
        printf("3. Delete an incorrect or outdated points entry.\n");
        printf("4. Display all current points standings.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of teams to create: ");
            scanf("%d", &count);
            getchar();
            createPointsTracker(count);
            break;

            case 2:
            insertPointsEntry();
            break;

            case 3:
            printf("Enter the team ID to delete: ");
            scanf("%d", &teamID);
            getchar();
            deletePointsEntry(teamID);
            break;

            case 4:
            displayPointsStandings();
            break;

            case 5:
            freePointsTracker();
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}

void createPointsTracker(int count) {

    Team *temp, *last = pointsTracker;

    if (count <= 0) {

        printf("Invalid number of teams.\n");
        return;
    }

    while (last != NULL && last->next != NULL) {

        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Team *)malloc(sizeof(Team));

        if (temp == NULL) {

            printf("Memory allocation failed!\n");
            return;
        }

        printf("\nEnter details for Team %d\n", i + 1);
        printf("Enter Team ID: ");
        scanf("%d", &temp->teamID);
        getchar();

        if (isDuplicateTeamID(temp->teamID)) {

            printf("Team ID %d already exists. Skipping this team.\n", temp->teamID);
            free(temp);
            continue;
        }

        printf("Enter Team Name: ");
        fgets(temp->teamName, sizeof(temp->teamName), stdin);
        temp->teamName[strcspn(temp->teamName, "\n")] = '\0';

        printf("Enter Points: ");
        scanf("%d", &temp->points);
        getchar();

        temp->next = NULL;

        if (pointsTracker == NULL) {

            pointsTracker = temp;

        } else {

            last->next = temp;
        }
        last = temp;
        totalTeams++;
    }
    printf("%d teams added to the points tracker.\n", count);
}

void insertPointsEntry() {
    Team *temp, *last = pointsTracker;

    temp = (Team *)malloc(sizeof(Team));

    if (temp == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Team ID: ");
    scanf("%d", &temp->teamID);
    getchar();

    if (isDuplicateTeamID(temp->teamID)) {

        printf("Team ID %d already exists. Cannot add duplicate.\n", temp->teamID);
        free(temp);
        return;
    }

    printf("Enter Team Name: ");
    fgets(temp->teamName, sizeof(temp->teamName), stdin);
    temp->teamName[strcspn(temp->teamName, "\n")] = '\0';

    printf("Enter Points: ");
    scanf("%d", &temp->points);
    getchar();

    temp->next = NULL;

    if (pointsTracker == NULL) {

        pointsTracker = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }
    last = temp;

    totalTeams++;
    printf("Team %s added to the points tracker with %d points.\n", temp->teamName, temp->points);
}

void deletePointsEntry(int teamID) {

    Team *temp = pointsTracker, *prev = NULL;

    if (pointsTracker == NULL) {
        printf("No teams in the points tracker.\n");
        return;
    }

    while (temp != NULL && temp->teamID != teamID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Team ID %d not found.\n", teamID);
        return;
    }

    if (prev == NULL) {

        pointsTracker = temp->next;

    } else {

        prev->next = temp->next;
    }

    free(temp);
    totalTeams--;
    printf("Team with ID %d deleted from the points tracker.\n", teamID);
}

void displayPointsStandings() {

    Team *temp = pointsTracker;
    int rank = 1;

    if (pointsTracker == NULL) {
        printf("No teams in the points tracker.\n");
        return;
    }

    printf("\n--- Current Points Standings ---\n");
    printf("Rank\tTeam ID\tTeam Name\tPoints\n");
    printf("----------------------------------------\n");
    while (temp != NULL) {
        printf("%d\t%d\t%s\t\t%d\n", rank++, temp->teamID, temp->teamName, temp->points);
        temp = temp->next;
    }
    printf("----------------------------------------\n");
}

void freePointsTracker() {

    Team *temp;

    while (pointsTracker != NULL) {

        temp = pointsTracker;
        pointsTracker = pointsTracker->next;
        free(temp);
    }
    totalTeams = 0;
    printf("All teams cleared from the points tracker.\n");
}

int isDuplicateTeamID(int teamID) {

    Team *temp = pointsTracker;

    while (temp != NULL) {
        if (temp->teamID == teamID) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
