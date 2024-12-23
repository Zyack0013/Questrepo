// 1.Write a menu-driven calculator using a do-while loop. Continue asking for user input until they choose to exit.

#include <stdio.h>

int main(){

    int a,b,option,result,s=1;

    do{
        printf("Menu \n 1.Addition\n 2.Substraction \n 3.Multiplication\n 4.Division\n 5.Exit\n Enter Your Choice : ");
        scanf("%d",&option);
        switch(option){
            case 1:
            printf("Enter the two integers : ");
            scanf("%d\n %d",&a,&b);
            result = a+b;
            printf("%d + %d = %d \n \n",a,b,result);
            break;
            case 2:
            printf("Enter the two integers : ");
            scanf("%d\n %d",&a,&b);
            result = a-b;
            printf("%d - %d = %d \n \n",a,b,result);
            break;
            case 3:
            printf("Enter the two integers : ");
            scanf("%d \n %d",&a,&b);
            result = a*b;
            printf("%d x %d = %d \n \n",a,b,result);
            break;
            case 4:
            printf("Enter the two integers : ");
            scanf("%d\n %d",&a,&b);
            result = a/b;
            printf("%d / %d = %d \n \n",a,b,result);
            break;
            case 5:
            s=0;
            break;
            default:
            printf("Invalid choice \n");
            break;
        }
    
    }while(s);
    return 0;
}