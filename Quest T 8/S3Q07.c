// 7. Material Weight Calculator
// Requirements:
// Input: Weights of materials (array of floats).
// Output: Total weight (float).
// Function: Accepts a pointer to the array and calculates the sum of weights.
// Constraints: Ensure no negative weights are input.

#include <stdio.h>

float totalWeight (float *weights, int size);

int main() {

    float weights[5],total_weight;

    int size = sizeof(weights)/sizeof(weights[0]);

    printf("Enter th weights\n");

    for(int i =0;i < size;i++){

        printf("Enter the weight of %d material : ",i+1);
        scanf("%f",&weights[i]);
        if(weights[i] < 0){

            printf("Enter a valid value!!!\n");
            return 1;

        }

    }

    total_weight = totalWeight(weights,size);

    printf("The total weight = %.2f\n",total_weight);

    return 0;
}

/*

Name : totalWeight
Return Datatype : float
parameters : float *weights, size
Short discription: Fn that accepts a pointer to the array and calculates the sum of weights.

*/



float totalWeight (float *weights, int size){

    float total=0;

    for(int i =0;i < size;i++) {

        total += weights[i];

    }


    return total;
}