// 5. const for Loop-Invariant Variable
// Problem Statement: Declare a const variable that holds a mathematical constant (e.g., PI = 3.14). Use this constant in a loop to calculate and print the areas of circles for a range of radii.


#include <stdio.h>

int main(){

    float const PI=3.14;
    int sr=1,er=5; 

    printf("Radius\t   Area \n");

    for (int r=sr;r<=er;r++){

        float area=PI*r*r;
        printf(" %d\t-> %.2f\n",r,area);
    }

    return 0;
}
