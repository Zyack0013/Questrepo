// 18. **Hospital Emergency Room Queue**: Develop a queue using linked lists to manage patients in a hospital emergency room. The system should prioritize patients based on the severity of their condition and manage multiple doctors.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient {

    char name[50];
    int severity;  
    struct Patient *next;
} Patient;


typedef struct {
    Patient *front;
    Patient *rear;
} Queue;

void initializeQueue(Queue *q);
int isQueueEmpty(Queue *q);
void enqueue(Queue *q, const char *name, int severity);
void dequeue(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {

    Queue emergencyQueue;
    initializeQueue(&emergencyQueue);

    int choice;
    char name[50];
    int severity;

    while (1) {

        printf("\nHospital Emergency Room Queue System\n");
        printf("1. Add Patient\n");
        printf("2. Treat Next Patient\n");
        printf("3. Display Patient Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter patient name: ");
                scanf(" %[^\n]s", name);
                printf("Enter severity (1-10, 10 = most severe): ");
                scanf("%d", &severity);
                if (severity < 1 || severity > 10) {
                    printf("Invalid severity. Please enter a value between 1 and 10.\n");
                } else {
                    enqueue(&emergencyQueue, name, severity);
                    printf("Patient added to the queue.\n");
                }
                break;

            case 2:
                dequeue(&emergencyQueue);
                break;

            case 3:
                displayQueue(&emergencyQueue);
                break;

            case 4:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&emergencyQueue);
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


void enqueue(Queue *q, const char *name, int severity) {

    Patient *newPatient = (Patient *)malloc(sizeof(Patient));

    if (!newPatient) {

        printf("Memory allocation failed. Unable to add patient.\n");
        return;

    }

    strcpy(newPatient->name, name);
    newPatient->severity = severity;
    newPatient->next = NULL;

    
    if (isQueueEmpty(q) || severity > q->front->severity) {
        
        newPatient->next = q->front;
        q->front = newPatient;
        
        if (q->rear == NULL) {
        
            q->rear = newPatient;
        
        }
    } else {
        
        Patient *current = q->front;
        
        while (current->next != NULL && current->next->severity >= severity) {
        
            current = current->next;
        
        }
        
        newPatient->next = current->next;
        current->next = newPatient;
        
        if (newPatient->next == NULL) {
        
            q->rear = newPatient;
        
        }
    }
}


void dequeue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("No patients in the queue.\n");
        return;

    }

    Patient *temp = q->front;
    printf("Treating patient: %s (Severity: %d)\n", temp->name, temp->severity);
    q->front = q->front->next;

    if (q->front == NULL) {

        q->rear = NULL;

    }

    free(temp);
}

void displayQueue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty. No patients to display.\n");
        return;

    }

    printf("Patients in the queue:\n");
    Patient *current = q->front;

    while (current != NULL) {

        printf("Name: %s, Severity: %d\n", current->name, current->severity);
        current = current->next;

    }

}

void freeQueue(Queue *q) {

    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
}
