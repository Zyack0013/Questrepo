// 8.Write a program to simulate a traffic light system. Take input as R, Y, or G (Red, Yellow, Green) and use a switch-case to display the corresponding action (e.g., R for Stop, Y for Get Ready, G for Go).

#include <stdio.h>

int main(){

    char s;

    printf("Enter the color (R for Red, Y for Yellow, G for Green) : ");
    scanf("%c",&s);

    switch(s){
        case 'R':
        case 'r':
        printf("Stop!");
        break;
        case 'Y':
        case 'y':
        printf("Get Ready");
        break;
        case 'G':
        case 'g':
        printf("Go!!!!!");
        break;
        default :
        printf("Enter a valid color");
        break;
    }

    return 0;
}