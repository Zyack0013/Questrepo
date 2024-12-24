// 2. Global Variable Across Functions
// Problem Statement: Declare a global variable and create multiple functions to modify its value. Each function should perform a different operation (e.g., addition, subtraction) on the global variable and print its updated value.

#include <stdio.h>

int a=20;

void sum(void);
void sub(void);
void mul(void);
void divi(void);

int main(){

    sum();
    sub();
    mul();
    divi();

    return 0;
}

void sum(void){

    printf("%d + 5 = %d\n",a,a+5);

}
void sub(void){

    printf("%d - 5 = %d\n",a,a-5);

}
void mul(void){

    printf("%d x 5 = %d \n",a,a*5);

}
void divi(void){

    printf("%d / 5 = %d \n",a,a/5);

}