// 1. **Stock Market Order Matching System**: Implement a queue using arrays to simulate a stock market's order matching system. Design a program where buy and sell orders are placed in a queue. The system should match and process orders based on price and time priority.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char type;   
    int quantity;
    float price;

} Order;

typedef struct {
    int capacity;
    int front;
    int rear;
    Order *orders;
} Queue;


void initializeQueue(Queue *q, int initialCapacity);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, char type, int quantity, float price);
void processOrders(Queue *buyQueue, Queue *sellQueue);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {

    Queue buyQueue, sellQueue;
    int initialCapacity = 10;

    
    initializeQueue(&buyQueue, initialCapacity);
    initializeQueue(&sellQueue, initialCapacity);

    int choice;
    char type;
    int quantity;
    float price;

    while (1) {
        printf("\nStock Market Order Matching System\n");
        printf("1. Place a Buy Order\n");
        printf("2. Place a Sell Order\n");
        printf("3. Process Orders\n");
        printf("4. Display Orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter quantity and price for Buy Order: ");
                scanf("%d %f", &quantity, &price);
                enqueue(&buyQueue, 'B', quantity, price);
                printf("Buy order placed.\n");
                break;

            case 2:
                printf("Enter quantity and price for Sell Order: ");
                scanf("%d %f", &quantity, &price);
                enqueue(&sellQueue, 'S', quantity, price);
                printf("Sell order placed.\n");
                break;

            case 3:
                processOrders(&buyQueue, &sellQueue);
                break;

            case 4:
                printf("\nBuy Orders:\n");
                displayQueue(&buyQueue);
                printf("\nSell Orders:\n");
                displayQueue(&sellQueue);
                break;

            case 5:
                printf("Exiting...\n");
                freeQueue(&buyQueue);
                freeQueue(&sellQueue);
                return 0;

            default:
                printf("Invalid choice!.\n");
                break;
        }
    }
    return 0;
}

void initializeQueue(Queue *q, int initialCapacity) {

    q->orders = (Order *)malloc(initialCapacity * sizeof(Order));
    q->front = 0;
    q->rear = -1;
    q->capacity = initialCapacity;
}


int isQueueEmpty(Queue *q) {

    return q->front > q->rear;

}


int isQueueFull(Queue *q) {

    return q->rear == q->capacity - 1;

}

void enqueue(Queue *q, char type, int quantity, float price) {

    if (isQueueFull(q)) {
        
        q->capacity *= 2;
        q->orders = (Order *)realloc(q->orders, q->capacity * sizeof(Order));
    }
    q->rear++;
    q->orders[q->rear].type = type;
    q->orders[q->rear].quantity = quantity;
    q->orders[q->rear].price = price;
}

void processOrders(Queue *buyQueue, Queue *sellQueue) {

    while (!isQueueEmpty(buyQueue) && !isQueueEmpty(sellQueue)) {

        Order *buyOrder = &buyQueue->orders[buyQueue->front];
        Order *sellOrder = &sellQueue->orders[sellQueue->front];

        if (buyOrder->price >= sellOrder->price) {

            int quantityMatched = (buyOrder->quantity < sellOrder->quantity) ? buyOrder->quantity : sellOrder->quantity;
            printf("Matched Order: %d units at %.2f\n", quantityMatched, sellOrder->price);

            buyOrder->quantity -= quantityMatched;
            sellOrder->quantity -= quantityMatched;

            if (buyOrder->quantity == 0) {
                buyQueue->front++;
            }
            if (sellOrder->quantity == 0) {
                sellQueue->front++;
            }
        } else {
            break;  // No match possible
        }
    }

    if (isQueueEmpty(buyQueue) || isQueueEmpty(sellQueue)) {
        printf("No more matches possible.\n");
    }
}


void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("No orders.\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("Type: %c, Quantity: %d, Price: %.2f\n",q->orders[i].type, q->orders[i].quantity, q->orders[i].price);
    }
}

void freeQueue(Queue *q) {
    free(q->orders);
}
