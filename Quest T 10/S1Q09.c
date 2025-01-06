// 9.Sentiment Analysis Processor
// Function Prototype: void processSentiments(const char *sentences[], int size, int *sentimentScores)
// Data Types: const char*[], int, int*
// Concepts: Strings, arrays, functions, pointers.
// Details: Analyze sentiments of sentences, updating sentiment scores by reference.



#include <stdio.h>
#include <string.h>

void processSentiments(char const *sentences[], int size, int *sentimentScores);

int main() {

    char const *sentences[] = {
        "I love this product!",
        "This is terrible.",
        "It's okay, not great but not bad.",
        "Absolutely fantastic experience.",
        "I dislike this item."
    };

    int size = 5;
    int sentimentScores[5]={0};

    processSentiments(sentences,size,sentimentScores);

    printf("Sentiment Scores:\n");

    for (int i = 0; i < size; i++) {

        printf("Sentence %d: %d\n", i + 1, sentimentScores[i]);

    }


    return 0;
}

void processSentiments(char const *sentences[], int size, int *sentimentScores) {

    for (int i = 0; i < size; i++) {
        
        if (strstr(sentences[i], "love") || strstr(sentences[i], "fantastic") || strstr(sentences[i], "great")) {

            sentimentScores[i] = 1; 
        } else 
        if(strstr(sentences[i], "terrible") || strstr(sentences[i], "dislike") || strstr(sentences[i], "bad")) {

            sentimentScores[i] = -1; 

        } else {

            sentimentScores[i] = 0; 
        }
    }
}