// 5.Convert to Uppercase
// Requirement: Write a program that converts all characters in a string to uppercase using strupr().
// Input: A string from the user.
// Output: The uppercase version of the string.

#include <stdio.h>
#include <string.h>

int main() {

    char str[100];

    printf("Enter the string : ");
    scanf("%s",str);

    strupr(str);

    printf("Uppercase version = %s",str);


    return 0;
}