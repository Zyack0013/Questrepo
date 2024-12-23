// 4. Inverted Right-Angled Triangle (Numbers)
//  12345
//  1234
//  123
//  12
//  1

#include <stdio.h>

int main(){

    int i,j,a=1,b;


    // Using for loop

    printf("<------- Using for loop ------->\n");


    for(i=5;i>=1;i--){
        for(j=1;j<=i;j++){
            printf("%d",j); 
        }
        printf("\n");
    }



    // Using while loop

    printf("<------- Using while loop ------->\n");


    while(a<=5){

        b=1;  
        while(b<=5-a+1){
            printf("%d",j); 
            j++;
        }
        printf("\n"); 
        i++;
    }


    return 0;


}