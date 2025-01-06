// 8.Decision Tree Constructor
// Function Prototype: void constructDecisionTree(const double *features, int size, int *treeStructure)
// Data Types: const double*, int, int*
// Concepts: Decision-making, arrays, functions.
// Details: Construct a decision tree based on feature data, updating the tree structure by reference.


#include <stdio.h>

void constructDecisionTree(double const *features, int size, int *treeStructure);

int main() {

    double features[] = {0.8, 1.2, 2.5, 0.4, 1.4};
    int size = 5;
    int treeStructure[size];

    constructDecisionTree(features,size,treeStructure);

    printf("Decision Tree Structure \n");
    printf("|------------------|\n");

    for (int i = 0; i < size; i++) {

        printf("Node %d: %d\n", i, treeStructure[i]);

    }


    return 0;
}

void constructDecisionTree(double const *features, int size, int *treeStructure) {

    for (int i = 0; i < size; i++) {

        if (features[i] < 1.0) {

            treeStructure[i] = -1; 

        } else 
        if(features[i] >= 1.0 && features[i] < 2.0) {

            treeStructure[i] = 0; 

        } else {

            treeStructure[i] = 1; 

        }
    }

}