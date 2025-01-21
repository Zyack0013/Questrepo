// 3. **Political Campaign Event Management**: Implement a queue using arrays to manage attendees at a political campaign event. The system should handle registration, check-in, and priority access for VIP attendees.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    char name[50];
    int isVIP; 

} Attendee;

typedef struct {

    int capacity;
    int front;
    int rear;
    Attendee *queue;

} Queue;


void initializeQueue(Queue *q, int initialCapacity);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, const char *name, int isVIP);
void priorityEnqueue(Queue *q, const char *name); 
void checkIn(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {
    
    Queue attendeeQueue;
    int initialCapacity = 10;

    initializeQueue(&attendeeQueue, initialCapacity);

    int choice;
    char name[50];
    int isVIP;

    while (1) {
        
        printf("\nPolitical Campaign Event Management\n");
        printf("1. Register Attendee\n");
        printf("2. Register VIP Attendee (Priority)\n");
        printf("3. Check-in Attendee\n");
        printf("4. Display Attendees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter attendee's name: ");
                scanf("%s", name);
                enqueue(&attendeeQueue, name, 0); 
                printf("Attendee registered.\n");
                break;

            case 2:
                printf("Enter VIP attendee's name: ");
                scanf("%s", name);
                priorityEnqueue(&attendeeQueue, name); 
                printf("VIP attendee registered with priority.\n");
                break;

            case 3:
                checkIn(&attendeeQueue);
                break;

            case 4:
                displayQueue(&attendeeQueue);
                break;

            case 5:
                printf("Exiting...\n");
                freeQueue(&attendeeQueue);
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}

void initializeQueue(Queue *q, int initialCapacity) {

    q->queue = (Attendee *)malloc(initialCapacity * sizeof(Attendee));
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

void enqueue(Queue *q, const char *name, int isVIP) {

    if (isQueueFull(q)) {

        q->capacity *= 2;
        q->queue = (Attendee *)realloc(q->queue, q->capacity * sizeof(Attendee));

    }
    q->rear++;
    strcpy(q->queue[q->rear].name, name);
    q->queue[q->rear].isVIP = isVIP;
}

void priorityEnqueue(Queue *q, const char *name) {
    if (isQueueFull(q)) {

        q->capacity *= 2;
        q->queue = (Attendee *)realloc(q->queue, q->capacity * sizeof(Attendee));

    }

    for (int i = q->rear; i >= q->front; i--) {

        q->queue[i + 1] = q->queue[i];

    }
    strcpy(q->queue[q->front].name, name);
    q->queue[q->front].isVIP = 1;
    q->rear++;
}

void checkIn(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("No attendees in the queue.\n");
        return;

    }

    printf("Checked-in: %s (%s)\n",q->queue[q->front].name,q->queue[q->front].isVIP ? "VIP" : "Regular");
    q->front++;
}

void displayQueue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("No attendees in the queue.\n");
        return;

    }

    printf("Attendees in the queue:\n");

    for (int i = q->front; i <= q->rear; i++) {

        printf("%s (%s)\n", q->queue[i].name, q->queue[i].isVIP ? "VIP" : "Regular");

    }
}

void freeQueue(Queue *q) {
    free(q->queue);
}
