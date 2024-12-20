// 10.Compare the areas of two rectangles given their lengths and breadths and determine which rectangle has a larger area.


#include <stdio.h>


int main() {

    float l1, b1, l2, b2, area1, area2;


    printf("Enter the length and breadth of the first rectangle: ");
    scanf("%f %f", &l1, &b1);


    printf("Enter the length and breadth of the second rectangle: ");
    scanf("%f %f", &l2, &b2);


    area1 = l1 * b1;
    area2 = l2 * b2;


    if (area1 > area2) {
        printf("The first rectangle has a larger area (%.2f) than the second rectangle (%.2f).\n", area1, area2);
    } else if (area1 < area2) {
        printf("The second rectangle has a larger area (%.2f) than the first rectangle (%.2f).\n", area2, area1);
    } else {
        printf("Both rectangles have the same area (%.2f).\n", area1);
    }

    return 0;
}