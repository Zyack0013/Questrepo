// 1. Pascal’s Triangle
 
//       1
//      1 1
//     1 2 1
//    1 3 3 1
//   1 4 6 4 1


#include <stdio.h>

int main(){


    int i,j,n,a=0,b,c;

    // using for loop

    printf("<------- Using for loop ------->\n"); 

    for(i=0;i<5;i++){

        for(j=0;j<5-i-1;j++){
            printf(" ");
        }

        n = 1; 
        for(j=0;j<=i;j++){
            printf("%d ",n);
            n = n*(i - j)/(j + 1); 
        }

        printf("\n");
    }

    // using while loop

    printf("<------- Using while loop ------->\n");

    while(a<5){
        
        b = 0;
        while(b<5-a-1){
            printf(" ");
            b++;
        }

        c = 1; 
        b = 0;
        while(b<=a){
            printf("%d ",c);
            c = c*(a-b)/(b+1); 
            b++;
        }

        printf("\n");
        a++;
    }

    return 0;
}
