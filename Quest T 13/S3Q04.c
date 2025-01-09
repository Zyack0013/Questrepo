// Problem 4: Research Collaborator Management
// Requirements:
// Create a structure Collaborator with members:
// char collaboratorID[10]
// char name[50]
// char institution[50]
// char expertiseArea[30]
// int numberOfProjects
// Functions to:
// Add a new collaborator to the database.
// Update the number of projects a collaborator is involved in.
// Display all collaborators from a specific institution.
// Find collaborators with expertise in a given area.
// Use dynamic memory allocation to manage the list of collaborators, allowing for expansion as more are added.



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Collaborator {

    char collaboratorID[10];
    char name[50];
    char institution[50];
    char expertiseArea[30];
    int numberOfProjects;
    
};


void addCollaborator(struct Collaborator **collaborators, int *size, int *capacity);
void updateNumberOfProjects(struct Collaborator *collaborators, int size);
void displayCollaboratorsFromInstitution(struct Collaborator *collaborators, int size, const char *institution);
void findCollaboratorsByExpertise(struct Collaborator *collaborators, int size, const char *expertiseArea);
void displayAllCollaborators(struct Collaborator *collaborators, int size);

int main() {

    int size = 0;
    int capacity = 2;  
    struct Collaborator *collaborators = (struct Collaborator *)malloc(capacity * sizeof(struct Collaborator));

    if (collaborators == NULL) {

        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;
    while (1) {
        printf("\n1. Add a new collaborator\n");
        printf("2. Update the number of projects for a collaborator\n");
        printf("3. Display all collaborators from a specific institution\n");
        printf("4. Find collaborators with expertise in a given area\n");
        printf("5. Display all collaborators\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                addCollaborator(&collaborators, &size, &capacity);
                break;
            case 2:
                updateNumberOfProjects(collaborators, size);
                break;
            case 3: {
                char institution[50];
                printf("Enter institution name: ");
                fgets(institution, sizeof(institution), stdin);
                institution[strcspn(institution, "\n")] = '\0';  
                displayCollaboratorsFromInstitution(collaborators, size, institution);
                break;
            }
            case 4: {
                char expertiseArea[30];
                printf("Enter expertise area: ");
                fgets(expertiseArea, sizeof(expertiseArea), stdin);
                expertiseArea[strcspn(expertiseArea, "\n")] = '\0';  
                findCollaboratorsByExpertise(collaborators, size, expertiseArea);
                break;
            }
            case 5:
                displayAllCollaborators(collaborators, size);
                break;
            case 6:
                free(collaborators);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addCollaborator(struct Collaborator **collaborators, int *size, int *capacity) {

    if (*size == *capacity) {

        *capacity *= 2;  
        *collaborators = (struct Collaborator *)realloc(*collaborators, *capacity * sizeof(struct Collaborator));
        
        if (*collaborators == NULL) {

            printf("Memory allocation failed!\n");
            exit(1);
        }
    }

    printf("Enter collaborator ID: ");
    fgets((*collaborators)[*size].collaboratorID, sizeof((*collaborators)[*size].collaboratorID), stdin);
    (*collaborators)[*size].collaboratorID[strcspn((*collaborators)[*size].collaboratorID, "\n")] = '\0';  


    printf("Enter name: ");
    fgets((*collaborators)[*size].name, sizeof((*collaborators)[*size].name), stdin);
    (*collaborators)[*size].name[strcspn((*collaborators)[*size].name, "\n")] = '\0';  
    printf("Enter institution: ");
    fgets((*collaborators)[*size].institution, sizeof((*collaborators)[*size].institution), stdin);
    (*collaborators)[*size].institution[strcspn((*collaborators)[*size].institution, "\n")] = '\0'; 

    printf("Enter expertise area: ");
    fgets((*collaborators)[*size].expertiseArea, sizeof((*collaborators)[*size].expertiseArea), stdin);
    (*collaborators)[*size].expertiseArea[strcspn((*collaborators)[*size].expertiseArea, "\n")] = '\0';  

    printf("Enter number of projects: ");
    scanf("%d", &(*collaborators)[*size].numberOfProjects);
    getchar();  

    (*size)++;
}

void updateNumberOfProjects(struct Collaborator *collaborators, int size) {

    char collaboratorID[10];
    printf("Enter collaborator ID to update: ");
    fgets(collaboratorID, sizeof(collaboratorID), stdin);
    collaboratorID[strcspn(collaboratorID, "\n")] = '\0';  

    int found = 0;

    for (int i = 0; i < size; i++) {

        if (strcmp(collaborators[i].collaboratorID, collaboratorID) == 0) {

            printf("Enter new number of projects: ");
            scanf("%d", &collaborators[i].numberOfProjects);
            getchar();  
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Collaborator with ID %s not found.\n", collaboratorID);
    }
}

void displayCollaboratorsFromInstitution(struct Collaborator *collaborators, int size, const char *institution) {

    printf("\nCollaborators from institution %s:\n", institution);
    int found = 0;

    for (int i = 0; i < size; i++) {

        if (strcmp(collaborators[i].institution, institution) == 0) {

            printf("Collaborator ID: %s, Name: %s, Expertise Area: %s, Number of Projects: %d\n",collaborators[i].collaboratorID, collaborators[i].name,collaborators[i].expertiseArea, collaborators[i].numberOfProjects);
            found = 1;
        }
    }

    if (!found) {

        printf("No collaborators found from institution %s.\n", institution);
    }
}

void findCollaboratorsByExpertise(struct Collaborator *collaborators, int size, const char *expertiseArea) {
    printf("\nCollaborators with expertise in %s:\n", expertiseArea);
    int found = 0;
    for (int i = 0; i < size; i++) {

        if (strcmp(collaborators[i].expertiseArea, expertiseArea) == 0) {

            printf("Collaborator ID: %s, Name: %s, Institution: %s, Number of Projects: %d\n",collaborators[i].collaboratorID, collaborators[i].name,collaborators[i].institution, collaborators[i].numberOfProjects);
            found = 1;
        }
    }

    if (!found) {
        printf("No collaborators found with expertise in %s.\n", expertiseArea);
    }
}

void displayAllCollaborators(struct Collaborator *collaborators, int size) {

    printf("\nAll Collaborators:\n");

    for (int i = 0; i < size; i++) {

        printf("Collaborator ID: %s, Name: %s, Institution: %s, Expertise Area: %s, Number of Projects: %d\n",collaborators[i].collaboratorID, collaborators[i].name,collaborators[i].institution, collaborators[i].expertiseArea,collaborators[i].numberOfProjects);
    }
}
