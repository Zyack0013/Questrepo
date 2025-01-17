// 15.Fuel Management System: Develop a stack to monitor fuel usage in an aerospace vehicle. Implement a switch-case menu with options:
// 1: Add a fuel usage entry (push)
// 2: Remove the last entry (pop)
// 3: View all fuel usage data
// 4: Peek at the latest fuel usage entry
// 5: Search for a specific fuel usage entry
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    int capacity;       
    int top;            
    float *fuelUsage;   

} FuelStack;

void initializeStack(FuelStack *s, int initialCapacity);
int isFull(FuelStack *s);
int isEmpty(FuelStack *s);
void addFuelUsage(FuelStack *s, float usage);
void removeFuelUsage(FuelStack *s);
void displayFuelUsage(FuelStack *s);
void peekFuelUsage(FuelStack *s);
void searchFuelUsage(FuelStack *s, float usage);
void freeStack(FuelStack *s);

int main() {


    FuelStack stack;
    int initialCapacity = 10;  
    initializeStack(&stack, initialCapacity);

    int choice;
    float usage;

    while (1) {

        printf("\nFuel Management System Menu:\n");
        printf("1: Add a fuel usage entry\n");
        printf("2: Remove the last entry\n");
        printf("3: View all fuel usage data\n");
        printf("4: Peek at the latest fuel usage entry\n");
        printf("5: Search for a specific fuel usage entry\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
            printf("Enter fuel usage (in liters): ");
            scanf("%f", &usage);
            addFuelUsage(&stack, usage);
            break;

            case 2:
            removeFuelUsage(&stack);
            break;

            case 3:
            displayFuelUsage(&stack);
            break;

            case 4:
            peekFuelUsage(&stack);
            break;

            case 5:
            printf("Enter fuel usage to search for (in liters): ");
            scanf("%f", &usage);
            searchFuelUsage(&stack, usage);
            break;

            case 6:
            printf("Exiting program.\n");
            freeStack(&stack);  
            exit(0);

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}

void initializeStack(FuelStack *s, int initialCapacity) {

    s->fuelUsage = (float *)malloc(initialCapacity * sizeof(float));

    if (!s->fuelUsage) {

        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = initialCapacity;
}

int isFull(FuelStack *s) {
    return s->top == s->capacity - 1;
}

int isEmpty(FuelStack *s) {
    return s->top == -1;
}

void addFuelUsage(FuelStack *s, float usage) {

    if (isFull(s)) {

        s->capacity *= 2;
        s->fuelUsage = (float *)realloc(s->fuelUsage, s->capacity * sizeof(float));

        if (!s->fuelUsage) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    s->fuelUsage[++s->top] = usage;
    printf("Fuel usage entry added: %.2f liters\n", usage);
}

void removeFuelUsage(FuelStack *s) {
    
    if (isEmpty(s)) {

        printf("No fuel usage entries to remove. The stack is empty.\n");
        
    } else {

        printf("Fuel usage entry removed: %.2f liters\n", s->fuelUsage[s->top]);
        s->top--;

    }
}

void displayFuelUsage(FuelStack *s) {

    if (isEmpty(s)) {

        printf("No fuel usage entries logged.\n");

    } else {

        printf("Fuel usage data:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %.2f liters\n", i + 1, s->fuelUsage[i]);

        }
    }
}

void peekFuelUsage(FuelStack *s) {

    if (isEmpty(s)) {

        printf("No fuel usage entries to peek at.\n");

    } else {

        printf("Most recent fuel usage: %.2f liters\n", s->fuelUsage[s->top]);

    }
}

void searchFuelUsage(FuelStack *s, float usage) {

    if (isEmpty(s)) {

        printf("No fuel usage entries to search.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {

            if (s->fuelUsage[i] == usage) {

                printf("Fuel usage %.2f liters found at position %d.\n", usage, i + 1);
                return;
            }
        }
        printf("Fuel usage %.2f liters not found.\n", usage);
    }
}

void freeStack(FuelStack *s) {

    free(s->fuelUsage);
}
