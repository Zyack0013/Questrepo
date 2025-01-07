// 3. Modify a String Using Double Pointer
// Write a function void modifyString(char **str) that takes a double pointer to a string, dynamically allocates a new string, assigns it to the pointer, and modifies the original string.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modifyString(char **str) {

    *str = (char *)malloc(50 * sizeof(char));  
    
    if (*str == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(*str, "Modified string through double pointer.");
}

int main() {

    char *str = NULL;

    modifyString(&str);

    if (str != NULL) {

        printf("Modified string: %s\n", str);
    }

    free(str);

    return 0;
}
