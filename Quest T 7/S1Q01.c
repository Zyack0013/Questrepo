// 1.Sum of Two Numbers
//  Write a program that takes two integers as input and calculates their sum using a function. Pass the integers to the function using call by value.

#include <stdio.h>

void sum1(int a,int b);  // function prototype
int sum2(int a,int b); // function prototype

int main(){

    int a,b,sum=0;

    printf("Enter the two integers : ");
    scanf("%d %d",&a,&b);

    sum1(a,b);
    sum = sum2(a,b);

    printf("F2-The sum of %d & %d = %d\n",a,b,sum);


    return 0;
}


/*

Name: sum1()
Return Type : void
Parameter(data type of each parameter): int a and int b are the parameter
Short discription: It is used to add two number given


*/

//function definition

void sum1(int a, int b){

    int sum=0;
    sum = a+b;

    printf("F1-The sum of %d & %d = %d\n",a,b,sum);

}

/*

Name: sum2()
Return Type : int
Parameter(data type of each parameter): int a and int b are the parameter
Short discription: It is used to add two number given


*/

//function definition

int sum2(int a , int b){

    int sum=0;

    sum=a+b;

    return sum;

}