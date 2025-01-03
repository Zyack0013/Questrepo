/******************************************************************************

Pointers & Array

*******************************************************************************/


/*  MODel 1 */

#include <stdio.h>

int main()
{
    int arr[5];
    int *ptr;
    
    ptr = arr;
    
    printf("Enter the elements \n");
    for(int i = 0; i < 5; i++){
        
        scanf("%d",ptr+i);
        
    }
    
    for(int i = 0; i < 5; i++){
        printf("%d => %d\n",i+1,*(ptr + i));
        
    }

    return 0;
}

/*  MODel 2 */


#include <stdio.h>

int main()
{
    int arr[5];
    int *ptr;
    
    ptr = arr;
    
    printf("Enter the elements \n");
    for(int i = 0; i < 5; i++){
        
        scanf("%d",&arr[i]);
        
    }
    
    for(int i = 0; i < 5; i++){
        
        printf("%d => %d\n",i+1,arr[i]);
        
    }

    return 0;
}


/*      MODel 3*/


#include <stdio.h>

int main()
{
    int arr[5];
    
    printf("Enter the elements \n");
    for(int i = 0; i < 5; i++){
        
        scanf("%d",arr+i);
        
    }
    
    for(int i = 0; i < 5; i++){
        
        printf("%d => %d\n",i+1,*(arr+i));
        
    }

    return 0;
}



/*
        MODel 4         Return a pointer from function       */



#include <stdio.h>

int* sum();

int main()
{
    int *ptr;
    ptr = sum();
    
    printf("Sum = %d",*ptr);

    return 0;
}

int* sum(){
    
    int a=10,b=15;
    
    int sum = a+b;
    int *ptr2 = &sum;
    return ptr2;
    
}


/*  Passin an array as parameter */

#include <stdio.h>

void printArray(int a[],int size); // void printArray(int [],int size);

int main()
{
    int arr[5] = {1,2,3,4,5};
    
    printArray(arr,5);
    
    return 0;
}

void printArray(int a[],int size){
    
    for(int i = 0;i < size;i++){
     
     printf("%d\n",a[i]);   
    }
    
}

/*          */

#include <stdio.h>

void printArray(int *ptr,int size); // void printArray(int [],int size);

int main()
{
    int arr[5] = {1,2,3,4,5};
    
    printArray(arr,5); //printArray(&arr[0],5);
    
    return 0;
}

void printArray(int *ptr,int size){
    
    for(int i = 0;i < size;i++){
     
     printf("%d\n",*(ptr + i));   // printf("%d\n",a[i]);  
    }
    
}
                      



                      