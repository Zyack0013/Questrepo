// 19. Scrap Material Management
// Requirements:
// Input: Scrap count for different materials (array of integers).
// Output: Updated scrap count.
// Function: Modifies the scrap count via pointers.
// Constraints: Ensure scrap count remains non-negative.





#include <stdio.h>


void updateScrapCount(int *scrap, int size, int *scrapAdjustment);

int main() {
    
    int scrap[] = {10, 5, 7, 3, 8};  
    int size = sizeof(scrap) / sizeof(scrap[0]);

    
    int scrapAdjustment[] = {-3, 2, -5, 1, -2};  

    
    printf("Initial Scrap Counts:\n");
    for (int i = 0; i < size; i++) {
        printf("Material %d: %d\n", i + 1, scrap[i]);
    }

    updateScrapCount(scrap, size, scrapAdjustment);

    
    printf("\nUpdated Scrap Counts:\n");
    for (int i = 0; i < size; i++) {

        printf("Material %d: %d\n", i + 1, scrap[i]);
    }

    return 0;
}

/*

Name : updateScrapCount
Return Datatype : void
parameters : int *scrap,size,*scrapAdjustment
Short discription: Fn that modifies the scrap count via pointers.

*/

void updateScrapCount(int *scrap, int size, int *scrapAdjustment) {
    
    for (int i = 0; i < size; i++) {

        *(scrap + i) += *(scrapAdjustment + i);  

        
        if (*(scrap + i) < 0) {

            printf("Warning: Scrap count for material %d cannot be negative. Setting it to 0.\n", i + 1);
            *(scrap + i) = 0;  
        }
    }
}
