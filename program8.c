// 8. Compare the ages of two people and determine who is older or if both are of the same age.


#include <stdio.h>

int main(){

    int p1,p2;

    printf("Enter the age of first person : ");
    scanf("%d",&p1);

    printf("Enter the age of second person : ");
    scanf("%d",&p2);

    if(p1>p2){
        printf("First person is older");
    }else 
    if(p2>p1){
        printf("Second person is older");
    }else{
        printf("Both are of same age"); 
    }

    return 0;
}