// Problem 1: Inventory Management System
// Description: Implement a linked list to manage the inventory of raw materials.
// Operations:
// Create an inventory list.
// Insert a new raw material.
// Delete a raw material from the inventory.
// Display the current inventory.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Inventory{

    int materialID;
    char materialName[50];
    int quantity;
    struct Inventory *next;

}Inventory;

Inventory *inventory = NULL;

static int totalCount = 0;

// Functions

void createInventory(int count);
void addNewMaterials();
void deleteMaterials(int materialId);
void displayInventory();

int main() {

    int choice,count,materialId;

    while(1){

        printf("\n\t\tWelcome\t\t\n");

        printf("1. Create an inventory list.\n");
        printf("2. Insert a new raw material.\n");
        printf("3. Delete a raw material from the inventory.\n");
        printf("4. Display the current inventory.\n");
        printf("5. Exit.\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1:
            printf("Enter the number of materials to add : ");
            scanf("%d",&count);
            getchar();
            createInventory(count);
            printf("\n Total materials in the inventory %d\n",totalCount);
            break;

            case 2:
            addNewMaterials();
            printf("\n Total materials in the inventory %d\n",totalCount);
            break;

            case 3: 
            displayInventory();
            printf("Enter the material Id for deletion : ");
            scanf("%d",&materialId);
            deleteMaterials(materialId);
            printf("\n Total materials in the inventory %d\n",totalCount);
            break;

            case 4:
            displayInventory();
            printf("\n Total materials in the inventory %d\n",totalCount);
            break;

            case 5:
            printf("Exiting....\n");
            return 0;

            default:
            printf("Invalid choice!\n");
            break;

        }
    }

    return 0;
}



void createInventory(int count){

    Inventory *temp,*last= inventory;

    if(count <= 0){

        printf("Invalid number of materials");
        return;
    }

    while(last != NULL && last->next != NULL){

        last = last->next;

    }

    for(int i = 0; i < count; i++) {

        temp = (Inventory *)malloc(sizeof(Inventory));

        if(temp == NULL){

            printf("Allocation failed!\n");
            return;
        }
        
        printf("\nEnter the Details of Material %d\n",i+1);
        printf("Enter the materila ID : ");
        scanf("%d",&temp->materialID);
        getchar();

        printf("Enter the material name : ");
        fgets(temp->materialName,sizeof(temp->materialName),stdin);
        temp->materialName[strcspn(temp->materialName, "\n")] = '\0';

        printf("Enter the quantity : ");
        scanf("%d",&temp->quantity);
        getchar();

        temp->next = NULL;

        if(inventory == NULL){

            inventory = temp;

        }else{

            last->next = temp;
        }

        last = temp;

        totalCount++;

    }

    printf("%d materials added!\n",count);

}

void addNewMaterials(){

    Inventory *temp,*last = inventory;

    temp = (Inventory *)malloc(sizeof(Inventory));

    if(temp == NULL){
        printf("Allocation failed!\n");
        return;
    }

    printf("Enter the material ID : ");
    scanf("%d",&temp->materialID);
    getchar();

    printf("Enter the material name : ");
    fgets(temp->materialName,sizeof(temp->materialName),stdin);
    temp->materialName[strcspn(temp->materialName,"\n")] = '\0';

    printf("Enter the quantity : ");
    scanf("%d",&temp->quantity);
    getchar();

    temp->next = NULL;

    if(inventory == NULL){

        inventory = temp;
    }else{

        while(last->next != NULL){

            last = last->next;
        }

        last->next = temp;

    }
    last = temp;

    totalCount++;

    printf("Materila Id %d is added to the inventory\n",last->materialID);

}

void deleteMaterials(int materialId){

    if (inventory == NULL) {

        printf("Inventory is empty.\n");
        return;
    }

    Inventory *temp=inventory,*last = NULL;

    // for 1st 

    if(temp != NULL && temp->materialID == materialId){

        inventory = temp->next;
        free(temp);
        printf("Material with ID %d deleted successfully.\n",materialId);
        totalCount--;
        return;
    }

    while(temp != NULL && temp->materialID != materialId){
        
        last = temp;
        temp = temp->next;
    }

    if(temp == NULL ){

        printf("Material with ID %d Not found\n",materialId);
        return;
    }

    last->next = temp->next;
    free(temp);
    printf("Material with ID %d deleted successfully.\n",materialId);
    totalCount--;

}

void displayInventory(){

    int i = 1;

    if (inventory == NULL) {

        printf("Inventory is empty.\n");
        return;

    }

    Inventory *temp = inventory;
    printf("\n\t\tInventory\t\t\n");
    printf("SLNO.\tMaterial ID\tMaterial Name\t\tQuantity\n");
    printf("--------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%d\t\t%d\t\t%s\t\t%d\n",i++, temp->materialID, temp->materialName, temp->quantity);
        temp = temp->next;
    }

    printf("--------------------------------------------------------\n");

}