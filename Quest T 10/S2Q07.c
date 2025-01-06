// 7.Substring Search
// Requirement: Create a program that searches for a substring within a given string using strstr() and returns its starting index or an appropriate message if not found.
// Input: A main string and a substring from the user.
// Output: Starting index or not found message.

#include <stdio.h>
#include <string.h>

int main() {

    char str[] = "This is a string";
    char strSearch[100],* pos;

    printf("Enter the search word : ");
    scanf("%s",strSearch);

    pos = strstr(str,strSearch);

    if(pos != NULL) {
        
        int startIndex = pos - str;
        printf("Substring found at index: %d\n", startIndex);
    } else {
        printf("Substring not found in the main string.\n");
    }


    


    return 0;
}