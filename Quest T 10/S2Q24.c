// 24.Convert String to Integer
//  - Requirement: Implement functionality to convert numeric strings into integer values without using standard conversion functions like atoi(), handling invalid inputs gracefully.
//  - Input: A numeric string.
//  - Output: Converted integer value or error message.


#include <stdio.h>
#include <ctype.h>

int stringToInt(const char *str);

int main() {
    
    char input[200];

    
    printf("Enter a numeric string: ");
    fgets(input, sizeof(input), stdin);

    
    int result = stringToInt(input);

    
    printf("Converted integer value: %d\n", result);

    return 0;
}

int stringToInt(const char *str) {

    int result = 0;
    int i = 0;
    int sign = 1;

    
    if (str[i] == '\0') {

        printf("Error: Empty input\n");
        return -1;
    }

    
    while (str[i] == ' ') {

        i++;
    }

    
    if (str[i] == '-') {

        sign = -1;
        i++;

    } else 
    if (str[i] == '+') {

        i++;
    }

   
    while (str[i] != '\0') {
        
        if (isdigit(str[i])) {

            result = result * 10 + (str[i] - '0');

        } else {
            
            printf("Error: Invalid character '%c' in input\n", str[i]);
            return -1;
        }
        i++;
    }

    return result * sign;  
}
