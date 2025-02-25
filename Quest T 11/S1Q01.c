// 1. Reverse a String
// Write a function void reverseString(char *str) that takes a pointer to a string and reverses the string in place.

#include <stdio.h>
#include <string.h>

void reverseString(char *str);

int main() {

    char str[100];

    printf("Enter the string : ");
    fgets(str,sizeof(str),stdin);

    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n",str);

    return 0;
}

void reverseString(char *str){

    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while(start < end) {

        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start ++;
        end--;

    }



}