// 4. Compare Two Strings
// Write a function int compareStrings(const char *str1, const char *str2) that compares two strings lexicographically and returns 0 if they are equal, a positive number if str1 is greater, or a negative number if str2 is greater.


#include <stdio.h>
#include <string.h>

int compareStrings(char const *str1,char const *str2);

int main() {

    char str1[100],str2[100];

    printf("Enter the string 1 : ");
    fgets(str1,sizeof(str1),stdin);

    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the string 2 : ");
    fgets(str2,sizeof(str2),stdin);

    str2[strcspn(str2, "\n")] = '\0';

    int result = compareStrings(str1,str2);

    if(result == 0){

        printf("Both are same");
    }else
    if(result > 0) {

        printf("String 1 is greater");
    }else 
    if(result < 0) {

        printf("String 2 is greater");
    }

    return 0;
}

int compareStrings(char const *str1,char const *str2) {

    int result = strcmp(str1,str2);

}