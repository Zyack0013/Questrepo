// 15.Count Vowels in String
// Requirement: Create a program that counts how many vowels are present in an input string by iterating through each character.
// Input: A string from the user.
// Output: Count of vowels.


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
