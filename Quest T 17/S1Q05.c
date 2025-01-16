// Problem 5: Order Processing System
// Description: Implement a linked list to track customer orders.
// Operations:
// Create an order list.
// Insert a new customer order.
// Delete a completed or canceled order.
// Display all current orders.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order {

    int orderID;
    char customerName[50];
    char orderDetails[100];
    struct Order *next;
} Order;

Order *orderList = NULL; 
static int totalOrders = 0;

void createOrderList(int count);
void insertNewOrder();
void deleteOrder(int orderID);
void displayAllOrders();

int main() {

    int choice, count, orderID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create an order list.\n");
        printf("2. Insert a new customer order.\n");
        printf("3. Delete a completed or canceled order.\n");
        printf("4. Display all current orders.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of orders to create: ");
            scanf("%d", &count);
            getchar();
            createOrderList(count);
            printf("\nTotal orders: %d\n", totalOrders);
            break;

            case 2:
            insertNewOrder();
            printf("\nTotal orders: %d\n", totalOrders);
            break;

            case 3:
            displayAllOrders();
            printf("Enter the Order ID to delete: ");
            scanf("%d", &orderID);
            deleteOrder(orderID);
            printf("\nTotal orders: %d\n", totalOrders);
            break;

            case 4:
            displayAllOrders();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice.!\n");
            break;
        }
    }

    return 0;
}

void createOrderList(int count) {

    if (count <= 0) {
        printf("Invalid number of orders.\n");
        return;
    }

    Order *temp, *last = orderList;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Order *)malloc(sizeof(Order));

        if (temp == NULL) {

            printf("Memory allocation failed for order %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Order %d:\n", i + 1);
        printf("Enter the Order ID: ");
        scanf("%d", &temp->orderID);
        getchar();

        printf("Enter the Customer Name: ");
        fgets(temp->customerName, sizeof(temp->customerName), stdin);
        temp->customerName[strcspn(temp->customerName, "\n")] = '\0';

        printf("Enter the Order Details: ");
        fgets(temp->orderDetails, sizeof(temp->orderDetails), stdin);
        temp->orderDetails[strcspn(temp->orderDetails, "\n")] = '\0';

        temp->next = NULL;

        if (orderList == NULL) {

            orderList = temp;

        } else {
            last->next = temp;
        }

        last = temp;
        totalOrders++;
    }

    printf("%d orders created successfully.\n", count);
}

void insertNewOrder() {
    Order *temp, *last = orderList;

    temp = (Order *)malloc(sizeof(Order));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Order ID: ");
    scanf("%d", &temp->orderID);
    getchar();

    Order *check = orderList;
    while (check != NULL) {

        if (check->orderID == temp->orderID) {

            printf("Error: Order ID %d already exists.\n", temp->orderID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Customer Name: ");
    fgets(temp->customerName, sizeof(temp->customerName), stdin);
    temp->customerName[strcspn(temp->customerName, "\n")] = '\0';

    printf("Enter the Order Details: ");
    fgets(temp->orderDetails, sizeof(temp->orderDetails), stdin);
    temp->orderDetails[strcspn(temp->orderDetails, "\n")] = '\0';

    temp->next = NULL;

    if (orderList == NULL) {

        orderList = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;

        }
        last->next = temp;
    }

    totalOrders++;
    printf("Order ID %d added successfully.\n", temp->orderID);
}

void deleteOrder(int orderID) {
    if (orderList == NULL) {
        printf("Order list is empty.\n");
        return;
    }

    Order *temp = orderList, *prev = NULL;

    if (temp != NULL && temp->orderID == orderID) {
        orderList = temp->next;
        free(temp);
        printf("Order ID %d deleted successfully.\n", orderID);
        totalOrders--;
        return;
    }

    while (temp != NULL && temp->orderID != orderID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Order ID %d not found.\n", orderID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Order ID %d deleted successfully.\n", orderID);
    totalOrders--;
}

void displayAllOrders() {

    if (orderList == NULL) {

        printf("Order list is empty.\n");
        return;
    }

    Order *temp = orderList;
    int i = 1;
    printf("\n\t\tCurrent Orders\t\t\n");
    printf("SLNO.\tOrder ID\tCustomer Name\t\tOrder Details\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%-30s\n", i++, temp->orderID, temp->customerName, temp->orderDetails);
        temp = temp->next;
    
    }

    printf("------------------------------------------------------------\n");
}
