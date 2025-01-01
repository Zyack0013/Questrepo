// 3.Find Maximum of Two Numbers
// Implement a function that takes two integers as arguments and returns the larger of the two. Demonstrate how the original values are not altered.


#include <stdio.h>

void largest1(int a,int b);
int largest2(int a,int b);

int main(){

    int a,b,result;

    printf("Enter the two numbers : \n");
    scanf("%d %d",&a,&b);

    largest1(a,b);
    result=largest2(a,b);

    if(result){
        if(result == a){

            printf("The largest2 number is %d\n",a);

        }else 
        if(result == b){
            printf("The largest2 number is %d\n",b);
        }
    }else{
        printf("Both are equal\n");
    }


    return 0;
}



/*

Name: largest1()
Return Type : void
Parameter(data type of each parameter): int a and int b are the parameter
Short discription: It is used to print the largest of the given para


*/

//function definition

void largest1(int a,int b){

    if(a<b){
        printf("The largest1 number is %d\n",b);
    }else 
    if(a>b){
        printf("The largest1 number is %d\n",a);
    }else{
        printf("Both are equal\n");
    }

}

/*

Name: largest2()
Return Type : int
Parameter(data type of each parameter): int a and int b are the parameter
Short discription: It is used to return the largest of the given para


*/

//function definition


int largest2(int a,int b){

    if(a<b){

        return b;
    }else 
    if(a>b){

        return a;
    }

    return 0;
    

}