// 2. **Customer Service Center Simulation**: Use a linked list to implement a queue for a customer service center. Each customer has a priority level based on their membership status, and the program should handle priority-based queueing and dynamic customer arrival.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Customer {

    int id;                  
    char name[50];           
    int priority;            
    struct Customer *next;   

} Customer;


typedef struct {
    Customer *front;  
    Customer *rear;   
} Queue;


void initializeQueue(Queue *q);
int isQueueEmpty(Queue *q);
void enqueue(Queue *q, int id, const char *name, int priority);
void serveCustomer(Queue *q);
void displayQueue(Queue *q);

int main() {

    Queue queue;
    initializeQueue(&queue);

    int choice, id, priority;
    char name[50];
    int nextCustomerId = 1;

    while (1) {

        printf("\nCustomer Service Center Simulation\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1:

                printf("Enter customer name: ");
                scanf("%s", name);
                printf("Enter priority level (1 = low, 2 = medium, 3 = high): ");
                scanf("%d", &priority);
                if (priority < 1 || priority > 3) {
                    printf("Invalid priority. Please enter 1, 2, or 3.\n");
                } else {
                    enqueue(&queue, nextCustomerId++, name, priority);
                    printf("Customer added to the queue.\n");
                }
                break;

            case 2:
                serveCustomer(&queue);
                break;

            case 3:
                displayQueue(&queue);
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}

void initializeQueue(Queue *q) {

    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(Queue *q) {

    return q->front == NULL;

}

void enqueue(Queue *q, int id, const char *name, int priority) {

    Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
    newCustomer->id = id;
    strcpy(newCustomer->name, name);
    newCustomer->priority = priority;
    newCustomer->next = NULL;

    if (isQueueEmpty(q)) {

        q->front = newCustomer;
        q->rear = newCustomer;
        return;

    }

    Customer *current = q->front;
    Customer *previous = NULL;

    while (current != NULL && current->priority >= priority) {

        previous = current;
        current = current->next;
    }

    if (previous == NULL) {

        newCustomer->next = q->front;
        q->front = newCustomer;
    } else {

        previous->next = newCustomer;
        newCustomer->next = current;

        if (current == NULL) {

            q->rear = newCustomer;

        }
    }
}

void serveCustomer(Queue *q) {
    
    if (isQueueEmpty(q)) {

        printf("No customers in the queue.\n");
        return;
    
    }

    Customer *customerToServe = q->front;
    printf("Serving customer: ID = %d, Name = %s, Priority = %d\n",customerToServe->id, customerToServe->name, customerToServe->priority);

    q->front = customerToServe->next;

    if (q->front == NULL) {

        q->rear = NULL;  

    }

    free(customerToServe);
}

void displayQueue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty.\n");
        return;

    }

    printf("Queue (highest priority first):\n");
    Customer *current = q->front;

    while (current != NULL) {

        printf("ID = %d, Name = %s, Priority = %d\n",current->id, current->name, current->priority);
        current = current->next;

    }
}
