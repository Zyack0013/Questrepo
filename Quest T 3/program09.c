// 9.Write a program to determine if the weight of an object exceeds the specified maximum limit (e.g., 50 kg).

#include <stdio.h>

int main(){

    float weight;

    printf("Enter the weight of the object : ");
    scanf("%f",&weight);

    if(weight >50 ){
        printf("The weight of the object exceeds the limit");
    }else {
        printf("The weight of the object does not exceeds the limit");
    }
    return 0;
}