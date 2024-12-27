// 7. Warehouse Inventory Tracker
// Develop a program to manage the inven levels of 10 products.
// Store inven levels in an array.
// Use a loop to update levels and a static variable to track items below reorder threshold.
// Use decision-making statements to suggest reorder actions.


#include <stdio.h>

#define PRODUCT 10
#define RECORDT 20


void checkInventory(int inven[]);

int main() {
    
    int inven[PRODUCT];  

    
    printf("Enter the inventory levels for %d products :\n", PRODUCT);

    for (int i = 0; i < PRODUCT; i++){

        printf("Product %d: ", i + 1);
        scanf("%d", &inven[i]);

    }


    checkInventory(inven);

    return 0;
}

void checkInventory(int inven[]){

    static int belTher = 0;  

    printf("\nInventory Levels:\n");

    for (int i = 0; i < PRODUCT; i++){

        printf("Product %d: %d units\n", i + 1, inven[i]);

        if (inven[i] < RECORDT){

            belTher++;
            printf("Product %d is below the reorder threshold.\n", i + 1);
        }
    }

    printf("\nProducts below the reorder threshold: %d\n",belTher);
}
