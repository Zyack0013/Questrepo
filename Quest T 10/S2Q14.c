// 14.Find Last Occurrence of Character
// Requirement: Write a program that finds the last occurrence of a character in a string using manual iteration instead of library functions, returning its index.
// Input: A string and a character from the user.
// Output: Index of last occurrence or not found message.


#include <stdio.h>

int findLastOccurrence(const char *str, char ch);

int main() {
    
    char input[200];
    char character;

    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    
    input[strcspn(input, "\n")] = '\0';

    
    printf("Enter a character to find: ");
    scanf("%c", &character);

    
    int index = findLastOccurrence(input, character);

    
    if (index != -1) {

        printf("The last occurrence of '%c' is at index %d.\n", character, index);

    } else {

        printf("Character '%c' not found in the string.\n", character);

    }

    return 0;
}

int findLastOccurrence(const char *str, char ch) {

    int lastIndex = -1;  

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] == ch) {

            lastIndex = i;  

        }
    }
    return lastIndex;
}
