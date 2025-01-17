// 6.Launch Countdown Management: Use a stack to manage the countdown sequence for a rocket launch. Implement a switch-case menu with options:
// 1: Add a countdown step (push)
// 2: Remove the last step (pop)
// 3: Display the current countdown
// 4: Peek at the next countdown step
// 5: Search for a specific countdown step
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char **countdownSteps;  
    int top;                
    int capacity;    

} CountdownStack;

void initializeStack(CountdownStack *s, int initialCapacity);
int isFull(CountdownStack *s);
int isEmpty(CountdownStack *s);
void addCountdownStep(CountdownStack *s, char *step);
void removeCountdownStep(CountdownStack *s);
void displayCountdown(CountdownStack *s);
void peekNextStep(CountdownStack *s);
void searchCountdownStep(CountdownStack *s, char *step);
void freeStack(CountdownStack *s);

int main() {

    CountdownStack stack;
    int initialCapacity = 10; 
    initializeStack(&stack, initialCapacity);

    int choice;
    char step[256];  

    while (1) {
        
        printf("\nLaunch Countdown Management Menu:\n");
        printf("1: Add a countdown step (push)\n");
        printf("2: Remove the last countdown step (pop)\n");
        printf("3: Display the current countdown\n");
        printf("4: Peek at the next countdown step\n");
        printf("5: Search for a specific countdown step\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {

            case 1:
            printf("Enter countdown step: ");
            fgets(step, sizeof(step), stdin);
            step[strcspn(step, "\n")] = 0; 
            addCountdownStep(&stack, step);
            break;

            case 2:
            removeCountdownStep(&stack);
            break;

            case 3:
            displayCountdown(&stack);
            break;

            case 4:
            peekNextStep(&stack);
            break;

            case 5:
            printf("Enter countdown step to search for: ");
            fgets(step, sizeof(step), stdin);
            step[strcspn(step, "\n")] = 0;
            searchCountdownStep(&stack, step);
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

void initializeStack(CountdownStack *s, int initialCapacity) {

    s->countdownSteps = (char **)malloc(initialCapacity * sizeof(char *));
    if (!s->countdownSteps) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = initialCapacity;
}


int isFull(CountdownStack *s) {

    return s->top == s->capacity - 1;
}

int isEmpty(CountdownStack *s) {

    return s->top == -1;
}

void addCountdownStep(CountdownStack *s, char *step) {

    if (isFull(s)) {

        s->capacity *= 2;
        s->countdownSteps = (char **)realloc(s->countdownSteps, s->capacity * sizeof(char *));

        if (!s->countdownSteps) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    s->countdownSteps[++s->top] = (char *)malloc(strlen(step) + 1);

    if (!s->countdownSteps[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(s->countdownSteps[s->top], step);
    printf("Countdown step added: %s\n", step);
}

void removeCountdownStep(CountdownStack *s) {

    if (isEmpty(s)) {

        printf("No countdown step to remove. The stack is empty.\n");

    } else {

        printf("Countdown step removed: %s\n", s->countdownSteps[s->top]);
        free(s->countdownSteps[s->top]);
        s->top--;
    }
}

void displayCountdown(CountdownStack *s) {

    if (isEmpty(s)) {

        printf("No countdown steps available.\n");

    } else {

        printf("Current countdown:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->countdownSteps[i]);
        }
    }
}

void peekNextStep(CountdownStack *s) {

    if (isEmpty(s)) {

        printf("No countdown steps to peek at.\n");
    } else {

        printf("Next countdown step: %s\n", s->countdownSteps[s->top]);
    }
}

void searchCountdownStep(CountdownStack *s, char *step) {

    if (isEmpty(s)) {

        printf("No countdown steps available to search.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->countdownSteps[i], step) == 0) {

                printf("Countdown step '%s' found at position %d.\n", step, i + 1);
                return;
            }
        }
        printf("Countdown step '%s' not found.\n", step);
    }
}

void freeStack(CountdownStack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->countdownSteps[i]);

    }
    free(s->countdownSteps);
}
