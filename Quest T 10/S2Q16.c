// 16.Count Specific Characters
// Requirement: Implement functionality to count how many times a specific character appears in an input string, allowing for case sensitivity options.
// Input: A string and a character from the user.
// Output: Count of occurrences.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countCharacter(const char *str, char target, int caseSensitive);

int main() {
    
    char input[200];
    char target;
    int caseSensitive;

    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    
    input[strcspn(input, "\n")] = '\0';

    
    printf("Enter the character to count: ");
    scanf(" %c", &target);

    
    printf("Case-sensitive? Enter 1 for Yes, 0 for No: ");
    scanf("%d", &caseSensitive);

    
    int count = countCharacter(input, target, caseSensitive);

    printf("The character '%c' appears %d time(s) in the string.\n", target, count);

    return 0;
}

int countCharacter(const char *str, char target, int caseSensitive) {

    int count = 0;

    
    for (int i = 0; str[i] != '\0'; i++) {

        if (caseSensitive) {
            
            if (str[i] == target) {
                count++;
            }
        } else {
            
            if (tolower(str[i]) == tolower(target)) {

                count++;
            }
        }
    }

    return count;
}
