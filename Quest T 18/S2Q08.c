// 8.Checkout Process Steps: Implement a stack to manage steps in the checkout process using a linked list. Include a switch-case menu with options:
// 1: Add a checkout step (push)
// 2: Remove the last step (pop)
// 3: Display all checkout steps
// 4: Peek at the current step
// 5: Search for a specific step
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct CheckoutStep {

    int stepID;
    char stepDescription[100];
    struct CheckoutStep *next;

} CheckoutStep;

typedef struct {

    CheckoutStep *top;

} CheckoutStack;

void initializeStack(CheckoutStack *stack);
int isEmpty(CheckoutStack *stack);
void push(CheckoutStack *stack, int stepID, const char *stepDescription);
void pop(CheckoutStack *stack);
void display(CheckoutStack *stack);
void peek(CheckoutStack *stack);
void search(CheckoutStack *stack, int stepID);
void freeStack(CheckoutStack *stack);

int main() {

    CheckoutStack stack;
    initializeStack(&stack);

    int choice, stepID;
    char stepDescription[100];

    while (1) {

        printf("\nCheckout Process Steps Menu:\n");
        printf("1: Add a checkout step (push)\n");
        printf("2: Remove the last step (pop)\n");
        printf("3: Display all checkout steps\n");
        printf("4: Peek at the current step\n");
        printf("5: Search for a specific step\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
            printf("Enter Step ID: ");
            scanf("%d", &stepID);
            printf("Enter Step Description: ");
            scanf(" %[^\n]s", stepDescription);
            push(&stack, stepID, stepDescription);
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
            printf("Enter Step ID to search: ");
            scanf("%d", &stepID);
            search(&stack, stepID);
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



void initializeStack(CheckoutStack *stack) {

    stack->top = NULL;

}

int isEmpty(CheckoutStack *stack) {

    return stack->top == NULL;

}

void push(CheckoutStack *stack, int stepID, const char *stepDescription) {

    CheckoutStep *newStep = (CheckoutStep *)malloc(sizeof(CheckoutStep));

    if (!newStep) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    newStep->stepID = stepID;
    strcpy(newStep->stepDescription, stepDescription);
    newStep->next = stack->top;
    stack->top = newStep;
    printf("Checkout step added: ID %d, Description: %s\n", stepID, stepDescription);

}

void pop(CheckoutStack *stack) {

    if (isEmpty(stack)) {

        printf("No steps to remove. Stack is empty.\n");

    } else {

        CheckoutStep *temp = stack->top;
        printf("Checkout step removed: ID %d, Description: %s\n", temp->stepID, temp->stepDescription);
        stack->top = stack->top->next;
        free(temp);

    }

}

void display(CheckoutStack *stack) {

    if (isEmpty(stack)) {

        printf("No checkout steps available.\n");

    } else {

        CheckoutStep *current = stack->top;
        printf("Checkout steps:\n");

        while (current) {

            printf("ID: %d, Description: %s\n", current->stepID, current->stepDescription);
            current = current->next;

        }

    }

}

void peek(CheckoutStack *stack) {

    if (isEmpty(stack)) {

        printf("No current step. Stack is empty.\n");

    } else {

        printf("Current step: ID %d, Description: %s\n", stack->top->stepID, stack->top->stepDescription);

    }

}

void search(CheckoutStack *stack, int stepID) {

    if (isEmpty(stack)) {

        printf("No steps available to search.\n");

    } else {

        CheckoutStep *current = stack->top;

        while (current) {

            if (current->stepID == stepID) {

                printf("Step found: ID %d, Description: %s\n", current->stepID, current->stepDescription);
                return;

            }

            current = current->next;

        }

        printf("Step with ID %d not found.\n", stepID);
    }

}

void freeStack(CheckoutStack *stack) {

    CheckoutStep *current = stack->top;

    while (current) {

        CheckoutStep *temp = current;
        current = current->next;
        free(temp);

    }

}
