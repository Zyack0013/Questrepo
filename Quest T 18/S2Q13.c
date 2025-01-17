// 13.Product Viewing History: Implement a stack to track the viewing history of products using a linked list. Include a switch-case menu with options:
// 1: Add a product to viewing history (push)
// 2: Remove the last viewed product (pop)
// 3: Display all viewed products
// 4: Peek at the most recent product viewed
// 5: Search for a specific product
// 6: Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    char name[256];
    struct Product *next;
} Product;


typedef struct {
    Product *top;
} ProductStack;


void initializeStack(ProductStack *stack);
int isEmpty(ProductStack *stack);
void push(ProductStack *stack, const char *name);
void pop(ProductStack *stack);
void display(ProductStack *stack);
void peek(ProductStack *stack);
void search(ProductStack *stack, const char *name);
void freeStack(ProductStack *stack);

int main() {

    ProductStack stack;
    initializeStack(&stack);

    int choice;
    char name[256];

    while (1) {
        
        printf("\nProduct Viewing History Menu:\n");
        printf("1: Add a product to viewing history (push)\n");
        printf("2: Remove the last viewed product (pop)\n");
        printf("3: Display all viewed products\n");
        printf("4: Peek at the most recent product viewed\n");
        printf("5: Search for a specific product\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
            printf("Enter the product name: ");
            scanf(" %[^\n]s", name);
            push(&stack, name);
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
            printf("Enter the product name to search: ");
            scanf(" %[^\n]s", name);
            search(&stack, name);
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


void initializeStack(ProductStack *stack) {

    stack->top = NULL;

}


int isEmpty(ProductStack *stack) {

    return stack->top == NULL;

}


void push(ProductStack *stack, const char *name) {

    Product *newProduct = (Product *)malloc(sizeof(Product));

    if (!newProduct) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    strcpy(newProduct->name, name);
    newProduct->next = stack->top;
    stack->top = newProduct;
    printf("Product added to viewing history: %s\n", name);

}


void pop(ProductStack *stack) {

    if (isEmpty(stack)) {

        printf("No products to remove. Viewing history is empty.\n");

    } else {

        Product *temp = stack->top;
        printf("Product removed from viewing history: %s\n", temp->name);
        stack->top = stack->top->next;
        free(temp);

    }

}


void display(ProductStack *stack) {

    if (isEmpty(stack)) {

        printf("Viewing history is empty.\n");

    } else {

        Product *current = stack->top;
        printf("Viewed Products:\n");

        while (current) {

            printf("- %s\n", current->name);
            current = current->next;

        }

    }

}


void peek(ProductStack *stack) {

    if (isEmpty(stack)) {

        printf("Viewing history is empty.\n");

    } else {

        printf("Most recent product viewed: %s\n", stack->top->name);

    }

}



void search(ProductStack *stack, const char *name) {

    if (isEmpty(stack)) {

        printf("Viewing history is empty.\n");

    } else {

        Product *current = stack->top;

        while (current) {

            if (strcmp(current->name, name) == 0) {

                printf("Product found in viewing history: %s\n", name);
                return;

            }

            current = current->next;

        }

        printf("Product '%s' not found in viewing history.\n", name);

    }

}


void freeStack(ProductStack *stack) {

    Product *current = stack->top;

    while (current) {

        Product *temp = current;
        current = current->next;
        free(temp);

    }

}
