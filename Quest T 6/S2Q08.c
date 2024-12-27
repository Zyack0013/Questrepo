// 8. Missile Launch Codes Validator
// Develop a program to validate 10 missile launch codes.
// Use an array to store the codes.
// Use const for defining valid code lengths and formats.
// Implement decision-making statements to mark invalid codes and count them using a static variable.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CODES 10
#define CODELEN 8

void codeValid(char codes[CODES][CODELEN + 1]);

int main(){

    char codes[CODES][CODELEN + 1]; 

    printf("Enter %d missile launch codes(%d):\n", CODES, CODELEN);

    for (int i = 0; i < CODES; i++){
        
        printf("Code %d: ", i + 1);
        scanf("%s",codes[i]);
    }

    
    codeValid(codes);

    return 0;
}

void codeValid(char codes[CODES][CODELEN + 1]){

    static int inCount = 0;  

    printf("\nValidating missile launch codes...\n");

    for (int i = 0; i < CODES; i++) {

        int isValid = 1;


        if (strlen(codes[i]) != CODELEN) {
            isValid = 0;
        }

        for (int j = 0; j < strlen(codes[i]); j++){

            if (!isalnum(codes[i][j])){

                isValid = 0;
                break;
            }
        }

        if (isValid) {

            printf("Code %d: %s --> Valid\n", i + 1, codes[i]);

        } else{

            printf("Code %d: %s --> Invalid\n", i + 1, codes[i]);
            inCount++;

        }
    }

    printf("\nNumber of invalid codes: %d\n", inCount);
}
