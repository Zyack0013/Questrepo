// 13.String Trimming
// Requirement: Implement functionality to trim leading and trailing whitespace from a given string, utilizing pointer arithmetic with strlen().
// Input: A string with extra spaces from the user.
// Output: Trimmed version of the string.


#include <stdio.h>
#include <string.h>

int isWhitespace(char c);
void trimWhitespace(char *str);

int main() {

    char input[200];

    
    printf("Enter a string with leading and trailing spaces: ");
    fgets(input, sizeof(input), stdin);

    
    input[strcspn(input, "\n")] = '\0';

    
    trimWhitespace(input);

    
    printf("Trimmed string: '%s'\n", input);

    return 0;
    
}

int isWhitespace(char c){

    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

void trimWhitespace(char *str) {

    char *start = str; 
    char *end = str + strlen(str) - 1; 


    
    while (*start && isWhitespace(*start)) {
        start++;
    }

    
    while (end > start && isWhitespace(*end)) {

        end--;
    }

    
    *(end + 1) = '\0';

    
    if (start != str) {

        memmove(str, start, end - start + 2);
    }

}
