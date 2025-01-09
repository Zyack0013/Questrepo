// Problem 5: Scientific Conference Submission Tracker
// Requirements:
// Define a structure ConferenceSubmission with the following:
// char submissionID[10]
// char authorName[50]
// char paperTitle[100]
// char conferenceName[50]
// char submissionDate[11]
// char status[20] (e.g., Pending, Accepted, Rejected)
// Functions to:
// Add a new conference submission.
// Update the status of a submission.
// Display all submissions to a specific conference.
// Find and display submissions by a specific author.
// Store the conference submissions in a dynamically allocated array, resizing the array as needed when more submissions are added.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ConferenceSubmission {
    
    char submissionID[10];
    char authorName[50];
    char paperTitle[100];
    char conferenceName[50];
    char submissionDate[11];  
    char status[20];  
};

void addSubmission(struct ConferenceSubmission **submissions, int *size, int *capacity);
void updateStatus(struct ConferenceSubmission *submissions, int size);
void displaySubmissionsToConference(struct ConferenceSubmission *submissions, int size, const char *conferenceName);
void findSubmissionsByAuthor(struct ConferenceSubmission *submissions, int size, const char *authorName);
void displayAllSubmissions(struct ConferenceSubmission *submissions, int size);

int main() {

    int size = 0;
    int capacity = 2;  
    struct ConferenceSubmission *submissions = (struct ConferenceSubmission *)malloc(capacity * sizeof(struct ConferenceSubmission));

    if (submissions == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;

    while (1) {

        printf("\n1. Add a new submission\n");
        printf("2. Update the status of a submission\n");
        printf("3. Display all submissions to a specific conference\n");
        printf("4. Find and display submissions by a specific author\n");
        printf("5. Display all submissions\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                addSubmission(&submissions, &size, &capacity);
                break;
            case 2:
                updateStatus(submissions, size);
                break;
            case 3: {
                char conferenceName[50];
                printf("Enter conference name: ");
                fgets(conferenceName, sizeof(conferenceName), stdin);
                conferenceName[strcspn(conferenceName, "\n")] = '\0';  
                displaySubmissionsToConference(submissions, size, conferenceName);
                break;
            }
            case 4: {
                char authorName[50];
                printf("Enter author name: ");
                fgets(authorName, sizeof(authorName), stdin);
                authorName[strcspn(authorName, "\n")] = '\0';  
                findSubmissionsByAuthor(submissions, size, authorName);
                break;
            }
            case 5:
                displayAllSubmissions(submissions, size);
                break;
            case 6:
                free(submissions);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addSubmission(struct ConferenceSubmission **submissions, int *size, int *capacity) {

    if (*size == *capacity) {

        *capacity *= 2;  
        *submissions = (struct ConferenceSubmission *)realloc(*submissions, *capacity * sizeof(struct ConferenceSubmission));

        if (*submissions == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter submission ID: ");
    fgets((*submissions)[*size].submissionID, sizeof((*submissions)[*size].submissionID), stdin);
    (*submissions)[*size].submissionID[strcspn((*submissions)[*size].submissionID, "\n")] = '\0';  

    printf("Enter author name: ");
    fgets((*submissions)[*size].authorName, sizeof((*submissions)[*size].authorName), stdin);
    (*submissions)[*size].authorName[strcspn((*submissions)[*size].authorName, "\n")] = '\0';  

    printf("Enter paper title: ");
    fgets((*submissions)[*size].paperTitle, sizeof((*submissions)[*size].paperTitle), stdin);
    (*submissions)[*size].paperTitle[strcspn((*submissions)[*size].paperTitle, "\n")] = '\0';  

    printf("Enter conference name: ");
    fgets((*submissions)[*size].conferenceName, sizeof((*submissions)[*size].conferenceName), stdin);
    (*submissions)[*size].conferenceName[strcspn((*submissions)[*size].conferenceName, "\n")] = '\0';  

    printf("Enter submission date (YYYY-MM-DD): ");
    fgets((*submissions)[*size].submissionDate, sizeof((*submissions)[*size].submissionDate), stdin);
    (*submissions)[*size].submissionDate[strcspn((*submissions)[*size].submissionDate, "\n")] = '\0';  

    printf("Enter submission status (Pending, Accepted, Rejected): ");
    fgets((*submissions)[*size].status, sizeof((*submissions)[*size].status), stdin);
    (*submissions)[*size].status[strcspn((*submissions)[*size].status, "\n")] = '\0';  

    (*size)++;
}


void updateStatus(struct ConferenceSubmission *submissions, int size) {

    char submissionID[10];
    printf("Enter submission ID to update: ");
    fgets(submissionID, sizeof(submissionID), stdin);
    submissionID[strcspn(submissionID, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < size; i++) {

        if (strcmp(submissions[i].submissionID, submissionID) == 0) {
            printf("Enter new status (Pending, Accepted, Rejected): ");
            fgets(submissions[i].status, sizeof(submissions[i].status), stdin);
            submissions[i].status[strcspn(submissions[i].status, "\n")] = '\0';  
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Submission with ID %s not found.\n", submissionID);
    }
}

void displaySubmissionsToConference(struct ConferenceSubmission *submissions, int size, const char *conferenceName) {
    printf("\nSubmissions to conference %s:\n", conferenceName);
    int found = 0;

    for (int i = 0; i < size; i++) {

        if (strcmp(submissions[i].conferenceName, conferenceName) == 0) {

            printf("Submission ID: %s, Author: %s, Paper Title: %s, Date: %s, Status: %s\n",submissions[i].submissionID, submissions[i].authorName,submissions[i].paperTitle, submissions[i].submissionDate,submissions[i].status);
            found = 1;
        }
    }

    if (!found) {
        printf("No submissions found for conference %s.\n", conferenceName);
    }
}

void findSubmissionsByAuthor(struct ConferenceSubmission *submissions, int size, const char *authorName) {

    printf("\nSubmissions by author %s:\n", authorName);
    int found = 0;

    for (int i = 0; i < size; i++) {

        if (strcmp(submissions[i].authorName, authorName) == 0) {
            printf("Submission ID: %s, Paper Title: %s, Conference: %s, Date: %s, Status: %s\n",submissions[i].submissionID, submissions[i].paperTitle,submissions[i].conferenceName, submissions[i].submissionDate,submissions[i].status);
            found = 1;
        }
    }

    if (!found) {
        printf("No submissions found by author %s.\n", authorName);
    }
}

void displayAllSubmissions(struct ConferenceSubmission *submissions, int size) {

    printf("\nAll Submissions:\n");

    for (int i = 0; i < size; i++) {

        printf("Submission ID: %s, Author: %s, Paper Title: %s, Conference: %s, Date: %s, Status: %s\n",submissions[i].submissionID, submissions[i].authorName,submissions[i].paperTitle, submissions[i].conferenceName,submissions[i].submissionDate, submissions[i].status);
    }
}
