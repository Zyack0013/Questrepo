// Problem 3: Machine Maintenance Schedule
// Description: Develop a linked list to manage the maintenance schedule of machines.
// Operations:
// Create a maintenance schedule.
// Insert a new maintenance task.
// Delete a completed maintenance task.
// Display the maintenance schedule.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MaintenanceTask {

    int taskID;
    char description[100];
    char machineName[50];
    struct MaintenanceTask *next;

} MaintenanceTask;

MaintenanceTask *first = NULL; 

void createSchedule(void);
void insertTask(int id, const char *desc, const char *machine);
void deleteTask(int id);
void displaySchedule(void);

int main() {
    int choice, id;
    char description[100], machineName[50];

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a maintenance schedule\n");
        printf("2. Insert a new maintenance task\n");
        printf("3. Delete a completed maintenance task\n");
        printf("4. Display the maintenance schedule\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
            createSchedule();
            break;
            case 2:
            printf("Enter Task ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter Task Description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0'; 
            printf("Enter Machine Name: ");
            fgets(machineName, sizeof(machineName), stdin);
            machineName[strcspn(machineName, "\n")] = '\0'; 
            insertTask(id, description, machineName);
            break;
            case 3:
            printf("Enter Task ID to delete: ");
            scanf("%d", &id);
            deleteTask(id);
            break;
            case 4:
            displaySchedule();
            break;
            case 5:
            printf("Exiting...\n");
            return 0;
            default:
            printf("Invalid choice!.\n");
            break;
        }
    }
}

void createSchedule(void) {

    if (first != NULL) {
        printf("Schedule already exists. Clear it first if needed.\n");
        return;
    }

    int n, id;
    char description[100], machineName[50];
    printf("Enter the number of maintenance tasks: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {

        printf("Enter Task ID: ");
        scanf("%d", &id);
        getchar();
        printf("Enter Task Description: ");
        fgets(description, sizeof(description), stdin);
        description[strcspn(description, "\n")] = '\0';
        printf("Enter Machine Name: ");
        fgets(machineName, sizeof(machineName), stdin);
        machineName[strcspn(machineName, "\n")] = '\0';
        insertTask(id, description, machineName);
    }
    printf("Maintenance schedule created successfully.\n");
}

void insertTask(int id, const char *desc, const char *machine) {

    MaintenanceTask *newTask = (MaintenanceTask *)malloc(sizeof(MaintenanceTask));

    if (newTask == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newTask->taskID = id;
    strcpy(newTask->description, desc);
    strcpy(newTask->machineName, machine);
    newTask->next = NULL;

    if (first == NULL) {
        first = newTask; 
    } else {
        MaintenanceTask *temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
    printf("Task %d added successfully.\n", id);
}

void deleteTask(int id) {

    if (first == NULL) {
        printf("No tasks in the schedule to delete.\n");
        return;
    }

    MaintenanceTask *temp = first, *prev = NULL;

    while (temp != NULL) {

        if (temp->taskID == id) {

            if (prev == NULL) {

                first = temp->next;
            } else {
                prev->next = temp->next;
            }
            printf("Task %d - '%s' for machine '%s' completed and removed from the schedule.\n",
                   temp->taskID, temp->description, temp->machineName);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Task ID %d not found in the schedule.\n", id);
}

void displaySchedule(void) {
    if (first == NULL) {
        printf("No tasks in the schedule.\n");
        return;
    }

    MaintenanceTask *temp = first;
    printf("\nMaintenance Schedule:\n");
    printf("Task ID\tDescription\t\tMachine Name\n");
    printf("------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%d\t%-20s\t%s\n", temp->taskID, temp->description, temp->machineName);
        temp = temp->next;
    }
}
