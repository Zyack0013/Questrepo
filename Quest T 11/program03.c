/******************************************************************************

Double pointer 

*******************************************************************************/
#include <stdio.h>

int main()
{
    int i = 5,j = 6,k = 7;
    
    int *ip1 = &i;
    int *ip2 = &j;
    
    printf("Address of i = %p\n",&i);
    printf("Address of j = %p\n",&j);
    printf("Address of k = %p\n",&k);
    
    printf("Address of ip1 = %p\n",&ip1);
    printf("Address of ip2 = %p\n",&ip2);
    
    int **ipp = &ip1;
    *ipp = ip2;
    
    printf("*ipp = %p\n",*ipp);
    printf("**ipp = %d\n",**ipp);
    
    return 0;
}
