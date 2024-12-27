// 9. Target Tracking System
// Write a program to track 10 target pos (x-coordinates) and categorize them as friendly or hostile.
// Use an array to store pos.
// Use a loop to process each position and conditionals to classify targets based on predefined criteria (e.g., distance from the base).
// Use register for frequently accessed decision thresholds.



#include <stdio.h>

#define TARGET 10
#define BPOSITION 0 
#define FTHERSHOLD 50 

void classyTarget(int pos[], int friendly[], int hostile[]);

int main() {

    int pos[TARGET]; 
    int friendly[TARGET] = {0};  
    int hostile[TARGET] = {0};


    printf("Enter the x-coordinates of %d targets:\n", TARGET);

    for (int i = 0; i < TARGET; i++) {

        printf("Target %d position: ", i + 1);
        scanf("%d", &pos[i]);
    }

    
    classyTarget(pos, friendly, hostile);

    
    printf("\nFriendly Targets:\n");

    for (int i = 0; i < TARGET; i++){

        if (friendly[i] != 0){

            printf("Target %d at position %d\n", i + 1, friendly[i]);

        }
    }

    printf("\nHostile Targets:\n");

    for (int i = 0; i < TARGET; i++) {

        if (hostile[i] != 0) {
            printf("Target %d at position %d\n", i + 1, hostile[i]);
        }
    }

    return 0;
}

void classyTarget(int pos[], int friendly[], int hostile[]) {

    register int threshold = FTHERSHOLD; 

    for (int i = 0; i < TARGET; i++) {

        if (pos[i] >= BPOSITION - threshold && pos[i] <= BPOSITION + threshold){

            friendly[i] = pos[i];  
        } else {
            hostile[i] = pos[i];  
        }
    }
}
