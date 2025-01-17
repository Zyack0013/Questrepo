// 1.Order Processing System: Implement a stack-based system using a linked list to manage order processing. Use a switch-case menu with options:
// 1: Add a new order (push)
// 2: Process the last order (pop)
// 3: Display all pending orders
// 4: Peek at the next order to be processed
// 5: Search for a specific order
// 6: Exit



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order {

    int orderID;
    char customerName[50];
    struct Order *next;

} Order;

typedef struct {

    Order *top;  

} OrderStack;

void initializeStack(OrderStack *s);
int isEmpty(OrderStack *s);
void addOrder(OrderStack *s, int orderID, const char *customerName);
void processOrder(OrderStack *s);
void displayOrders(OrderStack *s);
void peekOrder(OrderStack *s);
void searchOrder(OrderStack *s, int orderID);
void freeStack(OrderStack *s);

int main() {

    OrderStack stack;
    initializeStack(&stack);

    int choice, orderID;
    char customerName[50];

    while (1) {
        
        printf("\nOrder Processing System Menu:\n");
        printf("1: Add a new order\n");
        printf("2: Process the last order\n");
        printf("3: Display all pending orders\n");
        printf("4: Peek at the next order to be processed\n");
        printf("5: Search for a specific order\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1:
            printf("Enter Order ID: ");
            scanf("%d", &orderID);
            printf("Enter Customer Name: ");
            scanf(" %[^\n]s", customerName);  
            addOrder(&stack, orderID, customerName);
            break;

            case 2:
            processOrder(&stack);
            break;

            case 3:
            displayOrders(&stack);
            break;

            case 4:
            peekOrder(&stack);
            break;

            case 5:
            printf("Enter Order ID to search for: ");
            scanf("%d", &orderID);
            searchOrder(&stack, orderID);
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


void initializeStack(OrderStack *s) {

    s->top = NULL;

}

int isEmpty(OrderStack *s) {

    return s->top == NULL;

}

void addOrder(OrderStack *s, int orderID, const char *customerName) {

    Order *newOrder = (Order *)malloc(sizeof(Order));

    if (newOrder == NULL) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    newOrder->orderID = orderID;
    strcpy(newOrder->customerName, customerName);
    newOrder->next = s->top;
    s->top = newOrder;
    printf("Order added: Order ID %d, Customer: %s\n", orderID, customerName);
}

void processOrder(OrderStack *s) {

    if (isEmpty(s)) {

        printf("No pending orders to process.\n");

    } else {

        Order *temp = s->top;
        s->top = s->top->next;
        printf("Order processed: Order ID %d, Customer: %s\n", temp->orderID, temp->customerName);
        free(temp);

    }

}

void displayOrders(OrderStack *s) {

    if (isEmpty(s)) {

        printf("No pending orders.\n");

    } else {

        Order *current = s->top;
        printf("Pending orders:\n");

        while (current != NULL) {

            printf("Order ID: %d, Customer: %s\n", current->orderID, current->customerName);
            current = current->next;

        }

    }

}

void peekOrder(OrderStack *s) {

    if (isEmpty(s)) {

        printf("No pending orders.\n");

    } else {

        printf("Next order to be processed: Order ID %d, Customer: %s\n", s->top->orderID, s->top->customerName);

    }

}


void searchOrder(OrderStack *s, int orderID) {

    if (isEmpty(s)) {

        printf("No orders to search.\n");

    } else {

        Order *current = s->top;

        while (current != NULL) {

            if (current->orderID == orderID) {

                printf("Order found: Order ID %d, Customer: %s\n", current->orderID, current->customerName);
                return;

            }

            current = current->next;

        }

        printf("Order ID %d not found.\n", orderID);

    }

}

void freeStack(OrderStack *s) {

    Order *current = s->top;
    Order *next;


    while (current != NULL) {

        next = current->next;
        free(current);
        current = next;

    }

}
