// 10.Shipping Status Tracker: Develop a stack to track shipping status updates using a linked list. Implement a switch-case menu with options:
// 1: Add a shipping status update (push)
// 2: Remove the last update (pop)
// 3: View all shipping status updates
// 4: Peek at the latest update
// 5: Search for a specific update
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ShippingStatus {

    char update[100];
    struct ShippingStatus *next;

} ShippingStatus;

typedef struct {

    ShippingStatus *top;

} ShippingStack;

void initializeStack(ShippingStack *stack);
int isEmpty(ShippingStack *stack);
void push(ShippingStack *stack, const char *update);
void pop(ShippingStack *stack);
void display(ShippingStack *stack);
void peek(ShippingStack *stack);
void search(ShippingStack *stack, const char *update);
void freeStack(ShippingStack *stack);

int main() {

    ShippingStack stack;
    initializeStack(&stack);

    int choice;
    char update[100];

    while (1) {

        printf("\nShipping Status Tracker Menu:\n");
        printf("1: Add a shipping status update (push)\n");
        printf("2: Remove the last update (pop)\n");
        printf("3: View all shipping status updates\n");
        printf("4: Peek at the latest update\n");
        printf("5: Search for a specific update\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
            printf("Enter Shipping Status Update: ");
            scanf(" %[^\n]s", update);
            push(&stack, update);
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
            printf("Enter the update to search: ");
            scanf(" %[^\n]s", update);
            search(&stack, update);
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



void initializeStack(ShippingStack *stack) {

    stack->top = NULL;

}

int isEmpty(ShippingStack *stack) {

    return stack->top == NULL;

}

void push(ShippingStack *stack, const char *update) {

    ShippingStatus *newStatus = (ShippingStatus *)malloc(sizeof(ShippingStatus));

    if (!newStatus) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    strcpy(newStatus->update, update);
    newStatus->next = stack->top;
    stack->top = newStatus;
    printf("Shipping status update added: %s\n", update);
}

void pop(ShippingStack *stack) {

    if (isEmpty(stack)) {

        printf("No updates to remove. Stack is empty.\n");

    } else {

        ShippingStatus *temp = stack->top;
        printf("Shipping status update removed: %s\n", temp->update);
        stack->top = stack->top->next;
        free(temp);

    }

}

void display(ShippingStack *stack) {

    if (isEmpty(stack)) {

        printf("No shipping status updates available.\n");

    } else {

        ShippingStatus *current = stack->top;
        printf("Shipping Status Updates:\n");

        while (current) {

            printf("- %s\n", current->update);
            current = current->next;

        }

    }

}

void peek(ShippingStack *stack) {

    if (isEmpty(stack)) {

        printf("No current shipping status update. Stack is empty.\n");

    } else {

        printf("Latest shipping status update: %s\n", stack->top->update);

    }

}

void search(ShippingStack *stack, const char *update) {

    if (isEmpty(stack)) {

        printf("No shipping status updates available to search.\n");

    } else {

        ShippingStatus *current = stack->top;

        while (current) {

            if (strcmp(current->update, update) == 0) {

                printf("Shipping status update found: %s\n", current->update);
                return;

            }

            current = current->next;

        }

        printf("Shipping status update '%s' not found.\n", update);

    }

}

void freeStack(ShippingStack *stack) {

    ShippingStatus *current = stack->top;

    while (current) {

        ShippingStatus *temp = current;
        current = current->next;
        free(temp);

    }

}
