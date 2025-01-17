// 2.Satellite Deployment Sequence: Develop a stack using arrays to manage the sequence of satellite deployments from a spacecraft. Include a switch-case menu with options:
// 1: Push a new satellite deployment
// 2: Pop the last deployment
// 3: View the deployment sequence
// 4: Peek at the latest deployment
// 5: Search for a specific deployment
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    int capacity; 
    int top;     
    char **deployments;         
           
} Stack;

void initializeStack(Stack *s, int initialCapacity);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char *deployment);
void pop(Stack *s);
void viewStack(Stack *s);
void peek(Stack *s);
void search(Stack *s, char *deployment);
void freeStack(Stack *s);

int main() {

    Stack stack;
    int initialCapacity = 10; 
    initializeStack(&stack, initialCapacity);

    int choice;
    char deployment[100];

    while (1) {

        printf("\nSatellite Deployment Sequence:\n");
        printf("1: Push a new satellite deployment\n");
        printf("2: Pop the last deployment\n");
        printf("3: View the deployment sequence\n");
        printf("4: Peek at the latest deployment\n");
        printf("5: Search for a specific deployment\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
            printf("Enter the satellite name to deploy: ");
            fgets(deployment, sizeof(deployment), stdin);
            deployment[strcspn(deployment, "\n")] = 0; 
            push(&stack, deployment);
            break;

            case 2:
            pop(&stack);
            break;

            case 3:
            viewStack(&stack);
            break;

            case 4:
            peek(&stack);
            break;

            case 5:
            printf("Enter the satellite name to search for: ");
            fgets(deployment, sizeof(deployment), stdin);
            deployment[strcspn(deployment, "\n")] = 0; 
            search(&stack, deployment);
            break;

            case 6:
            printf("Exiting the program.\n");
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

    s->deployments = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->deployments) {
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

void push(Stack *s, char *deployment) {

    if (isFull(s)) {
        
        s->capacity *= 2;
        s->deployments = (char **)realloc(s->deployments, s->capacity * sizeof(char *));

        if (!s->deployments) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    s->deployments[++s->top] = (char *)malloc(strlen(deployment) + 1);
    if (!s->deployments[s->top]) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(s->deployments[s->top], deployment);
    printf("Satellite deployed: %s\n", deployment);
}

void pop(Stack *s) {

    if (isEmpty(s)) {

        printf("No deployments to remove. The stack is empty.\n");

    } else {

        printf("Satellite deployment removed: %s\n", s->deployments[s->top]);
        free(s->deployments[s->top]);
        s->top--;
    }
}

void viewStack(Stack *s) {

    if (isEmpty(s)) {

        printf("No satellite deployments in the sequence.\n");

    } else {

        printf("Current satellite deployment sequence:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->deployments[i]);
        }
    }
}

void peek(Stack *s) {

    if (isEmpty(s)) {

        printf("No satellite deployments in the sequence.\n");

    } else {

        printf("Latest satellite deployed: %s\n", s->deployments[s->top]);
    }
}

void search(Stack *s, char *deployment) {

    if (isEmpty(s)) {

        printf("No satellite deployments in the sequence.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->deployments[i], deployment) == 0) {

                printf("Satellite '%s' found at position: %d\n", deployment, i + 1);
                return;
            }
        }
        printf("Satellite '%s' not found in the sequence.\n", deployment);
    }
}

void freeStack(Stack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->deployments[i]);

    }

    free(s->deployments);
}
