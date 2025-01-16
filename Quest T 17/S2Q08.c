// Problem 8: Match Result Recording
// Description: Implement a linked list to record results of matches.Operations:
// Create a match result list.
// Insert a new match result.
// Delete an incorrect or outdated result.
// Display all recorded match results.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MatchResult {
    
    int matchID;
    char team1[50];
    char team2[50];
    int score1;
    int score2;
    char date[20];
    struct MatchResult *next;

} MatchResult;

MatchResult *matchResults = NULL;  
static int totalMatches = 0;

void createMatchResultList(int count);
void insertMatchResult();
void deleteMatchResult(int matchID);
void displayMatchResults();

int main() {

    int choice, count, matchID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a match result list.\n");
        printf("2. Insert a new match result.\n");
        printf("3. Delete an incorrect or outdated match result.\n");
        printf("4. Display all recorded match results.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of match results to add: ");
            scanf("%d", &count);
            getchar();
            createMatchResultList(count);
            printf("\nTotal matches recorded: %d\n", totalMatches);
            break;

            case 2:
            insertMatchResult();
            printf("\nTotal matches recorded: %d\n", totalMatches);
            break;

            case 3:
            displayMatchResults();
            printf("Enter the match ID to delete: ");
            scanf("%d", &matchID);
            deleteMatchResult(matchID);
            printf("\nTotal matches recorded: %d\n", totalMatches);
            break;

            case 4:
            displayMatchResults();
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

void createMatchResultList(int count) {

    if (count <= 0) {

        printf("Invalid number of match results.\n");
        return;
    }

    MatchResult *temp, *last = matchResults;

    while (last != NULL && last->next != NULL) {

        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (MatchResult *)malloc(sizeof(MatchResult));

        if (temp == NULL) {

            printf("Memory allocation failed for match result %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Match Result %d:\n", i + 1);
        printf("Enter Match ID: ");
        scanf("%d", &temp->matchID);
        getchar();

        printf("Enter Team 1 Name: ");
        fgets(temp->team1, sizeof(temp->team1), stdin);
        temp->team1[strcspn(temp->team1, "\n")] = '\0';

        printf("Enter Team 2 Name: ");
        fgets(temp->team2, sizeof(temp->team2), stdin);
        temp->team2[strcspn(temp->team2, "\n")] = '\0';

        printf("Enter Score for Team 1: ");
        scanf("%d", &temp->score1);

        printf("Enter Score for Team 2: ");
        scanf("%d", &temp->score2);

        printf("Enter Match Date (DD/MM/YYYY): ");
        scanf("%s", temp->date);

        temp->next = NULL;

        if (matchResults == NULL) {

            matchResults = temp;
        } else {

            last->next = temp;
        }

        last = temp;
        totalMatches++;
    }

    printf("%d match results added.\n", count);
}

void insertMatchResult() {

    MatchResult *temp, *last = matchResults;

    temp = (MatchResult *)malloc(sizeof(MatchResult));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Match ID: ");
    scanf("%d", &temp->matchID);
    getchar();

    MatchResult *check = matchResults;

    while (check != NULL) {

        if (check->matchID == temp->matchID) {

            printf("Match ID %d already exists.\n", temp->matchID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter Team 1 Name: ");
    fgets(temp->team1, sizeof(temp->team1), stdin);
    temp->team1[strcspn(temp->team1, "\n")] = '\0';

    printf("Enter Team 2 Name: ");
    fgets(temp->team2, sizeof(temp->team2), stdin);
    temp->team2[strcspn(temp->team2, "\n")] = '\0';

    printf("Enter Score for Team 1: ");
    scanf("%d", &temp->score1);

    printf("Enter Score for Team 2: ");
    scanf("%d", &temp->score2);

    printf("Enter Match Date (DD/MM/YYYY): ");
    scanf("%s", temp->date);

    temp->next = NULL;

    if (matchResults == NULL) {

        matchResults = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalMatches++;
    printf("Match result with ID %d added.\n", temp->matchID);
}

void deleteMatchResult(int matchID) {
    
    if (matchResults == NULL) {

        printf("No match results available.\n");
        return;
    }

    MatchResult *temp = matchResults, *prev = NULL;

    if (temp != NULL && temp->matchID == matchID) {

        matchResults = temp->next;
        free(temp);
        printf("Match result with ID %d deleted.\n", matchID);
        totalMatches--;
        return;
    }

    while (temp != NULL && temp->matchID != matchID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Match result with ID %d not found.\n", matchID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Match result with ID %d deleted.\n", matchID);
    totalMatches--;
}

void displayMatchResults() {

    if (matchResults == NULL) {

        printf("No match results available.\n");
        return;
    }

    MatchResult *temp = matchResults;
    int i = 1;
    printf("\n\t\tRecorded Match Results\t\t\n");
    printf("SLNO.\tMatch ID\tTeam 1\t\tTeam 2\t\tScore\t\tDate\n");
    printf("-------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s%-20s%d - %d\t%s\n", i++, temp->matchID, temp->team1, temp->team2, temp->score1, temp->score2, temp->date);

        temp = temp->next;
    }

    printf("-------------------------------------------------------------\n");
}
