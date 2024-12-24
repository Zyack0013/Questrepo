// 9. Local Variables with Limited Scope
// Problem Statement: Write a program where local variables are declared inside a block (e.g., if or for block). Demonstrate that they are inaccessible outside the block.

#include <stdio.h>

int main(){


    if(1){

        int a=30;
        printf("The value of 'a' inside if-block is %d",a);

    }

    // printf("The value of 'a' outside if-block is %d",a); // --> error: ‘a’ undeclared (first use in this function)

    return 0;
}