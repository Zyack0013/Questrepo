// String concatenation


#include <stdio.h>
#include <string.h>

void strConcatenation(char const *str1,char const *str2,char *result);

int main() {

    char str1[] = "Learn as if you will live forever";
    char str2[] = ",live like you will die tomorrow";
    char result[100];

    strConcatenation(str1,str2,result);

    printf("Concatenated String: %s\n",result);

    return 0;
}

void strConcatenation(char const *str1,char const *str2,char *result) {

    while(*str1 != '\0'){

        *result = *str1;
        str1++;
        result++;

    }
     while(*str2 != '\0'){

        *result = *str2;
        str2++;
        result++;

    }

    *result = '\0';

}


