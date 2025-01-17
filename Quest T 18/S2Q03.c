// 3.Product Return Management: Develop a stack to manage product returns using a linked list. Implement a switch-case menu with options:
// 1: Add a new return request (push)
// 2: Process the last return (pop)
// 3: Display all return requests
// 4: Peek at the next return to process
// 5: Search for a specific return request
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ReturnRequest {
    int requestID;
    char productName[100];
    char reason[100];
    struct ReturnRequest *next;
} ReturnRequest;


typedef struct {

    ReturnRequest *top; 

} ReturnStack;


void initializeStack(ReturnStack *stack);
int isEmpty(ReturnStack *stack);
void addReturnRequest(ReturnStack *stack, int requestID, const char *productName, const char *reason);
void processReturnRequest(ReturnStack *stack);
void displayReturnRequests(ReturnStack *stack);
void peekReturnRequest(ReturnStack *stack);
void searchReturnRequest(ReturnStack *stack, int requestID);
void freeStack(ReturnStack *stack);

int main() {


    ReturnStack stack;
    initializeStack(&stack);

    int choice, requestID;
    char productName[100], reason[100];

    while (1) {
        
        printf("\nProduct Return Management Menu:\n");
        printf("1: Add a new return request\n");
        printf("2: Process the last return\n");
        printf("3: Display all return requests\n");
        printf("4: Peek at the next return to process\n");
        printf("5: Search for a specific return request\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
            printf("Enter Request ID: ");
            scanf("%d", &requestID);
            printf("Enter Product Name: ");
            scanf(" %[^\n]s", productName); 
            printf("Enter Return Reason: ");
            scanf(" %[^\n]s", reason);
            addReturnRequest(&stack, requestID, productName, reason);
            break;

            case 2:
            processReturnRequest(&stack);
            break;

            case 3:
            displayReturnRequests(&stack);
            break;

            case 4:
            peekReturnRequest(&stack);
            break;

            case 5:
            printf("Enter Request ID to search: ");
            scanf("%d", &requestID);
            searchReturnRequest(&stack, requestID);
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



void initializeStack(ReturnStack *stack) {

    stack->top = NULL;

}


int isEmpty(ReturnStack *stack) {

    return stack->top == NULL;

}


void addReturnRequest(ReturnStack *stack, int requestID, const char *productName, const char *reason) {

    ReturnRequest *newRequest = (ReturnRequest *)malloc(sizeof(ReturnRequest));

    if (newRequest == NULL) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    newRequest->requestID = requestID;
    strcpy(newRequest->productName, productName);
    strcpy(newRequest->reason, reason);
    newRequest->next = stack->top;
    stack->top = newRequest;
    printf("Return request added: Request ID %d, Product: %s, Reason: %s\n", requestID, productName, reason);

}


void processReturnRequest(ReturnStack *stack) {

    if (isEmpty(stack)) {

        printf("No return requests to process.\n");

    } else {

        ReturnRequest *temp = stack->top;
        stack->top = stack->top->next;
        printf("Return request processed: Request ID %d, Product: %s, Reason: %s\n", temp->requestID, temp->productName, temp->reason);
        free(temp);

    }

}


void displayReturnRequests(ReturnStack *stack) {

    if (isEmpty(stack)) {

        printf("No pending return requests.\n");

    } else {

        ReturnRequest *current = stack->top;
        printf("Pending return requests:\n");

        while (current != NULL) {

            printf("Request ID: %d, Product: %s, Reason: %s\n", current->requestID, current->productName, current->reason);
            current = current->next;

        }

    }

}


void peekReturnRequest(ReturnStack *stack) {

    if (isEmpty(stack)) {

        printf("No pending return requests.\n");

    } else {

        printf("Next return request to process: Request ID %d, Product: %s, Reason: %s\n", stack->top->requestID, stack->top->productName, stack->top->reason);

    }

}


void searchReturnRequest(ReturnStack *stack, int requestID) {

    if (isEmpty(stack)) {

        printf("No return requests to search.\n");

    } else {

        ReturnRequest *current = stack->top;

        while (current != NULL) {

            if (current->requestID == requestID) {

                printf("Return request found: Request ID %d, Product: %s, Reason: %s\n", current->requestID, current->productName, current->reason);
                return;

            }

            current = current->next;

        }

        printf("Return request with ID %d not found.\n", requestID);

    }

}

void freeStack(ReturnStack *stack) {

    ReturnRequest *current = stack->top;
    ReturnRequest *next;

    while (current != NULL) {

        next = current->next;
        free(current);
        current = next;
    }
}
