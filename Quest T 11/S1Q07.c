// 7. Copy String
// Create a function void copyString(char *dest, const char *src) that copies the content of the source string src to the destination string dest.


#include <stdio.h>
#include <string.h>

void copyString(char *dest, const char *src);

int main() {

    char src[100], dest[100];

    printf("Enter the source string: ");
    fgets(src, sizeof(src), stdin);

    src[strcspn(src, "\n")] = '\0';

    
    copyString(dest, src);

    printf("Copied string: %s\n", dest);
    
    return 0;

}

void copyString(char *dest, const char *src) {
    
    strcpy(dest, src);

}
