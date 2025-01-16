// Problem 9: Supplier Management System
// Description: Use a linked list to manage a list of suppliers.
// Operations:
// Create a supplier list.
// Insert a new supplier.
// Delete an inactive or outdated supplier.
// Display all current suppliers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Supplier {

    int supplierID;
    char supplierName[100];
    char contactInfo[100];
    struct Supplier *next;

} Supplier;

Supplier *supplierList = NULL; 
static int totalSuppliers = 0;

void createSupplierList(int count);
void insertNewSupplier();
void deleteSupplier(int supplierID);
void displaySuppliers();

int main() {
    int choice, count, supplierID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a supplier list.\n");
        printf("2. Insert a new supplier.\n");
        printf("3. Delete an inactive or outdated supplier.\n");
        printf("4. Display all current suppliers.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of suppliers to add: ");
            scanf("%d", &count);
            getchar();
            createSupplierList(count);
            printf("\nTotal suppliers: %d\n", totalSuppliers);
            break;

            case 2:
            insertNewSupplier();
            printf("\nTotal suppliers: %d\n", totalSuppliers);
            break;

            case 3:
            displaySuppliers();
            printf("Enter the Supplier ID to delete: ");
            scanf("%d", &supplierID);
            deleteSupplier(supplierID);
            printf("\nTotal suppliers: %d\n", totalSuppliers);
            break;

            case 4:
            displaySuppliers();
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

void createSupplierList(int count) {

    if (count <= 0) {

        printf("Invalid number of suppliers.\n");
        return;
    }

    Supplier *temp, *last = supplierList;

    while (last != NULL && last->next != NULL) {

        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Supplier *)malloc(sizeof(Supplier));

        if (temp == NULL) {

            printf("Memory allocation failed for supplier %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Supplier %d:\n", i + 1);
        printf("Enter the Supplier ID: ");
        scanf("%d", &temp->supplierID);
        getchar();

        printf("Enter the Supplier Name: ");
        fgets(temp->supplierName, sizeof(temp->supplierName), stdin);
        temp->supplierName[strcspn(temp->supplierName, "\n")] = '\0';

        printf("Enter the Contact Information: ");
        fgets(temp->contactInfo, sizeof(temp->contactInfo), stdin);
        temp->contactInfo[strcspn(temp->contactInfo, "\n")] = '\0';

        temp->next = NULL;

        if (supplierList == NULL) {

            supplierList = temp;

        } else {
            last->next = temp;
        }

        last = temp;
        totalSuppliers++;
    }

    printf("%d suppliers added successfully.\n", count);
}

void insertNewSupplier() {

    Supplier *temp, *last = supplierList;

    temp = (Supplier *)malloc(sizeof(Supplier));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;

    }

    printf("Enter the Supplier ID: ");
    scanf("%d", &temp->supplierID);
    getchar();

    Supplier *check = supplierList;

    while (check != NULL) {

        if (check->supplierID == temp->supplierID) {

            printf("Error: Supplier ID %d already exists.\n", temp->supplierID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Supplier Name: ");
    fgets(temp->supplierName, sizeof(temp->supplierName), stdin);
    temp->supplierName[strcspn(temp->supplierName, "\n")] = '\0';

    printf("Enter the Contact Information: ");
    fgets(temp->contactInfo, sizeof(temp->contactInfo), stdin);
    temp->contactInfo[strcspn(temp->contactInfo, "\n")] = '\0';

    temp->next = NULL;

    if (supplierList == NULL) {

        supplierList = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;

        }
        last->next = temp;
    }

    totalSuppliers++;
    printf("Supplier ID %d added successfully.\n", temp->supplierID);
}

void deleteSupplier(int supplierID) {

    if (supplierList == NULL) {
        printf("Supplier list is empty.\n");
        return;
    }

    Supplier *temp = supplierList, *prev = NULL;

    if (temp != NULL && temp->supplierID == supplierID) {

        supplierList = temp->next;
        free(temp);
        printf("Supplier ID %d deleted successfully.\n", supplierID);
        totalSuppliers--;
        return;
    }

    while (temp != NULL && temp->supplierID != supplierID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Supplier ID %d not found.\n", supplierID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Supplier ID %d deleted successfully.\n", supplierID);
    totalSuppliers--;
}

void displaySuppliers() {

    if (supplierList == NULL) {

        printf("Supplier list is empty.\n");
        return;
    }

    Supplier *temp = supplierList;
    int i = 1;
    printf("\n\t\tSupplier List\t\t\n");
    printf("SLNO.\tSupplier ID\tSupplier Name\t\tContact Info\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%-20s\n", i++, temp->supplierID, temp->supplierName, temp->contactInfo);
        temp = temp->next;
    }

    printf("------------------------------------------------------------\n");
}
