// 2.String Copy
// Requirement: Implement a program that copies one string to another using strcpy(). The program should validate if the source string fits into the destination buffer.
// Input: Two strings from the user (source and destination).
// Output: The copied string.


#include <stdio.h>
#include <string.h>

int main() {

    char strSrc[100], strDest[100];

    printf("Enter the string : ");
    scanf("%s",strSrc);


    if(strlen(strSrc) >= sizeof(strDest)){

        printf("source string does not fits into the destination buffer");

    }else {

        strcpy(strDest,strSrc);

        printf("Source string: %s\n",strSrc);
        printf("Destination string after copy: %s\n",strDest);
    }


    return 0;
}