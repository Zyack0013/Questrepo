// 8.Write a program to calculate the average of a series of numbers entered by the user. Stop when the user enters zero.


#include <stdio.h>

int main(){
    float n,sum=0;
    int count=0;

    printf("Calculate the average of a series of numbers(Enter 0 to stop)\n");

    do{
        printf("Enter the number : ");
        scanf("%f",&n);

        if(n != 0) {
            sum += n;
            count++;
        }
    }while(n!=0);  

    if(count>0){
        printf("Average = %.2f\n",sum/count);
    } else{
        printf("Enter the number again.\n");
    }

    return 0;
}
