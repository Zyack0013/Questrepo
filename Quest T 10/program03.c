// Function to check if two string are equals



#include <stdio.h>
#include <stdbool.h>

int strLength(const char str[]);
bool isEqual(char const str1[],char const str2[]);

int main() {

    char str1[] = "Ananthu";
    char str2[] = "ananthu";

    if(isEqual(str1,str2)){

        printf("Both the strings are same.\n");
    }else {

        printf("Both the string are not the same\n");
    }

    return 0;
}

int strLength(const char str[]) {

    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

bool isEqual(char const str1[],char const str2[]) {

    if(strLength(str1) != strLength(str2)){

        return false;
    }

    for(int i = 0;str1[i] != '\0';i++){

        if(str1[i] != str2[i]){

            return false;
        }
        
    }
    return true;
}