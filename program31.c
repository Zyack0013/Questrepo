// 9.Write a program to calculate the electricity bill based on the number of units consumed using the following criteria:
// Units <= 100: ₹5 per unit
// Units > 100 and <= 200: ₹7 per unit
// Units > 200: ₹10 per unit


#include <stdio.h>

int main(){

    int units;
    float bill;

    printf("Enter the unit : ");
    scanf("%d",&units);

    if (units <= 100) {
        bill = units*5.0;

    } else if (units>100 && units<=200) {
        bill = (100*5.0) + ((units-100)*7.0);
    } else {
        bill = (100*5.0) + (100*7.0) + ((units-200)*10.0);
    }

    printf("The bill amount is: Rs.%.2f\n",bill);
    return 0;

}