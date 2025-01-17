// 10.Aerospace Simulation Events: Implement a stack to handle events in an aerospace simulation. Include a switch-case menu with options:
// 1: Push a new event
// 2: Pop the last event
// 3: Display all events
// 4: Peek at the most recent event
// 5: Search for a specific event
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char **events;  
    int top;         
    int capacity;    
} EventStack;


void initializeStack(EventStack *s, int initialCapacity);
int isFull(EventStack *s);
int isEmpty(EventStack *s);
void pushEvent(EventStack *s, char *event);
void popEvent(EventStack *s);
void displayEvents(EventStack *s);
void peekMostRecentEvent(EventStack *s);
void searchEvent(EventStack *s, char *event);
void freeStack(EventStack *s);

int main() {

    EventStack stack;
    int initialCapacity = 10;  
    initializeStack(&stack, initialCapacity);

    int choice;
    char event[256];  

    while (1) {
        
        printf("\nAerospace Simulation Events Menu:\n");
        printf("1: Push a new event\n");
        printf("2: Pop the last event\n");
        printf("3: Display all events\n");
        printf("4: Peek at the most recent event\n");
        printf("5: Search for a specific event\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
            printf("Enter event description: ");
            fgets(event, sizeof(event), stdin);
            event[strcspn(event, "\n")] = 0;  
            pushEvent(&stack, event);
            break;

            case 2:
            popEvent(&stack);
            break;

            case 3:
            displayEvents(&stack);
            break;

            case 4:
            peekMostRecentEvent(&stack);
            break;

            case 5:
            printf("Enter event description to search for: ");
            fgets(event, sizeof(event), stdin);
            event[strcspn(event, "\n")] = 0;  
            searchEvent(&stack, event);
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

void initializeStack(EventStack *s, int initialCapacity) {

    s->events = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->events) {

        printf("Memory allocation failed!\n");
        exit(1);
    }

    s->top = -1;
    s->capacity = initialCapacity;
}

int isFull(EventStack *s) {

    return s->top == s->capacity - 1;
}

int isEmpty(EventStack *s) {

    return s->top == -1;
}

void pushEvent(EventStack *s, char *event) {
    if (isFull(s)) {

        s->capacity *= 2;
        s->events = (char **)realloc(s->events, s->capacity * sizeof(char *));

        if (!s->events) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    s->events[++s->top] = (char *)malloc(strlen(event) + 1);

    if (!s->events[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(s->events[s->top], event);
    printf("Event added: %s\n", event);
}

void popEvent(EventStack *s) {

    if (isEmpty(s)) {

        printf("No events to pop. The stack is empty.\n");

    } else {

        printf("Event popped: %s\n", s->events[s->top]);
        free(s->events[s->top]);
        s->top--;
    }
}

void displayEvents(EventStack *s) {

    if (isEmpty(s)) {

        printf("No events in the stack.\n");

    } else {

        printf("All events in the stack:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->events[i]);
        }
    }
}

void peekMostRecentEvent(EventStack *s) {

    if (isEmpty(s)) {

        printf("No events to peek at.\n");

    } else {

        printf("Most recent event: %s\n", s->events[s->top]);

    }
}

void searchEvent(EventStack *s, char *event) {

    if (isEmpty(s)) {

        printf("No events in the stack to search.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->events[i], event) == 0) {

                printf("Event '%s' found at position %d.\n", event, i + 1);
                return;
            }
        }
        printf("Event '%s' not found.\n", event);
    }
}

void freeStack(EventStack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->events[i]);

    }

    free(s->events);

}
