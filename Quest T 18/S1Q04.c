// 4.Telemetry Data Storage: Implement a stack to store telemetry data from an aerospace vehicle. Use a switch-case menu with options:
// 1: Push new telemetry data
// 2: Pop the last data entry
// 3: View the stored telemetry data
// 4: Peek at the most recent data entry
// 5: Search for specific telemetry data
// 6: Exit



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char **data;    
    int top;        
    int capacity;   

} Stack;

void initializeStack(Stack *s, int initialCapacity);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char *entry);
void pop(Stack *s);
void displayStack(Stack *s);
void peek(Stack *s);
void search(Stack *s, char *entry);
void freeStack(Stack *s);

int main() {

    Stack stack;
    int initialCapacity = 10; 
    initializeStack(&stack, initialCapacity);

    int choice;
    char entry[256];  

    while (1) {
        
        printf("\nTelemetry Data Storage Menu:\n");
        printf("1: Push new telemetry data\n");
        printf("2: Pop the last data entry\n");
        printf("3: View the stored telemetry data\n");
        printf("4: Peek at the most recent data entry\n");
        printf("5: Search for specific telemetry data\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {

            case 1:
            printf("Enter telemetry data: ");
            fgets(entry, sizeof(entry), stdin);
            entry[strcspn(entry, "\n")] = 0;  
            push(&stack, entry);
            break;

            case 2:
            pop(&stack);
            break;

            case 3:
            displayStack(&stack);
            break;

            case 4:
            peek(&stack);
            break;

            case 5:
            printf("Enter telemetry data to search for: ");
            fgets(entry, sizeof(entry), stdin);
            entry[strcspn(entry, "\n")] = 0;
            search(&stack, entry);
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

void initializeStack(Stack *s, int initialCapacity) {

    s->data = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->data) {

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


void push(Stack *s, char *entry) {

    if (isFull(s)) {

        s->capacity *= 2;
        s->data = (char **)realloc(s->data, s->capacity * sizeof(char *));

        if (!s->data) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    s->data[++s->top] = (char *)malloc(strlen(entry) + 1);

    if (!s->data[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(s->data[s->top], entry);
    printf("Telemetry data pushed: %s\n", entry);
}

void pop(Stack *s) {

    if (isEmpty(s)) {

        printf("No data to pop. The stack is empty.\n");

    } else {

        printf("Telemetry data popped: %s\n", s->data[s->top]);
        free(s->data[s->top]);
        s->top--;
    }
}

void displayStack(Stack *s) {
    
    if (isEmpty(s)) {
        
        printf("No telemetry data available.\n");
    
    } else {
        
        printf("Stored telemetry data:\n");

        for (int i = 0; i <= s->top; i++) {
            printf("%d: %s\n", i + 1, s->data[i]);
        }
    }
}

void peek(Stack *s) {

    if (isEmpty(s)) {

        printf("No telemetry data to peek at.\n");

    } else {

        printf("Most recent telemetry data: %s\n", s->data[s->top]);
    }
}

void search(Stack *s, char *entry) {

    if (isEmpty(s)) {

        printf("No telemetry data available to search.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->data[i], entry) == 0) {

                printf("Telemetry data '%s' found at position %d.\n", entry, i + 1);
                return;
            }
        }
        printf("Telemetry data '%s' not found.\n", entry);
    }
}

void freeStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        free(s->data[i]);
    }
    free(s->data);
}
