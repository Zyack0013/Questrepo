// Problem 4: Employee Shift Management
// Description: Use a linked list to manage employee shifts in a manufacturing plant.
// Operations:
// Create a shift schedule.
// Insert a new shift.
// Delete a completed or canceled shift.
// Display the current shift schedule.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Shift {
    int shiftID;
    char employeeName[50];
    char shiftTime[20]; // 
    struct Shift *next;
} Shift;

Shift *shiftSchedule = NULL; 
static int totalShifts = 0;

void createShiftSchedule(int count);
void addNewShift();
void deleteShift(int shiftID);
void displayShiftSchedule();

int main() {

    int choice, count, shiftID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a shift schedule.\n");
        printf("2. Insert a new shift.\n");
        printf("3. Delete a completed or canceled shift.\n");
        printf("4. Display the current shift schedule.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of shifts to create: ");
            scanf("%d", &count);
            getchar();
            createShiftSchedule(count);
            printf("\nTotal shifts scheduled: %d\n", totalShifts);
            break;
            case 2:
            addNewShift();
            printf("\nTotal shifts scheduled: %d\n", totalShifts);
            break;
            case 3:
            displayShiftSchedule();
            printf("Enter the Shift ID to delete: ");
            scanf("%d", &shiftID);
            deleteShift(shiftID);
            printf("\nTotal shifts scheduled: %d\n", totalShifts);
            break;
            case 4:
            displayShiftSchedule();
            break;
            case 5:
            printf("Exiting...\n");
            return 0;
            default:
            printf("Invalid choice.!\n");
            break;
        }
    }

    return 0;
}

void createShiftSchedule(int count) {

    if (count <= 0) {
        printf("Invalid number of shifts.\n");
        return;
    }

    Shift *temp, *last = shiftSchedule;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Shift *)malloc(sizeof(Shift));

        if (temp == NULL) {

            printf("Memory allocation failed for shift %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Shift %d:\n", i + 1);
        printf("Enter the Shift ID: ");
        scanf("%d", &temp->shiftID);
        getchar();

        printf("Enter the Employee Name: ");
        fgets(temp->employeeName, sizeof(temp->employeeName), stdin);
        temp->employeeName[strcspn(temp->employeeName, "\n")] = '\0';

        printf("Enter the Shift Time (e.g., 9:00 AM - 5:00 PM): ");
        fgets(temp->shiftTime, sizeof(temp->shiftTime), stdin);
        temp->shiftTime[strcspn(temp->shiftTime, "\n")] = '\0';

        temp->next = NULL;

        if (shiftSchedule == NULL) {

            shiftSchedule = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalShifts++;
    }

    printf("%d shifts created successfully.\n", count);
}

void addNewShift() {

    Shift *temp, *last = shiftSchedule;

    temp = (Shift *)malloc(sizeof(Shift));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Shift ID: ");
    scanf("%d", &temp->shiftID);
    getchar();

    Shift *check = shiftSchedule;
    while (check != NULL) {
        if (check->shiftID == temp->shiftID) {
            printf("Error: Shift ID %d already exists.\n", temp->shiftID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Employee Name: ");
    fgets(temp->employeeName, sizeof(temp->employeeName), stdin);
    temp->employeeName[strcspn(temp->employeeName, "\n")] = '\0';

    printf("Enter the Shift Time (e.g., 9:00 AM - 5:00 PM): ");
    fgets(temp->shiftTime, sizeof(temp->shiftTime), stdin);
    temp->shiftTime[strcspn(temp->shiftTime, "\n")] = '\0';

    temp->next = NULL;

    if (shiftSchedule == NULL) {

        shiftSchedule = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;

        }
        last->next = temp;
    }

    totalShifts++;
    printf("Shift ID %d added successfully.\n", temp->shiftID);
}

void deleteShift(int shiftID) {

    if (shiftSchedule == NULL) {

        printf("Shift schedule is empty.\n");
        return;
    }

    Shift *temp = shiftSchedule, *prev = NULL;

    if (temp != NULL && temp->shiftID == shiftID) {
        shiftSchedule = temp->next;
        free(temp);
        printf("Shift ID %d deleted successfully.\n", shiftID);
        totalShifts--;
        return;
    }

    while (temp != NULL && temp->shiftID != shiftID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Shift ID %d not found.\n", shiftID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Shift ID %d deleted successfully.\n", shiftID);
    totalShifts--;
}

void displayShiftSchedule() {

    if (shiftSchedule == NULL) {

        printf("Shift schedule is empty.\n");
        return;
    }

    Shift *temp = shiftSchedule;
    int i = 1;

    printf("\n\t\tShift Schedule\t\t\n");
    printf("SLNO.\tShift ID\tEmployee Name\t\tShift Time\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%-20s\n", i++, temp->shiftID, temp->employeeName, temp->shiftTime);
        temp = temp->next;
    }

    printf("------------------------------------------------------------\n");
}
