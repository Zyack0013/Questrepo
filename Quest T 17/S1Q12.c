// Problem 12: Machine Parts Inventory
// Description: Use a linked list to track machine parts inventory.
// Operations:
// Create a parts inventory list.
// Insert a new part.
// Delete a part that is used up or obsolete.
// Display the current parts inventory.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Part {

    int partID;
    char partName[100];
    int quantity;
    struct Part *next;
} Part;

Part *partsInventory = NULL; 
static int totalParts = 0;

void createPartsInventory(int count);
void insertNewPart();
void deletePart(int partID);
void displayPartsInventory();

int main() {

    int choice, count, partID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a parts inventory list.\n");
        printf("2. Insert a new part.\n");
        printf("3. Delete a part that is used up or obsolete.\n");
        printf("4. Display the current parts inventory.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of parts to add: ");
            scanf("%d", &count);
            getchar();
            createPartsInventory(count);
            printf("\nTotal parts in inventory: %d\n", totalParts);
            break;

            case 2:
            insertNewPart();
            printf("\nTotal parts in inventory: %d\n", totalParts);
            break;

            case 3:
            displayPartsInventory();
            printf("Enter the part ID to delete: ");
            scanf("%d", &partID);
            deletePart(partID);
            printf("\nTotal parts in inventory: %d\n", totalParts);
            break;

            case 4:
            displayPartsInventory();
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

void createPartsInventory(int count) {

    if (count <= 0) {

        printf("Invalid number of parts.\n");
        return;
    }

    Part *temp, *last = partsInventory;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Part *)malloc(sizeof(Part));

        if (temp == NULL) {

            printf("Memory allocation failed for part entry %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Part %d:\n", i + 1);
        printf("Enter the Part ID: ");
        scanf("%d", &temp->partID);
        getchar();

        printf("Enter the Part Name: ");
        fgets(temp->partName, sizeof(temp->partName), stdin);
        temp->partName[strcspn(temp->partName, "\n")] = '\0';

        printf("Enter the Quantity: ");
        scanf("%d", &temp->quantity);
        getchar();

        temp->next = NULL;

        if (partsInventory == NULL) {

            partsInventory = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalParts++;
    }

    printf("%d parts added to inventory successfully.\n", count);
}

void insertNewPart() {

    Part *temp, *last = partsInventory;

    temp = (Part *)malloc(sizeof(Part));
    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Part ID: ");
    scanf("%d", &temp->partID);
    getchar();

    Part *check = partsInventory;

    while (check != NULL) {

        if (check->partID == temp->partID) {

            printf("Error: Part ID %d already exists.\n", temp->partID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Part Name: ");
    fgets(temp->partName, sizeof(temp->partName), stdin);
    temp->partName[strcspn(temp->partName, "\n")] = '\0';

    printf("Enter the Quantity: ");
    scanf("%d", &temp->quantity);
    getchar();

    temp->next = NULL;

    if (partsInventory == NULL) {

        partsInventory = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalParts++;
    printf("Part ID %d added to inventory successfully.\n", temp->partID);
}

void deletePart(int partID) {

    if (partsInventory == NULL) {

        printf("Inventory is empty.\n");
        return;
    }

    Part *temp = partsInventory, *prev = NULL;

    if (temp != NULL && temp->partID == partID) {
        partsInventory = temp->next;
        free(temp);
        printf("Part ID %d deleted successfully.\n", partID);
        totalParts--;
        return;
    }

    while (temp != NULL && temp->partID != partID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Part ID %d not found.\n", partID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Part ID %d deleted successfully.\n", partID);
    totalParts--;
}

void displayPartsInventory() {

    if (partsInventory == NULL) {

        printf("Inventory is empty.\n");
        return;
    }

    Part *temp = partsInventory;
    int i = 1;
    printf("\n\t\tMachine Parts Inventory\t\t\n");
    printf("SLNO.\tPart ID\t\tPart Name\t\tQuantity\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%d\n", i++, temp->partID, temp->partName, temp->quantity);
        temp = temp->next;
    }

    printf("------------------------------------------------------------\n");
}
