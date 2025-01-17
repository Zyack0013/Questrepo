// 15.Payment History: Implement a stack to record payment history using a linked list. Include a switch-case menu with options:
// 1: Add a new payment record (push)
// 2: Remove the last payment record (pop)
// 3: View all payment records
// 4: Peek at the latest payment record
// 5: Search for a specific payment record
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PaymentRecord {

    char description[256];
    double amount;
    struct PaymentRecord *next;

} PaymentRecord;

typedef struct {

    PaymentRecord *top;

} PaymentStack;

void initializeStack(PaymentStack *stack);
int isStackEmpty(PaymentStack *stack);
void pushPayment(PaymentStack *stack, const char *description, double amount);
void popPayment(PaymentStack *stack);
void displayPayments(PaymentStack *stack);
void peekPayment(PaymentStack *stack);
void searchPayment(PaymentStack *stack, const char *description);
void freeStack(PaymentStack *stack);

int main() {

    PaymentStack stack;
    initializeStack(&stack);

    int choice;
    char description[256];
    double amount;

    while (1) {
        
        printf("\nPayment History Menu:\n");
        printf("1: Add a new payment record (push)\n");
        printf("2: Remove the last payment record (pop)\n");
        printf("3: View all payment records\n");
        printf("4: Peek at the latest payment record\n");
        printf("5: Search for a specific payment record\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
            printf("Enter payment description: ");
            scanf(" %[^\n]s", description);
            printf("Enter payment amount: ");
            scanf("%lf", &amount);
            pushPayment(&stack, description, amount);
            break;

            case 2: 
            popPayment(&stack);
            break;

            case 3: 
            displayPayments(&stack);
            break;

            case 4: 
            peekPayment(&stack);
            break;

            case 5: 
            printf("Enter payment description to search: ");
            scanf(" %[^\n]s", description);
            searchPayment(&stack, description);
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

void initializeStack(PaymentStack *stack) {

    stack->top = NULL;

}

int isStackEmpty(PaymentStack *stack) {

    return stack->top == NULL;

}

void pushPayment(PaymentStack *stack, const char *description, double amount) {

    PaymentRecord *newRecord = (PaymentRecord *)malloc(sizeof(PaymentRecord));

    if (!newRecord) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(newRecord->description, description);
    newRecord->amount = amount;
    newRecord->next = stack->top;
    stack->top = newRecord;
    printf("Payment record added: %s, $%.2f\n", description, amount);

}

void popPayment(PaymentStack *stack) {

    if (isStackEmpty(stack)) {

        printf("No payment records to remove.\n");

    } else {

        PaymentRecord *temp = stack->top;
        printf("Payment record removed: %s, $%.2f\n", temp->description, temp->amount);
        stack->top = stack->top->next;
        free(temp);

    }

}

void displayPayments(PaymentStack *stack) {

    if (isStackEmpty(stack)) {

        printf("No payment records available.\n");

    } else {

        PaymentRecord *current = stack->top;
        printf("Payment Records:\n");

        while (current) {

            printf("- %s, $%.2f\n", current->description, current->amount);
            current = current->next;

        }

    }

}

void peekPayment(PaymentStack *stack) {

    if (isStackEmpty(stack)) {

        printf("No payment records available.\n");

    } else {

        printf("Latest payment record: %s, $%.2f\n", stack->top->description, stack->top->amount);

    }

}

void searchPayment(PaymentStack *stack, const char *description) {

    if (isStackEmpty(stack)) {

        printf("No payment records available.\n");

    } else {

        PaymentRecord *current = stack->top;

        while (current) {

            if (strcmp(current->description, description) == 0) {

                printf("Payment record found: %s, $%.2f\n", current->description, current->amount);
                return;

            }

            current = current->next;

        }

        printf("Payment record '%s' not found.\n", description);

    }

}

void freeStack(PaymentStack *stack) {

    PaymentRecord *current = stack->top;

    while (current) {

        PaymentRecord *temp = current;
        current = current->next;

        free(temp);
    }
}
