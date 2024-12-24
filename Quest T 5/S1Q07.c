// 7. Read-Only Global Variable
// Problem Statement: Declare a global constant variable and write a program that uses it across multiple functions without modifying its value. Demonstrate the immutability of the global constant.


#include <stdio.h>

int const cv =10;

void sum(void);
void sub(void);
void mul(void);
void divi(void);

int main(){

    printf("Global variable is %d \n",cv);

    sum();
    sub();
    mul();
    divi();


    return 0;
}


void sum(void){

    int a=30;

    printf("%d + Global variable = %d\n",a,a+cv);

}
void sub(void){

    int a=30;

    printf("%d - Global variable = %d\n",a,a-cv);

}
void mul(void){

    int a=30;

    printf("%d x Global variable = %d \n",a,a*cv);

}
void divi(void){

    int a=30;

    printf("%d / Global variable = %d \n",a,a/cv);

}
