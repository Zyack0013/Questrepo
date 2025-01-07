// 8. Count Vowels in a String
// Implement int countVowels(const char *str) that counts and returns the number of vowels in a given string.


#include <stdio.h>
#include <string.h>

int countVowels(char const *str);

int main() {

    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    int vowelCount = countVowels(input);
    printf("Number of vowels: %d\n",vowelCount);

    return 0;
}

int countVowels(char const *str) {

    int count = 0;
    
   
    for (int i = 0; i < strlen(str); i++) {
        
        char ch = str[i];

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {

            count++;

        }
    }

    return count;
}
