// 8. **Airport Runway Management**: Use a linked list to implement a queue for airplanes waiting to land or take off. The system should handle priority for emergency landings and manage runway allocation efficiently.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Airplane {

    char flightNumber[10];
    char action[10];         
    int priority;           
    struct Airplane *next;   
    
} Airplane;

typedef struct {

    Airplane *front;  
    Airplane *rear;   

} Queue;


void initializeQueue(Queue *q);
int isQueueEmpty(Queue *q);
void addAirplane(Queue *q, char *flightNumber, char *action, int priority);
void emergencyLanding(Queue *q, char *flightNumber);
void processNextAirplane(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {

    Queue runwayQueue;
    initializeQueue(&runwayQueue);

    int choice;
    char flightNumber[10], action[10];
    int priority;

    while (1) {

        printf("\n\t\tAirport Runway Management System\t\t\n");
        printf("1. Add Airplane\n");
        printf("2. Emergency Landing\n");
        printf("3. Process Next Airplane\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter flight number: ");
                scanf("%s", flightNumber);
                printf("Enter action (LAND/TAKEOFF): ");
                scanf("%s", action);
                printf("Is this an emergency? (1 for Yes, 0 for No): ");
                scanf("%d", &priority);
                addAirplane(&runwayQueue, flightNumber, action, priority);
                printf("Airplane added successfully.\n");
                break;

            case 2:
                printf("Enter flight number for emergency landing: ");
                scanf("%s", flightNumber);
                emergencyLanding(&runwayQueue, flightNumber);
                break;

            case 3:
                processNextAirplane(&runwayQueue);
                break;

            case 4:
                displayQueue(&runwayQueue);
                break;

            case 5:
                freeQueue(&runwayQueue);
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

void addAirplane(Queue *q, char *flightNumber, char *action, int priority) {

    Airplane *newAirplane = (Airplane *)malloc(sizeof(Airplane));

    if (!newAirplane) {

        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newAirplane->flightNumber, flightNumber);
    strcpy(newAirplane->action, action);
    newAirplane->priority = priority;
    newAirplane->next = NULL;

    if (isQueueEmpty(q)) {

        q->front = newAirplane;
        q->rear = newAirplane;
    } else {

        q->rear->next = newAirplane;
        q->rear = newAirplane;
    }
}

void emergencyLanding(Queue *q, char *flightNumber) {
    
    Airplane *prev = NULL, *current = q->front;

    while (current != NULL && strcmp(current->flightNumber, flightNumber) != 0) {

        prev = current;
        current = current->next;

    }

    if (current == NULL) {

        printf("Flight number %s not found in the queue.\n", flightNumber);
        return;
    }

    if (current == q->front) {

        printf("Flight number %s is already at the front for emergency.\n", flightNumber);
        return;
    }

    if (prev != NULL) {

        prev->next = current->next;

    }

    if (current == q->rear) {

        q->rear = prev;

    }

    current->next = q->front;
    q->front = current;
    printf("Flight number %s has been prioritized for emergency landing.\n", flightNumber);
}

void processNextAirplane(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("No airplanes in the queue to process.\n");
        return;
    }

    Airplane *temp = q->front;
    printf("Processing flight %s for %s.\n", temp->flightNumber, temp->action);

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}


void displayQueue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty.\n");
        return;
    }

    printf("Airplane Queue:\n");
    Airplane *current = q->front;

    while (current != NULL) {

        printf("Flight: %s, Action: %s, Priority: %s\n",current->flightNumber, current->action,current->priority ? "Emergency" : "Normal");
        current = current->next;
    }
}

void freeQueue(Queue *q) {

    Airplane *current = q->front;

    while (current != NULL) {
        Airplane *temp = current;
        current = current->next;
        free(temp);
    }

    q->front = NULL;
    q->rear = NULL;

}
