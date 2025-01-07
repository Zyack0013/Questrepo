// 6. Replace Character in String
// Write a function void replaceChar(char *str, char oldChar, char newChar) that replaces all occurrences of oldChar with newChar in the given string.


#include <stdio.h>
#include <string.h>

void replaceChar(char *str, char oldChar, char newChar);

int main() {

    char str[100];

    printf("Enter a string : ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';
    
    char oldChar, newChar;
    printf("Enter character to replace : ");
    scanf("%c",&oldChar);
    getchar();  
    printf("Enter new character : ");
    scanf("%c",&newChar);
    
    replaceChar(str, oldChar,newChar);

    printf("String after replaced : %s\n", str);
    return 0;
}

void replaceChar(char *str, char oldChar, char newChar) {

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] == oldChar) {

            str[i] = newChar;

        }
    }
}
