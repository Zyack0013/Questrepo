// 14. **Public Transport Scheduling**: Use linked lists to implement a queue for managing bus arrivals and departures at a terminal. The system should handle peak hours, off-peak hours, and prioritize express buses.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Bus {
    int busID;              
    char type[20];
    char schedule[20];
    struct Bus *next;       
} Bus;


typedef struct {
    Bus *front;
    Bus *rear;
} Queue;


void initializeQueue(Queue *queue);
int isQueueEmpty(Queue *queue);
void enqueue(Queue *queue, int busID, const char *type, const char *schedule);
void enqueueExpress(Queue *queue, int busID, const char *schedule);
void dequeue(Queue *queue);
void displayQueue(Queue *queue);
void freeQueue(Queue *queue);


int main() {

    Queue busQueue;
    initializeQueue(&busQueue);

    int choice, busID = 1;
    char type[20], schedule[20];

    while (1) {

        printf("\nPublic Transport Scheduling System\n");
        printf("1. Add Regular Bus\n");
        printf("2. Add Express Bus\n");
        printf("3. Dispatch Bus\n");
        printf("4. Display Bus Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter schedule (Peak/Off-Peak): ");
                scanf(" %[^\n]s", schedule);
                enqueue(&busQueue, busID++, "Regular", schedule);
                printf("Regular bus added to the queue.\n");
                break;

            case 2:
                printf("Enter schedule (Peak/Off-Peak): ");
                scanf(" %[^\n]s", schedule);
                enqueueExpress(&busQueue, busID++, schedule);
                printf("Express bus added to the queue with priority.\n");
                break;

            case 3:
                dequeue(&busQueue);
                break;

            case 4:
                displayQueue(&busQueue);
                break;

            case 5:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&busQueue);
                return 0;

            default:
                printf("Invalid choice!.\n");
                break;
        }
    }

    return 0;
}


void initializeQueue(Queue *queue) {

    queue->front = NULL;
    queue->rear = NULL;

}


int isQueueEmpty(Queue *queue) {

    return queue->front == NULL;

}


void enqueue(Queue *queue, int busID, const char *type, const char *schedule) {

    Bus *newBus = (Bus *)malloc(sizeof(Bus));

    if (!newBus) {

        printf("Memory allocation failed. Exiting.\n");
        exit(1);

    }

    newBus->busID = busID;
    strcpy(newBus->type, type);
    strcpy(newBus->schedule, schedule);
    newBus->next = NULL;

    if (isQueueEmpty(queue)) {

        queue->front = newBus;

    } else {

        queue->rear->next = newBus;

    }

    queue->rear = newBus;

}


void enqueueExpress(Queue *queue, int busID, const char *schedule) {

    Bus *newBus = (Bus *)malloc(sizeof(Bus));

    if (!newBus) {

        printf("Memory allocation failed. Exiting.\n");
        exit(1);

    }

    newBus->busID = busID;
    strcpy(newBus->type, "Express");
    strcpy(newBus->schedule, schedule);
    newBus->next = NULL;

    if (isQueueEmpty(queue) || strcmp(queue->front->type, "Regular") == 0) {

        newBus->next = queue->front;
        queue->front = newBus;

        if (queue->rear == NULL) {

            queue->rear = newBus;

        }

    } else {

        Bus *current = queue->front;

        while (current->next != NULL && strcmp(current->next->type, "Express") == 0) {

            current = current->next;

        }

        newBus->next = current->next;
        current->next = newBus;

        if (newBus->next == NULL) {

            queue->rear = newBus;

        }
    }
}


void dequeue(Queue *queue) {

    if (isQueueEmpty(queue)) {

        printf("The queue is empty. No buses to dispatch.\n");
        return;

    }

    Bus *temp = queue->front;
    printf("Dispatching bus:\n");
    printf("ID: %d, Type: %s, Schedule: %s\n", temp->busID, temp->type, temp->schedule);

    queue->front = queue->front->next;

    if (queue->front == NULL) {

        queue->rear = NULL;

    }

    free(temp);

}

void displayQueue(Queue *queue) {

    if (isQueueEmpty(queue)) {

        printf("The queue is empty. No buses to display.\n");
        return;

    }

    printf("Current Bus Queue:\n");
    Bus *current = queue->front;

    while (current != NULL) {

        printf("ID: %d, Type: %s, Schedule: %s\n", current->busID, current->type, current->schedule);
        current = current->next;

    }

}

void freeQueue(Queue *queue) {

    Bus *current = queue->front;

    while (current != NULL) {

        Bus *temp = current;
        current = current->next;
        free(temp);

    }
    queue->front = NULL;
    queue->rear = NULL;
}
