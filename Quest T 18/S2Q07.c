// 7.Wishlist Management: Develop a stack to manage user wishlists using a linked list. Use a switch-case menu with options:
// 1: Add a product to wishlist (push)
// 2: Remove the last added product (pop)
// 3: View all wishlist items
// 4: Peek at the most recent wishlist item
// 5: Search for a specific product in wishlist
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WishlistItem {

    int productID;
    char productName[100];
    struct WishlistItem *next;
    
} WishlistItem;

typedef struct {

    WishlistItem *top;
} WishlistStack;


void initializeStack(WishlistStack *stack);
int isEmpty(WishlistStack *stack);
void push(WishlistStack *stack, int productID, const char *productName);
void pop(WishlistStack *stack);
void display(WishlistStack *stack);
void peek(WishlistStack *stack);
void search(WishlistStack *stack, int productID);
void freeStack(WishlistStack *stack);

int main() {

    WishlistStack stack;
    initializeStack(&stack);

    int choice, productID;
    char productName[100];

    while (1) {
        
        printf("\nWishlist Management Menu:\n");
        printf("1: Add a product to wishlist (push)\n");
        printf("2: Remove the last added product (pop)\n");
        printf("3: View all wishlist items\n");
        printf("4: Peek at the most recent wishlist item\n");
        printf("5: Search for a specific product in wishlist\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
            printf("Enter Product ID: ");
            scanf("%d", &productID);
            printf("Enter Product Name: ");
            scanf(" %[^\n]s", productName);
            push(&stack, productID, productName);
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
            printf("Enter Product ID to search: ");
            scanf("%d", &productID);
            search(&stack, productID);
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

void initializeStack(WishlistStack *stack) {

    stack->top = NULL;
}

int isEmpty(WishlistStack *stack) {

    return stack->top == NULL;
}

void push(WishlistStack *stack, int productID, const char *productName) {

    WishlistItem *newItem = (WishlistItem *)malloc(sizeof(WishlistItem));

    if (!newItem) {

        printf("Memory allocation failed!\n");
        exit(1);
    }

    newItem->productID = productID;
    strcpy(newItem->productName, productName);
    newItem->next = stack->top;
    stack->top = newItem;
    printf("Product added to wishlist: ID %d, Name: %s\n", productID, productName);
}


void pop(WishlistStack *stack) {

    if (isEmpty(stack)) {

        printf("Wishlist is empty. No product to remove.\n");
    } else {

        WishlistItem *temp = stack->top;
        printf("Product removed from wishlist: ID %d, Name: %s\n", temp->productID, temp->productName);
        stack->top = stack->top->next;
        free(temp);
    }
}

void display(WishlistStack *stack) {

    if (isEmpty(stack)) {

        printf("Wishlist is empty.\n");

    } else {

        WishlistItem *current = stack->top;
        printf("Wishlist items:\n");

        while (current) {

            printf("ID: %d, Name: %s\n", current->productID, current->productName);
            current = current->next;
        }
    }
}

void peek(WishlistStack *stack) {

    if (isEmpty(stack)) {

        printf("Wishlist is empty.\n");

    } else {

        printf("Most recent wishlist item: ID %d, Name: %s\n", stack->top->productID, stack->top->productName);
    }
}

void search(WishlistStack *stack, int productID) {

    if (isEmpty(stack)) {

        printf("Wishlist is empty. No product to search.\n");

    } else {

        WishlistItem *current = stack->top;

        while (current) {

            if (current->productID == productID) {

                printf("Product found: ID %d, Name: %s\n", current->productID, current->productName);
                return;
            }
            current = current->next;
        }
        printf("Product with ID %d not found in wishlist.\n", productID);
    }
}

void freeStack(WishlistStack *stack) {

    WishlistItem *current = stack->top;

    while (current) {

        WishlistItem *temp = current;
        current = current->next;
        free(temp);
    }
}
