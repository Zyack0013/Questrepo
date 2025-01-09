// Problem 5: Sports Equipment Inventory System
// Requirements:
// Define a structure Equipment with members:
// char equipmentID[10]
// char name[30]
// char category[20] (e.g., balls, rackets)
// int quantity
// float pricePerUnit
// Functions to:
// Add new equipment to the inventory.
// Update the quantity of existing equipment.
// Display all equipment in a specific category.
// Calculate the total value of equipment in the inventory.
// Store the inventory data in a dynamically allocated array and ensure proper resizing when needed.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Equipment {
    char equipmentID[10];
    char name[30];
    char category[20];
    int quantity;
    float pricePerUnit;
};

void addEquipment(struct Equipment **inventory, int *size, int *capacity);
void updateQuantity(struct Equipment *inventory, int size);
void displayByCategory(struct Equipment *inventory, int size, const char *category);
float calculateTotalValue(struct Equipment *inventory, int size);

int main() {
    
    int size = 0;
    int capacity = 2; 
    struct Equipment *inventory = (struct Equipment *)malloc(capacity * sizeof(struct Equipment));

    if (inventory == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;

    while (1) {

        printf("\n1. Add new equipment\n");
        printf("2. Update equipment quantity\n");
        printf("3. Display all equipment in a specific category\n");
        printf("4. Calculate total value of the inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                addEquipment(&inventory, &size, &capacity);
                break;
            case 2:
                updateQuantity(inventory, size);
                break;
            case 3: {
                char category[20];
                printf("Enter category to display equipment: ");
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = '\0';  
                displayByCategory(inventory, size, category);
                break;
            }
            case 4:
                printf("Total value of the inventory: %.2f\n", calculateTotalValue(inventory, size));
                break;
            case 5:
                free(inventory);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addEquipment(struct Equipment **inventory, int *size, int *capacity) {

    if (*size == *capacity) {

        *capacity *= 2;  
        *inventory = (struct Equipment *)realloc(*inventory, *capacity * sizeof(struct Equipment));
        if (*inventory == NULL) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter equipment ID: ");
    fgets((*inventory)[*size].equipmentID, sizeof((*inventory)[*size].equipmentID), stdin);
    (*inventory)[*size].equipmentID[strcspn((*inventory)[*size].equipmentID, "\n")] = '\0';  

    printf("Enter equipment name: ");
    fgets((*inventory)[*size].name, sizeof((*inventory)[*size].name), stdin);
    (*inventory)[*size].name[strcspn((*inventory)[*size].name, "\n")] = '\0';  

    printf("Enter equipment category: ");
    fgets((*inventory)[*size].category, sizeof((*inventory)[*size].category), stdin);
    (*inventory)[*size].category[strcspn((*inventory)[*size].category, "\n")] = '\0';  

    printf("Enter equipment quantity: ");
    scanf("%d", &(*inventory)[*size].quantity);

    printf("Enter price per unit: ");
    scanf("%f", &(*inventory)[*size].pricePerUnit);
    getchar(); 

    (*size)++;
}

void updateQuantity(struct Equipment *inventory, int size) {

    char equipmentID[10];
    printf("Enter equipment ID to update quantity: ");
    fgets(equipmentID, sizeof(equipmentID), stdin);
    equipmentID[strcspn(equipmentID, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < size; i++) {

        if (strcmp(inventory[i].equipmentID, equipmentID) == 0) {

            printf("Enter updated quantity: ");
            scanf("%d", &inventory[i].quantity);
            getchar();  
            found = 1;
            break;
        }
    }

    if (!found) {

        printf("Equipment with ID %s not found.\n", equipmentID);
    }
}


void displayByCategory(struct Equipment *inventory, int size, const char *category) {

    int found = 0;
    printf("\nEquipment in category: %s\n", category);
    
    for (int i = 0; i < size; i++) {

        if (strcmp(inventory[i].category, category) == 0) {

            printf("ID: %s, Name: %s, Quantity: %d, Price per Unit: %.2f\n",
                   inventory[i].equipmentID, inventory[i].name, inventory[i].quantity, inventory[i].pricePerUnit);
            found = 1;
        }
    }

    if (!found) {

        printf("No equipment found for category %s.\n", category);
    }
}

float calculateTotalValue(struct Equipment *inventory, int size) {

    float totalValue = 0;
    for (int i = 0; i < size; i++) {

        totalValue += inventory[i].quantity * inventory[i].pricePerUnit;
    }
    return totalValue;
}
