// 6. **Traffic Light Control System**: Use a linked list to implement a queue for cars at a traffic light. The system should manage cars arriving at different times and simulate the light changing from red to green.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Car{
    
    int carID;
    struct Car *next;

}Car;

typedef struct{
    
    Car *front;
    Car *rear;
}Queue;



int main() {

    Queue trafficQueue;
    initializeQueue(&trafficQueue);

    int choice, carId;

    while (1) {
        printf("\nTraffic Light Control System\n");
        printf("1. Add car to queue (arriving at red light)\n");
        printf("2. Simulate light turning green (remove cars from queue)\n");
        printf("3. Display cars in queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter car ID to add: ");
                scanf("%d", &carId);
                enqueue(&trafficQueue, carId);
                break;

            case 2:
                simulateTrafficLight(&trafficQueue);
                break;

            case 3:
                displayQueue(&trafficQueue);
                break;

            case 4:
                printf("Exiting system.\n");
                while (!isEmpty(&trafficQueue)) {
                    dequeue(&trafficQueue);
                }
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

int isEmpty(Queue *q) {

    return q->front == NULL;

}

void enqueue(Queue *q, int carId) {

    Car *newCar = (Car *)malloc(sizeof(Car));
    
    if (!newCar) {
        printf("Memory allocation failed! Cannot add car to queue.\n");
        return;
    }
    
    newCar->carID = carId;
    newCar->next = NULL;

    if (isEmpty(q)) {
        q->front = newCar;
        q->rear = newCar;
    } else {
        q->rear->next = newCar;
        q->rear = newCar;
    }
    printf("Car %d added to the queue.\n", carId);
}

void dequeue(Queue *q) {

    if (isEmpty(q)) {

        printf("No cars in the queue.\n");
        return;
    }

    Car *temp = q->front;
    printf("Car %d passed through the light.\n", temp->carID);
    q->front = q->front->next;

    if (q->front == NULL) {  
        q->rear = NULL;
    }

    free(temp);
}

void simulateTrafficLight(Queue *q) {

    if (isEmpty(q)) {
        printf("No cars to process. The queue is empty.\n");
        return;
    }

    int numCars;
    printf("Enter the number of cars to pass through: ");
    scanf("%d", &numCars);

    while (numCars-- > 0 && !isEmpty(q)) {

        dequeue(q);
    }
}
