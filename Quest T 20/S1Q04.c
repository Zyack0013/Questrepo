// 4. **Bank Teller Simulation**: Develop a program using a linked list to simulate a queue at a bank. Customers arrive at random intervals, and each teller can handle one customer at a time. The program should simulate multiple tellers and different transaction times.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Customer {

    int id;
    int transactionTime; 
    struct Customer *next;

} Customer;

typedef struct {

    Customer *front;
    Customer *rear;

} Queue;


typedef struct {

    int id;
    int remainingTime; 
    Customer *currentCustomer;

} Teller;

void initializeQueue(Queue *q);
int isQueueEmpty(Queue *q);
void enqueue(Queue *q, int id, int transactionTime);
Customer *dequeue(Queue *q);
void displayQueue(Queue *q);
void simulateBank(Queue *q, Teller tellers[], int numTellers, int maxTime);
void processTellers(Queue *q, Teller tellers[], int numTellers, int time);
void freeQueue(Queue *q);

int main() {

    Queue customerQueue;
    int numTellers = 3;  
    int simulationTime = 20; 

    initializeQueue(&customerQueue);
    Teller tellers[numTellers];

    for (int i = 0; i < numTellers; i++) {

        tellers[i].id = i + 1;
        tellers[i].remainingTime = 0;
        tellers[i].currentCustomer = NULL;

    }

    simulateBank(&customerQueue, tellers, numTellers, simulationTime);

    freeQueue(&customerQueue);

    return 0;
}

void initializeQueue(Queue *q) {

    q->front = NULL;
    q->rear = NULL;

}

int isQueueEmpty(Queue *q) {

    return q->front == NULL;

}

void enqueue(Queue *q, int id, int transactionTime) {

    Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
    newCustomer->id = id;
    newCustomer->transactionTime = transactionTime;
    newCustomer->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = newCustomer;
    } else {
        q->rear->next = newCustomer;
    }
    q->rear = newCustomer;
}

Customer *dequeue(Queue *q) {

    if (isQueueEmpty(q)) {

        return NULL;
    }

    Customer *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {

        q->rear = NULL;
    
    }
    
    return temp;

}

void displayQueue(Queue *q) {

    if (isQueueEmpty(q)) {
        printf("No customers in the queue.\n");
        return;
    }

    Customer *current = q->front;
    printf("Queue: ");

    while (current != NULL) {

        printf("[Customer %d, Time: %d] ", current->id, current->transactionTime);
        current = current->next;
    }
    printf("\n");
}


void simulateBank(Queue *q, Teller tellers[], int numTellers, int maxTime) {
    
    srand(time(0)); 
    int customerID = 1;

    for (int time = 1; time <= maxTime; time++) {
        
        printf("\nTime: %d\n", time);

        
        if (rand() % 3 == 0) { 
        
            int transactionTime = rand() % 5 + 1; 
            enqueue(q, customerID++, transactionTime);
            printf("New customer added to the queue. ID: %d, Transaction Time: %d\n", customerID - 1, transactionTime);
        }

        displayQueue(q);

        processTellers(q, tellers, numTellers, time);
    }
}

void processTellers(Queue *q, Teller tellers[], int numTellers, int time) {
    
    for (int i = 0; i < numTellers; i++) {
        
        if (tellers[i].remainingTime > 0) {
            
            tellers[i].remainingTime--;
            printf("Teller %d is serving Customer %d. Remaining Time: %d\n",tellers[i].id,tellers[i].currentCustomer->id,tellers[i].remainingTime);
            if (tellers[i].remainingTime == 0) {
                printf("Teller %d finished serving Customer %d.\n",tellers[i].id,tellers[i].currentCustomer->id);
                free(tellers[i].currentCustomer); 
                tellers[i].currentCustomer = NULL;
            }
        }

        if (tellers[i].remainingTime == 0 && !isQueueEmpty(q)) {

            tellers[i].currentCustomer = dequeue(q);
            tellers[i].remainingTime = tellers[i].currentCustomer->transactionTime;
            printf("Teller %d started serving Customer %d. Transaction Time: %d\n",tellers[i].id,tellers[i].currentCustomer->id,tellers[i].remainingTime);
        }
    }
}

void freeQueue(Queue *q) {
    
    while (!isQueueEmpty(q)) {

        Customer *temp = dequeue(q);
        free(temp);
    }
}
