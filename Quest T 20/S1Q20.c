// 20. **Financial Market Data Analysis**: Use linked lists to implement a queue for analyzing financial market data. The system should handle large volumes of data, perform real-time analysis, and generate insights for decision-making.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MarketData {
    char symbol[10];    
    double price;       
    int volume;         
    struct MarketData *next; 
} MarketData;


typedef struct {
    MarketData *front;  
    MarketData *rear;   
} Queue;

void initializeQueue(Queue *q);
int isQueueEmpty(Queue *q);
void enqueue(Queue *q, char *symbol, double price, int volume);
void dequeue(Queue *q);
void displayQueue(Queue *q);
void analyzeData(Queue *q);
void freeQueue(Queue *q);

int main() {

    Queue marketQueue;
    initializeQueue(&marketQueue);

    int choice;
    char symbol[10];
    double price;
    int volume;

    while (1) {
        printf("\nFinancial Market Data Analysis System\n");
        printf("1. Add Market Data\n");
        printf("2. Remove Oldest Market Data\n");
        printf("3. Display Market Data Queue\n");
        printf("4. Analyze Market Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter symbol: ");
                scanf("%s", symbol);
                printf("Enter price: ");
                scanf("%lf", &price);
                printf("Enter volume: ");
                scanf("%d", &volume);
                enqueue(&marketQueue, symbol, price, volume);
                printf("Market data added successfully.\n");
                break;

            case 2:
                dequeue(&marketQueue);
                break;

            case 3:
                displayQueue(&marketQueue);
                break;

            case 4:
                analyzeData(&marketQueue);
                break;

            case 5:
                printf("Exiting the system. Goodbye!\n");
                freeQueue(&marketQueue);
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

void enqueue(Queue *q, char *symbol, double price, int volume) {

    MarketData *newNode = (MarketData *)malloc(sizeof(MarketData));

    if (!newNode) {

        printf("Memory allocation failed.\n");
        return;

    }

    strcpy(newNode->symbol, symbol);
    newNode->price = price;
    newNode->volume = volume;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {

        q->front = newNode;

    } else {

        q->rear->next = newNode;

    }

    q->rear = newNode;

}

void dequeue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty. No data to remove.\n");
        return;

    }

    MarketData *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {

        q->rear = NULL;

    }

    printf("Removing data: Symbol: %s, Price: %.2f, Volume: %d\n", temp->symbol, temp->price, temp->volume);
    free(temp);
}

void displayQueue(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty. No data to display.\n");
        return;

    }

    MarketData *current = q->front;
    printf("Market Data Queue:\n");

    while (current) {

        printf("Symbol: %s, Price: %.2f, Volume: %d\n", current->symbol, current->price, current->volume);
        current = current->next;

    }

}

void analyzeData(Queue *q) {

    if (isQueueEmpty(q)) {

        printf("The queue is empty. No data to analyze.\n");
        return;
    }

    double totalValue = 0.0;
    int totalVolume = 0;
    int count = 0;
    MarketData *current = q->front;

    while (current) {

        totalValue += current->price * current->volume;
        totalVolume += current->volume;
        count++;
        current = current->next;
    }

    double averagePrice = totalVolume > 0 ? totalValue / totalVolume : 0;
    printf("Analysis:\n");
    printf("Total Transactions: %d\n", count);
    printf("Total Volume: %d\n", totalVolume);
    printf("Average Price: %.2f\n", averagePrice);
}


void freeQueue(Queue *q) {

    while (!isQueueEmpty(q)) {

        dequeue(q);

    }

}
