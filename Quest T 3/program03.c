// 3. Use relational operators to check if a given number is positive (greater than 0).

#include <stdio.h>

int main(){

    int a;

    printf("Enter the number : ");
    scanf("%d",&a);

    if(a>0){
        printf("The %d is a positive number",a);
    }else{
        printf("The %d is not a positive number",a);
    }

    return 0;
}