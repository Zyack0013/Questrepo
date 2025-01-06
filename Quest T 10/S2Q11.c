// 11.String Duplication
// Requirement: Write a function that duplicates an input string (allocating new memory) using strdup() and displays both original and duplicated strings.
// Input: A string from the user.
// Output: Original and duplicated strings.


#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main() {
    
    char str[200];

    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    
    str[strcspn(str, "\n")] = '\0';

    
    char *duplicatedStr = strdup(str);

    
    if (duplicatedStr == NULL) {

        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    
    printf("Original string: %s\n", str);
    printf("Duplicated string: %s\n", duplicatedStr);

    
    free(duplicatedStr);

    return 0;
}
