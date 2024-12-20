// 9.Write a program that takes the year as input and uses a switch-case to check and print whether it is a leap year or not (use logical division by 4 and additional logic in cases).

#include <stdio.h>

int main(){

    int year,leap=0;

    printf("Enter the year : ");
    scanf("%d",&year);

    switch(1){
        case 1:
        if (year % 4 == 0){
            if (year % 100 == 0){
                if (year % 400 == 0){
                    leap=1;
                }else{
                    leap=0;
                }
            }else{
                leap=1;
            }
        }else{
            leap=0;
        }
        break;
    }

    switch(leap){
        case 1:
        printf("%d is a leap year",year);
        break;
        case 0:
        printf("%d is not a leap year",year);
        break;
    }

    return 0;
}