// Problem 14: Production Defect Tracking
// Description: Implement a linked list to track defects in the production process.
// Operations:
// Create a defect tracking list.
// Insert a new defect report.
// Delete a resolved defect.
// Display all current defects.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Defect {
    int defectID;
    char defectDescription[200];
    char status[20];  
    struct Defect *next;
} Defect;

Defect *defectList = NULL; 
static int totalDefects = 0;

void createDefectTrackingList(int count);
void insertNewDefect();
void deleteResolvedDefect(int defectID);
void displayDefects();

int main() {

    int choice, count, defectID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a defect tracking list.\n");
        printf("2. Insert a new defect report.\n");
        printf("3. Delete a resolved defect.\n");
        printf("4. Display all current defects.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of defects to add: ");
            scanf("%d", &count);
            getchar();
            createDefectTrackingList(count);
            printf("\nTotal defects in the system: %d\n", totalDefects);
            break;

            case 2:
            insertNewDefect();
            printf("\nTotal defects in the system: %d\n", totalDefects);
            break;

            case 3:
            displayDefects();
            printf("Enter the defect ID to delete (resolved defect): ");
            scanf("%d", &defectID);
            deleteResolvedDefect(defectID);
            printf("\nTotal defects in the system: %d\n", totalDefects);
            break;

            case 4:
            displayDefects();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}

void createDefectTrackingList(int count) {

    if (count <= 0) {

        printf("Invalid number of defects.\n");
        return;
    }

    Defect *temp, *last = defectList;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Defect *)malloc(sizeof(Defect));

        if (temp == NULL) {

            printf("Memory allocation failed for defect entry %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Defect %d:\n", i + 1);
        printf("Enter the Defect ID: ");
        scanf("%d", &temp->defectID);
        getchar();

        printf("Enter the Defect Description: ");
        fgets(temp->defectDescription, sizeof(temp->defectDescription), stdin);
        temp->defectDescription[strcspn(temp->defectDescription, "\n")] = '\0';

        printf("Enter the Defect Status: ");
        fgets(temp->status, sizeof(temp->status), stdin);
        temp->status[strcspn(temp->status, "\n")] = '\0';

        temp->next = NULL;

        if (defectList == NULL) {
            defectList = temp;
        } else {
            last->next = temp;
        }

        last = temp;
        totalDefects++;
    }

    printf("%d defects added to the tracking system successfully.\n", count);
}

void insertNewDefect() {

    Defect *temp, *last = defectList;

    temp = (Defect *)malloc(sizeof(Defect));

    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Defect ID: ");
    scanf("%d", &temp->defectID);
    getchar();

    Defect *check = defectList;
    while (check != NULL) {

        if (check->defectID == temp->defectID) {

            printf("Error: Defect ID %d already exists.\n", temp->defectID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Defect Description: ");
    fgets(temp->defectDescription, sizeof(temp->defectDescription), stdin);
    temp->defectDescription[strcspn(temp->defectDescription, "\n")] = '\0';

    printf("Enter the Defect Status: ");
    fgets(temp->status, sizeof(temp->status), stdin);
    temp->status[strcspn(temp->status, "\n")] = '\0';

    temp->next = NULL;

    if (defectList == NULL) {

        defectList = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalDefects++;
    printf("Defect ID %d added to the tracking system successfully.\n", temp->defectID);
}

void deleteResolvedDefect(int defectID) {

    if (defectList == NULL) {

        printf("No defects to delete.\n");
        return;
    }

    Defect *temp = defectList, *prev = NULL;

    if (temp != NULL && temp->defectID == defectID) {

        defectList = temp->next;
        free(temp);
        printf("Defect ID %d deleted successfully.\n", defectID);
        totalDefects--;
        return;
    }

    while (temp != NULL && temp->defectID != defectID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Defect ID %d not found.\n", defectID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Defect ID %d deleted successfully.\n", defectID);
    totalDefects--;
}

void displayDefects() {

    if (defectList == NULL) {

        printf("No defects to display.\n");
        return;
    }

    Defect *temp = defectList;
    int i = 1;
    printf("\n\t\tDefect Tracking System\t\t\n");
    printf("SLNO.\tDefect ID\tDefect Description\t\tStatus\n");
    printf("-------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%-20s\n", i++, temp->defectID, temp->defectDescription, temp->status);
        temp = temp->next;
    }

    printf("-------------------------------------------------------------\n");
}
