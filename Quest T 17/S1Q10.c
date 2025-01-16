// Problem 10: Manufacturing Project Timeline
// Description: Develop a linked list to manage the timeline of a manufacturing project.
// Operations:
// Create a project timeline.
// Insert a new project milestone.
// Delete a completed milestone.
// Display the current project timeline.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Milestone {

    int milestoneID;
    char milestoneName[100];
    char deadline[20]; 
    struct Milestone *next;
} Milestone;

Milestone *timeline = NULL; 
static int totalMilestones = 0;

void createTimeline(int count);
void insertMilestone();
void deleteMilestone(int milestoneID);
void displayTimeline();

int main() {
    int choice, count, milestoneID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a project timeline.\n");
        printf("2. Insert a new project milestone.\n");
        printf("3. Delete a completed milestone.\n");
        printf("4. Display the current project timeline.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of milestones to add: ");
            scanf("%d", &count);
            getchar();
            createTimeline(count);
            printf("\nTotal milestones: %d\n", totalMilestones);
            break;

            case 2:
            insertMilestone();
            printf("\nTotal milestones: %d\n", totalMilestones);
            break;

            case 3:
            displayTimeline();
            printf("Enter the Milestone ID to delete: ");
            scanf("%d", &milestoneID);
            deleteMilestone(milestoneID);
            printf("\nTotal milestones: %d\n", totalMilestones);
            break;

            case 4:
            displayTimeline();
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

void createTimeline(int count) {

    if (count <= 0) {

        printf("Invalid number of milestones.\n");
        return;
    }

    Milestone *temp, *last = timeline;

    while (last != NULL && last->next != NULL) {

        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Milestone *)malloc(sizeof(Milestone));

        if (temp == NULL) {

            printf("Memory allocation failed for milestone %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Milestone %d:\n", i + 1);
        printf("Enter the Milestone ID: ");
        scanf("%d", &temp->milestoneID);
        getchar();

        printf("Enter the Milestone Name: ");
        fgets(temp->milestoneName, sizeof(temp->milestoneName), stdin);
        temp->milestoneName[strcspn(temp->milestoneName, "\n")] = '\0';

        printf("Enter the Deadline (e.g., YYYY-MM-DD): ");
        fgets(temp->deadline, sizeof(temp->deadline), stdin);
        temp->deadline[strcspn(temp->deadline, "\n")] = '\0';

        temp->next = NULL;

        if (timeline == NULL) {

            timeline = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalMilestones++;
    }

    printf("%d milestones added successfully.\n", count);
}

void insertMilestone() {

    Milestone *temp, *last = timeline;

    temp = (Milestone *)malloc(sizeof(Milestone));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Milestone ID: ");
    scanf("%d", &temp->milestoneID);
    getchar();

    Milestone *check = timeline;

    while (check != NULL) {

        if (check->milestoneID == temp->milestoneID) {

            printf("Error: Milestone ID %d already exists.\n", temp->milestoneID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Milestone Name: ");
    fgets(temp->milestoneName, sizeof(temp->milestoneName), stdin);
    temp->milestoneName[strcspn(temp->milestoneName, "\n")] = '\0';

    printf("Enter the Deadline (e.g., YYYY-MM-DD): ");
    fgets(temp->deadline, sizeof(temp->deadline), stdin);
    temp->deadline[strcspn(temp->deadline, "\n")] = '\0';

    temp->next = NULL;

    if (timeline == NULL) {

        timeline = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalMilestones++;
    printf("Milestone ID %d added successfully.\n", temp->milestoneID);
}

void deleteMilestone(int milestoneID) {

    if (timeline == NULL) {

        printf("Project timeline is empty.\n");
        return;
    }

    Milestone *temp = timeline, *prev = NULL;

    if (temp != NULL && temp->milestoneID == milestoneID) {

        timeline = temp->next;
        free(temp);
        printf("Milestone ID %d deleted successfully.\n", milestoneID);
        totalMilestones--;
        return;
    }

    while (temp != NULL && temp->milestoneID != milestoneID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Milestone ID %d not found.\n", milestoneID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Milestone ID %d deleted successfully.\n", milestoneID);
    totalMilestones--;
}

void displayTimeline() {

    if (timeline == NULL) {

        printf("Project timeline is empty.\n");
        return;
    }

    Milestone *temp = timeline;
    int i = 1;
    printf("\n\t\tProject Timeline\t\t\n");
    printf("Milestone ID\tMilestone Name\t\tDeadline\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t\t%-20s\t%-10s\n", temp->milestoneID, temp->milestoneName, temp->deadline);
        temp = temp->next;
    }

    printf("------------------------------------------------------------\n");
}
