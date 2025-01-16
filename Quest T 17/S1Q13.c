// Problem 13: Packaging Line Schedule
// Description: Manage the schedule of packaging tasks using a linked list.
// Operations:
// Create a packaging task schedule.
// Insert a new packaging task.
// Delete a completed packaging task.
// Display the current packaging schedule.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {

    int taskID;
    char taskDescription[100];
    char deadline[20];
    struct Task *next;
} Task;

Task *schedule = NULL; 
static int totalTasks = 0;

void createPackagingSchedule(int count);
void insertNewTask();
void deleteTask(int taskID);
void displayPackagingSchedule();

int main() {

    int choice, count, taskID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a packaging task schedule.\n");
        printf("2. Insert a new packaging task.\n");
        printf("3. Delete a completed packaging task.\n");
        printf("4. Display the current packaging schedule.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of tasks to add: ");
            scanf("%d", &count);
            getchar();
            createPackagingSchedule(count);
            printf("\nTotal tasks in schedule: %d\n", totalTasks);
            break;

            case 2:
            insertNewTask();
            printf("\nTotal tasks in schedule: %d\n", totalTasks);
            break;

            case 3:
            displayPackagingSchedule();
            printf("Enter the task ID to delete: ");
            scanf("%d", &taskID);
            deleteTask(taskID);
            printf("\nTotal tasks in schedule: %d\n", totalTasks);
            break;

            case 4:
            displayPackagingSchedule();
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

void createPackagingSchedule(int count) {

    if (count <= 0) {
        printf("Invalid number of tasks.\n");
        return;
    }

    Task *temp, *last = schedule;

    while (last != NULL && last->next != NULL) {

        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Task *)malloc(sizeof(Task));

        if (temp == NULL) {

            printf("Memory allocation failed for task entry %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Task %d:\n", i + 1);
        printf("Enter the Task ID: ");
        scanf("%d", &temp->taskID);
        getchar();

        printf("Enter the Task Description: ");
        fgets(temp->taskDescription, sizeof(temp->taskDescription), stdin);
        temp->taskDescription[strcspn(temp->taskDescription, "\n")] = '\0';

        printf("Enter the Task Deadline: ");
        fgets(temp->deadline, sizeof(temp->deadline), stdin);
        temp->deadline[strcspn(temp->deadline, "\n")] = '\0';

        temp->next = NULL;

        if (schedule == NULL) {
            schedule = temp;
        } else {
            last->next = temp;
        }

        last = temp;
        totalTasks++;
    }

    printf("%d tasks added to the packaging schedule successfully.\n", count);
}

void insertNewTask() {
    Task *temp, *last = schedule;

    temp = (Task *)malloc(sizeof(Task));

    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Task ID: ");
    scanf("%d", &temp->taskID);
    getchar();

    Task *check = schedule;

    while (check != NULL) {

        if (check->taskID == temp->taskID) {

            printf("Error: Task ID %d already exists.\n", temp->taskID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Task Description: ");
    fgets(temp->taskDescription, sizeof(temp->taskDescription), stdin);
    temp->taskDescription[strcspn(temp->taskDescription, "\n")] = '\0';

    printf("Enter the Task Deadline: ");
    fgets(temp->deadline, sizeof(temp->deadline), stdin);
    temp->deadline[strcspn(temp->deadline, "\n")] = '\0';

    temp->next = NULL;

    if (schedule == NULL) {

        schedule = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalTasks++;
    printf("Task ID %d added to schedule successfully.\n", temp->taskID);
}

void deleteTask(int taskID) {

    if (schedule == NULL) {

        printf("Schedule is empty.\n");
        return;
    }

    Task *temp = schedule, *prev = NULL;

    if (temp != NULL && temp->taskID == taskID) {

        schedule = temp->next;
        free(temp);
        printf("Task ID %d deleted successfully.\n", taskID);
        totalTasks--;
        return;
    }

    while (temp != NULL && temp->taskID != taskID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Task ID %d not found.\n", taskID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Task ID %d deleted successfully.\n", taskID);
    totalTasks--;
}

void displayPackagingSchedule() {

    if (schedule == NULL) {

        printf("Schedule is empty.\n");
        return;
    }

    Task *temp = schedule;
    int i = 1;
    printf("\n\t\tPackaging Line Schedule\t\t\n");
    printf("SLNO.\tTask ID\t\tTask Description\t\tDeadline\n");
    printf("--------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%-20s\n", i++, temp->taskID, temp->taskDescription, temp->deadline);
        temp = temp->next;
    }

    printf("--------------------------------------------------------------\n");
}
