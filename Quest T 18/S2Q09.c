// 9.Coupon Code Management: Create a stack for managing coupon codes using a linked list. Use a switch-case menu with options:
// 1: Add a new coupon code (push)
// 2: Remove the last coupon code (pop)
// 3: View all available coupon codes
// 4: Peek at the latest coupon code
// 5: Search for a specific coupon code
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Coupon {

    char code[50];
    struct Coupon *next;

} Coupon;

typedef struct {

    Coupon *top;

} CouponStack;

void initializeStack(CouponStack *stack);
int isEmpty(CouponStack *stack);
void push(CouponStack *stack, const char *code);
void pop(CouponStack *stack);
void display(CouponStack *stack);
void peek(CouponStack *stack);
void search(CouponStack *stack, const char *code);
void freeStack(CouponStack *stack);

int main() {

    CouponStack stack;
    initializeStack(&stack);

    int choice;
    char code[50];

    while (1) {
        
        printf("\nCoupon Code Management Menu:\n");
        printf("1: Add a new coupon code (push)\n");
        printf("2: Remove the last coupon code (pop)\n");
        printf("3: View all available coupon codes\n");
        printf("4: Peek at the latest coupon code\n");
        printf("5: Search for a specific coupon code\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
            printf("Enter Coupon Code: ");
            scanf(" %[^\n]s", code);
            push(&stack, code);
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
            printf("Enter Coupon Code to search: ");
            scanf(" %[^\n]s", code);
            search(&stack, code);
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

void initializeStack(CouponStack *stack) {

    stack->top = NULL;

}


int isEmpty(CouponStack *stack) {

    return stack->top == NULL;

}


void push(CouponStack *stack, const char *code) {

    Coupon *newCoupon = (Coupon *)malloc(sizeof(Coupon));

    if (!newCoupon) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    strcpy(newCoupon->code, code);
    newCoupon->next = stack->top;
    stack->top = newCoupon;
    printf("Coupon code added: %s\n", code);

}


void pop(CouponStack *stack) {

    if (isEmpty(stack)) {

        printf("No coupon codes to remove. Stack is empty.\n");

    } else {

        Coupon *temp = stack->top;
        printf("Coupon code removed: %s\n", temp->code);
        stack->top = stack->top->next;
        free(temp);

    }

}


void display(CouponStack *stack) {

    if (isEmpty(stack)) {

        printf("No coupon codes available.\n");

    } else {

        Coupon *current = stack->top;
        printf("Available coupon codes:\n");

        while (current) {

            printf("- %s\n", current->code);
            current = current->next;

        }

    }

}


void peek(CouponStack *stack) {

    if (isEmpty(stack)) {

        printf("No current coupon code. Stack is empty.\n");

    } else {

        printf("Latest coupon code: %s\n", stack->top->code);

    }

}


void search(CouponStack *stack, const char *code) {

    if (isEmpty(stack)) {

        printf("No coupon codes available to search.\n");

    } else {

        Coupon *current = stack->top;

        while (current) {

            if (strcmp(current->code, code) == 0) {

                printf("Coupon code found: %s\n", current->code);
                return;

            }

            current = current->next;

        }

        printf("Coupon code '%s' not found.\n", code);

    }

}


void freeStack(CouponStack *stack) {

    Coupon *current = stack->top;

    while (current) {

        Coupon *temp = current;
        current = current->next;
        free(temp);

    }

}
