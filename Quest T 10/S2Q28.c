// 28.Replace Substring with Another String
//  - Requirement: Write functionality to replace all occurrences of one substring with another within a given main string.
//  - Input: Main text, target substring, replacement substring.
//  - Output: Modified main text after replacements.

#include <stdio.h>
#include <string.h>

void replaceSubstring(char *str, const char *target, const char *replacement);

int main() {
    
    char input[500];
    char target[100];
    char replacement[100];

    printf("Enter the main text: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    printf("Enter the substring to replace: ");
    fgets(target, sizeof(target), stdin);

    target[strcspn(target, "\n")] = '\0';

    printf("Enter the replacement substring: ");
    fgets(replacement, sizeof(replacement), stdin);

    replacement[strcspn(replacement, "\n")] = '\0';

    replaceSubstring(input, target, replacement);

    printf("Modified string: %s\n", input);

    return 0;
}

void replaceSubstring(char *str, const char *target, const char *replacement) {

    char buffer[500];
    char *pos;
    int target_len = strlen(target);
    int replacement_len = strlen(replacement);
    int buffer_index = 0;

    while ((pos = strstr(str, target)) != NULL) {
 
        while (str < pos) {

            buffer[buffer_index++] = *str++;
        }

        for (int i = 0; i < replacement_len; i++) {

            buffer[buffer_index++] = replacement[i];
        }

        str = pos + target_len;
    }

    while (*str) {

        buffer[buffer_index++] = *str++;
    }

    buffer[buffer_index] = '\0';
  
    strcpy(str - (str - buffer), buffer);

}
