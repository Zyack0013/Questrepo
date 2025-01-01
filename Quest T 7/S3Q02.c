// 2. Create a function that takes the current inventory count of a product and a quantity to add or remove. The function should return the new inventory count without changing the original count.
// Function Prototype:
// int updateInventory(int currentCount, int changeQuantity);



#include <stdio.h>

int updateInventory(int currentCount, int changeQuantity);

int main() {

    int currentCount, changeQuantity, updatedCount;

    printf("Enter the current inventory count: ");
    scanf("%d", &currentCount);

   
    printf("Enter the quantity to add/remove (use negative value to remove): ");
    scanf("%d", &changeQuantity);

    
    updatedCount = updateInventory(currentCount, changeQuantity);

    
    printf("The updated inventory count is: %d\n", updatedCount);

    return 0;
}

/*
Name : updateInventory
Return Datatype : int
parameters : int currentCount, changeQuantity
Short discription: its used to return the new inventory count

*/

int updateInventory(int currentCount, int changeQuantity) {
    
    int newCount = currentCount + changeQuantity;

    
    if (newCount < 0) {

        printf("Error: Inventory cannot be negative.\n");
        return currentCount; 
    }

    return newCount;
}