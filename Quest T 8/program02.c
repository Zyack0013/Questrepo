/*       Call By Refernce       */


/* MODel 1*/



#include <stdio.h>

int sum(int *num1,int *num2);

int main() {
    
    int a = 10,b = 20, sumValue = 0;
    
    printf("Address of a = %p\n",&a);
    printf("Address of b = %p\n",&b);
    
    sumValue = sum(&a,&b);
    
    printf("Sum = %d",sumValue);

    return 0;
}

int sum(int *num1,int *num2){
    
    printf("Value of num1 = %p\n",num1); // same as address of a
    printf("Value of num2 = %p\n",num2); // same as address of b
    
    int sum = *num1 + *num2;
    
    return sum;
}


/*  MODel 2   */



#include <stdio.h>

int sum(int *num1,int *num2);

int main() {
    
    int a = 10,b = 20, sumValue = 0;
    
    printf("Address of a = %p\n",&a);
    printf("Address of b = %p\n",&b);
    // Values before Modifying
    printf("BM-Value of a = %d\n",a);
    printf("BM-Value of b = %d\n",b);
    
    sumValue = sum(&a,&b);
    
    printf("Sum = %d\n",sumValue);
    
    // modified values
    printf("AM-Value of a = %d\n",a);
    printf("AM-Value of b = %d\n",b);

    return 0;
}

int sum(int *num1,int *num2){
    
    printf("Value of num1 = %p\n",num1);
    printf("Value of num2 = %p\n",num2);
    
    int sum = *num1 + *num2;
    
    // Modifying values of both a & b
    *num1 = *num1+10;
    *num2 = *num2+10;
    
    return sum;
}
