// 7.Write a program to calculate and print the grade of a student based on their percentage using an if-else-if ladder:
// = 90: Grade A
// = 75: Grade B
// = 50: Grade C
// < 50: Fail

#include <stdio.h>

int main(){

    int perc;

    printf("Enter your percentage : ");
    scanf("%d",&perc);

    if(perc >=90){
        printf("Grade A");
    }else
    if(perc >=75){
        printf("Grade B");
    }else
    if(perc >=50){
        printf("Grade C");
    }else
    if(perc <50){
        printf("Fail");
    }
    return 0;

}
