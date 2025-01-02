// 3. Inventory Management
// Requirements:
// Input: Current inventory levels of raw materials (array of integers).
// Output: Updated inventory levels.
// Function: Accepts a pointer to the inventory array and modifies values based on production or consumption.
// Constraints: No inventory level should drop below zero.


#include <stdio.h>

void inventoryUpdate(int *inventory,int *prodorcons, int size);

int main() {

    int inventory[5],prodorcons[5];

    int const size =5;

    for(int i =0; i < size; i++) {

        printf("Enter the units for inventory item %d : ",i+1);
        scanf("%d",&inventory[i]);
    }

    printf("\n");

    for(int i =0; i < size; i++) {

        printf("Enter the value of production(+ve) or consumption(-ve) of inventory item %d : ",i+1);
        scanf("%d",&prodorcons[i]);

    }

    for (int i = 0; i < size; i++) {

        printf("Before update - inventory item %d: %d units\n", i + 1,inventory[i]);
    }

    inventoryUpdate(inventory,prodorcons,size);

     for (int i = 0; i < size; i++) {

        printf("After update - inventory item %d: %d units\n", i + 1,inventory[i]);
    }



    return 0;
}

/*

Name : inventoryUpdate
Return Datatype : void
parameters : int *inventory,*prodorcons,size
Short discription: Fn that accepts a pointer to the inventory array and modifies values based on production or consumption

*/

void inventoryUpdate(int *inventory,int *prodorcons, int size){

   for(int i = 0;i < size; i++) {

    inventory[i] += prodorcons[i];

    if(inventory[i] < 0 ){

        inventory[i] = 0;

    }


   }

}