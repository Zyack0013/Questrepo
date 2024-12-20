// 7. Write a program to check if a given character is a lowercase English letter (between 'a' and 'z').


#include <stdio.h>

int main(){

    char a;

    printf("Enter the character : ");
    scanf("%c",&a);

    if(a>='a' && a<='z'){
        printf("%c is a lowercase english letter",a);
    }else{
        printf("%c is not a lowercase english letter",a);
    }
    return 0;
}