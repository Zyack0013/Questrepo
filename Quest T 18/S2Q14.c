// 14.Cart Item Management: Develop a stack to manage items in a shopping cart using a linked list. Use a switch-case menu with options:
// 1: Add an item to the cart (push)
// 2: Remove the last item (pop)
// 3: View all cart items
// 4: Peek at the last added item
// 5: Search for a specific item in the cart
// 6: Exit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CartItem {

    char name[256];
    struct CartItem *next;

} CartItem;

typedef struct {

    CartItem *top;

} CartStack;

void initializeCart(CartStack *cart);
int isCartEmpty(CartStack *cart);
void pushItem(CartStack *cart, const char *name);
void popItem(CartStack *cart);
void displayCart(CartStack *cart);
void peekItem(CartStack *cart);
void searchItem(CartStack *cart, const char *name);
void freeCart(CartStack *cart);

int main() {

    CartStack cart;
    initializeCart(&cart);

    int choice;
    char name[256];

    while (1) {
        
        printf("\nShopping Cart Menu:\n");
        printf("1: Add an item to the cart (push)\n");
        printf("2: Remove the last item (pop)\n");
        printf("3: View all cart items\n");
        printf("4: Peek at the last added item\n");
        printf("5: Search for a specific item in the cart\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: 
            printf("Enter the item name: ");
            scanf(" %[^\n]s", name);
            pushItem(&cart, name);
            break;

            case 2: 
            popItem(&cart);
            break;

            case 3: 
            displayCart(&cart);
            break;

            case 4: 
            peekItem(&cart);
            break;

            case 5: 
            printf("Enter the item name to search: ");
            scanf(" %[^\n]s", name);
            searchItem(&cart, name);
            break;

            case 6: 
            printf("Exiting program.\n");
            freeCart(&cart);
            exit(0);

            default:
            printf("Invalid choice!.\n");
            break;
        }
    }

    return 0;
}


void initializeCart(CartStack *cart) {

    cart->top = NULL;

}

int isCartEmpty(CartStack *cart) {

    return cart->top == NULL;

}

void pushItem(CartStack *cart, const char *name) {

    CartItem *newItem = (CartItem *)malloc(sizeof(CartItem));

    if (!newItem) {

        printf("Memory allocation failed!\n");
        exit(1);

    }

    strcpy(newItem->name, name);
    newItem->next = cart->top;
    cart->top = newItem;
    printf("Item added to cart: %s\n", name);

}

void popItem(CartStack *cart) {

    if (isCartEmpty(cart)) {

        printf("Cart is empty. No items to remove.\n");

    } else {

        CartItem *temp = cart->top;
        printf("Item removed from cart: %s\n", temp->name);
        cart->top = cart->top->next;
        free(temp);

    }

}

void displayCart(CartStack *cart) {

    if (isCartEmpty(cart)) {

        printf("Cart is empty.\n");

    } else {

        CartItem *current = cart->top;
        printf("Cart Items:\n");

        while (current) {

            printf("- %s\n", current->name);
            current = current->next;

        }

    }

}

void peekItem(CartStack *cart) {

    if (isCartEmpty(cart)) {

        printf("Cart is empty.\n");
    } else {

        printf("Last item in cart: %s\n", cart->top->name);

    }

}


void searchItem(CartStack *cart, const char *name) {

    if (isCartEmpty(cart)) {

        printf("Cart is empty.\n");

    } else {

        CartItem *current = cart->top;

        while (current) {

            if (strcmp(current->name, name) == 0) {

                printf("Item found in cart: %s\n", name);
                return;

            }

            current = current->next;

        }

        printf("Item '%s' not found in cart.\n", name);


    }

}


void freeCart(CartStack *cart) {

    CartItem *current = cart->top;

    while (current) {

        CartItem *temp = current;
        current = current->next;

        free(temp);

    }
}
