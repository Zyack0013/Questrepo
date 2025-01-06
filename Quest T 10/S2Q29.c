// 29.Count Occurrences of Substring
//  - Requirement: Create code that counts how many times one substring appears within another larger main text without overlapping occurrences.
//  - Input: Main text and target substring.
//  - Output: Count of occurrences.


#include <stdio.h>
#include <string.h>

int countOccurrences(const char *mainText, const char *target);

int main() {
    
    char input[500];
    char target[100];

    printf("Enter the main text: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    printf("Enter the substring to count occurrences: ");
    fgets(target, sizeof(target), stdin);

    target[strcspn(target, "\n")] = '\0';

    int count = countOccurrences(input, target);

    printf("The substring '%s' appears %d times in the main text.\n", target, count);

    return 0;
}

int countOccurrences(const char *mainText, const char *target) {

    int count = 0;
    const char *temp = mainText;
    int targetLen = strlen(target);

    while ((temp = strstr(temp, target)) != NULL) {

        count++;
        temp += targetLen; 
    }

    return count;
}
