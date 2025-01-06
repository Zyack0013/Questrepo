// 12.Case-Insensitive Comparison
// Requirement: Develop a program to compare two strings without case sensitivity using strcasecmp() and report equality or differences.
// Input: Two strings from the user.
// Output: Comparison result.


#include <stdio.h>
#include <string.h> 

int main() {
    
    char str1[200], str2[200];

    
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    
    int result = strcasecmp(str1, str2);

    
    if (result == 0) {

        printf("The strings are equal\n");

    } else {

        printf("The strings are different.\n");
    }

    return 0;
}
