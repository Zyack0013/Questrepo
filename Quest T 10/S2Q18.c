// 18.Check for Palindrome
// Requirement: Develop an algorithm to check if an input string is a palindrome by comparing characters from both ends towards the center, ignoring case and spaces.
// Input: A potential palindrome from the user.
// Output: Whether it is or isn't a palindrome.


#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isPalindrome(const char *str);

int main() {

    char input[200];

   
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

   
    input[strcspn(input, "\n")] = '\0';

    
    if (isPalindrome(input)) {

        printf("The string is a palindrome.\n");

    } else {

        printf("The string is not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(const char *str) {

    int start = 0;
    int end = strlen(str) - 1;

    
    while (start < end) {
        
        if (str[start] == ' ') {

            start++;

        } else 
        if (str[end] == ' ') {

            end--;

        } else {
            
            if (tolower(str[start]) != tolower(str[end])) {

                return 0;  
            }
            start++;
            end--;
        }
    }

    return 1;  
}
