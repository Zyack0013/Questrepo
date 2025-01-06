// 30.Implement Custom String Length Function
//  - Requirement: Finally, write your own implementation of strlen() function from scratch, demonstrating pointer manipulation techniques.
//  - Input: Any input text.
//  - Output: Length calculated by custom function.


#include <stdio.h>

int custom_strlen(const char *str);

int main() {
    
    char input[200];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    int length = custom_strlen(input);

    printf("The length of the string is: %d\n", length);

    return 0;
}

int custom_strlen(const char *str) {

    const char *ptr = str;
    int length = 0;

    while (*ptr != '\0') {

        length++;
        ptr++;
    }

    return length;
}
