// Problem 6: Tool Tracking System
// Description: Maintain a linked list to track tools used in the manufacturing process.
// Operations:
// Create a tool tracking list.
// Insert a new tool entry.
// Delete a tool that is no longer in use.
// Display all tools currently tracked.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tool {
    int toolID;
    char toolName[50];
    char toolStatus[20];
    struct Tool *next;
} Tool;

Tool *toolList = NULL; 
static int totalTools = 0;

void createToolList(int count);
void insertNewTool();
void deleteTool(int toolID);
void displayAllTools();

int main() {
    int choice, count, toolID;

    while (1) {

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Create a tool tracking list.\n");
        printf("2. Insert a new tool entry.\n");
        printf("3. Delete a tool that is no longer in use.\n");
        printf("4. Display all tools currently tracked.\n");
        printf("5. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
            printf("Enter the number of tools to track: ");
            scanf("%d", &count);
            getchar();
            createToolList(count);
            printf("\nTotal tools: %d\n", totalTools);
            break;

            case 2:
            insertNewTool();
            printf("\nTotal tools: %d\n", totalTools);
            break;

            case 3:
            displayAllTools();
            printf("Enter the Tool ID to delete: ");
            scanf("%d", &toolID);
            deleteTool(toolID);
            printf("\nTotal tools: %d\n", totalTools);
            break;

            case 4:
            displayAllTools();
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

void createToolList(int count) {

    if (count <= 0) {
        printf("Invalid number of tools.\n");
        return;
    }

    Tool *temp, *last = toolList;

    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    for (int i = 0; i < count; i++) {

        temp = (Tool *)malloc(sizeof(Tool));
        if (temp == NULL) {
            printf("Memory allocation failed for tool %d.\n", i + 1);
            return;
        }

        printf("\nEnter details for Tool %d:\n", i + 1);
        printf("Enter the Tool ID: ");
        scanf("%d", &temp->toolID);
        getchar();

        printf("Enter the Tool Name: ");
        fgets(temp->toolName, sizeof(temp->toolName), stdin);
        temp->toolName[strcspn(temp->toolName, "\n")] = '\0';

        printf("Enter the Tool Status (e.g., Active, Inactive): ");
        fgets(temp->toolStatus, sizeof(temp->toolStatus), stdin);
        temp->toolStatus[strcspn(temp->toolStatus, "\n")] = '\0';

        temp->next = NULL;

        if (toolList == NULL) {
            toolList = temp;
        } else {
            last->next = temp;
        }

        last = temp;
        totalTools++;
    }

    printf("%d tools added successfully.\n", count);
}

void insertNewTool() {

    Tool *temp, *last = toolList;

    temp = (Tool *)malloc(sizeof(Tool));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the Tool ID: ");
    scanf("%d", &temp->toolID);
    getchar();

    Tool *check = toolList;
    while (check != NULL) {
        if (check->toolID == temp->toolID) {
            printf("Error: Tool ID %d already exists.\n", temp->toolID);
            free(temp);
            return;
        }
        check = check->next;
    }

    printf("Enter the Tool Name: ");
    fgets(temp->toolName, sizeof(temp->toolName), stdin);
    temp->toolName[strcspn(temp->toolName, "\n")] = '\0';

    printf("Enter the Tool Status (e.g., Active, Inactive): ");
    fgets(temp->toolStatus, sizeof(temp->toolStatus), stdin);
    temp->toolStatus[strcspn(temp->toolStatus, "\n")] = '\0';

    temp->next = NULL;

    if (toolList == NULL) {
        toolList = temp;
    } else {

        while (last->next != NULL) {

            last = last->next;

        }
        last->next = temp;
    }

    totalTools++;
    printf("Tool ID %d added successfully.\n", temp->toolID);
}

void deleteTool(int toolID) {

    if (toolList == NULL) {

        printf("Tool list is empty.\n");
        return;
    }

    Tool *temp = toolList, *prev = NULL;

    if (temp != NULL && temp->toolID == toolID) {
        toolList = temp->next;
        free(temp);
        printf("Tool ID %d deleted successfully.\n", toolID);
        totalTools--;
        return;
    }

    while (temp != NULL && temp->toolID != toolID) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("Tool ID %d not found.\n", toolID);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Tool ID %d deleted successfully.\n", toolID);
    totalTools--;
}

void displayAllTools() {
    if (toolList == NULL) {
        printf("Tool list is empty.\n");
        return;
    }

    Tool *temp = toolList;
    int i = 1;
    printf("\n\t\tTracked Tools\t\t\n");
    printf("SLNO.\tTool ID\t\tTool Name\t\tTool Status\n");
    printf("------------------------------------------------------------\n");

    while (temp != NULL) {
        
        printf("%d\t%d\t\t%-20s\t%-20s\n", i++, temp->toolID, temp->toolName, temp->toolStatus);
        temp = temp->next;
    }

    printf("------------------------------------------------------------\n");
}
