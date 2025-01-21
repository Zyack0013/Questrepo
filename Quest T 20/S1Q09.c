// 9. **Stock Trading Simulation**: Develop a program using arrays to simulate a queue for stock trading orders. The system should manage buy and sell orders, handle order cancellations, and provide real-time updates.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int orderId;
    char orderType[5];  
    int price;        
    int quantity;     
} Order;

typedef struct {
    int capacity;
    int front;       
    int rear;        
    Order *orders;   
} Queue;

void initializeQueue(Queue *q, int capacity);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, Order order);
void dequeue(Queue *q);
void cancelOrder(Queue *q, int orderId);
void displayOrders(Queue *q);
void processOrders(Queue *q);


int main() {
    
    Queue orderQueue;
    int capacity = 10;  
    initializeQueue(&orderQueue, capacity);

    int choice, price, quantity, orderId;
    char orderType[5];

    while (1) {

        printf("\nStock Trading Simulation\n");
        printf("1. Place Buy Order\n");
        printf("2. Place Sell Order\n");
        printf("3. Cancel Order\n");
        printf("4. View All Orders\n");
        printf("5. Process Orders\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
            
            case 2:
                printf("Enter price: ");
                scanf("%d", &price);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter order ID: ");
                scanf("%d", &orderId);
                strcpy(orderType, (choice == 1) ? "BUY" : "SELL");
                
                Order newOrder = {orderId, "", price, quantity};
                strcpy(newOrder.orderType, orderType);
                enqueue(&orderQueue, newOrder);
                printf("Order placed successfully.\n");
                break;

            case 3:
                printf("Enter the order ID to cancel: ");
                scanf("%d", &orderId);
                cancelOrder(&orderQueue, orderId);
                break;

            case 4:
                displayOrders(&orderQueue);
                break;

            case 5:
                processOrders(&orderQueue);
                break;

            case 6:
                printf("Exiting the system.\n");
                free(orderQueue.orders);
                return 0;

            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}

void initializeQueue(Queue *q, int capacity) {

    q->orders = (Order *)malloc(capacity * sizeof(Order)); 
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;

}


int isQueueEmpty(Queue *q) {

    return q->rear == -1;

}

int isQueueFull(Queue *q) {

    return q->rear == q->capacity - 1;

}

void enqueue(Queue *q, Order order) {

    if (isQueueFull(q)) {

        printf("Queue is full. Cannot place more orders.\n");
        return;

    }

    q->orders[++q->rear] = order;

}

void dequeue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("Queue is empty. No orders to process.\n");
        return;
    }

    for (int i = 0; i < q->rear; i++) {

        q->orders[i] = q->orders[i + 1];

    }
    q->rear--;
}

void cancelOrder(Queue *q, int orderId) {
    
    if (isQueueEmpty(q)) {
     
        printf("Queue is empty. No orders to cancel.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i <= q->rear; i++) {

        if (q->orders[i].orderId == orderId) {

            printf("Cancelling Order ID %d: %s %d shares at $%d\n",q->orders[i].orderId, q->orders[i].orderType, q->orders[i].quantity, q->orders[i].price);

            for (int j = i; j < q->rear; j++) {

                q->orders[j] = q->orders[j + 1];

            }
            q->rear--;
            found = 1;
            break;
        }
    }

    if (!found) {

        printf("Order with ID %d not found.\n", orderId);

    }
}

void displayOrders(Queue *q) {
    
    if (isQueueEmpty(q)) {
    
        printf("No orders in the queue.\n");
        return;
    }

    printf("Orders in the queue:\n");
    
    for (int i = 0; i <= q->rear; i++) {

        printf("Order ID: %d, Type: %s, Price: %d, Quantity: %d\n",q->orders[i].orderId, q->orders[i].orderType, q->orders[i].price, q->orders[i].quantity);
    }
}

void processOrders(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("No orders to process.\n");
        return;
    }

    while (q->rear > 0) {

        Order buyOrder = q->orders[0];
        Order sellOrder = q->orders[1];

        if (strcmp(buyOrder.orderType, "BUY") == 0 && strcmp(sellOrder.orderType, "SELL") == 0) {

            printf("Matching BUY Order ID %d with SELL Order ID %d\n", buyOrder.orderId, sellOrder.orderId);
            printf("Price: $%d, Quantity: %d\n", sellOrder.price, buyOrder.quantity < sellOrder.quantity ? buyOrder.quantity : sellOrder.quantity);
            dequeue(q);
            dequeue(q);

        } else {

            break;

        }
    }
}
