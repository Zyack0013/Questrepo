// 8.Write a program to compute (x raised to the power y) using a for loop.

#include <stdio.h>

int main(){

    int x,y,result=1;
    printf("Enter the x value : ");
    scanf("%d\n",&x);

    printf("Enter the y value : ");
    scanf("%d",&y);

    for(int i=1;i<=y;i++){

        result *= x; 
    }

    printf("Result : %d",result);

    return 0;
}