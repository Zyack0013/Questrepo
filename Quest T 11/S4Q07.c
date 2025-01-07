// 7. Callback Function
// Create a program with a function void execute(int x, int (*callback)(int)) that applies a callback function to an integer and prints the result. Demonstrate with multiple callback functions (e.g., square, cube).

#include <stdio.h>

int square(int x);
int cube(int x);

void execute(int x, int (*callback)(int));

int main() {

    int num = 5;

    printf("Applying square operation:\n");
    execute(num, square);

    printf("Applying cube operation:\n");
    execute(num, cube);

    return 0;
}

int square(int x) {
    return x * x;
}

int cube(int x) {

    return x * x * x;
}

void execute(int x, int (*callback)(int)) {

    int result = callback(x); 
    printf("Result: %d\n", result);

}
