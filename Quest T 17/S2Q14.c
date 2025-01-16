// Problem 14: Player Transfer Records
// Description: Maintain a linked list to track player transfers between teams.Operations:
// Create a transfer record list.
// Insert a new transfer record.
// Delete an outdated or erroneous transfer record.
// Display all current transfer records.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Transfer {
    
    int transferID;
    char playerName[50];
    char fromTeam[50];
    char toTeam[50];
    struct Transfer *next;
} Transfer;

Transfer *transferList = NULL;
static int totalTransfers = 0;

void createTransferRecords(int count);
void insertTransferRecord();
void deleteTransferRecord(int transferID);
void displayTransferRecords();
void freeTransferRecords();
int isDuplicateTransferID(int transferID);

int main() {

    int choice, count, transferID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a transfer record list.\n");
        printf("2. Insert a new transfer record.\n");
        printf("3. Delete an outdated or erroneous transfer record.\n");
        printf("4. Display all current transfer records.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of transfer records to create: ");
            scanf("%d", &count);
            getchar();
            createTransferRecords(count);
            break;

            case 2:
            insertTransferRecord();
            break;

            case 3:
            printf("Enter the transfer ID to delete: ");
            scanf("%d", &transferID);
            getchar();
            deleteTransferRecord(transferID);
            break;

            case 4:
            displayTransferRecords();
            break;

            case 5:
            freeTransferRecords();
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}

void createTransferRecords(int count) {

    Transfer *temp, *last = transferList;

    if (count <= 0) {

        printf("Invalid number of transfer records.\n");
        return;
    }

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Transfer *)malloc(sizeof(Transfer));

        if (temp == NULL) {

            printf("Memory allocation failed!\n");
            return;
        }

        printf("\nEnter details for Transfer %d\n", i + 1);
        printf("Enter Transfer ID: ");
        scanf("%d", &temp->transferID);
        getchar();

        if (isDuplicateTransferID(temp->transferID)) {

            printf("Transfer ID %d already exists. Skipping this transfer.\n", temp->transferID);
            free(temp);
            continue;
        }

        printf("Enter Player Name: ");
        fgets(temp->playerName, sizeof(temp->playerName), stdin);
        temp->playerName[strcspn(temp->playerName, "\n")] = '\0';

        printf("Enter From Team: ");
        fgets(temp->fromTeam, sizeof(temp->fromTeam), stdin);
        temp->fromTeam[strcspn(temp->fromTeam, "\n")] = '\0';

        printf("Enter To Team: ");
        fgets(temp->toTeam, sizeof(temp->toTeam), stdin);
        temp->toTeam[strcspn(temp->toTeam, "\n")] = '\0';

        temp->next = NULL;

        if (transferList == NULL) {

            transferList = temp;

        } else {

            last->next = temp;
        }
        last = temp;
        totalTransfers++;
    }
    printf("%d transfer records created.\n", count);
}

void insertTransferRecord() {

    Transfer *temp, *last = transferList;

    temp = (Transfer *)malloc(sizeof(Transfer));

    if (temp == NULL) {

        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Transfer ID: ");
    scanf("%d", &temp->transferID);
    getchar();

    if (isDuplicateTransferID(temp->transferID)) {

        printf("Transfer ID %d already exists. Cannot add duplicate.\n", temp->transferID);
        free(temp);
        return;
    }

    printf("Enter Player Name: ");
    fgets(temp->playerName, sizeof(temp->playerName), stdin);
    temp->playerName[strcspn(temp->playerName, "\n")] = '\0';

    printf("Enter From Team: ");
    fgets(temp->fromTeam, sizeof(temp->fromTeam), stdin);
    temp->fromTeam[strcspn(temp->fromTeam, "\n")] = '\0';

    printf("Enter To Team: ");
    fgets(temp->toTeam, sizeof(temp->toTeam), stdin);
    temp->toTeam[strcspn(temp->toTeam, "\n")] = '\0';

    temp->next = NULL;

    if (transferList == NULL) {

        transferList = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }
    totalTransfers++;
    printf("Transfer record ID %d added.\n", temp->transferID);
}

void deleteTransferRecord(int transferID) {

    Transfer *temp = transferList, *prev = NULL;

    if (transferList == NULL) {
        printf("No transfer records available.\n");
        return;
    }

    while (temp != NULL && temp->transferID != transferID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Transfer ID %d not found.\n", transferID);
        return;
    }

    if (prev == NULL) {

        transferList = temp->next;
    } else {

        prev->next = temp->next;
    }

    free(temp);
    totalTransfers--;
    printf("Transfer record ID %d deleted successfully.\n", transferID);
}

void displayTransferRecords() {

    Transfer *temp = transferList;
    int i = 1;

    if (transferList == NULL) {
        printf("No transfer records available.\n");
        return;
    }

    printf("\n--- Current Transfer Records ---\n");
    printf("SL.No\tTransfer ID\tPlayer Name\tFrom Team\tTo Team\n");
    printf("----------------------------------------------------------\n");
    while (temp != NULL) {

        printf("%d\t%d\t\t%s\t\t%s\t\t%s\n", i++, temp->transferID, temp->playerName, temp->fromTeam, temp->toTeam);
        temp = temp->next;
    }
    printf("----------------------------------------------------------\n");
}

void freeTransferRecords() {

    Transfer *temp;
    while (transferList != NULL) {

        temp = transferList;
        transferList = transferList->next;
        free(temp);
    }
    totalTransfers = 0;
    printf("All transfer records cleared.\n");

}

int isDuplicateTransferID(int transferID) {

    Transfer *temp = transferList;

    while (temp != NULL) {

        if (temp->transferID == transferID) {

            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
