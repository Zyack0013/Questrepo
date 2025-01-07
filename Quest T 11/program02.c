/*         Malloc     */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int *p = (int *)malloc(100); // int *p = malloc(100);  
    printf("p = %p\n",p);
    free(p);
    printf("p = %p\n",p);

    return 0;
}




/******************************************************************************

Double pointer

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num = 25;
    int *p = &num;
    int **dp = &p;
    int ***tp = &dp;
    
    printf("001num = %d\n",*p);
    printf("002num = %d\n",**dp);
    printf("003num = %d\n",***tp);

    return 0;
}


/******************************************************************************

Double pointer

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num = 25;
    int *p = &num;
    int **dp = &p;
    int ***tp = &dp;
    
    printf("Address of num = %p\n",&num);
    printf("Address of p = %p\n",&p);
    printf("Address of dp = %p\n",&dp);
    
    printf("num value using p = %d\n",*p);
    printf("num value using dp = %p\n",**dp);
    
    return 0;
}
