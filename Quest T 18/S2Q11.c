// 11.User Review Management: Use a stack to manage user reviews for products using a linked list. Include a switch-case menu with options:
// 1: Add a new review (push)
// 2: Remove the last review (pop)
// 3: Display all reviews
// 4: Peek at the latest review
// 5: Search for a specific review
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Review {

    char text[256];
    struct Review *next;

} Review;

typedef struct {

    Review *top;

} ReviewStack;

void initializeStack(ReviewStack *stack);
int isEmpty(ReviewStack *stack);
void push(ReviewStack *stack, const char *text);
void pop(ReviewStack *stack);
void display(ReviewStack *stack);
void peek(ReviewStack *stack);
void search(ReviewStack *stack, const char *text);
void freeStack(ReviewStack *stack);

int main() {

    ReviewStack stack;
    initializeStack(&stack);

    int choice;
    char text[256];

    while (1) {

        printf("\nUser Review Management Menu:\n");
        printf("1: Add a new review (push)\n");
        printf("2: Remove the last review (pop)\n");
        printf("3: Display all reviews\n");
        printf("4: Peek at the latest review\n");
        printf("5: Search for a specific review\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
            printf("Enter your review: ");
            scanf(" %[^\n]s", text);
            push(&stack, text);
            break;

            case 2: 
            pop(&stack);
            break;

            case 3: 
            display(&stack);
            break;

            case 4: 
            peek(&stack);
            break;

            case 5: 
            printf("Enter the review text to search: ");
            scanf(" %[^\n]s", text);
            search(&stack, text);
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

void initializeStack(ReviewStack *stack) {

    stack->top = NULL;

}

int isEmpty(ReviewStack *stack) {

    return stack->top == NULL;

}

void push(ReviewStack *stack, const char *text) {

    Review *newReview = (Review *)malloc(sizeof(Review));

    if (!newReview) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    strcpy(newReview->text, text);
    newReview->next = stack->top;
    stack->top = newReview;
    printf("Review added: %s\n", text);

}

void pop(ReviewStack *stack) {

    if (isEmpty(stack)) {

        printf("No reviews to remove. Stack is empty.\n");

    } else {

        Review *temp = stack->top;
        printf("Review removed: %s\n", temp->text);
        stack->top = stack->top->next;
        free(temp);

    }

}

void display(ReviewStack *stack) {

    if (isEmpty(stack)) {

        printf("No reviews available.\n");

    } else {

        Review *current = stack->top;
        printf("User Reviews:\n");

        while (current) {

            printf("- %s\n", current->text);
            current = current->next;

        }

    }

}

void peek(ReviewStack *stack) {

    if (isEmpty(stack)) {

        printf("No reviews available. Stack is empty.\n");

    } else {

        printf("Latest review: %s\n", stack->top->text);

    }

}

void search(ReviewStack *stack, const char *text) {

    if (isEmpty(stack)) {

        printf("No reviews available to search.\n");

    } else {

        Review *current = stack->top;

        while (current) {

            if (strcmp(current->text, text) == 0) {

                printf("Review found: %s\n", current->text);
                return;
            }

            current = current->next;

        }

        printf("Review '%s' not found.\n", text);

    }

}

void freeStack(ReviewStack *stack) {

    Review *current = stack->top;

    while (current) {

        Review *temp = current;
        current = current->next;
        free(temp);

    }

}
