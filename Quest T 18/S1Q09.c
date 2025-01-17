// 9.Mission Control Command History: Create a stack to record the command history sent from mission control. Use a switch-case menu with options:
// 1: Add a command (push)
// 2: Undo the last command (pop)
// 3: View the command history
// 4: Peek at the most recent command
// 5: Search for a specific command
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **commands; 
    int top;          
    int capacity;     
} CommandStack;

void initializeStack(CommandStack *s, int initialCapacity);
int isFull(CommandStack *s);
int isEmpty(CommandStack *s);
void addCommand(CommandStack *s, char *command);
void undoCommand(CommandStack *s);
void viewCommandHistory(CommandStack *s);
void peekMostRecentCommand(CommandStack *s);
void searchCommand(CommandStack *s, char *command);
void freeStack(CommandStack *s);

int main() {

    CommandStack stack;
    int initialCapacity = 10;  
    initializeStack(&stack, initialCapacity);

    int choice;
    char command[256];  

    while (1) {
       
        printf("\nMission Control Command History Menu:\n");
        printf("1: Add a command (push)\n");
        printf("2: Undo the last command (pop)\n");
        printf("3: View the command history\n");
        printf("4: Peek at the most recent command\n");
        printf("5: Search for a specific command\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {

            case 1:
            printf("Enter mission control command: ");
            fgets(command, sizeof(command), stdin);
            command[strcspn(command, "\n")] = 0;  
            addCommand(&stack, command);
            break;

            case 2:
            undoCommand(&stack);
            break;

            case 3:
            viewCommandHistory(&stack);
            break;

            case 4:
            peekMostRecentCommand(&stack);
            break;

            case 5:
            printf("Enter command to search for: ");
            fgets(command, sizeof(command), stdin);
            command[strcspn(command, "\n")] = 0;
            searchCommand(&stack, command);
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

void initializeStack(CommandStack *s, int initialCapacity) {

    s->commands = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->commands) {

        printf("Memory allocation failed!\n");
        exit(1);
    }

    s->top = -1;
    s->capacity = initialCapacity;
}

int isFull(CommandStack *s) {

    return s->top == s->capacity - 1;
}

int isEmpty(CommandStack *s) {

    return s->top == -1;
}

void addCommand(CommandStack *s, char *command) {

    if (isFull(s)) {
       
        s->capacity *= 2;
        s->commands = (char **)realloc(s->commands, s->capacity * sizeof(char *));
       
        if (!s->commands) {

            printf("Memory allocation failed!\n");
            exit(1);

        }
    }

    s->commands[++s->top] = (char *)malloc(strlen(command) + 1);

    if (!s->commands[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    strcpy(s->commands[s->top], command);
    printf("Command added: %s\n", command);
}

void undoCommand(CommandStack *s) {

    if (isEmpty(s)) {

        printf("No commands to undo. The stack is empty.\n");

    } else {

        printf("Command undone: %s\n", s->commands[s->top]);
        free(s->commands[s->top]);
        s->top--;

    }
}

void viewCommandHistory(CommandStack *s) {

    if (isEmpty(s)) {

        printf("No commands in history.\n");

    } else {

        printf("Command history:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->commands[i]);

        }
    }
}

void peekMostRecentCommand(CommandStack *s) {

    if (isEmpty(s)) {

        printf("No commands in history to peek at.\n");

    } else {

        printf("Most recent command: %s\n", s->commands[s->top]);

    }
}


void searchCommand(CommandStack *s, char *command) {
    
    if (isEmpty(s)) {
    
        printf("No commands in history to search.\n");
    
    } else {
    
        for (int i = 0; i <= s->top; i++) {
    
            if (strcmp(s->commands[i], command) == 0) {
    
                printf("Command '%s' found at position %d.\n", command, i + 1);
                return;
            }
        }
        printf("Command '%s' not found.\n", command);
    }
}

void freeStack(CommandStack *s) {

    for (int i = 0; i <= s->top; i++) {
    
        free(s->commands[i]);
    
    }
    
    free(s->commands);
}
