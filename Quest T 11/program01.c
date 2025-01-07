/******************************************************************************

Pointers and String

*******************************************************************************/
#include <stdio.h>

void copyString(char *from,char *to);

int main()
{
    char str1[] = "Ananthu";
    char str2[20];
    char *ptr1,*ptr2;
    
    ptr1 = str1;
    ptr2 = str2;
    copyString(ptr1,ptr2);
    
    printf("str2 = %s",str2);

    return 0;
}

void copyString(char *from,char *to){
    
    for(; *from != '\0';from++,to++) {
        
        *to = *from;
    }
    
    *to = '\0';
    
}
