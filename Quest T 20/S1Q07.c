// 7. **Election Vote Counting System**: Implement a queue using arrays to manage the vote counting process during an election. The system should handle multiple polling stations and ensure votes are counted in the order received.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {

    int capacity;
    int front;           
    int rear;            
    int *votes;          
    
}Queue;

void initializeQueue(Queue *q, int capacity);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int vote);
int dequeue(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {


    Queue voteQueue;
    int capacity;

    printf("Enter the maximum number of votes the system can handle: ");
    scanf("%d", &capacity);

    initializeQueue(&voteQueue, capacity);

    int choice, vote;

    while (1) {
        printf("\nElection Vote Counting System\n");
        printf("1. Add vote (enqueue)\n");
        printf("2. Process vote (dequeue)\n");
        printf("3. Display remaining votes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull(&voteQueue)) {
                    printf("Queue is full! Cannot add more votes.\n");
                } else {
                    printf("Enter vote (candidate ID): ");
                    scanf("%d", &vote);
                    enqueue(&voteQueue, vote);
                }
                break;

            case 2:
                if (isEmpty(&voteQueue)) {
                    printf("No votes to process. The queue is empty.\n");
                } else {
                    printf("Processed vote for candidate ID: %d\n", dequeue(&voteQueue));
                }
                break;

            case 3:
                displayQueue(&voteQueue);
                break;

            case 4:
                printf("Exiting system.\n");
                freeQueue(&voteQueue);
                return 0;

            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}


void initializeQueue(Queue *q, int capacity){

    q->votes =  (int *)malloc(capacity * sizeof(int));
    
    if (!q->votes) {
    
        printf("Memory allocation failed! Exiting.\n");
        exit(1);
    
    }
    q->front = -1;
    q->rear = -1;
    q->capacity = capacity;
}

int isFull(Queue *q){

    return q->rear == q->capacity - 1;
}

int isEmpty(Queue *q){

    return q->front == -1 || q->front > q->rear;

}

void enqueue(Queue *q, int vote){

    if (isFull(q)) {
        
        printf("Queue is full! Cannot enqueue.\n");
        return;
    
    }
    
    if (isEmpty(q)) {

        q->front = 0; 
    }
    q->rear++;
    q->votes[q->rear] = vote;
    printf("Vote for candidate ID %d added to the queue.\n", vote);

}

int dequeue(Queue *q){

    if (isEmpty(q)) {
    
        printf("Queue is empty!.\n");
        return -1;
    
    }
    
    int vote = q->votes[q->front];
    q->front++;
    
    if (q->front > q->rear) { 

        q->front = q->rear = -1;
    }
    return vote;

}

void displayQueue(Queue *q){

      if (isEmpty(q)) {

        printf("No votes in the queue.\n");
        return;

    }
    
    printf("Remaining votes in queue: ");
    
    for (int i = q->front; i <= q->rear; i++) {

        printf("%d ", q->votes[i]);

    }
    printf("\n");

}

void freeQueue(Queue *q){

    free(q->votes);
    q->votes = NULL;
    q->front = q->rear = -1;
    q->capacity = 0;

}