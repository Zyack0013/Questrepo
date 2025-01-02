// 8.Implement a program that uses a constant pointer within loops to iterate through multiple variables (not stored in arrays) and print their values.


#include <stdio.h>

int main() {

    int a=10,b=20,c=30,d=40,e=50;

    int *arr[5] = {&a,&b,&c,&d,&e};

    int *const ptr = NULL;

    for(int i = 0;i < 5;i++) {

        int *const ptr = arr[i];

        printf("Variable %c value: %d\n",'a'+i,*ptr);

    }

    return 0;
}