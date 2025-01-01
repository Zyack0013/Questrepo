// 2.Swap Two Numbers
//  Write a program to swap two numbers using a function. Observe and explain why the original numbers remain unchanged due to call by value.


#include <stdio.h>

void swap1(int a,int b);
int swap2(int a,int b);

int main(){

    int a,b,arr[2];

    printf("Enter the two numbers : \n");
    scanf("%d %d",&a,&b);

    printf("Before swap : a = %d, b = %d\n",a,b);

    swap1(a,b);

    arr[0]=swap2(a,b);
    arr[1]=swap2(b,a);

   
    a=arr[0];
    b= arr[1];
    printf("After swap2 a=%d & b=%d\n",a,b);

    return 0;
}

/*

Name: swap1()
Return Type : void
Parameter(data type of each parameter): int a and int b are the parameter
Short discription: It is used to swap two number given and print the swaped numbers


*/

//function definition

void swap1(int a,int b){

    int temp =a;
    a=b;
    b=temp;

    printf("After swap1 a=%d & b=%d\n",a,b);

}

/*

Name: swap2()
Return Type : int
Parameter(data type of each parameter): int a and int b are the parameter
Short discription: It is used to return the second parameter given


*/

//function definition

int swap2(int a,int b){

    return b;
}