// 17. **Election Polling Booth Management**: Use arrays to implement a queue for managing voters at a polling booth. The system should handle voter registration, verification, and ensure smooth voting process.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char voterID[20];
} Voter;

typedef struct {
    Voter *queue;      // Dynamic array for voters
    int front;         // Index of the front of the queue
    int rear;          // Index of the rear of the queue
    int capacity;      // Maximum capacity of the queue
} Queue;

// Function Prototypes
void initializeQueue(Queue *q, int capacity);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, const char *name, const char *voterID);
void dequeue(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {
    int capacity, choice;
    char name[50], voterID[20];

    printf("Enter the maximum capacity of the queue: ");
    scanf("%d", &capacity);

    Queue voterQueue;
    initializeQueue(&voterQueue, capacity);

    while (1) {
        printf("\nElection Polling Booth Management System\n");
        printf("1. Register Voter\n");
        printf("2. Verify and Allow Voter (Dequeue)\n");
        printf("3. Display All Voters in Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isQueueFull(&voterQueue)) {
                    printf("Queue is full. Cannot register more voters.\n");
                } else {
                    printf("Enter voter name: ");
                    scanf(" %[^\n]s", name);
                    printf("Enter voter ID: ");
                    scanf(" %[^\n]s", voterID);
                    enqueue(&voterQueue, name, voterID);
                    printf("Voter registered successfully.\n");
                }
                break;

            case 2:
                dequeue(&voterQueue);
                break;

            case 3:
                displayQueue(&voterQueue);
                break;

            case 4:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&voterQueue);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Initialize the queue
void initializeQueue(Queue *q, int capacity) {
    q->queue = (Voter *)malloc(capacity * sizeof(Voter));
    if (!q->queue) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    q->front = -1;
    q->rear = -1;
    q->capacity = capacity;
}

// Check if the queue is empty
int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

// Check if the queue is full
int isQueueFull(Queue *q) {
    return q->rear == q->capacity - 1;
}

// Enqueue a new voter
void enqueue(Queue *q, const char *name, const char *voterID) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot add voter.\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    strcpy(q->queue[q->rear].name, name);
    strcpy(q->queue[q->rear].voterID, voterID);
}

// Dequeue a voter for verification
void dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("The queue is empty. No voters to verify.\n");
        return;
    }
    printf("Verifying and allowing voter:\n");
    printf("Name: %s, Voter ID: %s\n", q->queue[q->front].name, q->queue[q->front].voterID);

    if (q->front == q->rear) { 
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}


void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("The queue is empty. No voters to display.\n");
        return;
    }

    printf("Voters in the queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("Name: %s, Voter ID: %s\n", q->queue[i].name, q->queue[i].voterID);
    }
}


void freeQueue(Queue *q) {

    free(q->queue);
    q->queue = NULL;
    q->front = -1;
    q->rear = -1;
    q->capacity = 0;
}
