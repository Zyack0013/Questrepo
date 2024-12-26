// 3. Dynamic Menu-Driven Calculator
// Problem Statement: Create a menu-driven calculator with options for addition, subtraction, multiplication, and division. Use:
// A static variable to track the total number of op performed.
// A const pointer to hold operation names.
// A do-while loop for the menu and a switch case for operation selection.
// Key Concepts Covered: Storage classes (static), Type qualifiers (const), Decision-making (switch), Looping (do-while).


#include <stdio.h>

#define maxOP 4


void add(float a,float b);
void subtract(float a,float b);
void mul(float a,float b);
void divi(float a,float b);

int main() {
    
    static int count = 0;
    
    
    const char *op[maxOP] = {"Addition","Subtraction","Multiplication","Division"};

    int choice;
    float num1, num2;
    
    do {
        
        printf("\n<----Menu---->\n");
        for(int i = 0; i < maxOP; i++){

            printf("%d. %s\n",i + 1,op[i]);

        }

        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        if(choice==5){

            printf("Exiting.Total op : %d\n",count);
            break;
        }

        if(choice>=1 && choice<=4){
            
            printf("Enter two numbers : ");
            scanf("%f %f",&num1,&num2);

            
            switch(choice){

                case 1: 
                add(num1,num2);
                break;
                case 2: 
                subtract(num1,num2);
                break;
                case 3: 
                mul(num1,num2);
                break;
                case 4:
                divi(num1,num2);
                    break;
                default:
                printf("Invalid choice!\n");
                break;
            }

            
            count++;

        } else {

            printf("Invalid choice.Try again.\n");

        }

    }while(choice!=5);

    return 0;
}


void add(float a,float b){

    printf("Result : %.2f\n",a+b);

}

void subtract(float a,float b){

    printf("Result : %.2f\n",a-b);

}


void mul(float a,float b){

    printf("Result : %.2f\n",a*b);

}


void divi(float a,float b){

    if(b!=0){

        printf("Result : %.2f\n",a/b);

    }else{

        printf("Can not divide by zero.\n");

    }
}
