// Problem 1: Research Paper Database Management
// Requirements:
// Define a structure ResearchPaper with the following members:
// char title[100]
// char author[50]
// char journal[50]
// int year
// char DOI[30]
// Functions to:
// Add a new research paper to the database.
// Update the details of an existing paper using its DOI.
// Display all papers published in a specific journal.
// Find and display the most recent papers published by a specific author.
// Use dynamic memory allocation to store and manage the research papers in an array, resizing it as needed.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ResearchPaper {
    char title[100];
    char author[50];
    char journal[50];
    int year;
    char DOI[30];
};

void addResearchPaper(struct ResearchPaper **papers, int *size, int *capacity);
void updateResearchPaper(struct ResearchPaper *papers, int size);
void displayByJournal(struct ResearchPaper *papers, int size, const char *journal);
void displayByAuthor(struct ResearchPaper *papers, int size, const char *author);
void displayAllPapers(struct ResearchPaper *papers, int size);

int main() {
    
    int size = 0;
    int capacity = 2;  
    struct ResearchPaper *papers = (struct ResearchPaper *)malloc(capacity * sizeof(struct ResearchPaper));

    if (papers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;
    while (1) {

        printf("\n1. Add new research paper\n");
        printf("2. Update research paper details\n");
        printf("3. Display all papers in a specific journal\n");
        printf("4. Display most recent papers by a specific author\n");
        printf("5. Display all research papers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                addResearchPaper(&papers, &size, &capacity);
                break;
            case 2:
                updateResearchPaper(papers, size);
                break;
            case 3: {
                char journal[50];
                printf("Enter journal name: ");
                fgets(journal, sizeof(journal), stdin);
                journal[strcspn(journal, "\n")] = '\0';  
                displayByJournal(papers, size, journal);
                break;
            }
            case 4: {
                char author[50];
                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0';  
                displayByAuthor(papers, size, author);
                break;
            }
            case 5:
                displayAllPapers(papers, size);
                break;
            case 6:
                free(papers);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


void addResearchPaper(struct ResearchPaper **papers, int *size, int *capacity) {

    if (*size == *capacity) {

        *capacity *= 2;  
        *papers = (struct ResearchPaper *)realloc(*papers, *capacity * sizeof(struct ResearchPaper));

        if (*papers == NULL) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter paper title: ");
    fgets((*papers)[*size].title, sizeof((*papers)[*size].title), stdin);
    (*papers)[*size].title[strcspn((*papers)[*size].title, "\n")] = '\0';  

    printf("Enter paper author: ");
    fgets((*papers)[*size].author, sizeof((*papers)[*size].author), stdin);
    (*papers)[*size].author[strcspn((*papers)[*size].author, "\n")] = '\0';  

    printf("Enter journal name: ");
    fgets((*papers)[*size].journal, sizeof((*papers)[*size].journal), stdin);
    (*papers)[*size].journal[strcspn((*papers)[*size].journal, "\n")] = '\0';  

    printf("Enter year of publication: ");
    scanf("%d", &(*papers)[*size].year);
    getchar();  

    printf("Enter DOI: ");
    fgets((*papers)[*size].DOI, sizeof((*papers)[*size].DOI), stdin);
    (*papers)[*size].DOI[strcspn((*papers)[*size].DOI, "\n")] = '\0'; 

    (*size)++;
}


void updateResearchPaper(struct ResearchPaper *papers, int size) {

    char DOI[30];
    printf("Enter the DOI of the paper to update: ");
    fgets(DOI, sizeof(DOI), stdin);
    DOI[strcspn(DOI, "\n")] = '\0';  

    int found = 0;
    for (int i = 0; i < size; i++) {

        if (strcmp(papers[i].DOI, DOI) == 0) {

            printf("Enter new paper title: ");
            fgets(papers[i].title, sizeof(papers[i].title), stdin);
            papers[i].title[strcspn(papers[i].title, "\n")] = '\0';  

            printf("Enter new paper author: ");
            fgets(papers[i].author, sizeof(papers[i].author), stdin);
            papers[i].author[strcspn(papers[i].author, "\n")] = '\0'; 

            printf("Enter new journal name: ");
            fgets(papers[i].journal, sizeof(papers[i].journal), stdin);
            papers[i].journal[strcspn(papers[i].journal, "\n")] = '\0';  

            printf("Enter new year of publication: ");
            scanf("%d", &papers[i].year);
            getchar();  

            printf("Enter new DOI: ");
            fgets(papers[i].DOI, sizeof(papers[i].DOI), stdin);
            papers[i].DOI[strcspn(papers[i].DOI, "\n")] = '\0'; 

            found = 1;
            break;
        }
    }

    if (!found) {

        printf("Paper with DOI %s not found.\n", DOI);
    }
}

void displayByJournal(struct ResearchPaper *papers, int size, const char *journal) {

    int found = 0;
    printf("\nPapers published in the journal: %s\n", journal);

    for (int i = 0; i < size; i++) {

        if (strcmp(papers[i].journal, journal) == 0) {

            printf("Title: %s, Author: %s, Year: %d, DOI: %s\n",papers[i].title, papers[i].author, papers[i].year, papers[i].DOI);
            found = 1;
        }
    }

    if (!found) {

        printf("No papers found in the journal %s.\n", journal);
    }
}

void displayByAuthor(struct ResearchPaper *papers, int size, const char *author) {

    int found = 0;
    int latestYear = -1;
    printf("\nMost recent papers by author: %s\n", author);

    for (int i = 0; i < size; i++) {

        if (strcmp(papers[i].author, author) == 0 && papers[i].year > latestYear) {

            latestYear = papers[i].year;
        }
    }

    for (int i = 0; i < size; i++) {

        if (strcmp(papers[i].author, author) == 0 && papers[i].year == latestYear) {

            printf("Title: %s, Journal: %s, Year: %d, DOI: %s\n",papers[i].title, papers[i].journal, papers[i].year, papers[i].DOI);
            found = 1;
        }
    }

    if (!found) {

        printf("No recent papers found for author %s.\n", author);
    }
}


void displayAllPapers(struct ResearchPaper *papers, int size) {
    printf("\nAll Research Papers:\n");
    for (int i = 0; i < size; i++) {

        printf("Title: %s, Author: %s, Journal: %s, Year: %d, DOI: %s\n",papers[i].title, papers[i].author, papers[i].journal, papers[i].year, papers[i].DOI);
    }
}
