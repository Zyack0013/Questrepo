// 6. Tool Life Tracker
// Requirements:
// Input: Current tool usage hours (integer) and maximum life span.
// Output: Updated remaining life (integer).
// Function: Updates remaining life using pointers.
// Constraints: Remaining life cannot go below zero.


#include <stdio.h>

void updateLife(int *remainingLife,int maxLife,int usedHrs);

int main() {

    int remainingLife= 80,maxLife = 100,usedHrs;

    printf("Remaining life = %d\n",remainingLife);

    printf("The usage hours : ");
    scanf("%d",&usedHrs);


    updateLife(&remainingLife,maxLife,usedHrs);

    printf("Updated remaining life = %d\n",remainingLife);


    return 0;
}

/*

Name : updateLife
Return Datatype : void
parameters : int *remainingLife,int maxLife,int usedHrs
Short discription: Fn that updates remaining life using pointers..

*/


void updateLife(int *remainingLife,int maxLife,int usedHrs){

    if(usedHrs > *remainingLife){

        *remainingLife = 0;

    }else {

        *remainingLife -= usedHrs;
    }
}