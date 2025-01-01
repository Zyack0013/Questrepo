// 10. Quality Control: Defective Rate Analysis
// Input: Two integers: number of defective items and total batch size.
// Output: Defective rate (percentage).
// Function:
// float calculate_defective_rate(int defective_items, int batch_size);


#include <stdio.h>


float calculate_defective_rate(int defective_items, int batch_size);

int main(){

    int defective_items, batch_size;
    float defective_rate;

    
    printf("Enter the number of defective items: ");
    scanf("%d", &defective_items);

    
    printf("Enter the total batch size: ");
    scanf("%d", &batch_size);

    
    if (defective_items < 0 || batch_size <= 0) {

        printf("Error: Defective items cannot be negative, and batch size must be positive.\n");
        return 1;
    }

    
    defective_rate = calculate_defective_rate(defective_items, batch_size);

    
    if (defective_rate == -1) {
        return 1;
    }

    printf("Defective Rate: %.2f%%\n", defective_rate);

    return 0;
}


float calculate_defective_rate(int defective_items, int batch_size){

    if (batch_size <= 0) {
        printf("Error: Batch size must be greater than zero.\n");
        return -1; 
    }

    return ((float)defective_items / batch_size) * 100;
}