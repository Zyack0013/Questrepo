// 26.Merge Two Strings Alternately
//  - Requirement: Create functionality to merge two strings alternately into one while handling cases where strings may be of different lengths.
//  - Input: Two strings.
//  - Output: Merged alternating characters.


#include <stdio.h>
#include <string.h>

void mergeAlternately(char *str1, char *str2, char *result);

int main() {

    char str1[100], str2[100], result[200];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  

    mergeAlternately(str1, str2, result);

    printf("Merged string: %s\n", result);

    return 0;
}


void mergeAlternately(char *str1, char *str2, char *result) {
    
    int i = 0, j = 0, k = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    while (i < len1 && j < len2) {

        result[k++] = str1[i++];
        result[k++] = str2[j++];
    }

    while (i < len1) {

        result[k++] = str1[i++];
    }


    while (j < len2) {

        result[k++] = str2[j++];
    }
   
    result[k] = '\0';

}
