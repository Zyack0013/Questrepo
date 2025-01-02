// 16. Warehouse Space Allocation
// Requirements:
// Input: Space used for each section (array of integers).
// Output: Updated space allocation.
// Function: Adjusts space allocation using pointers.
// Constraints: Ensure total space used does not exceed warehouse capacity.



#include <stdio.h>


void adjustSpaceAllocation(int *spaceUsed, int sections, int warehouseCapacity);

int main() {
    
    int spaceUsed[5] = {200, 300, 150, 400, 250};
    int warehouseCapacity = 1200; 
    int sections = sizeof(spaceUsed) / sizeof(spaceUsed[0]);

    
    printf("Space used before adjustment:\n");
    for(int i = 0; i < sections; i++) {

        printf("Section %d: %d sqm\n", i + 1, spaceUsed[i]);

    }

    
    adjustSpaceAllocation(spaceUsed, sections, warehouseCapacity);

    
    printf("\nUpdated space allocation:\n");

    for(int i = 0; i < sections; i++) {

        printf("Section %d: %d sqm\n", i + 1, spaceUsed[i]);

    }

    return 0;
}

/*

Name : adjustSpaceAllocation
Return Datatype : void
parameters : int *spaceUsed,sections,warehouseCapacity
Short discription: Fn that adjusts space allocation using pointers.

*/

void adjustSpaceAllocation(int *spaceUsed, int sections, int warehouseCapacity) {

    int totalSpaceUsed = 0;
    
    
    for(int i = 0; i < sections; i++) {
        totalSpaceUsed += *(spaceUsed + i);
    }


    if(totalSpaceUsed > warehouseCapacity) {

        int excessSpace = totalSpaceUsed - warehouseCapacity;
        printf("\nWarning: Total space exceeds warehouse capacity by %d sqm. Adjusting...\n", excessSpace);
        
        
        for(int i = 0; i < sections; i++) {

            int maxAllowedSpace = (int)(((float)(*(spaceUsed + i)) / totalSpaceUsed) * warehouseCapacity);

            if(*(spaceUsed + i) > maxAllowedSpace) {
                *(spaceUsed + i) = maxAllowedSpace;
            }
        }
    }
}
