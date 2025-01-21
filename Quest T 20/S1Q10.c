// 10. **Conference Registration System**: Implement a queue using linked lists for managing registrations at a conference. The system should handle walk-in registrations, pre-registrations, and cancellations.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int registrationId;
    char name[50];       
    char type[15];       
} Registration;


typedef struct Node {
    Registration registration; 
    struct Node *next;          
} Node;


typedef struct {
    Node *front;  
    Node *rear;   
} Queue;


void initializeQueue(Queue *q);
int isQueueEmpty(Queue *q);
void enqueue(Queue *q, Registration reg);
void dequeue(Queue *q);
void cancelRegistration(Queue *q, int registrationId);
void displayRegistrations(Queue *q);

int main() {

    Queue registrationQueue;
    initializeQueue(&registrationQueue);

    int choice, registrationId;
    char name[50], type[15];

    while (1) {

        printf("\nConference Registration System\n");
        printf("1. Register Walk-In\n");
        printf("2. Register Pre-Registration\n");
        printf("3. Cancel Registration\n");
        printf("4. View All Registrations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter your name: ");
                scanf(" %[^\n]s", name);  
                strcpy(type, "WALK-IN");
                registrationId = rand() % 1000 + 1;  
                printf("Your registration ID is: %d\n", registrationId);
                Registration walkInReg = {registrationId, "", ""};
                strcpy(walkInReg.name, name);
                strcpy(walkInReg.type, type);
                enqueue(&registrationQueue, walkInReg);
                break;

            case 2:
                printf("Enter your name: ");
                scanf(" %[^\n]s", name);  
                strcpy(type, "PRE-REGISTER");
                registrationId = rand() % 1000 + 1;  
                printf("Your registration ID is: %d\n", registrationId);
                Registration preReg = {registrationId, "", ""};
                strcpy(preReg.name, name);
                strcpy(preReg.type, type);
                enqueue(&registrationQueue, preReg);
                break;

            case 3:
                if (isQueueEmpty(&registrationQueue)) {
                    printf("No registrations to cancel.\n");
                } else {
                    printf("Enter the registration ID to cancel: ");
                    scanf("%d", &registrationId);
                    cancelRegistration(&registrationQueue, registrationId);
                }
                break;

            case 4:
                displayRegistrations(&registrationQueue);
                break;

            case 5:
                printf("Exiting the system. Goodbye!\n");
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


void enqueue(Queue *q, Registration reg) {

    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {

        printf("Memory allocation failed. Cannot register.\n");
        return;
    }
    newNode->registration = reg;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {

        q->front = newNode;
        q->rear = newNode;

    } else {

        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Registration successful for %s (ID: %d, Type: %s).\n",reg.name, reg.registrationId, reg.type);

}


void dequeue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("No registrations to process.\n");
        return;

    }

    Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {

        q->rear = NULL;  

    }

    printf("Processing registration for %s (ID: %d, Type: %s).\n",temp->registration.name, temp->registration.registrationId, temp->registration.type);
    free(temp);
}

void cancelRegistration(Queue *q, int registrationId) {

    if (isQueueEmpty(q)) {

        printf("No registrations to cancel.\n");
        return;

    }

    Node *temp = q->front;
    Node *prev = NULL;

    while (temp != NULL && temp->registration.registrationId != registrationId) {

        prev = temp;
        temp = temp->next;

    }

    if (temp == NULL) {
        
        printf("Registration ID %d not found.\n", registrationId);
        return;

    }

    if (prev == NULL) {

        q->front = temp->next;  
    
    } else {

        prev->next = temp->next;

    }

    if (temp == q->rear) {

        q->rear = prev;  

    }

    free(temp);
    printf("Registration ID %d has been cancelled successfully.\n", registrationId);
}

void displayRegistrations(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("No registrations available.\n");
        return;
    }

    Node *temp = q->front;
    printf("Registrations:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: %s, Type: %s\n",
               temp->registration.registrationId,
               temp->registration.name,
               temp->registration.type);
        temp = temp->next;
    }
}
