// 14.Astronaut Activity Log: Implement a stack for logging astronaut activities during a mission. Use a switch-case menu with options:
// 1: Add a new activity (push)
// 2: Remove the last activity (pop)
// 3: Display the activity log
// 4: Peek at the most recent activity
// 5: Search for a specific activity
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    int capacity;
    int top;             
    char **activities;   
    
} ActivityStack;


void initializeStack(ActivityStack *s, int initialCapacity);
int isFull(ActivityStack *s);
int isEmpty(ActivityStack *s);
void addActivity(ActivityStack *s, char *activity);
void removeActivity(ActivityStack *s);
void displayActivities(ActivityStack *s);
void peekActivity(ActivityStack *s);
void searchActivity(ActivityStack *s, char *activity);
void freeStack(ActivityStack *s);

int main() {

    ActivityStack stack;
    int initialCapacity = 10;  
    initializeStack(&stack, initialCapacity);

    int choice;
    char activity[256];  

    while (1) {
       
        printf("\nAstronaut Activity Log Menu:\n");
        printf("1: Add a new activity\n");
        printf("2: Remove the last activity\n");
        printf("3: Display the activity log\n");
        printf("4: Peek at the most recent activity\n");
        printf("5: Search for a specific activity\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
            printf("Enter astronaut activity: ");
            fgets(activity, sizeof(activity), stdin);
            activity[strcspn(activity, "\n")] = 0;  
            addActivity(&stack, activity);
            break;

            case 2:
            removeActivity(&stack);
            break;

            case 3:
            displayActivities(&stack);
            break;

            case 4:
            peekActivity(&stack);
            break;

            case 5:
            printf("Enter activity to search for: ");
            fgets(activity, sizeof(activity), stdin);
            activity[strcspn(activity, "\n")] = 0;  
            searchActivity(&stack, activity);
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
void initializeStack(ActivityStack *s, int initialCapacity) {

    s->activities = (char **)malloc(initialCapacity * sizeof(char *));

    if (!s->activities) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    s->top = -1;
    s->capacity = initialCapacity;
}

int isFull(ActivityStack *s) {

    return s->top == s->capacity - 1;

}

int isEmpty(ActivityStack *s) {

    return s->top == -1;

}

void addActivity(ActivityStack *s, char *activity) {

    if (isFull(s)) {

        s->capacity *= 2;
        s->activities = (char **)realloc(s->activities, s->capacity * sizeof(char *));

        if (!s->activities) {

            printf("Memory allocation failed!\n");
            exit(1);

        }
    }

    s->activities[++s->top] = (char *)malloc(strlen(activity) + 1);

    if (!s->activities[s->top]) {

        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(s->activities[s->top], activity);
    printf("Activity added: %s\n", activity);
}

void removeActivity(ActivityStack *s) {

    if (isEmpty(s)) {

        printf("No activities to remove. The stack is empty.\n");

    } else {

        printf("Activity removed: %s\n", s->activities[s->top]);
        free(s->activities[s->top]);
        s->top--;

    }
}

void displayActivities(ActivityStack *s) {

    if (isEmpty(s)) {

        printf("No activities logged.\n");

    } else {

        printf("Activity log:\n");

        for (int i = 0; i <= s->top; i++) {

            printf("%d: %s\n", i + 1, s->activities[i]);

        }
    }
}

void peekActivity(ActivityStack *s) {

    if (isEmpty(s)) {

        printf("No activities to peek at.\n");

    } else {

        printf("Most recent activity: %s\n", s->activities[s->top]);

    }
}

void searchActivity(ActivityStack *s, char *activity) {

    if (isEmpty(s)) {

        printf("No activities to search.\n");

    } else {

        for (int i = 0; i <= s->top; i++) {

            if (strcmp(s->activities[i], activity) == 0) {

                printf("Activity '%s' found at position %d.\n", activity, i + 1);
                return;
            }

        }

        printf("Activity '%s' not found.\n", activity);
    }
}

void freeStack(ActivityStack *s) {

    for (int i = 0; i <= s->top; i++) {

        free(s->activities[i]);

    }

    free(s->activities);
}
