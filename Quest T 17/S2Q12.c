// Problem 12: Fan Club Membership Management
// Description: Implement a linked list to manage memberships in a sports team’s fan club.Operations:
// Create a membership list.
// Insert a new member.
// Delete a member who cancels their membership.
// Display all current members.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Member {

    int memberID;
    char name[50];
    struct Member *next;

} Member;

Member *head = NULL; 
int totalMembers = 0; 

void createMembershipList(int count);
void insertMember();
void deleteMember(int memberID);
void displayAllMembers();

int main() {

    int choice, count, memberID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a membership list (add initial members).\n");
        printf("2. Insert a new member.\n");
        printf("3. Delete a member who cancels their membership.\n");
        printf("4. Display all current members.\n");
        printf("5. Exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {

            case 1:
            printf("Enter the number of initial members: ");
            scanf("%d", &count);
            getchar();
            createMembershipList(count);
            break;

            case 2:
            insertMember();
            break;

            case 3:
            printf("Enter the Member ID to delete: ");
            scanf("%d", &memberID);
            getchar();
            deleteMember(memberID);
            break;

            case 4:
            displayAllMembers();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice! Please .\n");
            break;
        }
    }

    return 0;
}

void createMembershipList(int count) {

    if (count <= 0) {

        printf("Invalid number of members.\n");
        return;
    }

    Member *temp, *last = NULL;
    char name[50];

    for (int i = 0; i < count; i++) {

        temp = (Member *)malloc(sizeof(Member));

        if (!temp) {

            printf("Memory allocation failed!\n");
            return;
        }

        totalMembers++;
        temp->memberID = totalMembers;

        printf("Enter name for Member ID %d: ", totalMembers);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; 
        strcpy(temp->name, name);

        temp->next = NULL;

        if (head == NULL) {

            head = temp;

        } else {

            last->next = temp;
        }
        last = temp;

        printf("Member ID %d added successfully.\n", totalMembers);
    }
}

// Function to insert a new member
void insertMember() {

    Member *temp = (Member *)malloc(sizeof(Member));

    if (!temp) {

        printf("Memory allocation failed!\n");
        return;
    }

    totalMembers++;
    temp->memberID = totalMembers;

    printf("Enter name for Member ID %d: ", totalMembers);
    fgets(temp->name, sizeof(temp->name), stdin);
    temp->name[strcspn(temp->name, "\n")] = '\0'; 

    temp->next = NULL;

    if (head == NULL) {

        head = temp;

    } else {

        Member *ptr = head;

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    printf("Member ID %d inserted successfully.\n", totalMembers);
}

void deleteMember(int memberID) {

    if (head == NULL) {
        printf("No members available to delete.\n");
        return;
    }

    Member *temp = head, *prev = NULL;

    while (temp != NULL) {

        if (temp->memberID == memberID) {

            if (prev == NULL) {
                // Deleting the head
                head = temp->next;
            } else {

                prev->next = temp->next;
            }

            free(temp);
            printf("Member ID %d deleted successfully.\n", memberID);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Member ID %d not found.\n", memberID);
}

void displayAllMembers() {

    if (head == NULL) {
        printf("No members available.\n");
        return;
    }

    Member *temp = head;

    printf("\nCurrent Members:\n");
    printf("Member ID\tName\n");
    printf("------------------------\n");

    while (temp != NULL) {
        printf("%d\t\t%s\n", temp->memberID, temp->name);
        temp = temp->next;
    }
}
