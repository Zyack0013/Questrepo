// Problem 8: Quality Control Checklist
// Description: Implement a linked list to manage a quality control checklist.
// Operations:
// Create a quality control checklist.
// Insert a new checklist item.
// Delete a completed or outdated checklist item.
// Display the current quality control checklist.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Checklist {

    int itemID;
    char itemName[100];
    char itemStatus[20];
    struct Checklist *next;

} Checklist;

Checklist *qualityChecklist = NULL;
static int totalItems = 0;

void createChecklist(int count);
void insertNewItem();
void deleteItem(int itemID);
void displayChecklist();

int main() {

    int choice, count, itemID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a quality control checklist.\n");
        printf("2. Insert a new checklist item.\n");
        printf("3. Delete a completed or outdated checklist item.\n");
        printf("4. Display the current quality control checklist.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of items to add: ");
            scanf("%d", &count);
            getchar();
            createChecklist(count);
            printf("\nTotal items: %d\n", totalItems);
            break;

            case 2:
            insertNewItem();
            printf("\nTotal items: %d\n", totalItems);
            break;

            case 3:
            displayChecklist();
            printf("Enter the Item ID to delete: ");
            scanf("%d", &itemID);
            deleteItem(itemID);
            printf("\nTotal items: %d\n", totalItems);
            break;

            case 4:
            displayChecklist();
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

void createChecklist(int count) {

    if (count <= 0) {
        printf("Invalid number of items.\n");
        return;
    }

    Checklist *temp, *last = qualityChecklist;

    while (last != NULL && last->next != NULL) {

        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Checklist *)malloc(sizeof(Checklist));

        if (temp == NULL) {

            printf("Memory allocation failed for item %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Item %d:\n", i + 1);
        printf("Enter the Item ID: ");
        scanf("%d", &temp->itemID);
        getchar();

        printf("Enter the Item Name: ");
        fgets(temp->itemName, sizeof(temp->itemName), stdin);
        temp->itemName[strcspn(temp->itemName, "\n")] = '\0';

        printf("Enter the Item Status (e.g., Pending, Completed): ");
        fgets(temp->itemStatus, sizeof(temp->itemStatus), stdin);
        temp->itemStatus[strcspn(temp->itemStatus, "\n")] = '\0';

        temp->next = NULL;

        if (qualityChecklist == NULL) {

            qualityChecklist = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalItems++;
    }

    printf("%d items added successfully.\n", count);
}

void insertNewItem() {

    Checklist *temp, *last = qualityChecklist;

    temp = (Checklist *)malloc(sizeof(Checklist));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Item ID: ");
    scanf("%d", &temp->itemID);
    getchar();

    Checklist *check = qualityChecklist;

    while (check != NULL) {

        if (check->itemID == temp->itemID) {

            printf("Error: Item ID %d already exists.\n", temp->itemID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Item Name: ");
    fgets(temp->itemName, sizeof(temp->itemName), stdin);
    temp->itemName[strcspn(temp->itemName, "\n")] = '\0';

    printf("Enter the Item Status (e.g., Pending, Completed): ");
    fgets(temp->itemStatus, sizeof(temp->itemStatus), stdin);
    temp->itemStatus[strcspn(temp->itemStatus, "\n")] = '\0';

    temp->next = NULL;

    if (qualityChecklist == NULL) {

        qualityChecklist = temp;
        
    } else {

        while (last->next != NULL) {

            last = last->next;

        }
        last->next = temp;
    }

    totalItems++;
    printf("Item ID %d added successfully.\n", temp->itemID);
}

void deleteItem(int itemID) {

    if (qualityChecklist == NULL) {

        printf("Checklist is empty.\n");
        return;
    }

    Checklist *temp = qualityChecklist, *prev = NULL;

    if (temp != NULL && temp->itemID == itemID) {
        qualityChecklist = temp->next;
        free(temp);
        printf("Item ID %d deleted successfully.\n", itemID);
        totalItems--;
        return;
    }

    while (temp != NULL && temp->itemID != itemID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Item ID %d not found.\n", itemID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Item ID %d deleted successfully.\n", itemID);
    totalItems--;
}

void displayChecklist() {
    if (qualityChecklist == NULL) {
        printf("Checklist is empty.\n");
        return;
    }

    Checklist *temp = qualityChecklist;
    int i = 1;
    printf("\n\t\tQuality Control Checklist\t\t\n");
    printf("SLNO.\tItem ID\t\tItem Name\t\tItem Status\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%-20s\n", i++, temp->itemID, temp->itemName, temp->itemStatus);
        temp = temp->next;

    }

    printf("------------------------------------------------------------\n");
}
