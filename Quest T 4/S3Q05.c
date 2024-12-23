// 5.Write a program to repeatedly display the multiplication table of a number until the user decides to stop.

#include <stdio.h>

int main(){

    int n,choice,j=10;

     printf("Enter the number : ");
     scanf("%d",&n);

    do{
       printf("The Table of %d : ",n);
       for (int i=1;i<=j;i++){
        printf("%d x %d = %d \n",n,i,n*i);
       }
       printf("Do you want to continue\n If Yes enter 1\n If to stop enter 0 \n Your Choice :");
       scanf("%d",&choice);
       j=j+10;
    }while(choice);

    return 0;
}
