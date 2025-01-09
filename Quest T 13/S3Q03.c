// Problem 3: Grant Application Tracker
// Requirements:
// Define a structure GrantApplication with the following members:
// char applicationID[10]
// char applicantName[50]
// char projectTitle[100]
// float requestedAmount
// char status[20] (e.g., Submitted, Approved, Rejected)
// Functions to:
// Add a new grant application.
// Update the status of an application.
// Display all applications requesting an amount greater than a specified value.
// Find and display applications that are currently "Approved."
// Store the grant applications in a dynamically allocated array, resizing it as necessary.



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct GrantApplication {

    char applicationID[10];
    char applicantName[50];
    char projectTitle[100];
    float requestedAmount;
    char status[20];  
};

void addGrantApplication(struct GrantApplication **applications, int *size, int *capacity);
void updateApplicationStatus(struct GrantApplication *applications, int size);
void displayApplicationsGreaterThanAmount(struct GrantApplication *applications, int size, float amount);
void displayApprovedApplications(struct GrantApplication *applications, int size);
void displayAllApplications(struct GrantApplication *applications, int size);

int main() {

    int size = 0;
    int capacity = 2; 
    struct GrantApplication *applications = (struct GrantApplication *)malloc(capacity * sizeof(struct GrantApplication));

    if (applications == NULL) {

        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;
    while (1) {

        printf("\n1. Add a new grant application\n");
        printf("2. Update the status of an application\n");
        printf("3. Display all applications requesting more than a specified amount\n");
        printf("4. Display all approved applications\n");
        printf("5. Display all applications\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                addGrantApplication(&applications, &size, &capacity);
                break;
            case 2:
                updateApplicationStatus(applications, size);
                break;
            case 3: {
                float amount;
                printf("Enter the amount: ");
                scanf("%f", &amount);
                getchar();  
                displayApplicationsGreaterThanAmount(applications, size, amount);
                break;
            }
            case 4:
                displayApprovedApplications(applications, size);
                break;
            case 5:
                displayAllApplications(applications, size);
                break;
            case 6:
                free(applications);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addGrantApplication(struct GrantApplication **applications, int *size, int *capacity) {

    if (*size == *capacity) {

        *capacity *= 2;  
        *applications = (struct GrantApplication *)realloc(*applications, *capacity * sizeof(struct GrantApplication));

        if (*applications == NULL) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter application ID: ");
    fgets((*applications)[*size].applicationID, sizeof((*applications)[*size].applicationID), stdin);
    (*applications)[*size].applicationID[strcspn((*applications)[*size].applicationID, "\n")] = '\0';  

    printf("Enter applicant's name: ");
    fgets((*applications)[*size].applicantName, sizeof((*applications)[*size].applicantName), stdin);
    (*applications)[*size].applicantName[strcspn((*applications)[*size].applicantName, "\n")] = '\0';  

    printf("Enter project title: ");
    fgets((*applications)[*size].projectTitle, sizeof((*applications)[*size].projectTitle), stdin);
    (*applications)[*size].projectTitle[strcspn((*applications)[*size].projectTitle, "\n")] = '\0';  

    printf("Enter requested amount: ");
    scanf("%f", &(*applications)[*size].requestedAmount);
    getchar();  

    printf("Enter status (Submitted, Approved, Rejected): ");
    fgets((*applications)[*size].status, sizeof((*applications)[*size].status), stdin);
    (*applications)[*size].status[strcspn((*applications)[*size].status, "\n")] = '\0';  

    (*size)++;
}

void updateApplicationStatus(struct GrantApplication *applications, int size) {

    char applicationID[10];
    printf("Enter application ID to update: ");
    fgets(applicationID, sizeof(applicationID), stdin);
    applicationID[strcspn(applicationID, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < size; i++) {

        if (strcmp(applications[i].applicationID, applicationID) == 0) {

            printf("Enter new status (Submitted, Approved, Rejected): ");
            fgets(applications[i].status, sizeof(applications[i].status), stdin);
            applications[i].status[strcspn(applications[i].status, "\n")] = '\0';  
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Application with ID %s not found.\n", applicationID);
    }
}

void displayApplicationsGreaterThanAmount(struct GrantApplication *applications, int size, float amount) {

    printf("\nApplications requesting more than %.2f:\n", amount);
    int found = 0;
    for (int i = 0; i < size; i++) {

        if (applications[i].requestedAmount > amount) {

            printf("Application ID: %s, Applicant: %s, Project: %s, Requested Amount: %.2f, Status: %s\n",applications[i].applicationID, applications[i].applicantName,applications[i].projectTitle, applications[i].requestedAmount,applications[i].status);
            found = 1;
        }
    }

    if (!found) {
        printf("No applications found requesting more than %.2f.\n", amount);
    }
}

void displayApprovedApplications(struct GrantApplication *applications, int size) {

    printf("\nApproved Applications:\n");
    int found = 0;

    for (int i = 0; i < size; i++) {

        if (strcmp(applications[i].status, "Approved") == 0) {

            printf("Application ID: %s, Applicant: %s, Project: %s, Requested Amount: %.2f, Status: %s\n",applications[i].applicationID, applications[i].applicantName,applications[i].projectTitle, applications[i].requestedAmount,applications[i].status);
            found = 1;
        }
    }

    if (!found) {
        printf("No approved applications found.\n");
    }
}

void displayAllApplications(struct GrantApplication *applications, int size) {

    printf("\nAll Grant Applications:\n");

    for (int i = 0; i < size; i++) {

        printf("Application ID: %s, Applicant: %s, Project: %s, Requested Amount: %.2f, Status: %s\n",applications[i].applicationID, applications[i].applicantName,applications[i].projectTitle, applications[i].requestedAmount,applications[i].status);
    }
}
