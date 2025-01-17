// 2.Customer Support Ticketing: Create a stack using a linked list to handle customer support tickets. Include a switch-case menu with options:
// 1: Add a new ticket (push)
// 2: Resolve the latest ticket (pop)
// 3: View all pending tickets
// 4: Peek at the latest ticket
// 5: Search for a specific ticket
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ticket {

    int ticketID;
    char issueDescription[100];
    struct Ticket *next;

} Ticket;

typedef struct {

    Ticket *top;  

} TicketStack;

void initializeStack(TicketStack *s);
int isEmpty(TicketStack *s);
void addTicket(TicketStack *s, int ticketID, const char *issueDescription);
void resolveTicket(TicketStack *s);
void viewPendingTickets(TicketStack *s);
void peekTicket(TicketStack *s);
void searchTicket(TicketStack *s, int ticketID);
void freeStack(TicketStack *s);

int main() {

    TicketStack stack;
    initializeStack(&stack);

    int choice, ticketID;
    char issueDescription[100];

    while (1) {
        
        printf("\nCustomer Support Ticketing System Menu:\n");
        printf("1: Add a new ticket\n");
        printf("2: Resolve the latest ticket\n");
        printf("3: View all pending tickets\n");
        printf("4: Peek at the latest ticket\n");
        printf("5: Search for a specific ticket\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
            printf("Enter Ticket ID: ");
            scanf("%d", &ticketID);
            printf("Enter Issue Description: ");
            scanf(" %[^\n]s", issueDescription);  // Read a string with spaces
            addTicket(&stack, ticketID, issueDescription);
            break;

            case 2:
            resolveTicket(&stack);
            break;

            case 3:
            viewPendingTickets(&stack);
            break;

            case 4:
            peekTicket(&stack);
            break;

            case 5:
            printf("Enter Ticket ID to search for: ");
            scanf("%d", &ticketID);
            searchTicket(&stack, ticketID);
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



void initializeStack(TicketStack *s) {

    s->top = NULL;

}

int isEmpty(TicketStack *s) {

    return s->top == NULL;

}

void addTicket(TicketStack *s, int ticketID, const char *issueDescription) {

    Ticket *newTicket = (Ticket *)malloc(sizeof(Ticket));

    if (newTicket == NULL) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    newTicket->ticketID = ticketID;
    strcpy(newTicket->issueDescription, issueDescription);
    newTicket->next = s->top;
    s->top = newTicket;
    printf("Ticket added: Ticket ID %d, Issue: %s\n", ticketID, issueDescription);
}

void resolveTicket(TicketStack *s) {

    if (isEmpty(s)) {

        printf("No pending tickets to resolve.\n");

    } else {

        Ticket *temp = s->top;
        s->top = s->top->next;
        printf("Ticket resolved: Ticket ID %d, Issue: %s\n", temp->ticketID, temp->issueDescription);
        free(temp);

    }

}

void viewPendingTickets(TicketStack *s) {

    if (isEmpty(s)) {

        printf("No pending tickets.\n");

    } else {

        Ticket *current = s->top;
        printf("Pending tickets:\n");

        while (current != NULL) {

            printf("Ticket ID: %d, Issue: %s\n", current->ticketID, current->issueDescription);
            current = current->next;

        }

    }

}

void peekTicket(TicketStack *s) {

    if (isEmpty(s)) {

        printf("No pending tickets.\n");

    } else {

        printf("Next ticket to be resolved: Ticket ID %d, Issue: %s\n", s->top->ticketID, s->top->issueDescription);

    }
}

void searchTicket(TicketStack *s, int ticketID) {

    if (isEmpty(s)) {

        printf("No tickets to search.\n");

    } else {

        Ticket *current = s->top;

        while (current != NULL) {

            if (current->ticketID == ticketID) {

                printf("Ticket found: Ticket ID %d, Issue: %s\n", current->ticketID, current->issueDescription);
                return;

            }

            current = current->next;

        }

        printf("Ticket ID %d not found.\n", ticketID);

    }

}

void freeStack(TicketStack *s) {

    Ticket *current = s->top;
    Ticket *next;

    while (current != NULL) {

        next = current->next;
        free(current);
        current = next;

    }

}
