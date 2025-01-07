// 5. String Concatenation with Dynamic Memory
// Implement a function that takes two strings, dynamically allocates memory to concatenate them, and returns the new concatenated string. Ensure to free the memory after use.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(const char *str1, const char *str2);

int main() {

    char str1[100], str2[100];

   
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; 

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; 

  
    char *concatenated = concatenateStrings(str1, str2);

    if (concatenated != NULL) {
        
        printf("Concatenated String: %s\n", concatenated);

        
        free(concatenated);
    }

    return 0;
}



char* concatenateStrings(const char *str1, const char *str2) {
    
    size_t length1 = strlen(str1);
    size_t length2 = strlen(str2);
    size_t totalLength = length1 + length2 + 1; 

    
    char *result = (char *)malloc(totalLength * sizeof(char));

    if (result == NULL) {

        printf("Memory allocation failed.\n");
        return NULL;

    }

    strcpy(result, str1);


    strcat(result, str2);

    return result; 
}