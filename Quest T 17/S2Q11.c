// Problem 11: Coaching Staff Management
// Description: Use a linked list to manage the coaching staff of a sports team.Operations:
// Create a coaching staff list.
// Insert a new coach.
// Delete a coach who leaves the team.
// Display the current coaching staff.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Coach {

    int coachID;
    char name[50];
    char role[30];
    struct Coach *next;

} Coach;

Coach *first = NULL; 
int totalCoaches = 0; 

void createCoachingStaff(int count);
void insertCoach();
void deleteCoach(int coachID);
void displayCoachingStaff();

int main() {

    int choice, count, coachID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create coaching staff list (add initial coaches).\n");
        printf("2. Insert a new coach.\n");
        printf("3. Delete a coach who leaves the team.\n");
        printf("4. Display the current coaching staff.\n");
        printf("5. Exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
            printf("Enter the number of initial coaches: ");
            scanf("%d", &count);
            getchar();
            createCoachingStaff(count);
            break;

            case 2:
            insertCoach();
            break;

            case 3:
            printf("Enter the Coach ID to delete: ");
            scanf("%d", &coachID);
            getchar();
            deleteCoach(coachID);
            break;

            case 4:
            displayCoachingStaff();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}

void createCoachingStaff(int count) {

    if (count <= 0) {

        printf("Invalid number of coaches.\n");
        return;
    }

    Coach *temp, *last = NULL;
    char name[50], role[30];

    for (int i = 0; i < count; i++) {

        temp = (Coach *)malloc(sizeof(Coach));

        if (!temp) {

            printf("Memory allocation failed!\n");
            return;
        }

        totalCoaches++;
        temp->coachID = totalCoaches;

        printf("Enter details for Coach ID %d:\n", totalCoaches);
        printf("Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; 
        strcpy(temp->name, name);

        printf("Role: ");
        fgets(role, sizeof(role), stdin);
        role[strcspn(role, "\n")] = '\0'; 
        strcpy(temp->role, role);

        temp->next = NULL;

        if (first == NULL) {

            first = temp;

        } else {

            last->next = temp;
        }
        last = temp;

        printf("Coach ID %d added successfully.\n", totalCoaches);
    }
}

void insertCoach() {

    Coach *temp = (Coach *)malloc(sizeof(Coach));

    if (!temp) {

        printf("Memory allocation failed!\n");
        return;
    }

    totalCoaches++;
    temp->coachID = totalCoaches;

    printf("Enter details for Coach ID %d:\n", totalCoaches);
    printf("Name: ");
    fgets(temp->name, sizeof(temp->name), stdin);
    temp->name[strcspn(temp->name, "\n")] = '\0'; 

    printf("Role: ");
    fgets(temp->role, sizeof(temp->role), stdin);
    temp->role[strcspn(temp->role, "\n")] = '\0'; 

    temp->next = NULL;

    if (first == NULL) {
        first = temp;
    } else {

        Coach *ptr = first;
        while (ptr->next != NULL) {

            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    printf("Coach ID %d inserted successfully.\n", totalCoaches);
}

void deleteCoach(int coachID) {

    if (first == NULL) {

        printf("No coaches available to delete.\n");
        return;
    }

    Coach *temp = first, *prev = NULL;

    while (temp != NULL) {

        if (temp->coachID == coachID) {

            if (prev == NULL) {

                // Deleting the first
                first = temp->next;
            } else {

                prev->next = temp->next;

            }
            free(temp);
            printf("Coach ID %d deleted successfully.\n", coachID);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Coach ID %d not found.\n", coachID);
}

void displayCoachingStaff() {

    if (first == NULL) {

        printf("No coaches available.\n");
        return;
    }

    Coach *temp = first;

    printf("\nCurrent Coaching Staff:\n");
    printf("Coach ID\tName\t\tRole\n");
    printf("-----------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t\t%-15s\t%s\n", temp->coachID, temp->name, temp->role);
        temp = temp->next;
    }
}
