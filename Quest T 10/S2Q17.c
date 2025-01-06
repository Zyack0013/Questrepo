// 17.Remove All Occurrences of Character
// Requirement: Write a function that removes all occurrences of a specified character from an input string, modifying it in place.
// Input: A string and a character to remove from it.
// Output: Modified string without specified characters.


#include <stdio.h>
#include <string.h>

void removeCharacter(char *str, char target);

int main() {
    
    char input[200];
    char target;


    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    printf("Enter the character to remove: ");
    scanf(" %c", &target);

    removeCharacter(input, target);

    printf("Modified string: '%s'\n", input);

    return 0;
}

void removeCharacter(char *str, char target) {

    int i = 0, j = 0;

    
    while (str[i] != '\0') {
        
        if (str[i] != target) {
            str[j] = str[i];
            j++;
        }
        i++;
    }

    
    str[j] = '\0';
}
