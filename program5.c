// 5.Given a student's marks in a subject, determine if the student has passed (marks >= 40).


#include <stdio.h>

int main(){

    float mark;

    printf("Enter the mark : ");
    scanf("%f",&mark);

    if(mark >= 40){
        printf("You have passed");
    }else{
        printf("You have failed");
    }
    return 0;
}