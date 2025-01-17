// 12.Promotion Notification System: Create a stack for managing promotional notifications using a linked list. Use a switch-case menu with options:
// 1: Add a new notification (push)
// 2: Remove the last notification (pop)
// 3: View all notifications
// 4: Peek at the latest notification
// 5: Search for a specific notification
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Notification {
    char text[256];
    struct Notification *next;
} Notification;


typedef struct {
    Notification *top;
} NotificationStack;


void initializeStack(NotificationStack *stack);
int isEmpty(NotificationStack *stack);
void push(NotificationStack *stack, const char *text);
void pop(NotificationStack *stack);
void display(NotificationStack *stack);
void peek(NotificationStack *stack);
void search(NotificationStack *stack, const char *text);
void freeStack(NotificationStack *stack);

int main() {

    NotificationStack stack;
    initializeStack(&stack);

    int choice;
    char text[256];

    while (1) {
        
        printf("\nPromotion Notification System Menu:\n");
        printf("1: Add a new notification (push)\n");
        printf("2: Remove the last notification (pop)\n");
        printf("3: View all notifications\n");
        printf("4: Peek at the latest notification\n");
        printf("5: Search for a specific notification\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
            printf("Enter the notification text: ");
            scanf(" %[^\n]s", text);
            push(&stack, text);
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
            printf("Enter the notification text to search: ");
            scanf(" %[^\n]s", text);
            search(&stack, text);
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



void initializeStack(NotificationStack *stack) {

    stack->top = NULL;

}


int isEmpty(NotificationStack *stack) {

    return stack->top == NULL;

}



void push(NotificationStack *stack, const char *text) {

    Notification *newNotification = (Notification *)malloc(sizeof(Notification));

    if (!newNotification) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    strcpy(newNotification->text, text);
    newNotification->next = stack->top;
    stack->top = newNotification;
    printf("Notification added: %s\n", text);

}

void pop(NotificationStack *stack) {

    if (isEmpty(stack)) {

        printf("No notifications to remove. Stack is empty.\n");

    } else {

        Notification *temp = stack->top;
        printf("Notification removed: %s\n", temp->text);
        stack->top = stack->top->next;
        free(temp);

    }

}


void display(NotificationStack *stack) {

    if (isEmpty(stack)) {

        printf("No notifications available.\n");

    } else {

        Notification *current = stack->top;
        printf("Promotion Notifications:\n");

        while (current) {

            printf("- %s\n", current->text);
            current = current->next;

        }

    }

}

void peek(NotificationStack *stack) {

    if (isEmpty(stack)) {

        printf("No notifications available. Stack is empty.\n");

    } else {

        printf("Latest notification: %s\n", stack->top->text);

    }

}


void search(NotificationStack *stack, const char *text) {

    if (isEmpty(stack)) {

        printf("No notifications available to search.\n");

    } else {

        Notification *current = stack->top;

        while (current) {

            if (strcmp(current->text, text) == 0) {
                printf("Notification found: %s\n", current->text);
                return;
            }

            current = current->next;

        }

        printf("Notification '%s' not found.\n", text);

    }

}


void freeStack(NotificationStack *stack) {

    Notification *current = stack->top;

    while (current) {
        Notification *temp = current;
        current = current->next;
        free(temp);
    }
}
