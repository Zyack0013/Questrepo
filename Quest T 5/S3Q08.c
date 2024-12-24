// 8. const Variable for Nested Loop Patterns
// Problem Statement: Use two const variables to define the number of rows and columns for printing a rectangular pattern using nested loops. The dimensions of the rectangle should be based on the const variables.


#include <stdio.h>

int main(){

    int const rows=4,cols=16;
    
    printf("\n");

    for(int i=0;i<rows;i++){
        
        for(int j=0;j<cols;j++){

            printf(" *");
        }
        printf("\n");
    }


    return 0;

}