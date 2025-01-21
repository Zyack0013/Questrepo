// 5. **Real-Time Data Feed Processing**: Implement a queue using arrays to process real-time data feeds from multiple financial instruments. The system should handle high-frequency data inputs and ensure data integrity and order.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    int capacity;
    int size;
    int front;
    int rear;
    char **data;

}Queue;


void initializeQueue(Queue *q, int capacity);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q,char const *feed);
void dequeue(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);



int main() {

    int capacity = 5;
    Queue dataFeedQueue;

    initializeQueue(&dataFeedQueue, capacity);

    enqueue(&dataFeedQueue, "AAPL: 150.25");
    enqueue(&dataFeedQueue, "GOOG: 2800.50");
    enqueue(&dataFeedQueue, "MSFT: 330.10");
    enqueue(&dataFeedQueue, "AMZN: 3450.25");
    enqueue(&dataFeedQueue, "TSLA: 900.60");

    printf("Queue after initial data feeds:\n");
    displayQueue(&dataFeedQueue);

    printf("\nProcessing data feeds:\n");
    dequeue(&dataFeedQueue);
    dequeue(&dataFeedQueue);

    printf("\nQueue after processing two feeds:\n");
    displayQueue(&dataFeedQueue);

    enqueue(&dataFeedQueue, "NVDA: 620.75");
    enqueue(&dataFeedQueue, "META: 290.90");

    printf("\nQueue after adding new data feeds:\n");
    displayQueue(&dataFeedQueue);

    
    freeQueue(&dataFeedQueue);

    return 0;


}

void initializeQueue(Queue *q, int capacity){

    q->data = (char **)malloc(capacity * sizeof(char *)); 
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;

}

int isFull(Queue *q){

    return q->size == q->capacity;


}

int isEmpty(Queue *q){

    return q->size == 0;

}

void enqueue(Queue *q,char const *feed){

    if(isFull(q)){

        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = (char *)malloc((strlen(feed) + 1) * sizeof(char));
    strcpy(q->data[q->rear], feed);
    q->size++;
    printf("Enqueued: %s\n", feed);

}

void dequeue(Queue *q) {

    if (isEmpty(q)) {

        printf("Queue is empty!.\n");
        return;
    }
    printf("Dequeued: %s\n", q->data[q->front]);
    free(q->data[q->front]);
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

void displayQueue(Queue *q) {
 
    if (isEmpty(q)) {
        printf("Queue is empty!.\n");
        return;
    }
 
    printf("Current Queue:\n");
 
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%s\n", q->data[index]);
    }
}


void freeQueue(Queue *q) {
 
    for (int i = 0; i < q->size; i++) {
 
        int index = (q->front + i) % q->capacity;
        free(q->data[index]);
 
    }
    free(q->data);
}