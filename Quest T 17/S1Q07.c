// Problem 7: Product Assembly Line
// Description: Use a linked list to manage the assembly stages of a product.
// Operations:
// Create an assembly line stage list.
// Insert a new stage.
// Delete a completed stage.
// Display the current assembly stages.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an assembly stage
typedef struct Stage {
    int stageID;
    char stageName[50];
    char stageStatus[20];
    struct Stage *next;
} Stage;

Stage *assemblyLine = NULL; // Head of the linked list
static int totalStages = 0;

// Function prototypes
void createAssemblyLine(int count);
void insertNewStage();
void deleteStage(int stageID);
void displayAssemblyLine();

int main() {
    int choice, count, stageID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create an assembly line stage list.\n");
        printf("2. Insert a new stage.\n");
        printf("3. Delete a completed stage.\n");
        printf("4. Display the current assembly stages.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of stages to add: ");
            scanf("%d", &count);
            getchar();
            createAssemblyLine(count);
            printf("\nTotal stages: %d\n", totalStages);
            break;

            case 2:
            insertNewStage();
            printf("\nTotal stages: %d\n", totalStages);
            break;

            case 3:
            displayAssemblyLine();
            printf("Enter the Stage ID to delete: ");
            scanf("%d", &stageID);
            deleteStage(stageID);
            printf("\nTotal stages: %d\n", totalStages);
            break;

            case 4:
            displayAssemblyLine();
            break;

            case 5:
            printf("Exiting...\n");
            return 0;

            default:
            printf("Invalid choice.!\n");
            break;
        }
    }

    return 0;
}

void createAssemblyLine(int count) {

    if (count <= 0) {
        printf("Invalid number of stages.\n");
        return;
    }

    Stage *temp, *last = assemblyLine;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Stage *)malloc(sizeof(Stage));

        if (temp == NULL) {

            printf("Memory allocation failed for stage %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Stage %d:\n", i + 1);
        printf("Enter the Stage ID: ");
        scanf("%d", &temp->stageID);
        getchar();

        printf("Enter the Stage Name: ");
        fgets(temp->stageName, sizeof(temp->stageName), stdin);
        temp->stageName[strcspn(temp->stageName, "\n")] = '\0';

        printf("Enter the Stage Status (e.g., Pending, Completed): ");
        fgets(temp->stageStatus, sizeof(temp->stageStatus), stdin);
        temp->stageStatus[strcspn(temp->stageStatus, "\n")] = '\0';

        temp->next = NULL;

        if (assemblyLine == NULL) {

            assemblyLine = temp;

        } else {

            last->next = temp;
        }

        last = temp;
        totalStages++;
    }

    printf("%d stages added successfully.\n", count);
}

void insertNewStage() {

    Stage *temp, *last = assemblyLine;

    temp = (Stage *)malloc(sizeof(Stage));
    if (temp == NULL) {

        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Stage ID: ");
    scanf("%d", &temp->stageID);
    getchar();

    Stage *check = assemblyLine;
    while (check != NULL) {
        if (check->stageID == temp->stageID) {
            printf("Error: Stage ID %d already exists.\n", temp->stageID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Stage Name: ");
    fgets(temp->stageName, sizeof(temp->stageName), stdin);
    temp->stageName[strcspn(temp->stageName, "\n")] = '\0';

    printf("Enter the Stage Status (e.g., Pending, Completed): ");
    fgets(temp->stageStatus, sizeof(temp->stageStatus), stdin);
    temp->stageStatus[strcspn(temp->stageStatus, "\n")] = '\0';

    temp->next = NULL;

    if (assemblyLine == NULL) {

        assemblyLine = temp;

    } else {

        while (last->next != NULL) {

            last = last->next;
        }
        last->next = temp;
    }

    totalStages++;
    printf("Stage ID %d added successfully.\n", temp->stageID);
}

void deleteStage(int stageID) {

    if (assemblyLine == NULL) {
        printf("Assembly line is empty.\n");
        return;
    }

    Stage *temp = assemblyLine, *prev = NULL;

    if (temp != NULL && temp->stageID == stageID) {

        assemblyLine = temp->next;
        free(temp);
        printf("Stage ID %d deleted successfully.\n", stageID);
        totalStages--;
        return;
    }

    while (temp != NULL && temp->stageID != stageID) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Stage ID %d not found.\n", stageID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Stage ID %d deleted successfully.\n", stageID);
    totalStages--;
}

void displayAssemblyLine() {

    if (assemblyLine == NULL) {

        printf("Assembly line is empty.\n");
        return;
    }

    Stage *temp = assemblyLine;
    int i = 1;
    printf("\n\t\tAssembly Stages\t\t\n");
    printf("SLNO.\tStage ID\tStage Name\t\tStage Status\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {

        printf("%d\t%d\t\t%-20s\t%-20s\n", i++, temp->stageID, temp->stageName, temp->stageStatus);
        temp = temp->next;
    }

    printf("------------------------------------------------------------\n");
}
