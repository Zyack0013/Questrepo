// 22.Remove Duplicates from String
//  -  Requirement: Develop an algorithm to remove duplicate characters while maintaining their first occurrence order in an input string.
//  -  Input: A string with potential duplicate characters.
//  -  Output: Modified version of the original without duplicates.


#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str);

int main() {
    
    char input[200];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    removeDuplicates(input);
 
    printf("String after removing duplicates: %s\n", input);

    return 0;
}

void removeDuplicates(char *str) {

    int i, j, len = strlen(str);
    int found;

    
    for (i = 0; i < len; i++) {

        found = 0;
        
        
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {

                found = 1; 
                break;
            }
        }

        
        if (found == 0) {

            str[i] = str[i];  

        } else {
         
            for (j = i; j < len; j++) {

                str[j] = str[j + 1];
            }
            len--; 
            i--; 
        }
    }
}
