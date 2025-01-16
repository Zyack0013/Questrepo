// Problem 7: Sports League Standings
// Description: Develop a linked list to manage the standings of teams in a sports league.Operations:
// Create a league standings list.
// Insert a new team.
// Delete a team that withdraws.
// Display the current league standings.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Team {
    
    int teamID;
    char teamName[50];
    int points;
    int matchesPlayed;
    int wins;
    int losses;
    int draws;
    struct Team *next;
} Team;

Team *leagueStandings = NULL;  
static int totalTeams = 0;

void createLeagueStandings(int count);
void insertNewTeam();
void deleteTeam(int teamID);
void displayLeagueStandings();

int main() {

    int choice, count, teamID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a league standings list.\n");
        printf("2. Insert a new team.\n");
        printf("3. Delete a team that withdraws.\n");
        printf("4. Display the current league standings.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of teams to add: ");
            scanf("%d", &count);
            getchar();
            createLeagueStandings(count);
            printf("\nTotal teams in the league: %d\n", totalTeams);
            break;

            case 2:
            insertNewTeam();
            printf("\nTotal teams in the league: %d\n", totalTeams);
            break;

            case 3:
            displayLeagueStandings();
            printf("Enter the team ID to delete: ");
            scanf("%d", &teamID);
            deleteTeam(teamID);
            printf("\nTotal teams in the league: %d\n", totalTeams);
            break;

            case 4:
            displayLeagueStandings();
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

void createLeagueStandings(int count) {

    if (count <= 0) {
        printf("Invalid number of teams.\n");
        return;
    }

    Team *temp, *last = leagueStandings;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Team *)malloc(sizeof(Team));

        if (temp == NULL) {

            printf("Memory allocation failed for team %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Team %d:\n", i + 1);
        printf("Enter Team ID: ");
        scanf("%d", &temp->teamID);
        getchar();

        printf("Enter Team Name: ");
        fgets(temp->teamName, sizeof(temp->teamName), stdin);
        temp->teamName[strcspn(temp->teamName, "\n")] = '\0';

        printf("Enter Team Points: ");
        scanf("%d", &temp->points);

        printf("Enter Matches Played: ");
        scanf("%d", &temp->matchesPlayed);

        printf("Enter Wins: ");
        scanf("%d", &temp->wins);

        printf("Enter Losses: ");
        scanf("%d", &temp->losses);

        printf("Enter Draws: ");
        scanf("%d", &temp->draws);

        temp->next = NULL;

        if (leagueStandings == NULL) {

            leagueStandings = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalTeams++;
    }

    printf("%d teams added to the league standings.\n", count);
}

void insertNewTeam() {

    Team *temp, *last = leagueStandings;

    temp = (Team *)malloc(sizeof(Team));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Team ID: ");
    scanf("%d", &temp->teamID);
    getchar();

    Team *check = leagueStandings;

    while (check != NULL) {

        if (check->teamID == temp->teamID) {

            printf("Error: Team ID %d already exists.\n", temp->teamID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter Team Name: ");
    fgets(temp->teamName, sizeof(temp->teamName), stdin);
    temp->teamName[strcspn(temp->teamName, "\n")] = '\0';

    printf("Enter Team Points: ");
    scanf("%d", &temp->points);

    printf("Enter Matches Played: ");
    scanf("%d", &temp->matchesPlayed);

    printf("Enter Wins: ");
    scanf("%d", &temp->wins);

    printf("Enter Losses: ");
    scanf("%d", &temp->losses);

    printf("Enter Draws: ");
    scanf("%d", &temp->draws);

    temp->next = NULL;

    if (leagueStandings == NULL) {

        leagueStandings = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalTeams++;
    printf("Team ID %d added to the league standings.\n", temp->teamID);
}

void deleteTeam(int teamID) {

    if (leagueStandings == NULL) {

        printf("No teams available in the league.\n");
        return;
    }

    Team *temp = leagueStandings, *prev = NULL;

    if (temp != NULL && temp->teamID == teamID) {

        leagueStandings = temp->next;
        free(temp);
        printf("Team ID %d withdrew from the league.\n", teamID);
        totalTeams--;
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

    prev->next = temp->next;
    free(temp);
    printf("Team ID %d withdrew from the league.\n", teamID);
    totalTeams--;
}

void displayLeagueStandings() {

    if (leagueStandings == NULL) {

        printf("No teams available in the league.\n");
        return;
    }

    Team *temp = leagueStandings;
    int i = 1;
    printf("\n\t\tLeague Standings\t\t\n");
    printf("SLNO.\tTeam ID\tTeam Name\tPoints\tMatches Played\tWins\tLosses\tDraws\n");
    printf("--------------------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t%-20s\t%d\t%d\t\t%d\t%d\t%d\n", i++, temp->teamID, temp->teamName, temp->points, temp->matchesPlayed, temp->wins, temp->losses, temp->draws);
        temp = temp->next;
    }

    printf("--------------------------------------------------------------------------\n");
}
