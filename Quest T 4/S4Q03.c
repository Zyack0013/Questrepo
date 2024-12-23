// 3. Floyd’s Triangle (Numbers)
//  1
//  2 3
//  4 5 6
//  7 8 9 10
//  11 12 13 14 15


#include <stdio.h>

int main(){

    int i,j,a=1,b,n=1,c=1;

    // Using for loop

    printf("<------- Using for loop ------->\n");

    for(i=0;i<5;i++){

        for(j=0;j<=i;j++){

            printf("%d ",n++);
        }
        printf("\n");
    }
    printf("\n");

    // Using while loop

    printf("<------- Using while loop ------->\n");

    while(a<=5){
        b=1;
        while(b<=a){
            printf("%d ",c++);
            b++;
        }
        printf("\n");
        a++;
    }


    return 0;
}