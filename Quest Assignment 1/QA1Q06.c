// 6. Password Validator
// Problem Statement: Implement a password validation program. Use:
// A static variable to count the number of failed attempts.
// A const variable for the maximum allowed attempts.
// if-else and switch statements to handle validation rules.
// A do-while loop to retry password entry.
// Key Concepts Covered: Storage classes (static), Type qualifiers (const), Decision-making (if-else, switch), Looping (do-while).
 
#include <stdio.h>

int validate(const char *password);

int main(){

    static int failA = 0;  
    int const maxA = 4;   
    char password[50];
    int isV;

    printf("<----Password Validator---->\n");

    do {

        printf("\nEnter your password: ");
        scanf("%s",password);

        isV = validate(password);

        if(isV){

            printf("Valid password.\n");
            break;

        }else{

            failA++;
            printf("Invalid password.You have %d attempt remaining.\n",maxA-failA);

        }
    }while(failA<maxA);

    if(failA>=maxA){

        printf("\nMaximum attempts exceeded. Access denied.\n");

    }

    return 0;
}

int validate(const char *password){

    int upcase = 0, locase = 0, digits = 0, spechar = 0;
    int i = 0;

    while(password[i]!='\0'){

        char ch=password[i];
        if(ch>='A' && ch<='Z'){

            upcase = 1;

        }else
        if(ch>='a' && ch<='z')
        {
            locase = 1;

        }else
        if(ch>='0' && ch<='9')
        {
            digits = 1;

        }else{
            spechar = 1;
        }
        i++;
    }

    if(i<8){

        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    if(!upcase){

        printf("At least one uppercase letter needed.\n");
        return 0;

    }

    if(!locase){
        
        printf("At least one lowercase letter needed.\n");
        return 0;
    }

    if(!digits){

        printf("At least one digit needed.\n");
        return 0;
    }

    if(!spechar){

        printf("At least one special character needed.\n");
        return 0;
    }

    return 1;
}
