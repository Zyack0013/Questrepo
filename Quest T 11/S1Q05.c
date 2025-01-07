// 5. Find Substring
// Implement char* findSubstring(const char *str, const char *sub) that returns a pointer to the first occurrence of the substring sub in the string str, or NULL if the substring is not found.

#include <stdio.h>
#include <string.h>

void getString(char *str,int size);
char* findSubstring(char const *str,char const *sub);

int main() {

    char str1[100],str2[100];

    printf("Enter the main string: ");
    getString(str1,sizeof(str1));
    printf("Enter the substring to find: ");
    getString(str2,sizeof(str2));

    char *result = findSubstring(str1,str2);

    if(result != NULL){

        printf("Substring found at position: %ld\n", result - str1);

    }else{

        printf("Substring not found.\n");

    }


    return 0;
}


void getString(char *str,int size){

    fgets(str,size,stdin);

    str[strcspn(str, "\n")] = '\0';
    
}


char* findSubstring(char const *str,char const *sub) {

    return strstr(str, sub);

}