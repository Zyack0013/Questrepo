// 9. Defect Rate Analyzer
// Requirements:
// Input: Total products and defective products (integers).
// Output: Defect rate (float).
// Function: Uses pointers to calculate defect rate = (Defective / Total) * 100.
// Constraints: Ensure total products > defective products.





#include <stdio.h>


void defRate(int *totalProducts, int *defectiveProducts, float *defectRate);

int main() {
   
    int totalProducts, defectiveProducts;
    float defectRate;

  
    printf("Enter the total number of products: ");
    scanf("%d", &totalProducts);

    printf("Enter the number of defective products: ");
    scanf("%d", &defectiveProducts);

    
    if (totalProducts <= 0) {

        printf("Error: Total products must be greater than 0.\n");
        return 1;
    }
    if (defectiveProducts > totalProducts) {

        printf("Error: Defective products cannot exceed total products.\n");
        return 1;
    }

    
    defRate(&totalProducts, &defectiveProducts, &defectRate);

    printf("Defect rate: %.2f%%\n", defectRate);

    return 0;
}

/*

Name : defRate
Return Datatype : void
parameters : int *totalProducts,*defectiveProducts,float *defectRate
Short discription: Fn that uses pointers to calculate defect rate = (Defective / Total) * 100.

*/

void defRate(int *totalProducts, int *defectiveProducts, float *defectRate){

    *defectRate = ((float)(*defectiveProducts) / (*totalProducts))*100;
}
