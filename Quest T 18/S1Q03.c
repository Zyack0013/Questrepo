// 3.Rocket Launch Checklist: Create a stack for a rocket launch checklist using arrays. Implement a switch-case menu with options:
// 1: Add a checklist item (push)
// 2: Remove the last item (pop)
// 3: Display the current checklist
// 4: Peek at the top checklist item
// 5: Search for a specific checklist item
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

    int capacity;     
    int top;          
    char **checklist; 

} ChecklistStack;

void initializeStack(ChecklistStack *stack, int initialCapacity);
int isStackEmpty(ChecklistStack *stack);
void pushChecklistItem(ChecklistStack *stack, const char *item);
void popChecklistItem(ChecklistStack *stack);
void displayChecklist(ChecklistStack *stack);
void peekChecklistItem(ChecklistStack *stack);
void searchChecklistItem(ChecklistStack *stack, const char *item);
void freeStack(ChecklistStack *stack);

int main() {

    ChecklistStack stack;
    initializeStack(&stack, 5); 

    int choice;
    char item[256];

    while (1) {
        
        printf("\nRocket Launch Checklist Menu:\n");
        printf("1: Add a checklist item (push)\n");
        printf("2: Remove the last item (pop)\n");
        printf("3: Display the current checklist\n");
        printf("4: Peek at the top checklist item\n");
        printf("5: Search for a specific checklist item\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
            printf("Enter the checklist item: ");
            scanf(" %[^\n]s", item);
            pushChecklistItem(&stack, item);
            break;

            case 2: 
            popChecklistItem(&stack);
            break;

            case 3: 
            displayChecklist(&stack);
            break;

            case 4: 
            peekChecklistItem(&stack);
            break;

            case 5: 
            printf("Enter the item to search for: ");
            scanf(" %[^\n]s", item);
            searchChecklistItem(&stack, item);
            break;

            case 6: 
            freeStack(&stack);
            printf("Exiting... Goodbye!\n");
            exit(0);

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}

void initializeStack(ChecklistStack *stack, int initialCapacity) {

    stack->checklist = (char **)malloc(initialCapacity * sizeof(char *));
    stack->top = -1;
    stack->capacity = initialCapacity;

}

int isStackEmpty(ChecklistStack *stack) {

    return stack->top == -1;

}


void pushChecklistItem(ChecklistStack *stack, const char *item) {
    
    if (stack->top == stack->capacity - 1) {
    
        stack->capacity *= 2;
        stack->checklist = (char **)realloc(stack->checklist, stack->capacity * sizeof(char *));
        printf("Stack capacity increased to %d.\n", stack->capacity);
    
    }

    
    stack->checklist[++stack->top] = (char *)malloc((strlen(item) + 1) * sizeof(char));
    strcpy(stack->checklist[stack->top], item);
    printf("Added: \"%s\"\n", item);
}

void popChecklistItem(ChecklistStack *stack) {

    if (isStackEmpty(stack)) {

        printf("Error: The checklist is empty.\n");
        return;
    }

    printf("Removed: \"%s\"\n", stack->checklist[stack->top]);
    free(stack->checklist[stack->top--]);
}

void displayChecklist(ChecklistStack *stack) {

    if (isStackEmpty(stack)) {

        printf("The checklist is empty.\n");
        return;
    }

    printf("Current Checklist:\n");

    for (int i = stack->top; i >= 0; i--) {

        printf("%d: %s\n", i + 1, stack->checklist[i]);
    }
}

void peekChecklistItem(ChecklistStack *stack) {

    if (isStackEmpty(stack)) {

        printf("The checklist is empty.\n");
        return;
    }

    printf("Top checklist item: \"%s\"\n", stack->checklist[stack->top]);
}


void searchChecklistItem(ChecklistStack *stack, const char *item) {

    if (isStackEmpty(stack)) {

        printf("The checklist is empty.\n");
        return;
    }

    for (int i = stack->top; i >= 0; i--) {

        if (strcmp(stack->checklist[i], item) == 0) {

            printf("Item found at position %d: \"%s\"\n", i + 1, stack->checklist[i]);
            return;
        }
    }

    printf("Item not found: \"%s\"\n", item);
}


void freeStack(ChecklistStack *stack) {

    for (int i = 0; i <= stack->top; i++) {

        free(stack->checklist[i]);

    }
    free(stack->checklist);
}
