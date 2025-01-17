// 11.Pilot Training Maneuver Stack: Use a stack to keep track of training maneuvers for pilots. Implement a switch-case menu with options:
// 1: Add a maneuver (push)
// 2: Remove the last maneuver (pop)
// 3: View all maneuvers
// 4: Peek at the most recent maneuver
// 5: Search for a specific maneuver
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char **maneuvers;  
    int top;            
    int capacity;       

} ManeuverStack;

void initializeStack(ManeuverStack *s, int initialCapacity);
int isFull(ManeuverStack *s);
int isEmpty(ManeuverStack *s);
void pushManeuver(ManeuverStack *s, char *maneuver);
void popManeuver(ManeuverStack *s);
void viewManeuvers(ManeuverStack *s);
void peekMostRecentManeuver(ManeuverStack *s);
void searchManeuver(ManeuverStack *s, char *maneuver);
void freeStack(ManeuverStack *s);

int main() {
    ManeuverStack stack;
    int initialCapacity = 10;  
    initializeStack(&stack, initialCapacity);

    int choice;
    char maneuver[256];  
    while (1) {
        
        printf("\nPilot Training Maneuver Stack Menu:\n");
        printf("1: Add a maneuver (push)\n");
        printf("2: Remove the last maneuver (pop)\n");
        printf("3: View all maneuvers\n");
        printf("4: Peek at the most recent maneuver\n");
        printf("5: Search for a specific maneuver\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {

            case 1:
            printf("Enter maneuver description: ");
            fgets(maneuver, sizeof(maneuver), stdin);
            maneuver[strcspn(maneuver, "\n")] = 0;  
            pushManeuver(&stack, maneuver);
            break;

            case 2:
            popManeuver(&stack);
            break;

            case 3:
            viewManeuvers(&stack);
            break;

            case 4:
            peekMostRecentManeuver(&stack);
            break;

            case 5:
            printf("Enter maneuver description to search for: ");
            fgets(maneuver, sizeof(maneuver), stdin);
            maneuver[strcspn(maneuver, "\n")] = 0;  
            searchManeuver(&stack, maneuver);
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

void initializeStack(ManeuverStack *s, int initialCapacity) {

    s->maneuvers = (char **)malloc(initialCapacity * sizeof(char *));
    
    if (!s->maneuvers) {
    
        printf("Memory allocation failed!\n");
        exit(1);
    
    }
    
    s->top = -1;
    s->capacity = initialCapacity;
}

int isFull(ManeuverStack *s) {

    return s->top == s->capacity - 1;

}

int isEmpty(ManeuverStack *s) {

    return s->top == -1;

}

void pushManeuver(ManeuverStack *s, char *maneuver) {

    if (isFull(s)) {

        s->capacity *= 2;
        s->maneuvers = (char **)realloc(s->maneuvers, s->capacity * sizeof(char *));

        if (!s->maneuvers) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    s->maneuvers[++s->top] = (char *)malloc(strlen(maneuver) + 1);

    if (!s->maneuvers[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);

    }
    strcpy(s->maneuvers[s->top], maneuver);
    printf("Maneuver added: %s\n", maneuver);
}

void popManeuver(ManeuverStack *s) {

    if (isEmpty(s)) {

        printf("No maneuvers to pop. The stack is empty.\n");

    } else {

        printf("Maneuver popped: %s\n", s->maneuvers[s->top]);
        free(s->maneuvers[s->top]);
        s->top--;

    }
}

void viewManeuvers(ManeuverStack *s) {

    if (isEmpty(s)) {

        printf("No maneuvers in the stack.\n");

    } else {

        printf("All maneuvers in the stack:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->maneuvers[i]);

        }
    }
}

void peekMostRecentManeuver(ManeuverStack *s) {

    if (isEmpty(s)) {

        printf("No maneuvers to peek at.\n");

    } else {

        printf("Most recent maneuver: %s\n", s->maneuvers[s->top]);

    }
}

void searchManeuver(ManeuverStack *s, char *maneuver) {

    if (isEmpty(s)) {

        printf("No maneuvers in the stack to search.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {


            if (strcmp(s->maneuvers[i], maneuver) == 0) {

                printf("Maneuver '%s' found at position %d.\n", maneuver, i + 1);
                return;

            }

        }

        printf("Maneuver '%s' not found.\n", maneuver);
    }
}

void freeStack(ManeuverStack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->maneuvers[i]);

    }

    free(s->maneuvers);

}
