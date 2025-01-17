// 1.Flight Path Logging System: Implement a stack-based system using arrays to record the sequence of flight paths an aircraft takes. Use a switch-case menu with options:
// 1: Add a new path (push)
// 2: Undo the last path (pop)
// 3: Display the current flight path stack
// 4: Peek at the top path
// 5: Search for a specific path
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    int capacity;  
    int top;
    char **paths;       
      
} Stack;

void initializeStack(Stack *s, int initialCapacity);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char *path);
void pop(Stack *s);
void display(Stack *s);
void peek(Stack *s);
void search(Stack *s, char *path);
void freeStack(Stack *s);

int main() {

    Stack stack;
    int initialCapacity = 10;  
    initializeStack(&stack, initialCapacity);

    int choice;
    char path[100];

    while (1) {

        printf("\nFlight Path Logging System:\n");
        printf("1: Add a new path (push)\n");
        printf("2: Undo the last path (pop)\n");
        printf("3: Display the current flight path stack\n");
        printf("4: Peek at the top path\n");
        printf("5: Search for a specific path\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
            printf("Enter the flight path to add: ");
            fgets(path, sizeof(path), stdin);
            path[strcspn(path, "\n")] = 0; 
            push(&stack, path);
            break;

            case 2:
            pop(&stack);
            break;

            case 3:
            display(&stack);
            break;

            case 4:
            peek(&stack);
            break;

            case 5:
            printf("Enter the flight path to search: ");
            fgets(path, sizeof(path), stdin);
            path[strcspn(path, "\n")] = 0; 
            search(&stack, path);
            break;

            case 6:
            printf("Exiting the program.\n");
            freeStack(&stack); 
            return 0;

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}

void initializeStack(Stack *s, int initialCapacity) {

    s->paths = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->paths) {

        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = initialCapacity;
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char *path) {

    if (isFull(s)) {

        s->capacity *= 2;
        s->paths = (char **)realloc(s->paths, s->capacity * sizeof(char *));

        if (!s->paths) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    s->paths[++s->top] = (char *)malloc(strlen(path) + 1);

    if (!s->paths[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(s->paths[s->top], path);
    printf("Flight path added: %s\n", path);
}

void pop(Stack *s) {

    if (isEmpty(s)) {

        printf("Stack underflow! No paths to undo.\n");

    } else {

        printf("Flight path removed: %s\n", s->paths[s->top]);
        free(s->paths[s->top]);
        s->top--;
    }
}

void display(Stack *s) {

    if (isEmpty(s)) {

        printf("No flight paths in the stack.\n");

    } else {

        printf("Current flight paths:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->paths[i]);

        }
    }
}

void peek(Stack *s) {

    if (isEmpty(s)) {

        printf("No flight paths in the stack.\n");

    } else {

        printf("Top flight path: %s\n", s->paths[s->top]);
    }
}

void search(Stack *s, char *path) {

    if (isEmpty(s)) {

        printf("No flight paths in the stack.\n");
    } else {

        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->paths[i], path) == 0) {

                printf("Flight path found at position: %d\n", i + 1);
                return;
            }
        }
        printf("Flight path not found.\n");
    }
}

void freeStack(Stack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->paths[i]);
    }
    free(s->paths);
}
