// Problem 2: Tournament Fixture Scheduler
// Requirements:
// Create a structure Match with members:
// char team1[30]
// char team2[30]
// char date[11] (format: YYYY-MM-DD)
// char venue[50]
// Functions to:
// Schedule a new match between two teams.
// Display all scheduled matches.
// Search for matches scheduled on a specific date.
// Cancel a match by specifying both team names and the date.
// Ensure that the match schedule is stored in an array, with the ability to dynamically adjust its size.



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"

struct Match{

    char team1[30];
    char team2[30];
    char date[11];
    char venue[50];
};

void scheduleMatch(struct Match **matches,int *N);
void displaySchedule(struct Match *matches,int N);
void searchByDate(struct Match *matches,int N);
void cancelMatch(struct Match **matches,int *N);
void matchesSize(struct Match **matches,int *N);


int main(){

    int N = 0;
    struct Match *matches = NULL;

    int choice;

    while(1){

        printf("\t\tWELCOME\t\t\n");
        printf("1. Schedule a new match.\n");
        printf("2. Display all scheduled matches.\n");
        printf("3. Search for matches scheduled.\n");
        printf("4. Cancel a match.\n");
        printf("5. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1:
            scheduleMatch(&matches,&N);
            break;

            case 2:
            displaySchedule(matches,N);
            break;

            case 3:
            searchByDate(matches,N);
            break;

            case 4:
            cancelMatch(&matches,&N);
            break;

            case 5:
            printf("Exiting....\n");
            free(matches);
            return 0;

            default:
            printf("Invalid choice!\n");

        }
    }

    return 0;

}

void matchesSize(struct Match **matches,int *N){

    *N += 1;
    *matches = realloc(*matches, *N * sizeof(struct Match));

    if (*matches == NULL) {

        printf("Allocation failed!\n");
        exit(1);

    }
}

void scheduleMatch(struct Match **matches,int *N){

    struct Match newMatch;

    matchesSize(matches,N);

    getStringInput("Enter Team 1 : ",newMatch.team1);
    getStringInput("Enter Team 2 : ",newMatch.team2);
    getStringInput("Enter date (YYYY-MM-DD) : ",newMatch.date);
    getStringInput("Enter the venue : ",newMatch.venue);

    (*matches)[*N - 1] = newMatch;
    printf("New match is scheluded successfully!\n");

    

}

void displaySchedule(struct Match *matches,int N){

    if (N == 0) {

        printf("No matches scheduled.\n");
        return;
    }

    printf("\n\t\tScheduled Matches\t\t\n");

    for (int i = 0; i < N; i++) {

        printf("Match %d: %s vs %s\n", i + 1,matches[i].team1, matches[i].team2);
        printf("Date: %s, Venue: %s\n", matches[i].date, matches[i].venue);

    }

}

void searchByDate(struct Match *matches,int N){

    char searchDate[11];

    getStringInput("Enter date to search (YYYY-MM-DD) : ",searchDate);

    int found = 0;
    printf("\n\t\tMatches on %s\t\t\n", searchDate);
    
    for (int i = 0; i < N; i++) {

        if (strcmp(matches[i].date, searchDate) == 0) {

            printf("Match %d: %s vs %s, Venue: %s\n", i + 1, matches[i].team1, matches[i].team2, matches[i].venue);
            found = 1;
        }
    }

    if (!found) {

        printf("No matches found on %s.\n", searchDate);
    }

}

void cancelMatch(struct Match **matches,int *N){

    if (*N == 0) {
        printf("No matches to cancel.\n");
        return;
    }

    char team1[30], team2[30], date[11],team01[30];
    getStringInput("Enter team 1 : ",team1);
    printf("%s\n",team1);
    getStringInput("Enter team 2 : ",team2);
    printf("%s\n",team1);
    getStringInput("Enter the match date (YYYY-MM-DD) : ",date);
    printf("%s\n",team1);

    strcpy(team01,team1);

    printf("%d",strcasecmp((*matches)[0].team1,team01));


    int found = 0;

    for (int i = 0; i < *N; i++) {
        
        if (strcasecmp((*matches)[i].team1,team1) == 0 && strcasecmp((*matches)[i].team2, team2) == 0 && strcasecmp((*matches)[i].date, date) == 0) {
            printf("%s\n",team1);
            printf("%s\n",team2);

            found = 1;
            for (int j = i; j < *N - 1; j++) {

                (*matches)[j] = (*matches)[j + 1];
            }

            (*N)--;
            printf("Match canceled successfully!\n");
            break;
        }
    }

    if (!found) {

        printf("No match found with the specified details.\n");

    }

}


