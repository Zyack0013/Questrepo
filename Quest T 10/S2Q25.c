// 25.Check Anagram Status Between Two Strings
//  - Requirement: Write code to check if two strings are anagrams by sorting their characters and comparing them.
//  - Input: Two strings.
//  - Output: Whether they are anagrams.


#include <stdio.h>
#include <string.h>

void sortString(char *str);
int areAnagrams(char *str1, char *str2);

int main() {

    char str1[100], str2[100];
   
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  

   
    if (areAnagrams(str1, str2)) {

        printf("The strings are anagrams.\n");

    } else {

        printf("The strings are not anagrams.\n");
    }

    return 0;
}


void sortString(char *str) {

    int length = strlen(str);

    for (int i = 0; i < length - 1; i++) {

        for (int j = i + 1; j < length; j++) {

            if (str[i] > str[j]) {
               
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}


int areAnagrams(char *str1, char *str2) {
    
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }


    sortString(str1);
    sortString(str2);

    return strcmp(str1, str2) == 0;
}

