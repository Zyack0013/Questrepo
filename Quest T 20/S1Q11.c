// 11. **Political Debate Audience Management**: Use arrays to implement a queue for managing the audience at a political debate. The system should handle entry, seating arrangements, and priority access for media personnel.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an audience member
typedef struct {
    int id;          // Unique ID for the audience member
    char name[50];   // Name of the audience member
    char type[20];   // Type: "GENERAL" or "MEDIA"
} Audience;

// Structure to represent the queue
typedef struct {
    Audience *queue;   // Pointer to the dynamically allocated array
    int front;         // Index of the front of the queue
    int rear;          // Index of the rear of the queue
    int capacity;      // Current capacity of the queue
} AudienceQueue;

// Function Prototypes
void initializeQueue(AudienceQueue *q, int initialCapacity);
int isQueueEmpty(AudienceQueue *q);
int isQueueFull(AudienceQueue *q);
void resizeQueue(AudienceQueue *q);
void enqueue(AudienceQueue *q, Audience member);
void enqueuePriority(AudienceQueue *q, Audience member);
void dequeue(AudienceQueue *q);
void displayQueue(AudienceQueue *q);
void freeQueue(AudienceQueue *q);

// Main Function
int main() {
    AudienceQueue audienceQueue;
    initializeQueue(&audienceQueue, 5);  // Initialize with a capacity of 5

    int choice;
    Audience member;
    int idCounter = 1;

    while (1) {
        printf("\nPolitical Debate Audience Management System\n");
        printf("1. Add General Audience\n");
        printf("2. Add Media Personnel (Priority)\n");
        printf("3. Remove Audience Member (Seated)\n");
        printf("4. View All Audience\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1:
                if (isQueueFull(&audienceQueue)) {
                    resizeQueue(&audienceQueue);
                }
                printf("Enter the name of the audience member: ");
                scanf(" %[^\n]s", member.name);  // Read name with spaces
                strcpy(member.type, "GENERAL");
                member.id = idCounter++;
                enqueue(&audienceQueue, member);
                printf("General audience member added successfully.\n");
                break;

            case 2:
                if (isQueueFull(&audienceQueue)) {
                    resizeQueue(&audienceQueue);
                }
                printf("Enter the name of the media personnel: ");
                scanf(" %[^\n]s", member.name);  // Read name with spaces
                strcpy(member.type, "MEDIA");
                member.id = idCounter++;
                enqueuePriority(&audienceQueue, member);
                printf("Media personnel added successfully with priority.\n");
                break;

            case 3:
                dequeue(&audienceQueue);
                break;

            case 4:
                displayQueue(&audienceQueue);
                break;

            case 5:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&audienceQueue);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}


void initializeQueue(AudienceQueue *q, int initialCapacity) {

    q->queue = (Audience *)malloc(initialCapacity * sizeof(Audience));

    if (q->queue == NULL) {

        printf("Memory allocation failed. Exiting.\n");
        exit(1);

    }
    q->front = -1;
    q->rear = -1;
    q->capacity = initialCapacity;
}

int isQueueEmpty(AudienceQueue *q) {
    return q->front == -1;
}

int isQueueFull(AudienceQueue *q) {
    return q->rear == q->capacity - 1;
}

void resizeQueue(AudienceQueue *q) {
    q->capacity *= 2;
    q->queue = (Audience *)realloc(q->queue, q->capacity * sizeof(Audience));
    if (q->queue == NULL) {
        printf("Memory allocation failed during resizing. Exiting.\n");
        exit(1);
    }
    printf("Queue resized to capacity: %d\n", q->capacity);
}

void enqueue(AudienceQueue *q, Audience member) {
    if (isQueueFull(q)) {
        resizeQueue(q);
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = member;
}

void enqueuePriority(AudienceQueue *q, Audience member) {

    if (isQueueFull(q)) {
        resizeQueue(q);
    }
    if (isQueueEmpty(q)) {
        enqueue(q, member);
        return;
    }
    for (int i = q->rear; i >= q->front; i--) {
        q->queue[i + 1] = q->queue[i];
    }
    q->queue[q->front] = member;
    q->rear++;
}

void dequeue(AudienceQueue *q) {

    if (isQueueEmpty(q)) {
        printf("The audience queue is empty. No one to remove.\n");
        return;
    }
    printf("Audience member removed: ID: %d, Name: %s, Type: %s\n",
           q->queue[q->front].id, q->queue[q->front].name, q->queue[q->front].type);

    for (int i = q->front; i < q->rear; i++) {
        q->queue[i] = q->queue[i + 1];
    }
    q->rear--;

    if (q->rear < q->front) {
        q->front = -1;
        q->rear = -1;
    }
}

void displayQueue(AudienceQueue *q) {

    if (isQueueEmpty(q)) {
        printf("The audience queue is empty.\n");
        return;
    }
    printf("Audience Queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("ID: %d, Name: %s, Type: %s\n",q->queue[i].id, q->queue[i].name, q->queue[i].type);
    }
}

void freeQueue(AudienceQueue *q) {

    free(q->queue);
    q->queue = NULL;
    q->front = -1;
    q->rear = -1;
    q->capacity = 0;
}
