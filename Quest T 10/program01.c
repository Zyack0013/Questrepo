/******************************************************************************

String  

*******************************************************************************/
#include <stdio.h>

int main()
{
    char arr[] = {"hello"};//
    for(int i = 0;i < 6;i++){

        printf("arr[%d] = %p\n",i,(arr+i));
        printf("arr[%d] = %c\n",i,*(arr+i));
    }

    return 0;
}




/******************************************************************************

String length

*******************************************************************************/
#include <stdio.h>

int main()
{
    char str1[] = "To be or not to be";
    char str2[] = ",thats is the question";
    unsigned int count = 0;
    
    while(str1[count] != '\0'){
        ++count;
    }
    
    printf("The length of the string \"%s\" is %d charaters \n",str1,count);
    
    count = 0;
    
    while(str2[count] != '\0'){
        ++count;
    }
    
    printf("The length of the string \"%s\" is %d charaters \n",str2,count);

    return 0;
}

/******************************************************************************

String length using function(not strnlen)

*******************************************************************************/

int arrLength(char arr[]);

int main() {

    char arr[] = "A function for array length";

    int length = arrLength(arr);

    printf("The length of arr- \"%s\" = %d",arr,length);

    return 0;
}

int arrLength(char arr[]){

    int count = 0;
    for(int i=0; arr[i]!= '\0';i++) {
        ++count;
    }
    return count;
}


/*    strlen   */

#include <stdio.h>
#include <string.h>

int main()
{
    char name[]= "Ananthu";
    printf("Length of the string is %d %d \n",strlen(name));

    return 0;
}


/*    strcpy   */


#include <stdio.h>
#include <string.h>

int main()
{
    char firstName[10];
    char lastName[10];
    
    strcpy(firstName,"Ananthu");
    strcpy(lastName,"Joshylal");
    
    printf("Name : %s %s",firstName,lastName);

    return 0;
}


/*    strncpy    */

#include <stdio.h>
#include <string.h>

int main()
{
    char firstName[5];
    char lastName[10];
    
    strncpy(firstName,"Ananthu",4);
    // strcpy(lastName,"Joshylal");
    
    printf("Name : %s ",firstName);

    return 0;
}