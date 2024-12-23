// 2. Binary Pattern
//  1
//  01
//  101
//  0101
//  10101


#include <stdio.h>

int main(){

    int i,j,a=1,b;

    // Using for loop

    printf("<------- Using for loop ------->\n"); 


    for(i=0;i<5;i++){

        for(j=0;j<=i;j++){

            if ((i + j)%2 == 0) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    printf("\n");


    // Using while loop

    printf("<------- Using while loop ------->\n");

    while(a<=5){

        b=1;
        while(b<=a){
            if((a+b)%2 == 0){
                printf("1");
            }else{
                printf("0");
            }
            b++;
        } 
        printf("\n");
        a++;
    }


    return 0;
}