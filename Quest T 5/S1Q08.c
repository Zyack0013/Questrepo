// 8. Global Variable for Configuration
// Problem Statement: Use a global variable to store configuration settings (e.g., int configValue = 100). Write multiple functions that use this global configuration variable to perform operations.


#include <stdio.h>

int configValue = 45;

void sum(int a);
void sub(int a);
void mul(int a);
void divi(int a);

int main(){

    printf("The Config value is %d\n",configValue);

    sum(2);
    sub(10);
    mul(3);
    divi(5);


    return 0;
}

void sum(int a){

    printf("Config Value + %d = %d\n",a,configValue+a);
}

void sub(int a){

    printf("Config Value - %d = %d\n",a,configValue-a);
}

void mul(int a){

    printf("Config Value x %d = %d\n",a,configValue*a);
}

void divi(int a){

    printf("Config Value / %d = %d\n",a,configValue/a);
}