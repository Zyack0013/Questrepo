// 5.Implement a program that uses pointers and decision-making statements to check if two constant integers are equal or not, printing an appropriate message based on the comparison.


#include <stdio.h>

int main() {

    int a,b;

    printf("Enter the two integers : ");
    scanf("%d %d",&a,&b);

    int const *ptr1 = &a;
    int const *ptr2 = &b;

    if(*ptr1 == *ptr2) {

        printf("Both %d and %d are equal\n",*ptr1,*ptr2);
    }else {

        printf("Both %d and %d are not equal\n",*ptr1,*ptr2);

    }


    return 0;
}