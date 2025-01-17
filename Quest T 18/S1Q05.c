// 5.Space Mission Task Manager: Design a stack-based task manager for space missions using arrays. Include a switch-case menu with options:
// 1: Add a task (push)
// 2: Mark the last task as completed (pop)
// 3: List all pending tasks
// 4: Peek at the most recent task
// 5: Search for a specific task
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char **tasks;    
    int top;         
    int capacity;    
} TaskStack;

void initializeStack(TaskStack *s, int initialCapacity);
int isFull(TaskStack *s);
int isEmpty(TaskStack *s);
void addTask(TaskStack *s, char *task);
void markTaskAsCompleted(TaskStack *s);
void listTasks(TaskStack *s);
void peek(TaskStack *s);
void searchTask(TaskStack *s, char *task);
void freeStack(TaskStack *s);

int main() {

    TaskStack stack;
    int initialCapacity = 10;  
    initializeStack(&stack, initialCapacity);

    int choice;
    char task[256];  

    while (1) {
        
        printf("\nSpace Mission Task Manager Menu:\n");
        printf("1: Add a task (push)\n");
        printf("2: Mark the last task as completed (pop)\n");
        printf("3: List all pending tasks\n");
        printf("4: Peek at the most recent task\n");
        printf("5: Search for a specific task\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {

            case 1:
            printf("Enter task description: ");
            fgets(task, sizeof(task), stdin);
            task[strcspn(task, "\n")] = 0;  
            addTask(&stack, task);
            break;

            case 2:
            markTaskAsCompleted(&stack);
            break;

            case 3:
            listTasks(&stack);
            break;

            case 4:
            peek(&stack);
            break;

            case 5:
            printf("Enter task description to search for: ");
            fgets(task, sizeof(task), stdin);
            task[strcspn(task, "\n")] = 0;
            searchTask(&stack, task);
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

void initializeStack(TaskStack *s, int initialCapacity) {

    s->tasks = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->tasks) {

        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = initialCapacity;
}

int isFull(TaskStack *s) {

    return s->top == s->capacity - 1;
}

int isEmpty(TaskStack *s) {

    return s->top == -1;
}

void addTask(TaskStack *s, char *task) {

    if (isFull(s)) {

        s->capacity *= 2;
        s->tasks = (char **)realloc(s->tasks, s->capacity * sizeof(char *));

        if (!s->tasks) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    s->tasks[++s->top] = (char *)malloc(strlen(task) + 1);
    
    if (!s->tasks[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(s->tasks[s->top], task);
    printf("Task added: %s\n", task);
}

void markTaskAsCompleted(TaskStack *s) {

    if (isEmpty(s)) {

        printf("No pending tasks to complete.\n");

    } else {

        printf("Task completed: %s\n", s->tasks[s->top]);
        free(s->tasks[s->top]);
        s->top--;
    }
}

void listTasks(TaskStack *s) {

    if (isEmpty(s)) {

        printf("No tasks pending.\n");

    } else {
        printf("Pending tasks:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->tasks[i]);
        }
    }
}

void peek(TaskStack *s) {

    if (isEmpty(s)) {

        printf("No tasks to peek at.\n");

    } else {

        printf("Most recent task: %s\n", s->tasks[s->top]);
    }
}

void searchTask(TaskStack *s, char *task) {

    if (isEmpty(s)) {

        printf("No tasks available to search.\n");

    } else {
        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->tasks[i], task) == 0) {

                printf("Task '%s' found at position %d.\n", task, i + 1);
                return;
            }
        }
        printf("Task '%s' not found.\n", task);
    }
}

void freeStack(TaskStack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->tasks[i]);
    }
    free(s->tasks);
}
