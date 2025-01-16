// Problem 15: Finished Goods Dispatch System
// Description: Use a linked list to manage the dispatch schedule of finished goods.
// Operations:
// Create a dispatch schedule.
// Insert a new dispatch entry.
// Delete a dispatched or canceled entry.
// Display the current dispatch schedule.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dispatch {

    int dispatchID;
    char productName[100];
    int quantity;
    char dispatchDate[20];  
    char status[20];        
    struct Dispatch *next;

} Dispatch;

Dispatch *dispatchList = NULL;  
static int totalDispatches = 0;

void createDispatchSchedule(int count);
void insertNewDispatchEntry();
void deleteDispatchEntry(int dispatchID);
void displayDispatchSchedule();

int main() {

    int choice, count, dispatchID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a dispatch schedule.\n");
        printf("2. Insert a new dispatch entry.\n");
        printf("3. Delete a dispatched or canceled entry.\n");
        printf("4. Display the current dispatch schedule.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of dispatches to add: ");
            scanf("%d", &count);
            getchar();
            createDispatchSchedule(count);
            printf("\nTotal dispatches in the system: %d\n", totalDispatches);
            break;

            case 2:
            insertNewDispatchEntry();
            printf("\nTotal dispatches in the system: %d\n", totalDispatches);
            break;

            case 3:
            displayDispatchSchedule();
            printf("Enter the dispatch ID to delete (dispatched or canceled entry): ");
            scanf("%d", &dispatchID);
            deleteDispatchEntry(dispatchID);
            printf("\nTotal dispatches in the system: %d\n", totalDispatches);
            break;

            case 4:
            displayDispatchSchedule();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}

void createDispatchSchedule(int count) {

    if (count <= 0) {

        printf("Invalid number of dispatches.\n");
        return;
    }

    Dispatch *temp, *last = dispatchList;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Dispatch *)malloc(sizeof(Dispatch));

        if (temp == NULL) {

            printf("Memory allocation failed for dispatch entry %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Dispatch %d:\n", i + 1);
        printf("Enter the Dispatch ID: ");
        scanf("%d", &temp->dispatchID);
        getchar();

        printf("Enter the Product Name: ");
        fgets(temp->productName, sizeof(temp->productName), stdin);
        temp->productName[strcspn(temp->productName, "\n")] = '\0';

        printf("Enter the Quantity: ");
        scanf("%d", &temp->quantity);
        getchar();

        printf("Enter the Dispatch Date (YYYY-MM-DD): ");
        fgets(temp->dispatchDate, sizeof(temp->dispatchDate), stdin);
        temp->dispatchDate[strcspn(temp->dispatchDate, "\n")] = '\0';

        printf("Enter the Dispatch Status: ");
        fgets(temp->status, sizeof(temp->status), stdin);
        temp->status[strcspn(temp->status, "\n")] = '\0';

        temp->next = NULL;

        if (dispatchList == NULL) {

            dispatchList = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalDispatches++;
    }

    printf("%d dispatches added to the system successfully.\n", count);
}

void insertNewDispatchEntry() {

    Dispatch *temp, *last = dispatchList;

    temp = (Dispatch *)malloc(sizeof(Dispatch));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Dispatch ID: ");
    scanf("%d", &temp->dispatchID);
    getchar();

    Dispatch *check = dispatchList;

    while (check != NULL) {

        if (check->dispatchID == temp->dispatchID) {

            printf("Error: Dispatch ID %d already exists.\n", temp->dispatchID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Product Name: ");
    fgets(temp->productName, sizeof(temp->productName), stdin);
    temp->productName[strcspn(temp->productName, "\n")] = '\0';

    printf("Enter the Quantity: ");
    scanf("%d", &temp->quantity);
    getchar();

    printf("Enter the Dispatch Date (YYYY-MM-DD): ");
    fgets(temp->dispatchDate, sizeof(temp->dispatchDate), stdin);
    temp->dispatchDate[strcspn(temp->dispatchDate, "\n")] = '\0';

    printf("Enter the Dispatch Status: ");
    fgets(temp->status, sizeof(temp->status), stdin);
    temp->status[strcspn(temp->status, "\n")] = '\0';

    temp->next = NULL;

    if (dispatchList == NULL) {
        dispatchList = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;

        }
        last->next = temp;
    }

    totalDispatches++;
    printf("Dispatch ID %d added to the system successfully.\n", temp->dispatchID);
}

void deleteDispatchEntry(int dispatchID) {

    if (dispatchList == NULL) {

        printf("No dispatches to delete.\n");
        return;
    }

    Dispatch *temp = dispatchList, *prev = NULL;

    if (temp != NULL && temp->dispatchID == dispatchID) {

        dispatchList = temp->next;
        free(temp);
        printf("Dispatch ID %d deleted successfully.\n", dispatchID);
        totalDispatches--;
        return;
    }

    while (temp != NULL && temp->dispatchID != dispatchID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Dispatch ID %d not found.\n", dispatchID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Dispatch ID %d deleted successfully.\n", dispatchID);
    totalDispatches--;
}

void displayDispatchSchedule() {

    if (dispatchList == NULL) {

        printf("No dispatches to display.\n");
        return;
    }

    Dispatch *temp = dispatchList;
    int i = 1;
    printf("\n\t\tDispatch Schedule\t\t\n");
    printf("SLNO.\tDispatch ID\tProduct Name\tQuantity\tDispatch Date\tStatus\n");
    printf("-----------------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%d\t\t%s\t\t%s\n", i++, temp->dispatchID, temp->productName, temp->quantity, temp->dispatchDate, temp->status);

        temp = temp->next;
    }

    printf("-----------------------------------------------------------------------\n");
}
