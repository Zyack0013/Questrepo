// 8.GCD of Two Numbers
//  Write a function to calculate the greatest common divisor (GCD) of two numbers passed by value.

#include <stdio.h>

void gcd1(int a, int b);
int gcd2(int a, int b);

int main(){

    int a,b,gcdresult;

    printf("Enter the two integers : \n");
    scanf("%d %d",&a,&b);

    gcd1(a,b);

    gcdresult = gcd2(a,b);

    printf("The GCD2 of %d and %d is: %d\n",a,b,gcdresult);


    return 0;
}

/*
Name : gcd1
Return Datatype : void
parameters : int a,b 
Short discription: its used to print the gcd of two given number

*/

void gcd1(int a, int b){

    int temp1,temp2;

    temp1= a;
    temp2=b;


    while (b != 0) {

        int temp = b;
        b = a % b;  
        a = temp;   
    }

    printf("The GCD1 of %d and %d is: %d\n",temp1,temp2,a);
}


/*
Name : gcd2
Return Datatype : int
parameters : int a,b 
Short discription: its used to return the gcd of two given number

*/


int gcd2(int a, int b){


    while (b != 0) {

        int temp = b;
        b = a % b;  
        a = temp;   
    }

    return a;
}
