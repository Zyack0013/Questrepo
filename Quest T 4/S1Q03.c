// 3.Factorial of a Number:
// Write a program to compute the factorial of a number using a while loop.


#include <stdio.h>

int main(){

    int a,fac=1,i=1;

    printf("Enter the number : ");
    scanf("%d",&a);

    if(a<0){
        printf("There is no factorial for negitive numbers");
    }else{

        while(i<=a){
        fac = fac*i;
        i++;
       }
     printf("Factorial of %d is %d",a,fac);
    }
   

    return 0;
}