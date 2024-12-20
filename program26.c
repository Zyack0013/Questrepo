// 4.Write a program to check if a student has passed an exam based on their marks (pass marks are 40). If the marks are below 40, display "Fail."

#include <stdio.h>

int main(){

    int mark;

    printf("Enter the mark : ");
    scanf("%d",&mark);

    if(mark>=40){
        printf("Passed");
    }else{
        printf("Fail");
    }

    return 0;
}