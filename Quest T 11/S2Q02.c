// 2. Dynamic String Input
// Implement a function that dynamically allocates memory for a string, reads a string input from the user, and then prints the string. Free the memory after use.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dynamicString(void);

int main() {

    dynamicString();

    return 0;
}


void dynamicString(void) {

    int size;
    
    printf("Enter the size of the string : ");
    scanf("%d",&size);

    while (getchar() != '\n');

    char *str = (char *)malloc(size * sizeof(char));

    printf("Enter the string : ");
    fgets(str,size+1,stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("The entered string is \"%s\"",str);

}