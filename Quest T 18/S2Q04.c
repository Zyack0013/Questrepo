// 4.Inventory Restock System: Implement a stack to manage inventory restocking using a linked list. Use a switch-case menu with options:
// 1: Add a restock entry (push)
// 2: Process the last restock (pop)
// 3: View all restock entries
// 4: Peek at the latest restock entry
// 5: Search for a specific restock entry
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct RestockEntry {

    int itemID;
    char itemName[100];
    int quantity;
    struct RestockEntry *next;

} RestockEntry;


typedef struct {

    RestockEntry *top; 

} RestockStack;


void initializeStack(RestockStack *stack);
int isEmpty(RestockStack *stack);
void addRestockEntry(RestockStack *stack, int itemID, const char *itemName, int quantity);
void processRestockEntry(RestockStack *stack);
void viewRestockEntries(RestockStack *stack);
void peekRestockEntry(RestockStack *stack);
void searchRestockEntry(RestockStack *stack, int itemID);
void freeStack(RestockStack *stack);

int main() {

    RestockStack stack;
    initializeStack(&stack);

    int choice, itemID, quantity;
    char itemName[100];

    while (1) {
        
        printf("\nInventory Restock System Menu:\n");
        printf("1: Add a restock entry\n");
        printf("2: Process the last restock\n");
        printf("3: View all restock entries\n");
        printf("4: Peek at the latest restock entry\n");
        printf("5: Search for a specific restock entry\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
            printf("Enter Item ID: ");
            scanf("%d", &itemID);
            printf("Enter Item Name: ");
            scanf(" %[^\n]s", itemName); 
            printf("Enter Quantity: ");
            scanf("%d", &quantity);
            addRestockEntry(&stack, itemID, itemName, quantity);
            break;

            case 2:
            processRestockEntry(&stack);
            break;

            case 3:
            viewRestockEntries(&stack);
            break;

            case 4:
            peekRestockEntry(&stack);
            break;

            case 5:
            printf("Enter Item ID to search: ");
            scanf("%d", &itemID);
            searchRestockEntry(&stack, itemID);
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


void initializeStack(RestockStack *stack) {

    stack->top = NULL;

}


int isEmpty(RestockStack *stack) {

    return stack->top == NULL;

}


void addRestockEntry(RestockStack *stack, int itemID, const char *itemName, int quantity) {

    RestockEntry *newEntry = (RestockEntry *)malloc(sizeof(RestockEntry));

    if (newEntry == NULL) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    newEntry->itemID = itemID;
    strcpy(newEntry->itemName, itemName);
    newEntry->quantity = quantity;
    newEntry->next = stack->top;
    stack->top = newEntry;
    printf("Restock entry added: Item ID %d, Name: %s, Quantity: %d\n", itemID, itemName, quantity);

}


void processRestockEntry(RestockStack *stack) {

    if (isEmpty(stack)) {

        printf("No restock entries to process.\n");

    } else {

        RestockEntry *temp = stack->top;
        stack->top = stack->top->next;
        printf("Restock entry processed: Item ID %d, Name: %s, Quantity: %d\n", temp->itemID, temp->itemName, temp->quantity);
        free(temp);

    }

}


void viewRestockEntries(RestockStack *stack) {

    if (isEmpty(stack)) {

        printf("No pending restock entries.\n");

    } else {

        RestockEntry *current = stack->top;
        printf("Pending restock entries:\n");

        while (current != NULL) {

            printf("Item ID: %d, Name: %s, Quantity: %d\n", current->itemID, current->itemName, current->quantity);
            current = current->next;

        }

    }

}


void peekRestockEntry(RestockStack *stack) {

    if (isEmpty(stack)) {

        printf("No pending restock entries.\n");

    } else {

        printf("Next restock entry: Item ID %d, Name: %s, Quantity: %d\n", stack->top->itemID, stack->top->itemName, stack->top->quantity);

    }

}


void searchRestockEntry(RestockStack *stack, int itemID) {

    if (isEmpty(stack)) {

        printf("No restock entries to search.\n");

    } else {

        RestockEntry *current = stack->top;

        while (current != NULL) {

            if (current->itemID == itemID) {

                printf("Restock entry found: Item ID %d, Name: %s, Quantity: %d\n", current->itemID, current->itemName, current->quantity);
                return;

            }

            current = current->next;

        }

        printf("Restock entry with Item ID %d not found.\n", itemID);

    }

}


void freeStack(RestockStack *stack) {

    RestockEntry *current = stack->top;
    RestockEntry *next;

    while (current != NULL) {

        next = current->next;
        free(current);
        current = next;

    }

}
