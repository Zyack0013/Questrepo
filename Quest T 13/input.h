#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <string.h>

void getStringInput(const char *prompt, char *input) {
    
    printf("%s", prompt);
    if (fgets(input, 100, stdin) != NULL) {
        
        input[strcspn(input, "\n")] = '\0';
    }
}

#endif