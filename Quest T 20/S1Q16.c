// 16. **Financial Transaction Processing**: Implement a queue using linked lists to process financial transactions. The system should handle deposits, withdrawals, and transfers, ensuring real-time processing and accuracy.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Transaction {

    char type[15];      
    double amount;      
    char account[30];   
    struct Transaction *next;
} Transaction;

typedef struct {
    Transaction *front; 
    Transaction *rear;  
} Queue;


void initializeQueue(Queue *q);
int isQueueEmpty(Queue *q);
void enqueue(Queue *q, const char *type, double amount, const char *account);
void dequeue(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {

    Queue transactionQueue;
    initializeQueue(&transactionQueue);

    int choice;
    char type[15], account[30];
    double amount;

    while (1) {

        printf("\nFinancial Transaction Processing System\n");
        printf("1. Add Deposit\n");
        printf("2. Add Withdrawal\n");
        printf("3. Add Transfer\n");
        printf("4. Process Transaction (Dequeue)\n");
        printf("5. Display All Transactions\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf(" %[^\n]s", account);
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                enqueue(&transactionQueue, "Deposit", amount, account);
                printf("Deposit transaction added.\n");
                break;

            case 2:
                printf("Enter account number: ");
                scanf(" %[^\n]s", account);
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);
                enqueue(&transactionQueue, "Withdrawal", amount, account);
                printf("Withdrawal transaction added.\n");
                break;

            case 3:
                printf("Enter account number: ");
                scanf(" %[^\n]s", account);
                printf("Enter transfer amount: ");
                scanf("%lf", &amount);
                enqueue(&transactionQueue, "Transfer", amount, account);
                printf("Transfer transaction added.\n");
                break;

            case 4:
                dequeue(&transactionQueue);
                break;

            case 5:
                displayQueue(&transactionQueue);
                break;

            case 6:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&transactionQueue);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}


void initializeQueue(Queue *q) {

    q->front = NULL;
    q->rear = NULL;

}


int isQueueEmpty(Queue *q) {

    return q->front == NULL;

}


void enqueue(Queue *q, const char *type, double amount, const char *account) {

    Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));

    if (!newTransaction) {

        printf("Memory allocation failed. Cannot add transaction.\n");
        return;

    }

    strcpy(newTransaction->type, type);
    newTransaction->amount = amount;
    strcpy(newTransaction->account, account);
    newTransaction->next = NULL;

    if (isQueueEmpty(q)) {

        q->front = newTransaction;
        q->rear = newTransaction;

    } else {

        q->rear->next = newTransaction;
        q->rear = newTransaction;

    }
}


void dequeue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty. No transactions to process.\n");
        return;

    }

    Transaction *temp = q->front;
    printf("Processing Transaction:\n");
    printf("Type: %s\n", temp->type);
    printf("Amount: %.2f\n", temp->amount);
    printf("Account: %s\n", temp->account);

    q->front = q->front->next;

    if (q->front == NULL) {

        q->rear = NULL;

    }

    free(temp);
}

void displayQueue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty. No transactions to display.\n");
        return;

    }

    Transaction *current = q->front;
    printf("All Transactions:\n");

    while (current) {

        printf("Type: %s, Amount: %.2f, Account: %s\n",current->type, current->amount, current->account);
        current = current->next;

    }

}


void freeQueue(Queue *q) {

    while (!isQueueEmpty(q)) {

        dequeue(q);

    }
}
