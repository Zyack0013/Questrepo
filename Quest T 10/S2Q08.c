// 8.Character Search
// Requirement: Write a program that finds the first occurrence of a character in a string using strchr() and returns its index or indicates if not found.
// Input: A string and a character from the user.
// Output: Index of first occurrence or not found message.


#include <stdio.h>
#include <string.h>


int main() {

    char str[] = "This is a string";
    char strSearch,* pos;

    printf("Enter the search word : ");
    scanf("%c",strSearch);

    pos = strchr(str,strSearch);

    if(pos != NULL) {
        
        int startIndex = pos - str;
        printf("Substring found at index: %d\n", startIndex);
    } else {
        printf("Substring not found in the main string.\n");
    }


    


    return 0;
}