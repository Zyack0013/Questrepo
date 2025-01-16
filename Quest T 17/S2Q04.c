// Problem 4: Sports Equipment Inventory
// Description: Use a linked list to manage the inventory of sports equipment.Operations:
// Create an equipment inventory list.
// Insert a new equipment item.
// Delete an item that is no longer usable.
// Display the current equipment inventory.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Equipment {
    
    int equipmentID;
    char equipmentName[50];
    int quantity;
    struct Equipment *next;
} Equipment;

Equipment *inventory = NULL;  
static int totalItems = 0;

void createEquipmentInventory(int count);
void insertNewEquipmentItem();
void deleteEquipmentItem(int equipmentID);
void displayEquipmentInventory();

int main() {

    int choice, count, equipmentID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create an equipment inventory list.\n");
        printf("2. Insert a new equipment item.\n");
        printf("3. Delete an item that is no longer usable.\n");
        printf("4. Display the current equipment inventory.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of equipment items to add: ");
            scanf("%d", &count);
            getchar();
            createEquipmentInventory(count);
            printf("\nTotal equipment items: %d\n", totalItems);
            break;

            case 2:
            insertNewEquipmentItem();
            printf("\nTotal equipment items: %d\n", totalItems);
            break;

            case 3:
            displayEquipmentInventory();
            printf("Enter the equipment ID to delete: ");
            scanf("%d", &equipmentID);
            deleteEquipmentItem(equipmentID);
            printf("\nTotal equipment items: %d\n", totalItems);
            break;

            case 4:
            displayEquipmentInventory();
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

void createEquipmentInventory(int count) {

    if (count <= 0) {

        printf("Invalid number of equipment items.\n");
        return;
    }

    Equipment *temp, *last = inventory;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Equipment *)malloc(sizeof(Equipment));

        if (temp == NULL) {

            printf("Memory allocation failed for item %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Equipment Item %d:\n", i + 1);
        printf("Enter the Equipment ID: ");
        scanf("%d", &temp->equipmentID);
        getchar();

        printf("Enter Equipment Name: ");
        fgets(temp->equipmentName, sizeof(temp->equipmentName), stdin);
        temp->equipmentName[strcspn(temp->equipmentName, "\n")] = '\0';

        printf("Enter Equipment Quantity: ");
        scanf("%d", &temp->quantity);
        getchar();

        temp->next = NULL;

        if (inventory == NULL) {
            inventory = temp;
        } else {
            last->next = temp;
        }

        last = temp;
        totalItems++;
    }

    printf("%d equipment items added to the inventory successfully.\n", count);
}

void insertNewEquipmentItem() {

    Equipment *temp, *last = inventory;

    temp = (Equipment *)malloc(sizeof(Equipment));
    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Equipment ID: ");
    scanf("%d", &temp->equipmentID);
    getchar();

    Equipment *check = inventory;

    while (check != NULL) {

        if (check->equipmentID == temp->equipmentID) {

            printf("Error: Equipment ID %d already exists.\n", temp->equipmentID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter Equipment Name: ");
    fgets(temp->equipmentName, sizeof(temp->equipmentName), stdin);
    temp->equipmentName[strcspn(temp->equipmentName, "\n")] = '\0';

    printf("Enter Equipment Quantity: ");
    scanf("%d", &temp->quantity);
    getchar();

    temp->next = NULL;

    if (inventory == NULL) {

        inventory = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalItems++;
    printf("Equipment ID %d added to the inventory successfully.\n", temp->equipmentID);
}

void deleteEquipmentItem(int equipmentID) {

    if (inventory == NULL) {
        printf("No equipment items in the inventory.\n");
        return;
    }

    Equipment *temp = inventory, *prev = NULL;

    if (temp != NULL && temp->equipmentID == equipmentID) {

        inventory = temp->next;
        free(temp);
        printf("Equipment ID %d deleted successfully.\n", equipmentID);
        totalItems--;
        return;
    }

    while (temp != NULL && temp->equipmentID != equipmentID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Equipment ID %d not found.\n", equipmentID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Equipment ID %d deleted successfully.\n", equipmentID);
    totalItems--;
}

void displayEquipmentInventory() {

    if (inventory == NULL) {

        printf("No equipment items in the inventory.\n");
        return;
    }

    Equipment *temp = inventory;
    int i = 1;
    printf("\n\t\tSports Equipment Inventory\t\t\n");
    printf("SLNO.\tEquipment ID\tEquipment Name\t\tQuantity\n");
    printf("-----------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%d\n", i++, temp->equipmentID, temp->equipmentName, temp->quantity);
        temp = temp->next;
    }

    printf("-----------------------------------------------------------\n");
}
