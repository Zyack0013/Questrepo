// 19.Extract Substring
// Requirement: Create functionality to extract a substring based on specified start index and length parameters, ensuring valid indices are provided by users.
// Input: A main string, start index, and length from the user.
// Output: Extracted substring or error message for invalid indices.

#include <stdio.h>
#include <string.h>

void extractSubstring(const char *str, int start, int length, char *substring);

int main() {
    
    char input[200];
    int start, length;
    char result[200];


    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    input[strcspn(input, "\n")] = '\0';

    printf("Enter start index: ");
    scanf("%d", &start);
    printf("Enter length: ");
    scanf("%d", &length);

    extractSubstring(input, start, length, result);

    printf("Extracted Substring: %s\n", result);

    return 0;
}

void extractSubstring(const char *str, int start, int length, char *substring) {

    int strLength = strlen(str);

    
    if (start < 0 || start >= strLength || length < 0 || start + length > strLength) {

        strcpy(substring, "Error: Invalid indices.");
        return;

    }

  
    for (int i = 0; i < length; i++) {

        substring[i] = str[start + i];

    }
    
    substring[length] = '\0';
}
