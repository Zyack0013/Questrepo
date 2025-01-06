// 20.Sort Characters in String
// Requirement: Implement functionality to sort characters in an input string alphabetically, demonstrating usage of nested loops for comparison without library sorting functions.
// Input: A string from the user.
// Output: Sorted version of the characters in the string.


#include <stdio.h>
#include <string.h>

void sortString(char *str);

int main() {
    
    char input[200];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    input[strcspn(input, "\n")] = '\0';

    sortString(input);

    printf("Sorted string: %s\n", input);

    return 0;
}

void sortString(char *str) {

    int length = strlen(str);

    for (int i = 0; i < length - 1; i++) {

        for (int j = i + 1; j < length; j++) {
          
            if (str[i] > str[j]) {

                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
