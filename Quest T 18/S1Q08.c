// 8.Spacecraft Docking Procedure: Develop a stack for the sequence of steps in a spacecraft docking procedure. Implement a switch-case menu with options:
// 1: Push a new step
// 2: Pop the last step
// 3: Display the procedure steps
// 4: Peek at the next step in the procedure
// 5: Search for a specific step
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    char **steps;   
    int top;         
    int capacity;   

} DockingStack;

void initializeStack(DockingStack *s, int initialCapacity);
int isFull(DockingStack *s);
int isEmpty(DockingStack *s);
void addStep(DockingStack *s, char *step);
void removeStep(DockingStack *s);
void displaySteps(DockingStack *s);
void peekNextStep(DockingStack *s);
void searchStep(DockingStack *s, char *step);
void freeStack(DockingStack *s);

int main() {

    DockingStack stack;
    int initialCapacity = 10; 
    initializeStack(&stack, initialCapacity);

    int choice;
    char step[256];  
    while (1) {

        printf("\nSpacecraft Docking Procedure Menu:\n");
        printf("1: Push a new step\n");
        printf("2: Pop the last step\n");
        printf("3: Display the procedure steps\n");
        printf("4: Peek at the next step in the procedure\n");
        printf("5: Search for a specific step\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  
        switch (choice) {

            case 1:
            printf("Enter spacecraft docking procedure step: ");
            fgets(step, sizeof(step), stdin);
            step[strcspn(step, "\n")] = 0;  
            addStep(&stack, step);
            break;

            case 2:
            removeStep(&stack);
            break;

            case 3:
            displaySteps(&stack);
            break;

            case 4:
            peekNextStep(&stack);
            break;

            case 5:
            printf("Enter procedure step to search for: ");
            fgets(step, sizeof(step), stdin);
            step[strcspn(step, "\n")] = 0;
            searchStep(&stack, step);
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

void initializeStack(DockingStack *s, int initialCapacity) {

    s->steps = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->steps) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    s->top = -1;
    s->capacity = initialCapacity;
}

int isFull(DockingStack *s) {

    return s->top == s->capacity - 1;

}

int isEmpty(DockingStack *s) {

    return s->top == -1;

}


void addStep(DockingStack *s, char *step) {

    if (isFull(s)) {

        s->capacity *= 2;
        s->steps = (char **)realloc(s->steps, s->capacity * sizeof(char *));

        if (!s->steps) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    s->steps[++s->top] = (char *)malloc(strlen(step) + 1);

    if (!s->steps[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);

    }
    strcpy(s->steps[s->top], step);
    printf("Docking step added: %s\n", step);

}

void removeStep(DockingStack *s) {

    if (isEmpty(s)) {

        printf("No docking procedure steps to remove. The stack is empty.\n");
    
    } else {
    
        printf("Docking step removed: %s\n", s->steps[s->top]);
        free(s->steps[s->top]);
        s->top--;
    
    }
}

void displaySteps(DockingStack *s) {

    if (isEmpty(s)) {

        printf("No docking procedure steps available.\n");

    } else {

        printf("Docking procedure steps:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->steps[i]);
        }
    }
}

void peekNextStep(DockingStack *s) {

    if (isEmpty(s)) {

        printf("No docking procedure steps to peek at.\n");

    } else {

        printf("Next docking procedure step: %s\n", s->steps[s->top]);
    }
}

void searchStep(DockingStack *s, char *step) {

    if (isEmpty(s)) {

        printf("No docking procedure steps available to search.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->steps[i], step) == 0) {

                printf("Docking step '%s' found at position %d.\n", step, i + 1);
                return;
            }
        }
        printf("Docking step '%s' not found.\n", step);
    }
}

void freeStack(DockingStack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->steps[i]);
    }
    free(s->steps);
}
