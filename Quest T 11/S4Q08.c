// 8. Menu System Using Function Pointers
// Implement a simple menu system where each menu option corresponds to a different function, and a function pointer array is used to call the selected function based on user input.


#include <stdio.h>
#include <stdlib.h>


void option1(void);
void option2(void);
void exitProgram(void);

void menu(void);

int main() {

    int choice;

    void (*menuFunctions[])() = {option1, option2,exitProgram};
    int numOptions = sizeof(menuFunctions) / sizeof(menuFunctions[0]);

    while (1) {

        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > numOptions) {

            printf("Invalid choice. Please try again.\n");
            continue;
        }

        (*menuFunctions[choice - 1])();

    }

    return 0;
}

void option1(void) {

    printf("You selected Option 1: What a wonderful World.\n");

}

void option2(void) {

    printf("You selected Option 2: Addition.\n");
    int a, b;

    printf("Enter two numbers to add: ");
    scanf("%d %d", &a, &b);

    printf("Result: %d\n", a + b);
}


void exitProgram(void) {

    printf("Exiting the program.\n");
    exit(0);

}

void menu(void) {

    printf("\n=== Menu ===\n");
    printf("1. Option 1: Display a message\n");
    printf("2. Option 2: Addition\n");
    printf("3. Exit\n");

}
