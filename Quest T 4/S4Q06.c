// 6. Inverted Pyramid (Stars) 
//  *********
//   *******
//    *****
//     ***
//      *


#include <stdio.h>

int main(){

    int i,j,n,a=1,b;

     // Using for loop

    printf("<------- Using for loop ------->\n");

     for(i=6-1;i>=1;i--){
        
        for(n=1;n<=6-i;n++){
            printf(" ");
        }
        
        for(j=1;j<=(2*i-1);j++){
            printf("*");
        }
        printf("\n");
    }



    // Using while loop

    printf("<------- Using while loop ------->\n");


    a=6-1;
    while(a>=1){
        
        n=1;
        while(n<=6-a){
            printf(" ");
            n++;
        }
        
        b=1;
        while(b<=(2*a-1)){
            printf("*");
            b++;
        }
        printf("\n");
        a--;
    }

    return 0;

}