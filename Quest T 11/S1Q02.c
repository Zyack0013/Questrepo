// 2. Concatenate Two Strings
// Implement a function void concatenateStrings(char *dest, const char *src) that appends the source string to the destination string using pointers.


#include <stdio.h>
#include <string.h>

void concatenateStrings(char *dest,char const *src);

int main() {

    char src[100],dest[200];

    printf("Enter the destination string : ");
    fgets(dest,sizeof(dest),stdin);

    dest[strcspn(dest, "\n")] = '\0';

    printf("Enter the source string : ");
    fgets(src,sizeof(src),stdin);

    src[strcspn(src, "\n")] = '\0';

    concatenateStrings(dest,src);

    printf("The string after concatenation : %s",dest);

    return 0;
}


void concatenateStrings(char *dest,char const *src) {

    strcat(dest,src);

}