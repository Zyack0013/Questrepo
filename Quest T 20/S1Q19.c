// 19. **Political Survey Data Collection**: Implement a queue using arrays to manage data collection for a political survey. The system should handle multiple surveyors collecting data simultaneously and ensure data consistency.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];     
    char opinion[100]; 
    int age;
} SurveyRecord;


typedef struct {
    SurveyRecord *records; 
    int front;             
    int rear;              
    int capacity;          
} Queue;


void initializeQueue(Queue *q, int capacity);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, SurveyRecord record);
void dequeue(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {

    int initialCapacity = 10;
    Queue surveyQueue;
    initializeQueue(&surveyQueue, initialCapacity);

    int choice;
    SurveyRecord record;

    while (1) {

        printf("\nPolitical Survey Data Collection System\n");
        printf("1. Add Survey Record\n");
        printf("2. Remove First Survey Record\n");
        printf("3. Display All Survey Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (isQueueFull(&surveyQueue)) {
                    printf("Queue is full. Expanding capacity...\n");
                    surveyQueue.capacity *= 2;
                    surveyQueue.records = realloc(surveyQueue.records, surveyQueue.capacity * sizeof(SurveyRecord));
                    if (!surveyQueue.records) {
                        printf("Memory allocation failed.\n");
                        exit(EXIT_FAILURE);
                    }
                }
                printf("Enter participant name: ");
                scanf(" %[^\n]s", record.name);
                printf("Enter age: ");
                scanf("%d", &record.age);
                printf("Enter opinion: ");
                scanf(" %[^\n]s", record.opinion);
                enqueue(&surveyQueue, record);
                printf("Survey record added successfully.\n");
                break;

            case 2:
                dequeue(&surveyQueue);
                break;

            case 3:
                displayQueue(&surveyQueue);
                break;

            case 4:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&surveyQueue);
                return 0;

            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}


void initializeQueue(Queue *q, int capacity) {

    q->records = (SurveyRecord *)malloc(capacity * sizeof(SurveyRecord));

    if (!q->records) {

        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);

    }

    q->front = -1;
    q->rear = -1;
    q->capacity = capacity;
}

int isQueueEmpty(Queue *q) {

    return q->front == -1;

}

int isQueueFull(Queue *q) {

    return q->rear == q->capacity - 1;

}


void enqueue(Queue *q, SurveyRecord record) {

    if (isQueueFull(q)) {

        printf("Queue is full. Cannot add more records.\n");
        return;

    }

    if (isQueueEmpty(q)) {

        q->front = 0;

    }

    q->rear++;
    q->records[q->rear] = record;
}

void dequeue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("Queue is empty. No records to remove.\n");
        return;
    }

    printf("Removing record: Name: %s, Age: %d, Opinion: %s\n", q->records[q->front].name, q->records[q->front].age, q->records[q->front].opinion);

    if (q->front == q->rear) {

        q->front = -1;
        q->rear = -1;

    } else {

        q->front++;

    }
}

void displayQueue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty. No records to display.\n");
        return;

    }
    printf("Survey Records in the Queue:\n");

    for (int i = q->front; i <= q->rear; i++) {

        printf("Name: %s, Age: %d, Opinion: %s\n", q->records[i].name, q->records[i].age, q->records[i].opinion);

    }
}


void freeQueue(Queue *q) {

    free(q->records);

}
