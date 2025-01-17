// 13.Emergency Procedures for Spacecraft: Create a stack-based system for handling emergency procedures in a spacecraft. Implement a switch-case menu with options:
// 1: Add a procedure (push)
// 2: Remove the last procedure (pop)
// 3: View all procedures
// 4: Peek at the next procedure
// 5: Search for a specific procedure
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    int capacity;
    int top;             
    char **procedures;

} ProcedureStack;


void initializeStack(ProcedureStack *s, int initialCapacity);
int isFull(ProcedureStack *s);
int isEmpty(ProcedureStack *s);
void addProcedure(ProcedureStack *s, char *procedure);
void removeProcedure(ProcedureStack *s);
void viewProcedures(ProcedureStack *s);
void peekNextProcedure(ProcedureStack *s);
void searchProcedure(ProcedureStack *s, char *procedure);
void freeStack(ProcedureStack *s);

int main() {

    ProcedureStack stack;
    int initialCapacity = 10;  
    initializeStack(&stack, initialCapacity);

    int choice;
    char procedure[256];  

    while (1) {
        
        printf("\nEmergency Procedures for Spacecraft Menu:\n");
        printf("1: Add a procedure\n");
        printf("2: Remove the last procedure\n");
        printf("3: View all procedures\n");
        printf("4: Peek at the next procedure\n");
        printf("5: Search for a specific procedure\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {

            case 1:
            printf("Enter emergency procedure: ");
            fgets(procedure, sizeof(procedure), stdin);
            procedure[strcspn(procedure, "\n")] = 0;  
            addProcedure(&stack, procedure);
            break;

            case 2:
            removeProcedure(&stack);
            break;

            case 3:
            viewProcedures(&stack);
            break;

            case 4:
            peekNextProcedure(&stack);
            break;

            case 5:
            printf("Enter procedure to search for: ");
            fgets(procedure, sizeof(procedure), stdin);
            procedure[strcspn(procedure, "\n")] = 0;  
            searchProcedure(&stack, procedure);
            break;

            case 6:
            printf("Exiting program.\n");
            freeStack(&stack);  
            exit(0);

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}


void initializeStack(ProcedureStack *s, int initialCapacity) {

    s->procedures = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->procedures) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    s->top = -1;
    s->capacity = initialCapacity;
}


int isFull(ProcedureStack *s) {

    return s->top == s->capacity - 1;

}



int isEmpty(ProcedureStack *s) {

    return s->top == -1;

}


void addProcedure(ProcedureStack *s, char *procedure) {

    if (isFull(s)) {
        
        s->capacity *= 2;
        s->procedures = (char **)realloc(s->procedures, s->capacity * sizeof(char *));

        if (!s->procedures) {

            printf("Memory allocation failed!\n");
            exit(1);

        }
    }

    s->procedures[++s->top] = (char *)malloc(strlen(procedure) + 1);

    if (!s->procedures[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(s->procedures[s->top], procedure);
    printf("Procedure added: %s\n", procedure);
}


void removeProcedure(ProcedureStack *s) {

    if (isEmpty(s)) {

        printf("No procedures to remove. The stack is empty.\n");

    } else {

        printf("Procedure removed: %s\n", s->procedures[s->top]);
        free(s->procedures[s->top]);
        s->top--;

    }
}


void viewProcedures(ProcedureStack *s) {

    if (isEmpty(s)) {

        printf("No procedures in the stack.\n");

    } else {

        printf("All procedures in the stack:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->procedures[i]);

        }
    }
}


void peekNextProcedure(ProcedureStack *s) {

    if (isEmpty(s)) {

        printf("No procedures to peek at.\n");

    } else {

        printf("Next procedure: %s\n", s->procedures[s->top]);

    }
}


void searchProcedure(ProcedureStack *s, char *procedure) {

    if (isEmpty(s)) {

        printf("No procedures in the stack to search.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->procedures[i], procedure) == 0) {

                printf("Procedure '%s' found at position %d.\n", procedure, i + 1);
                return;

            }
        }

        printf("Procedure '%s' not found.\n", procedure);

    }
}


void freeStack(ProcedureStack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->procedures[i]);

    }

    free(s->procedures);

}
