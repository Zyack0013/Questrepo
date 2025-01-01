// 5. Material Wastage Calculation
// Input: Two integers: total material length and leftover material length.
// Output: The amount of material wasted.
// Function:
// int calculate_wastage(int total_length, int leftover_length);


#include <stdio.h>


int calculate_wastage(int total_length, int leftover_length);

int main() {


    int total_length,leftover_length, wastage;

    
    printf("Enter the total material length: ");
    scanf("%d", &total_length);

    
    printf("Enter the leftover material length: ");
    scanf("%d", &leftover_length);

    wastage = calculate_wastage(total_length, leftover_length);

    if (wastage != -1) {
        printf("The amount of material wasted is: %d units\n", wastage);
    }

    return 0;
}


int calculate_wastage(int total_length, int leftover_length){

    if(total_length < 0 || leftover_length < 0 || leftover_length > total_length){

        printf("Invalid input.\n");
        return -1; 
    }
    return total_length - leftover_length;
}