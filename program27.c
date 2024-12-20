// 5.Given the lengths of three sides, write a program to determine if the triangle is valid using nested if-else. If valid, check if it is an equilateral triangle.

#include <stdio.h>

int main(){

    float side1,side2,side3;

    printf("Enter the 3 sides : ");
    scanf("%f \n %f \n %f",&side1,&side2,&side3);

    if(side1+side2>side3 && side1+side3>side2 && side3+side2>side1){
        printf("The triangle is valid \n");

        if(side1=side2=side3){
            printf("It is an equilateral triangle");
        }
    }else{
        printf("Not valid!!");
    }

    return 0;
}