// 3. String Length
// Create a function int stringLength(const char *str) that calculates and returns the length of a string using pointers.


#include <stdio.h>
#include <string.h>

int stringLength(char const *str);

int main() {

    char str[100];

    printf("Enter the string : ");
    fgets(str,sizeof(str),stdin);

    str[strcspn(str, "\n")] = '\0';

    int length = stringLength(str);

    printf("The length of the string \"%s\" = %d",str,length);


    return 0;
}

int stringLength(char const *str) {

    int length = strlen(str);

    return length;

}