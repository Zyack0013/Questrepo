// Problem 2: Tournament Match Scheduling
// Description: Use a linked list to schedule matches in a tournament.Operations:
// Create a match schedule.
// Insert a new match.
// Delete a completed or canceled match.
// Display the current match schedule.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Match {

    int matchID;
    char team1[50];
    char team2[50];
    char matchDate[20];
    char matchTime[10];
    struct Match *next;
} Match;

Match *matchSchedule = NULL;  
static int totalMatches = 0;

void createMatchSchedule(int count);
void insertNewMatch();
void deleteMatch(int matchID);
void displayMatchSchedule();

int main() {

    int choice, count, matchID;

    while (1) {
        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a match schedule.\n");
        printf("2. Insert a new match.\n");
        printf("3. Delete a completed or canceled match.\n");
        printf("4. Display the current match schedule.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of matches to add: ");
            scanf("%d", &count);
            getchar();
            createMatchSchedule(count);
            printf("\nTotal matches in the schedule: %d\n", totalMatches);
            break;

            case 2:
            insertNewMatch();
            printf("\nTotal matches in the schedule: %d\n", totalMatches);
            break;

            case 3:
            displayMatchSchedule();
            printf("Enter the match ID to delete: ");
            scanf("%d", &matchID);
            deleteMatch(matchID);
            printf("\nTotal matches in the schedule: %d\n", totalMatches);
            break;

            case 4:
            displayMatchSchedule();
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

void createMatchSchedule(int count) {

    if (count <= 0) {

        printf("Invalid number of matches.\n");
        return;
    }

    Match *temp, *last = matchSchedule;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Match *)malloc(sizeof(Match));

        if (temp == NULL) {

            printf("Memory allocation failed for match entry %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Match %d:\n", i + 1);
        printf("Enter the Match ID: ");
        scanf("%d", &temp->matchID);
        getchar();

        printf("Enter Team 1 name: ");
        fgets(temp->team1, sizeof(temp->team1), stdin);
        temp->team1[strcspn(temp->team1, "\n")] = '\0';

        printf("Enter Team 2 name: ");
        fgets(temp->team2, sizeof(temp->team2), stdin);
        temp->team2[strcspn(temp->team2, "\n")] = '\0';

        printf("Enter the Match Date (DD/MM/YYYY): ");
        fgets(temp->matchDate, sizeof(temp->matchDate), stdin);
        temp->matchDate[strcspn(temp->matchDate, "\n")] = '\0';

        printf("Enter the Match Time (HH:MM): ");
        fgets(temp->matchTime, sizeof(temp->matchTime), stdin);
        temp->matchTime[strcspn(temp->matchTime, "\n")] = '\0';

        temp->next = NULL;

        if (matchSchedule == NULL) {
            matchSchedule = temp;
        } else {
            last->next = temp;
        }

        last = temp;
        totalMatches++;
    }

    printf("%d matches added to the schedule successfully.\n", count);
}

void insertNewMatch() {
    Match *temp, *last = matchSchedule;

    temp = (Match *)malloc(sizeof(Match));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Match ID: ");
    scanf("%d", &temp->matchID);
    getchar();

    Match *check = matchSchedule;
    while (check != NULL) {

        if (check->matchID == temp->matchID) {

            printf("Error: Match ID %d already exists.\n", temp->matchID);
            free(temp);
            return;

        }
        check = check->next;
    }

    printf("Enter Team 1 name: ");
    fgets(temp->team1, sizeof(temp->team1), stdin);
    temp->team1[strcspn(temp->team1, "\n")] = '\0';

    printf("Enter Team 2 name: ");
    fgets(temp->team2, sizeof(temp->team2), stdin);
    temp->team2[strcspn(temp->team2, "\n")] = '\0';

    printf("Enter the Match Date (DD/MM/YYYY): ");
    fgets(temp->matchDate, sizeof(temp->matchDate), stdin);
    temp->matchDate[strcspn(temp->matchDate, "\n")] = '\0';

    printf("Enter the Match Time (HH:MM): ");
    fgets(temp->matchTime, sizeof(temp->matchTime), stdin);
    temp->matchTime[strcspn(temp->matchTime, "\n")] = '\0';

    temp->next = NULL;

    if (matchSchedule == NULL) {

        matchSchedule = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalMatches++;
    printf("Match ID %d added to the schedule successfully.\n", temp->matchID);
}

void deleteMatch(int matchID) {

    if (matchSchedule == NULL) {

        printf("No matches in the schedule.\n");
        return;
    }

    Match *temp = matchSchedule, *prev = NULL;

    if (temp != NULL && temp->matchID == matchID) {

        matchSchedule = temp->next;
        free(temp);
        printf("Match ID %d deleted successfully.\n", matchID);
        totalMatches--;
        return;
    }

    while (temp != NULL && temp->matchID != matchID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Match ID %d not found.\n", matchID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Match ID %d deleted successfully.\n", matchID);
    totalMatches--;
}

void displayMatchSchedule() {

    if (matchSchedule == NULL) {
        printf("No matches in the schedule.\n");
        return;
    }

    Match *temp = matchSchedule;
    int i = 1;
    printf("\n\t\tTournament Match Schedule\t\t\n");
    printf("SLNO.\tMatch ID\tTeam 1\t\tTeam 2\t\tMatch Date\tMatch Time\n");
    printf("--------------------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%d\t%d\t\t%-20s\t%-20s\t%s\t%s\n", i++, temp->matchID, temp->team1, temp->team2, temp->matchDate, temp->matchTime);
        temp = temp->next;
    }

    printf("--------------------------------------------------------------------\n");
}
