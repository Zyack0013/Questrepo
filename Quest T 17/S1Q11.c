// Problem 11: Warehouse Storage Management
// Description: Implement a linked list to manage the storage of goods in a warehouse.
// Operations:
// Create a storage list.
// Insert a new storage entry.
// Delete a storage entry when goods are shipped.
// Display the current warehouse storage.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Storage {
    int storageID;
    char goodsName[100];
    int quantity;
    struct Storage *next;
} Storage;

Storage *warehouseStorage = NULL; 
static int totalEntries = 0;

void createStorageList(int count);
void insertStorageEntry();
void deleteStorageEntry(int storageID);
void displayStorage();

int main() {

    int choice, count, storageID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a storage list.\n");
        printf("2. Insert a new storage entry.\n");
        printf("3. Delete a storage entry when goods are shipped.\n");
        printf("4. Display the current warehouse storage.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of storage entries to add: ");
            scanf("%d", &count);
            getchar();
            createStorageList(count);
            printf("\nTotal storage entries: %d\n", totalEntries);
            break;

            case 2:
            insertStorageEntry();
            printf("\nTotal storage entries: %d\n", totalEntries);
            break;

            case 3:
            displayStorage();
            printf("Enter the Storage ID to delete: ");
            scanf("%d", &storageID);
            deleteStorageEntry(storageID);
            printf("\nTotal storage entries: %d\n", totalEntries);
            break;

            case 4:
            displayStorage();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}

void createStorageList(int count) {

    if (count <= 0) {

        printf("Invalid number of storage entries.\n");
        return;
    }

    Storage *temp, *last = warehouseStorage;


    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Storage *)malloc(sizeof(Storage));

        if (temp == NULL) {

            printf("Memory allocation failed for storage entry %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Storage Entry %d:\n", i + 1);
        printf("Enter the Storage ID: ");
        scanf("%d", &temp->storageID);
        getchar();

        printf("Enter the Goods Name: ");
        fgets(temp->goodsName, sizeof(temp->goodsName), stdin);
        temp->goodsName[strcspn(temp->goodsName, "\n")] = '\0';

        printf("Enter the Quantity: ");
        scanf("%d", &temp->quantity);
        getchar();

        temp->next = NULL;

        if (warehouseStorage == NULL) {

            warehouseStorage = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalEntries++;
    }

    printf("%d storage entries added successfully.\n", count);
}

void insertStorageEntry() {

    Storage *temp, *last = warehouseStorage;

    temp = (Storage *)malloc(sizeof(Storage));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Storage ID: ");
    scanf("%d", &temp->storageID);
    getchar();

    Storage *check = warehouseStorage;

    while (check != NULL) {

        if (check->storageID == temp->storageID) {

            printf("Error: Storage ID %d already exists.\n", temp->storageID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Goods Name: ");
    fgets(temp->goodsName, sizeof(temp->goodsName), stdin);
    temp->goodsName[strcspn(temp->goodsName, "\n")] = '\0';

    printf("Enter the Quantity: ");
    scanf("%d", &temp->quantity);
    getchar();

    temp->next = NULL;

    if (warehouseStorage == NULL) {

        warehouseStorage = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;

        }
        last->next = temp;
    }

    totalEntries++;
    printf("Storage entry ID %d added successfully.\n", temp->storageID);
}

void deleteStorageEntry(int storageID) {

    if (warehouseStorage == NULL) {

        printf("Warehouse storage is empty.\n");
        return;
    }

    Storage *temp = warehouseStorage, *prev = NULL;

    if (temp != NULL && temp->storageID == storageID) {

        warehouseStorage = temp->next;
        free(temp);
        printf("Storage entry ID %d deleted successfully.\n", storageID);
        totalEntries--;
        return;
    }

    while (temp != NULL && temp->storageID != storageID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Storage entry ID %d not found.\n", storageID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Storage entry ID %d deleted successfully.\n", storageID);
    totalEntries--;
}

void displayStorage() {

    if (warehouseStorage == NULL) {

        printf("Warehouse storage is empty.\n");
        return;
    }

    Storage *temp = warehouseStorage;
    int i = 1;
    printf("\n\t\tWarehouse Storage\t\t\n");
    printf("SLNO.\tStorage ID\tGoods Name\t\tQuantity\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%d\n", i++, temp->storageID, temp->goodsName, temp->quantity);
        temp = temp->next;
    }

    printf("------------------------------------------------------------\n");
}
