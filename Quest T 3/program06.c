// 6.Use relational operators to check if a given number lies between 10 and 50 (inclusive).

#include <stdio.h>

int main(){

    int a;
    printf("Enter the number : ");
    scanf("%d",&a);

    if(a>=10 && a<=50){
        printf("%d lies between 10 and 50",a);
    }else{
        printf("%d does not lies between 10 and 50",a);
    }
    return 0;
}