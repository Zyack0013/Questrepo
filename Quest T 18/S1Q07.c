// 7.Aircraft Maintenance Logs: Implement a stack to keep track of maintenance logs for an aircraft. Use a switch-case menu with options:
// 1: Add a new log (push)
// 2: Remove the last log (pop)
// 3: View all maintenance logs
// 4: Peek at the latest maintenance log
// 5: Search for a specific maintenance log
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    char **logs;    
    int top;        
    int capacity;   

} MaintenanceStack;

void initializeStack(MaintenanceStack *s, int initialCapacity);
int isFull(MaintenanceStack *s);
int isEmpty(MaintenanceStack *s);
void addLog(MaintenanceStack *s, char *log);
void removeLog(MaintenanceStack *s);
void viewLogs(MaintenanceStack *s);
void peekLatestLog(MaintenanceStack *s);
void searchLog(MaintenanceStack *s, char *log);
void freeStack(MaintenanceStack *s);

int main() {

    MaintenanceStack stack;
    int initialCapacity = 10; 
    initializeStack(&stack, initialCapacity);

    int choice;
    char log[256];  

    while (1) {

        printf("\nAircraft Maintenance Logs Menu:\n");
        printf("1: Add a new log (push)\n");
        printf("2: Remove the last log (pop)\n");
        printf("3: View all maintenance logs\n");
        printf("4: Peek at the latest maintenance log\n");
        printf("5: Search for a specific maintenance log\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            
            case 1:
            printf("Enter maintenance log: ");
            fgets(log, sizeof(log), stdin);
            log[strcspn(log, "\n")] = 0; 
            addLog(&stack, log);
            break;
            
            case 2:
            removeLog(&stack);
            break;
            
            case 3:
            viewLogs(&stack);
            break;
            
            case 4:
            peekLatestLog(&stack);
            break;
            
            case 5:
            printf("Enter maintenance log to search for: ");
            fgets(log, sizeof(log), stdin);
            log[strcspn(log, "\n")] = 0;
            searchLog(&stack, log);
            break;
            
            case 6:
            printf("Exiting program.\n");
            freeStack(&stack);  
            exit(0);
            
            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}

void initializeStack(MaintenanceStack *s, int initialCapacity) {

    s->logs = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->logs) {

        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = initialCapacity;
}

int isFull(MaintenanceStack *s) {

    return s->top == s->capacity - 1;
}

int isEmpty(MaintenanceStack *s) {

    return s->top == -1;
}

void addLog(MaintenanceStack *s, char *log) {

    if (isFull(s)) {

        s->capacity *= 2;
        s->logs = (char **)realloc(s->logs, s->capacity * sizeof(char *));

        if (!s->logs) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    s->logs[++s->top] = (char *)malloc(strlen(log) + 1);

    if (!s->logs[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(s->logs[s->top], log);
    printf("Maintenance log added: %s\n", log);
}

void removeLog(MaintenanceStack *s) {

    if (isEmpty(s)) {

        printf("No maintenance logs to remove. The stack is empty.\n");

    } else {

        printf("Maintenance log removed: %s\n", s->logs[s->top]);
        free(s->logs[s->top]);
        s->top--;
    }
}

void viewLogs(MaintenanceStack *s) {

    if (isEmpty(s)) {

        printf("No maintenance logs available.\n");

    } else {

        printf("Maintenance logs:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->logs[i]);
        }
    }
}

void peekLatestLog(MaintenanceStack *s) {

    if (isEmpty(s)) {

        printf("No maintenance logs available to peek at.\n");

    } else {

        printf("Latest maintenance log: %s\n", s->logs[s->top]);

    }
}

void searchLog(MaintenanceStack *s, char *log) {

    if (isEmpty(s)) {

        printf("No maintenance logs available to search.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->logs[i], log) == 0) {

                printf("Maintenance log '%s' found at position %d.\n", log, i + 1);
                return;
            }
        }
        printf("Maintenance log '%s' not found.\n", log);
    }
}

void freeStack(MaintenanceStack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->logs[i]);
    }
    free(s->logs);
}
