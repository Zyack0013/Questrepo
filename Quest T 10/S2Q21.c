// 21.Count Words in String
// Requirement: Write code to count how many words are present in an input sentence by identifying spaces as delimiters, utilizing strtok().
// Input: A sentence from the user.
// Output: Number of words counted.


#include <stdio.h>
#include <string.h>

int countWords(const char *sentence);

int main() {
    
    char sentence[200];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    int wordCount = countWords(sentence);

    printf("Number of words: %d\n", wordCount);

    return 0;
}

int countWords(const char *sentence) {

    char sentenceCopy[200];
    strcpy(sentenceCopy, sentence); 

    int count = 0;
    char *token = strtok(sentenceCopy, " ");  

    
    while (token != NULL) {

        count++;  
        token = strtok(NULL, " "); 
    }

    return count;
}
