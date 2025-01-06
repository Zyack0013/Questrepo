// 6.Convert to Lowercase
// Requirement: Implement a program that converts all characters in a string to lowercase using strlwr().
// Input: A string from the user.
// Output: The lowercase version of the string.

#include <stdio.h>
#include <string.h>

int main() {

    char str[100];

    printf("Enter the string : ");
    scanf("%s",str);

    strlwr(str);

    printf("Lowercase version = %s",str);


    return 0;
}