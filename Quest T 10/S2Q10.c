// 10.String Tokenization
// Requirement: Create a program that tokenizes an input string into words using strtok() and counts how many tokens were found.
// Input: A sentence from the user.
// Output: Number of words (tokens).

#include <stdio.h>
#include <string.h>

int main() {
    
    char str[200];

    
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

   
    str[strcspn(str, "\n")] = '\0';

    
    char *token = strtok(str, " ");  
    int count = 0;

    while (token != NULL) {

        count++;                     
        token = strtok(NULL, " ");    
    }

   
    printf("Number of words: %d\n", count);

    return 0;
}
