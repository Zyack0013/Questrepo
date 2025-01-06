// 3.String Concatenation
// Requirement: Create a program that concatenates two strings using strcat(). Ensure the destination string has enough space to hold the result.
// Input: Two strings from the user.
// Output: The concatenated string.


#include <stdio.h>
#include <string.h>

int main() {

    char strSrc[100],strDest[200],strSpace [] = " ";

    printf("Enter the destination string : ");
    scanf("%s",strDest);
    printf("Enter the source string : ");
    scanf("%s",strSrc);


    if (strlen(strDest) + strlen(strSrc) >= sizeof(strDest)) {

        printf("Destination string does not have enough space to hold the result.\n");

    } else {
        
        strcat(strDest,strSpace);
        strcat(strDest,strSrc);
        printf("Concatenated string: %s\n",strDest);
    }


    return 0;
}