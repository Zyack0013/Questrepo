// 10. State Machine with Function Pointers
// Design a simple state machine where each state is represented by a function, and transitions are handled using function pointers. For example, implement a traffic light system with states like Red, Green, and Yellow.


#include <stdio.h>

void redState();
void greenState();
void yellowState();

void (*currentState)();

void transitionTo(void (*nextState)()) {

    currentState = nextState;
}

int main() {

    currentState = redState;

    for (int i = 0; i < 5; i++) {

        currentState();

        if (currentState == redState) {

            transitionTo(greenState);
        } else 
        if (currentState == greenState) {

            transitionTo(yellowState);
        } else 
        if (currentState == yellowState) {

            transitionTo(redState);
        }
    }

    return 0;
}

void redState() {
    printf("Red Light: Stop\n");
}

void greenState() {
    printf("Green Light: Go\n");
}

void yellowState() {
    printf("Yellow Light: Caution\n");
}
