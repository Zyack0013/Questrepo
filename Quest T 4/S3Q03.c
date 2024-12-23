// 3.Write a program that asks for a password until the user provides the correct one using a do-while loop.

#include <stdio.h>
#include <string.h>

int main(){

    char pws[20], cp[]="QWERTY";

    do{
        printf("Enter your password : ");
        scanf("%s",pws);

        if(strcmp(pws,cp)==0){
            printf("Welcome User\n");
        }else{
            printf("Incorrect password, Try Again!! \n");
        }
    }while (strcmp(pws,cp)!=0);


    return 0;
}