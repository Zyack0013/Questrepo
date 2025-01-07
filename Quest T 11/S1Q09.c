// 9. Check Palindrome
// Write a function int isPalindrome(const char *str) that checks if a given string is a palindrome and returns 1 if true, otherwise 0.


#include <stdio.h>
#include <string.h>

int isPalindrome(char const *str);

int main() {

    char input[100];

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

int isPalindrome(char const *str) {

    int start = 0;
    int end = strlen(str) - 1;

    
    while (start < end) {
       
        if (str[start] != str[end]) {

            return 0;
        }
        start++;
        end--;
    }

    return 1; 
}
