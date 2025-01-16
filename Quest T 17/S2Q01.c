// Problem 1: Team Roster Management
// Description: Implement a linked list to manage the roster of players in a sports team.Operations:
// Create a team roster.
// Insert a new player.
// Delete a player who leaves the team.
// Display the current team roster.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Player {

    int playerID;
    char playerName[50];
    int age;
    char position[30];
    struct Player *next;

} Player;

Player *teamRoster = NULL;  
static int totalPlayers = 0;

void createTeamRoster(int count);
void insertNewPlayer();
void deletePlayer(int playerID);
void displayTeamRoster();

int main() {

    int choice, count, playerID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a team roster.\n");
        printf("2. Insert a new player.\n");
        printf("3. Delete a player who leaves the team.\n");
        printf("4. Display the current team roster.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of players to add: ");
            scanf("%d", &count);
            getchar();
            createTeamRoster(count);
            printf("\nTotal players in the team: %d\n", totalPlayers);
            break;

            case 2:
            insertNewPlayer();
            printf("\nTotal players in the team: %d\n", totalPlayers);
            break;

            case 3:
            displayTeamRoster();
            printf("Enter the player ID to delete: ");
            scanf("%d", &playerID);
            deletePlayer(playerID);
            printf("\nTotal players in the team: %d\n", totalPlayers);
            break;

            case 4:
            displayTeamRoster();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice.!\n");
            break;
        }
    }

    return 0;
}

void createTeamRoster(int count) {

    if (count <= 0) {

        printf("Invalid number of players.\n");
        return;
    }

    Player *temp, *last = teamRoster;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Player *)malloc(sizeof(Player));

        if (temp == NULL) {

            printf("Memory allocation failed for player entry %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Player %d:\n", i + 1);
        printf("Enter the Player ID: ");
        scanf("%d", &temp->playerID);
        getchar();

        printf("Enter the Player Name: ");
        fgets(temp->playerName, sizeof(temp->playerName), stdin);
        temp->playerName[strcspn(temp->playerName, "\n")] = '\0';

        printf("Enter the Player Age: ");
        scanf("%d", &temp->age);
        getchar();

        printf("Enter the Player Position: ");
        fgets(temp->position, sizeof(temp->position), stdin);
        temp->position[strcspn(temp->position, "\n")] = '\0';

        temp->next = NULL;

        if (teamRoster == NULL) {

            teamRoster = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalPlayers++;
    }

    printf("%d players added to the team roster successfully.\n", count);
}

void insertNewPlayer() {

    Player *temp, *last = teamRoster;

    temp = (Player *)malloc(sizeof(Player));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Player ID: ");
    scanf("%d", &temp->playerID);
    getchar();

    Player *check = teamRoster;

    while (check != NULL) {

        if (check->playerID == temp->playerID) {

            printf("Error: Player ID %d already exists.\n", temp->playerID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Player Name: ");
    fgets(temp->playerName, sizeof(temp->playerName), stdin);
    temp->playerName[strcspn(temp->playerName, "\n")] = '\0';

    printf("Enter the Player Age: ");
    scanf("%d", &temp->age);
    getchar();

    printf("Enter the Player Position: ");
    fgets(temp->position, sizeof(temp->position), stdin);
    temp->position[strcspn(temp->position, "\n")] = '\0';

    temp->next = NULL;

    if (teamRoster == NULL) {

        teamRoster = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalPlayers++;
    printf("Player ID %d added to the team roster successfully.\n", temp->playerID);
}

void deletePlayer(int playerID) {

    if (teamRoster == NULL) {
        printf("No players in the team roster.\n");
        return;
    }

    Player *temp = teamRoster, *prev = NULL;

    if (temp != NULL && temp->playerID == playerID) {
        teamRoster = temp->next;
        free(temp);
        printf("Player ID %d deleted successfully.\n", playerID);
        totalPlayers--;
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
    printf("Player ID %d deleted successfully.\n", playerID);
    totalPlayers--;
}

void displayTeamRoster() {

    if (teamRoster == NULL) {
        printf("No players in the team roster.\n");
        return;
    }

    Player *temp = teamRoster;

    int i = 1;
    printf("\n\t\tTeam Roster\t\t\n");
    printf("SLNO.\tPlayer ID\tPlayer Name\t\tAge\tPosition\n");
    printf("----------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%d\t%d\t\t%-20s\t%d\t%s\n",i++, temp->playerID, temp->playerName, temp->age, temp->position);
        temp = temp->next;
    }

    printf("----------------------------------------------------------\n");
}
