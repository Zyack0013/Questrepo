// 12. **Bank Loan Application Processing**: Develop a queue using linked lists to manage loan applications at a bank. The system should prioritize applications based on the loan amount and applicant's credit score.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct LoanApplication {
    int id;
    char name[50]; 
    double loanAmount;   
    int creditScore;     
    struct LoanApplication *next;  
} LoanApplication;

typedef struct {
    LoanApplication *front;  
    LoanApplication *rear;   
} LoanQueue;


void initializeQueue(LoanQueue *queue);
int isQueueEmpty(LoanQueue *queue);
void enqueue(LoanQueue *queue, int id, const char *name, double loanAmount, int creditScore);
void dequeue(LoanQueue *queue);
void displayQueue(LoanQueue *queue);
void freeQueue(LoanQueue *queue);


int main() {

    LoanQueue loanQueue;
    initializeQueue(&loanQueue);

    int choice, id = 1;
    char name[50];
    double loanAmount;
    int creditScore;

    while (1) {
        printf("\nBank Loan Application Processing System\n");
        printf("1. Add Loan Application\n");
        printf("2. Process Next Application\n");
        printf("3. View All Applications\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter applicant's name: ");
                scanf(" %[^\n]s", name);
                printf("Enter loan amount: ");
                scanf("%lf", &loanAmount);
                printf("Enter credit score: ");
                scanf("%d", &creditScore);
                enqueue(&loanQueue, id++, name, loanAmount, creditScore);
                printf("Loan application added successfully.\n");
                break;

            case 2:
                dequeue(&loanQueue);
                break;

            case 3:
                displayQueue(&loanQueue);
                break;

            case 4:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&loanQueue);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}


void initializeQueue(LoanQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isQueueEmpty(LoanQueue *queue) {
    return queue->front == NULL;
}


void enqueue(LoanQueue *queue, int id, const char *name, double loanAmount, int creditScore) {

    LoanApplication *newApplication = (LoanApplication *)malloc(sizeof(LoanApplication));

    if (!newApplication) {

        printf("Memory allocation failed. Cannot add application.\n");
        return;
    }

    newApplication->id = id;
    strcpy(newApplication->name, name);
    newApplication->loanAmount = loanAmount;
    newApplication->creditScore = creditScore;
    newApplication->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = newApplication;
        queue->rear = newApplication;
    } else {
        
        LoanApplication *current = queue->front;
        LoanApplication *previous = NULL;

        while (current && (current->loanAmount > loanAmount || (current->loanAmount == loanAmount && current->creditScore >= creditScore))) {

            previous = current;
            current = current->next;
        }

        if (!previous) {
           
            newApplication->next = queue->front;
            queue->front = newApplication;
        } else {
            
            previous->next = newApplication;
            newApplication->next = current;
        }

        if (!current) {
            
            queue->rear = newApplication;
        }
    }
}

void dequeue(LoanQueue *queue) {

    if (isQueueEmpty(queue)) {

        printf("The queue is empty. No applications to process.\n");
        return;
    }

    LoanApplication *applicationToProcess = queue->front;
    printf("Processing application:\n");

    printf("ID: %d, Name: %s, Loan Amount: %.2lf, Credit Score: %d\n",applicationToProcess->id, applicationToProcess->name,applicationToProcess->loanAmount, applicationToProcess->creditScore);

    queue->front = applicationToProcess->next;

    if (!queue->front) {

        queue->rear = NULL;  
    }

    free(applicationToProcess);
}

void displayQueue(LoanQueue *queue) {

    if (isQueueEmpty(queue)) {

        printf("The queue is empty. No applications to display.\n");
        return;

    }

    LoanApplication *current = queue->front;
    printf("Loan Applications in Queue:\n");
    
    while (current) {
        
        printf("ID: %d, Name: %s, Loan Amount: %.2lf, Credit Score: %d\n",current->id, current->name, current->loanAmount, current->creditScore);
        current = current->next;
    }
}

void freeQueue(LoanQueue *queue) {

    while (!isQueueEmpty(queue)) {

        dequeue(queue);

    }

}
