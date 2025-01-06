// 23.Find First Non-Repeating Character
//  -  Requirement: Create functionality to find the first non-repeating character in an input string, demonstrating effective use of arrays for counting occurrences.
//  -  Input: A sample input from the user.
//  -  Output: The first non-repeating character or indication if all are repeating.

#include <stdio.h>
#include <string.h>

#define CHAR_COUNT 256  

char findFirstNonRepeating(char *str);

int main() {

    char input[200];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    char result = findFirstNonRepeating(input);

    if (result != '\0') {
        printf("The first non-repeating character is: %c\n", result);
    } else {
        printf("All characters are repeating.\n");
    }

    return 0;
}

char findFirstNonRepeating(char *str) {

    int count[CHAR_COUNT] = {0};  
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;  
    }

    
    for (i = 0; str[i] != '\0'; i++) {

        if (count[(unsigned char)str[i]] == 1) {
            
            return str[i];  
        }
    }

    return '\0';  
}