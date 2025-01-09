// Problem 1: Player Statistics Management
// Requirements:
// Define a structure Player with the following members:
// char name[50]
// int age
// char team[30]
// int matchesPlayed
// int totalRuns
// int totalWickets
// Functions to:
// Add a new player to the system.
// Update a player’s statistics after a match.
// Display the details of players from a specific team.
// Find the player with the highest runs and the player with the most wickets.
// Use dynamic memory allocation to store player data in an array and expand it as needed.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Player{

    char name[50];
    int age;
    char team[30];
    int matchesPlayed;
    int totalRuns;
    int totalWickets;

};

void addPlayer(struct Player **players,int *N);
void updatePlayer(struct Player *players,int N);
void displayTeamPlayers(struct Player *players,int N);
void findByRunsAndWickets(struct Player *players,int N);
void playerSize(struct Player **players,int *N);

int main() {

    int N = 0;
    struct Player *players = NULL;

    int choice;

    while(1){

        printf("\t\tWELCOME\t\t\n");
        printf("1. Add a new player.\n");
        printf("2. Update a player’s statistics.\n");
        printf("3. Display players details.\n");
        printf("4. Find the best players.\n");
        printf("5. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1:
            addPlayer(&players,&N);
            break;

            case 2:
            updatePlayer(players,N);
            break;

            case 3:
            displayTeamPlayers(players,N);
            break;

            case 4:
            findByRunsAndWickets(players,N);
            break;

            case 5:
            printf("Exiting....\n");
            free(players);
            return 0;

            default:
            printf("Invalid choice!\n");

        }
    }

    return 0;
}


void playerSize(struct Player **players,int *N){

    *N += 1;
    *players = realloc(*players, *N * sizeof(struct Player));

    if (*players == NULL) {
        printf("Allocation failed!\n");
        exit(1);
    }

}


void addPlayer(struct Player **players,int *N){

    struct Player newPlayer;

    playerSize(players,N);

    printf("Enter player name : ");
    fgets(newPlayer.name, sizeof(newPlayer.name), stdin);
    newPlayer.name[strcspn(newPlayer.name, "\n")] = '\0';

    printf("Enter player age : ");
    scanf("%d", &newPlayer.age);
    getchar();
    
    printf("Enter player team : ");
    fgets(newPlayer.team, sizeof(newPlayer.team), stdin);
    newPlayer.team[strcspn(newPlayer.team, "\n")] = '\0';

    printf("Enter the matches played till now : ");
    scanf("%d",&newPlayer.matchesPlayed);

    printf("Enter the runs scored till now : ");
    scanf("%d",&newPlayer.totalRuns);

    printf("Enter the wickets taken till now : ");
    scanf("%d",&newPlayer.totalWickets);

    (*players)[*N - 1] = newPlayer;
    printf("New player added successfully!\n");

}

void updatePlayer(struct Player *players,int N){

    char name[50];
    int found = 0;

    printf("Enter the name of the player to update statistics: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < N; i++) {

        if (strcasecmp(players[i].name, name) == 0) {

            found = 1;
            printf("Enter runs scored by %s in the match: ", players[i].name);
            int runs;
            scanf("%d", &runs);
            getchar();

            printf("Enter wickets taken by %s in the match: ", players[i].name);
            int wickets;
            scanf("%d", &wickets);
            getchar();

            players[i].totalRuns += runs;
            players[i].totalWickets += wickets;
            players[i].matchesPlayed++;

            printf("Player stats updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Player not found!\n");
    }
}

void displayTeamPlayers(struct Player *players,int N){

     char teamName[30];
    int found = 0;

    printf("Enter the team name: ");
    fgets(teamName, sizeof(teamName), stdin);
    teamName[strcspn(teamName, "\n")] = '\0';

    printf("Players from team %s:\n", teamName);

    for (int i = 0; i < N; i++) {
        if (strcasecmp(players[i].team, teamName) == 0) {
            printf("Name: %s, Age: %d, Matches Played: %d, Total Runs: %d, Total Wickets: %d\n",
                   players[i].name, players[i].age, players[i].matchesPlayed,
                   players[i].totalRuns, players[i].totalWickets);
            found = 1;
        }
    }

    if (!found) {
        printf("No players found from team %s.\n", teamName);
    }
}

void findByRunsAndWickets(struct Player *players,int N){

    if (N == 0) {
        printf("No players available.\n");
        return;
    }

    struct Player topRunsPlayer = players[0];
    struct Player topWicketsPlayer = players[0];

    for (int i = 1; i < N; i++) {
        if (players[i].totalRuns > topRunsPlayer.totalRuns) {

            topRunsPlayer = players[i];
        }

        if (players[i].totalWickets > topWicketsPlayer.totalWickets) {

            topWicketsPlayer = players[i];
            
        }
    }

    printf("Player with most runs: %s with %d runs\n", topRunsPlayer.name, topRunsPlayer.totalRuns);
    printf("Player with most wickets: %s with %d wickets\n", topWicketsPlayer.name, topWicketsPlayer.totalWickets);
}

