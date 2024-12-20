// 3.Write a program that takes a single character as input and uses a switch-case to determine if it is a vowel or a consonant.

#include <stdio.h>

int main(){

    char a;

    printf("Enter the single character : ");
    scanf("%c",&a);

    switch(a){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
        printf("%c is a vowel",a);
        break;
        default:
        if((a>='a' && a<='z') || (a>='A' && a<='Z')){
            printf("%c is a consonant",a);
        }else{
            printf("%c is not a letter",a);
        }
        
    }
    return 0;
}