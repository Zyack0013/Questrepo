// Problem 2: Production Line Queue
// Description: Use a linked list to manage the queue of tasks on a production line.
// Operations:
// Create a production task queue.
// Insert a new task into the queue.
// Delete a completed task.
// Display the current task queue.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int taskID;
    char description[100];
    struct Task *next;
} Task;

Task *front = NULL; 
Task *rear = NULL;  

void createQueue(void);
void insertTask(int id, const char *desc);
void deleteTask(void);
void displayQueue(void);

int main() {

    int choice, id;
    char description[100];

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a new task queue\n");
        printf("2. Insert a new task into the queue\n");
        printf("3. Delete a completed task\n");
        printf("4. Display the current task queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
            createQueue();
            break;

            case 2:
            printf("Enter Task ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter Task Description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = '\0'; 
            insertTask(id, description);
            break;

            case 3:
            deleteTask();
            break;

            case 4:
            displayQueue();
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

void createQueue(void) {

    if (front != NULL) {

        printf("Task queue already exists.\n");
        return;
    }

    int n, id;
    char description[100];
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {

        printf("Enter Task ID: ");
        scanf("%d", &id);
        getchar();
        printf("Enter Task Description: ");
        fgets(description, sizeof(description), stdin);
        description[strcspn(description, "\n")] = '\0'; 
        insertTask(id, description);
    }
    printf("%d tasks added successfully.\n", n);
}

void insertTask(int id, const char *desc) {

    Task *newTask = (Task *)malloc(sizeof(Task));

    if (newTask == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    newTask->taskID = id;
    strcpy(newTask->description, desc);
    newTask->next = NULL;

    if (front == NULL) {
        front = rear = newTask; 
    } else {
        rear->next = newTask;
        rear = newTask;
    }
    printf("Task %d added successfully.\n", id);
}

void deleteTask(void) {

    if (front == NULL) {

        printf("No tasks to delete. The queue is empty.\n");
        return;
    }

    Task *temp = front;
    printf("Task %d - '%s' completed and removed from the queue.\n", front->taskID, front->description);
    front = front->next;
    free(temp);

    if (front == NULL) {

        rear = NULL;

    }
}

void displayQueue(void) {

    if (front == NULL) {

        printf("The task queue is empty.\n");
        return;
    }

    Task *temp = front;
    printf("\nCurrent Task Queue:\n");
    printf("Task ID\tDescription\n");

    while (temp != NULL) {

        printf("%d\t%s\n", temp->taskID, temp->description);
        temp = temp->next;
    }
}
