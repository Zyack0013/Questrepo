// 10. Tokenize String
// Create a function void tokenizeString(char *str, const char *delim, void (*processToken)(const char *)) that tokenizes the string str using delimiters in delim, and for each token, calls processToken.


#include <stdio.h>
#include <string.h>

void processToken(char const *token);
void tokenizeString(char *str, char const *delim, void (*processToken)(char const *));

int main() {

    char input[100];
    char const *delimiters = " ,.;";  

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  

    tokenizeString(input, delimiters, processToken);  

    return 0;
}

void processToken(char const *token) {
    
    printf("Token: %s\n", token);

}

void tokenizeString(char *str, char const *delim, void (*processToken)(char const *)) {
    
    char *token = strtok(str,delim);

    while (token != NULL) {

        processToken(token);
        token = strtok(NULL,delim);  
    }
}

