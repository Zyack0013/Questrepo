// 5.Flash Sale Deal Management: Create a stack for managing flash sale deals using a linked list. Include a switch-case menu with options:
// 1: Add a new deal (push)
// 2: Remove the last deal (pop)
// 3: View all active deals
// 4: Peek at the latest deal
// 5: Search for a specific deal
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Deal {

    int dealID;
    char dealName[100];
    float discount;
    struct Deal *next;

} Deal;

typedef struct {

    Deal *top; 

} DealStack;


void initializeStack(DealStack *stack);
int isEmpty(DealStack *stack);
void addDeal(DealStack *stack, int dealID, const char *dealName, float discount);
void removeDeal(DealStack *stack);
void viewDeals(DealStack *stack);
void peekDeal(DealStack *stack);
void searchDeal(DealStack *stack, int dealID);
void freeStack(DealStack *stack);

int main() {

    DealStack stack;
    initializeStack(&stack);

    int choice, dealID;
    char dealName[100];
    float discount;

    while (1) {
        
        printf("\nFlash Sale Deal Management Menu:\n");
        printf("1: Add a new deal\n");
        printf("2: Remove the last deal\n");
        printf("3: View all active deals\n");
        printf("4: Peek at the latest deal\n");
        printf("5: Search for a specific deal\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
            printf("Enter Deal ID: ");
            scanf("%d", &dealID);
            printf("Enter Deal Name: ");
            scanf(" %[^\n]s", dealName); 
            printf("Enter Discount (in %%): ");
            scanf("%f", &discount);
            addDeal(&stack, dealID, dealName, discount);
            break;

            case 2:
            removeDeal(&stack);
            break;

            case 3:
            viewDeals(&stack);
            break;

            case 4:
            peekDeal(&stack);
            break;

            case 5:
            printf("Enter Deal ID to search: ");
            scanf("%d", &dealID);
            searchDeal(&stack, dealID);
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

void initializeStack(DealStack *stack) {

    stack->top = NULL;

}


int isEmpty(DealStack *stack) {

    return stack->top == NULL;

}


void addDeal(DealStack *stack, int dealID, const char *dealName, float discount) {

    Deal *newDeal = (Deal *)malloc(sizeof(Deal));

    if (newDeal == NULL) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    newDeal->dealID = dealID;
    strcpy(newDeal->dealName, dealName);
    newDeal->discount = discount;
    newDeal->next = stack->top;
    stack->top = newDeal;
    printf("Deal added: ID %d, Name: %s, Discount: %.2f%%\n", dealID, dealName, discount);

}


void removeDeal(DealStack *stack) {

    if (isEmpty(stack)) {

        printf("No deals to remove.\n");

    } else {

        Deal *temp = stack->top;
        stack->top = stack->top->next;
        printf("Deal removed: ID %d, Name: %s, Discount: %.2f%%\n", temp->dealID, temp->dealName, temp->discount);
        free(temp);

    }

}


void viewDeals(DealStack *stack) {

    if (isEmpty(stack)) {

        printf("No active deals.\n");

    } else {

        Deal *current = stack->top;
        printf("Active deals:\n");

        while (current != NULL) {

            printf("ID: %d, Name: %s, Discount: %.2f%%\n", current->dealID, current->dealName, current->discount);
            current = current->next;

        }

    }

}


void peekDeal(DealStack *stack) {

    if (isEmpty(stack)) {

        printf("No active deals.\n");

    } else {

        printf("Latest deal: ID %d, Name: %s, Discount: %.2f%%\n", stack->top->dealID, stack->top->dealName, stack->top->discount);

    }

}


void searchDeal(DealStack *stack, int dealID) {

    if (isEmpty(stack)) {

        printf("No deals to search.\n");

    } else {

        Deal *current = stack->top;

        while (current != NULL) {

            if (current->dealID == dealID) {
                printf("Deal found: ID %d, Name: %s, Discount: %.2f%%\n", current->dealID, current->dealName, current->discount);
                return;

            }

            current = current->next;

        }

        printf("Deal with ID %d not found.\n", dealID);

    }

}

void freeStack(DealStack *stack) {

    Deal *current = stack->top;
    Deal *next;

    while (current != NULL) {

        next = current->next;
        free(current);
        current = next;

    }

}
