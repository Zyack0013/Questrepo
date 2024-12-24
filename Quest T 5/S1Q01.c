// 1. Basic Global and Local Variable Usage
// Problem Statement: Write a program that declares a global variable and a local variable with the same name.      Modify and print both variables to demonstrate their scope and accessibility.


#include <stdio.h>
int count=120;

void fun(void);


int main(){
    
    printf("Global variable is %d \n",count);

    fun();

    return 0;
}

void fun(void){

    int count=60;

    printf("Local variable is %d \n",count);

    {
        extern int count;
        count =150;
        printf("Modified Global variable is %d \n",count);
    }
    
    count=90;
    printf("Modified Local variable is %d \n",count);
    

}