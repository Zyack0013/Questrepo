// 4. Static Variable to Track Loop Exit Condition
// Problem Statement: Write a program where a loop executes until a specific condition is met. Use a static variable to track and display the number of times the loop exited due to the condition being true.


#include <stdio.h>

static int ecount=0;

void loop(void);

int main(){

    loop();

    loop();
    
    loop();

    printf("the number of times the loop exited = %d\n",ecount);


    return 0;
}

void loop(void){

    int i=1,lcount=0;

    while(i<=10){

        i++;
    }

    printf("Loop exited !!\n");
    ecount++;

}