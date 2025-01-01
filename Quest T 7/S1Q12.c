// 12.Quadratic Equation Solver
//  Write a function to calculate the roots of a quadratic equation ax2+bx+c=0ax^2 + bx + c = 0ax2+bx+c=0. Pass the coefficients a,b,a, b,a,b, and ccc as arguments.

#include <stdio.h>
#include <math.h>


void quadSol1(int a,int b,int c);
// double quadSol2(int a,int b,int c);

int main(){

    int a,b,c;

    printf("Enter the coefficients a, b, and c of the quadratic equation ax^2 + bx + c = 0:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    quadSol1(a,b,c);

    return 0;
}


void quadSol1(int a,int b,int c){

    int discri = b*b-4*a*c;


    if(discri > 0){
    
        double root1 = (-b + sqrt(discri)) / (2 * a);
        double root2 = (-b - sqrt(discri)) / (2 * a);
        printf("The roots are real and different.\n");
        printf("Root 1: %.2f\n", root1);
        printf("Root 2: %.2f\n", root2);
    }
    else 
    if(discri == 0){

        double root = -b / (2 * a);
        printf("The root is real and the same.\n");
        printf("Root: %.2f\n", root);
    }
    else{
        
        double realP = -b / (2 * a);
        double imgP = sqrt(-discri) / (2 * a);

        printf("The roots are complex and different.\n");
        printf("Root 1: %.2f + %.2fi\n",realP,imgP);
        printf("Root 2: %.2f - %.2fi\n",realP,imgP);
    }

}


// double quadSol1(int a,int b,int c){

//      int discri = b*b-4*a*c;


//     if(discri > 0){
    
//         double root1 = (-b + sqrt(discri)) / (2 * a);
//         double root2 = (-b - sqrt(discri)) / (2 * a);
//         printf("The roots are real and different.\n");
//         printf("Root 1: %.2f\n", root1);
//         printf("Root 2: %.2f\n", root2);
//     }
//     else 
//     if(discri == 0){

//         double root = -b / (2 * a);
//         printf("The root is real and the same.\n");
//         printf("Root: %.2f\n", root);
//     }
//     else{
        
//         double realP = -b / (2 * a);
//         double imgP = sqrt(-discri) / (2 * a);

//         printf("The roots are complex and different.\n");
//         printf("Root 1: %.2f + %.2fi\n",realP,imgP);
//         printf("Root 2: %.2f - %.2fi\n",realP,imgP);
//     }
// }