/******************************************************************************

                    POINTERS                        

*******************************************************************************/
#include <stdio.h>

int main()
{
    
    int a;
    float b;
    char c;
    
    int * pint = &a;
    float * pflt = &b;
    char * pchr = &c;
    
    printf("Size of pint = %ld \n",sizeof(pint));
    printf("Size of pflt = %ld \n",sizeof(pflt));
    printf("Size of pchr = %ld \n",sizeof(pchr));
    printf("address of pint = %p \n",&pint);
    printf("pint = %p \n",pint);
    printf("address of a = %p\n",&a);
    printf("address of pflt = %p \n",&pflt);
    printf("pflt = %p \n",pflt);
    printf("address of b = %p\n",&b);
    printf("address of pchr = %p \n",&pchr);
    printf("pchr = %p \n",pchr);
    printf("address of c = %p\n",&c);
   

    return 0;
}



/*         MODel 2        */



/******************************************************************************
 
 Understanding pointers
  
*******************************************************************************/
#include <stdio.h>

int main()
{
    
    int a = 10;
    float b = 3.14,n;
    char c = 'a';
    
    int * pint = &a;
    float * pflt = &b;
    char * pchr = &c;
    //  dereference
    
    *pflt = *pflt + 10.0; //write operation
    n = *pflt;   // read operation
    
    printf("n = %.2f \n",n);
    return 0;
}


/*         MODel 3          */


// scanf using pointer


#include <stdio.h>

int main()
{
    
    int a;
    int *ptr = &a;
    
    printf("Enter the value : ");
    scanf("%d",ptr); // ptr = &value
    
    printf("a = %d \n",a);
    return 0;
}



/* pointer and const*/


//  1.Constant data & changable Pointer 

#include <stdio.h>

int main()
{
    
    int a = 10,b = 20;
    
    int const *ptr = &a; // constant data || but we acn modify the pointer
    // *ptr = b; --> noy allowed
    
    printf("001 ptr = %p\n",ptr);
    printf("001 ptr = %d\n",*ptr);
    
    ptr = &b;
    
    printf("002 ptr = %p\n",ptr);
    printf("002ptr = %d\n",*ptr);
    
    return 0;
}

/*
            OUTPUT

001 ptr = 0x7ffc49b05608
001 ptr = 10
002 ptr = 0x7ffc49b0560c
002ptr = 20

*/


//  2.Changable data & constant Pointer 



#include <stdio.h>

int main()
{
    
    int a = 10,b = 20;
    
    int *const ptr = &a; // constant data || but we acn modify the pointer
    // *ptr = b; --> noy allowed
    
    printf("001 ptr = %p\n",ptr);
    printf("001 ptr = %d\n",*ptr);
    
    // ptr = &b;
    *ptr = b;
    
    printf("002 ptr = %p\n",ptr);
    printf("002ptr = %d\n",*ptr);
    
    return 0;
}


/*     
         OUTPUT   

001 ptr = 0x7fffe4e3c178
001 ptr = 10
002 ptr = 0x7fffe4e3c178
002ptr = 20

*/


/*     Void Pointer    */


#include <stdio.h>

int main()
{
    int a = 20;
    float b = 3.14;
    char c = 'a';
    
    void *ptr;
    
    ptr = &a;
    
    
    // printf("Value at a = %d \n",*ptr);// error: invalid use of void expression
    printf("Value at a = %d \n",*(int *)ptr);
    
    ptr = &b;
    
    printf("Value at b = %.2f \n",*(float *)ptr);
    
    ptr = &c;
    
    printf("Value at c = %c \n",*(char *)ptr);
    
    return 0;
}