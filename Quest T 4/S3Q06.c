// 6.Write a program where the user guesses a predefined number. Continue the game until the correct number is guessed.


#include <stdio.h>

int main(){

    int gn,setn= 77;

    do{
        printf("Enter your guess : ");
        scanf("%d",&gn);

        if(gn>setn){
            printf("Try lower numbers\n");
        }else if(gn<setn){
            printf("Try higher numbers\n");
        }else {
            printf("Correct gusses!!!\n");
        }
    }while(gn!=setn);


    return 0;

}