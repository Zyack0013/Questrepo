// 13. **Online Shopping Checkout System**: Implement a queue using arrays for an online shopping platform's checkout system. The program should handle multiple customers checking out simultaneously and manage inventory updates.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id;                 
    char name[50];          
    int itemCount;          
    double totalAmount;     
} Customer;

typedef struct {
    Customer *customers;    
    int front;              
    int rear;               
    int size;               
    int capacity;
} Queue;


void initializeQueue(Queue *queue, int capacity);
int isQueueEmpty(Queue *queue);
int isQueueFull(Queue *queue);
void enqueue(Queue *queue, int id, const char *name, int itemCount, double totalAmount);
void dequeue(Queue *queue);
void displayQueue(Queue *queue);
void freeQueue(Queue *queue);

int main() {
    
    Queue checkoutQueue;
    int capacity;
    
    printf("Enter initial queue capacity: ");
    scanf("%d", &capacity);
    initializeQueue(&checkoutQueue, capacity);

    int choice, id = 1, itemCount;
    char name[50];
    double totalAmount;

    while (1) {

        printf("\nOnline Shopping Checkout System\n");
        printf("1. Add Customer to Queue\n");
        printf("2. Process Checkout\n");
        printf("3. Display All Customers in Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isQueueFull(&checkoutQueue)) {
                    printf("Queue is full. Cannot add more customers.\n");
                } else {
                    printf("Enter customer name: ");
                    scanf(" %[^\n]s", name);
                    printf("Enter number of items: ");
                    scanf("%d", &itemCount);
                    printf("Enter total amount: ");
                    scanf("%lf", &totalAmount);
                    enqueue(&checkoutQueue, id++, name, itemCount, totalAmount);
                    printf("Customer added to the queue successfully.\n");
                }
                break;

            case 2:
                dequeue(&checkoutQueue);
                break;

            case 3:
                displayQueue(&checkoutQueue);
                break;

            case 4:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&checkoutQueue);
                return 0;

            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}

void initializeQueue(Queue *queue, int capacity) {

    queue->customers = (Customer *)malloc(capacity * sizeof(Customer));

    if (!queue->customers) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
}

int isQueueEmpty(Queue *queue) {
    return queue->size == 0;
}

int isQueueFull(Queue *queue) {

    return queue->size == queue->capacity;
}

void enqueue(Queue *queue, int id, const char *name, int itemCount, double totalAmount) {

    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue customer.\n");
        return;
    }
    queue->rear++;
    if (queue->rear == queue->capacity) {

        queue->rear = 0; 

    }
    queue->customers[queue->rear].id = id;
    strcpy(queue->customers[queue->rear].name, name);
    queue->customers[queue->rear].itemCount = itemCount;
    queue->customers[queue->rear].totalAmount = totalAmount;
    queue->size++;
}

void dequeue(Queue *queue) {

    if (isQueueEmpty(queue)) {

        printf("The queue is empty. No customers to process.\n");
        return;

    }

    Customer customer = queue->customers[queue->front];
    printf("Processing checkout for:\n");
    printf("ID: %d, Name: %s, Items: %d, Total Amount: %.2lf\n",customer.id, customer.name, customer.itemCount, customer.totalAmount);

    queue->front++;
    if (queue->front == queue->capacity) {
        queue->front = 0; 
    }
    queue->size--;
}

void displayQueue(Queue *queue) {

    if (isQueueEmpty(queue)) {

        printf("The queue is empty. No customers to display.\n");
        return;

    }

    printf("Customers in Queue:\n");
    int i = queue->front;
    for (int count = 0; count < queue->size; count++) {

        printf("ID: %d, Name: %s, Items: %d, Total Amount: %.2lf\n",queue->customers[i].id, queue->customers[i].name,queue->customers[i].itemCount, queue->customers[i].totalAmount);
        i++;
        if (i == queue->capacity) {

            i = 0; 
        }
    }
}

void freeQueue(Queue *queue) {
    free(queue->customers);
    queue->customers = NULL;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = 0;
}
