// 15. **Political Rally Crowd Control**: Develop a queue using arrays to manage the crowd at a political rally. The system should handle entry, exit, and VIP sections, ensuring safety and order.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char type[10];  
} Person;

typedef struct {
    Person *queue;  
    int front;      
    int rear;       
    int capacity;
    int size;       
} Queue;

void initializeQueue(Queue *q, int capacity);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void resizeQueue(Queue *q);
void enqueue(Queue *q, char const *name, char const *type);
void enqueueVIP(Queue *q, char const *name);
void dequeue(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);


int main() {

    Queue crowdQueue;
    initializeQueue(&crowdQueue, 5);

    int choice;
    char name[50], type[10];

    while (1) {
        printf("\nPolitical Rally Crowd Control System\n");
        printf("1. Add Regular Person\n");
        printf("2. Add VIP Person\n");
        printf("3. Remove a Person\n");
        printf("4. Display Crowd\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]s", name);
                enqueue(&crowdQueue, name, "Regular");
                printf("Regular person added to the queue.\n");
                break;

            case 2:
                printf("Enter name: ");
                scanf(" %[^\n]s", name);
                enqueueVIP(&crowdQueue, name);
                printf("VIP person added to the queue with priority.\n");
                break;

            case 3:
                dequeue(&crowdQueue);
                break;

            case 4:
                displayQueue(&crowdQueue);
                break;

            case 5:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&crowdQueue);
                return 0;

            default:
                printf("Invalid choice!.\n");
                break;
        }
    }
}


void initializeQueue(Queue *q, int capacity) {

    q->queue = (Person *)malloc(capacity * sizeof(Person));

    if (!q->queue) {

        printf("Memory allocation failed. Exiting.\n");
        exit(1);

    }

    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    q->size = 0;
}

int isQueueEmpty(Queue *q) {

    return q->size == 0;

}


int isQueueFull(Queue *q) {

    return q->size == q->capacity;

}


void resizeQueue(Queue *q) {

    int newCapacity = q->capacity * 2;
    q->queue = (Person *)realloc(q->queue, newCapacity * sizeof(Person));

    if (!q->queue) {

        printf("Memory reallocation failed. Exiting.\n");
        exit(1);

    }

    q->capacity = newCapacity;
}


void enqueue(Queue *q, char const *name, char const *type) {

    if (isQueueFull(q)) {

        resizeQueue(q);

    }

    q->rear = (q->rear + 1);
    strcpy(q->queue[q->rear].name, name);
    strcpy(q->queue[q->rear].type, type);
    q->size++;
}


void enqueueVIP(Queue *q, char const *name) {
    
    if (isQueueFull(q)) {
    
        resizeQueue(q);
    
    }
    
    for (int i = q->rear + 1; i > q->front; i--) {
    
        q->queue[i] = q->queue[i - 1];
    
    }
    
    strcpy(q->queue[q->front].name, name);
    strcpy(q->queue[q->front].type, "VIP");
    q->rear++;
    q->size++;
}


void dequeue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty. No person to remove.\n");
        return;

    }

    printf("Removing person:\n");
    printf("Name: %s, Type: %s\n", q->queue[q->front].name, q->queue[q->front].type);

    for (int i = q->front; i < q->rear; i++) {

        q->queue[i] = q->queue[i + 1];

    }

    q->rear--;
    q->size--;
}

void displayQueue(Queue *q) {

    if (isQueueEmpty(q)) {
    
        printf("The queue is empty. No people to display.\n");
        return;
    
    }

    printf("Current Crowd:\n");
    
    for (int i = q->front; i <= q->rear; i++) {
    
        printf("Name: %s, Type: %s\n", q->queue[i].name, q->queue[i].type);
    
    }
}

void freeQueue(Queue *q) {

    free(q->queue);
    q->queue = NULL;
    q->front = 0;
    q->rear = -1;
    q->capacity = 0;
    q->size = 0;
}
