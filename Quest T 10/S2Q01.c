// 1.String Length Calculation
// Requirement: Write a program that takes a string input and calculates its length using strlen(). The program should handle empty strings and output appropriate messages.
// Input: A string from the user.
// Output: Length of the string.

#include <stdio.h>
#include <string.h>

int main() {

    char str1[100];

    printf("Enter the string : ");
    scanf("%s",str1);

    int length = strlen(str1);

    if(length == 0) {

        printf("You entered a empty string");

    }else {

        printf("The length of the string \"%s\" is %d",str1,length);

    }



    return 0;
}
