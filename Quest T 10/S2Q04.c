// 4.String Comparison
// Requirement: Develop a program that compares two strings using strcmp(). It should indicate if they are equal or which one is greater.
// Input: Two strings from the user.
// Output: Comparison result.


#include <stdio.h>
#include <string.h>

int main () {

    char str1[100],str2[100];
    int result;

    printf("Enter the string 1: ");
    scanf("%s",str1);

    printf("Enter the string 2: ");
    scanf("%s",str2);

    result = strcmp(str1,str2);

    if(result == 0){

        printf("Both the strings are equal");
    }else 
    if(result < 0) {
        printf("String 2 is greater");
    }else
    if(result > 0) {
        printf("string 1 is greater");
    }

    return 0;
}