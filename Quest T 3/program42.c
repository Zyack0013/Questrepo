// 10.Write a program to calculate the area of different shapes based on user input:
// 1 for Circle
// 2 for Rectangle
// 3 for Triangle
// Use a switch-case to perform the respective area calculations.

#include <stdio.h>
#define PI 3.14

int main(){

    int choice;
    float area, radius, length, width, base, height;
    printf("Choose a shape to calculate its area:\n 1. Circle\n 2. Rectangle\n 3. Triangle\n Enter your choice : " );
    scanf("%d",&choice);

    switch(choice){

        case 1:
        printf("Enter the radius of the circle : ");
        scanf("%f", &radius);
        area = PI * radius * radius;
        printf("The area of the circle is: %.2f\n", area);
        break;

        case 2:
        printf("Enter the length and width of the rectangle : ");
        scanf("%f %f",&length, &width);
        area = length * width;
        printf("The area of the rectangle is: %.2f\n", area);
        break;

        case 3:
        printf("Enter the base and height of the triangle: ");
        scanf("%f %f", &base, &height);
        area = 0.5 * base * height;
        printf("The area of the triangle is: %.2f\n", area);
        break;

        default:
        printf("Choose a valid option");
        break;
    }

    return 0;

}