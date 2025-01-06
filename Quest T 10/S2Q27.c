// 27.Count Consonants in String
//  - Requirement: Develop code to count consonants while ignoring vowels and whitespace characters.
//  - Input: Any input text.
//  - Output: Count of consonants.

#include <stdio.h>
#include <ctype.h>

int countConsonants(const char *str);

int main() {

    char input[200];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int consonantCount = countConsonants(input);

    printf("Number of consonants: %d\n", consonantCount);

    return 0;
}

int countConsonants(const char *str) {
    
    int count = 0;
    
    while (*str != '\0') {
       
        if (isalpha(*str) && !strchr("AEIOUaeiou", *str)) {

            count++;
        }
        str++;
    }
    
    return count;
}