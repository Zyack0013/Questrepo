// 4.Write a program to verify if the given length and breadth of a rectangle satisfy the condition of a valid rectangle (length > 0 and breadth > 0).

#include <stdio.h>

int main(){

    float length,breadth;

    printf("Enter the length : ");
    scanf("%f",&length);

    printf("Enter the breadth : ");
    scanf("%f",&breadth);

    if(length > 0 && breadth > 0 ){
        printf("The condition are vaild");
    }else{
        printf("The condition are not vaild ");
    }
    return 0;
}