// 6.User Session History: Use a stack to track user session history in an e-commerce site using a linked list. Implement a switch-case menu with options:
// 1: Add a session (push)
// 2: End the last session (pop)
// 3: Display all sessions
// 4: Peek at the most recent session
// 5: Search for a specific session
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Session {

    int sessionID;
    char username[50];
    char timestamp[50];
    struct Session *next;

} Session;

typedef struct {

    Session *top; 
} SessionStack;


void initializeStack(SessionStack *stack);
int isEmpty(SessionStack *stack);
void addSession(SessionStack *stack, int sessionID, const char *username, const char *timestamp);
void endSession(SessionStack *stack);
void displaySessions(SessionStack *stack);
void peekSession(SessionStack *stack);
void searchSession(SessionStack *stack, int sessionID);
void freeStack(SessionStack *stack);

int main() {

    SessionStack stack;
    initializeStack(&stack);

    int choice, sessionID;
    char username[50];
    char timestamp[50];

    while (1) {
        
        printf("\nUser Session History Menu:\n");
        printf("1: Add a session\n");
        printf("2: End the last session\n");
        printf("3: Display all sessions\n");
        printf("4: Peek at the most recent session\n");
        printf("5: Search for a specific session\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
            printf("Enter Session ID: ");
            scanf("%d", &sessionID);
            printf("Enter Username: ");
            scanf(" %[^\n]s", username); 
            printf("Enter Timestamp: ");
            scanf(" %[^\n]s", timestamp); 
            addSession(&stack, sessionID, username, timestamp);
            break;

            case 2:
            endSession(&stack);
            break;

            case 3:
            displaySessions(&stack);
            break;

            case 4:
            peekSession(&stack);
            break;

            case 5:
            printf("Enter Session ID to search: ");
            scanf("%d", &sessionID);
            searchSession(&stack, sessionID);
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


void initializeStack(SessionStack *stack) {

    stack->top = NULL;

}


int isEmpty(SessionStack *stack) {

    return stack->top == NULL;

}


void addSession(SessionStack *stack, int sessionID, const char *username, const char *timestamp) {

    Session *newSession = (Session *)malloc(sizeof(Session));

    if (newSession == NULL) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    newSession->sessionID = sessionID;
    strcpy(newSession->username, username);
    strcpy(newSession->timestamp, timestamp);
    newSession->next = stack->top;
    stack->top = newSession;
    printf("Session added: ID %d, Username: %s, Timestamp: %s\n", sessionID, username, timestamp);

}


void endSession(SessionStack *stack) {

    if (isEmpty(stack)) {

        printf("No sessions to end.\n");

    } else {

        Session *temp = stack->top;
        stack->top = stack->top->next;
        printf("Session ended: ID %d, Username: %s, Timestamp: %s\n", temp->sessionID, temp->username, temp->timestamp);
        free(temp);

    }

}


void displaySessions(SessionStack *stack) {

    if (isEmpty(stack)) {

        printf("No active sessions.\n");

    } else {

        Session *current = stack->top;
        printf("Active sessions:\n");

        while (current != NULL) {

            printf("ID: %d, Username: %s, Timestamp: %s\n", current->sessionID, current->username, current->timestamp);
            current = current->next;

        }

    }

}


void peekSession(SessionStack *stack) {

    if (isEmpty(stack)) {

        printf("No active sessions.\n");

    } else {

        printf("Most recent session: ID %d, Username: %s, Timestamp: %s\n", stack->top->sessionID, stack->top->username, stack->top->timestamp);

    }

}


void searchSession(SessionStack *stack, int sessionID) {

    if (isEmpty(stack)) {

        printf("No sessions to search.\n");

    } else {

        Session *current = stack->top;

        while (current != NULL) {

            if (current->sessionID == sessionID) {

                printf("Session found: ID %d, Username: %s, Timestamp: %s\n", current->sessionID, current->username, current->timestamp);
                return;

            }

            current = current->next;

        }

        printf("Session with ID %d not found.\n", sessionID);

    }

}

void freeStack(SessionStack *stack) {

    Session *current = stack->top;
    Session *next;

    while (current != NULL) {

        next = current->next;
        free(current);
        current = next;

    }

}
