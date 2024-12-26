// 9. Game Score Tracker
// Problem Statement: Track scores in a simple game. Use:
// A static variable to maintain the current score.
// A const variable for the winning score.
// if-else statements to decide if the player has won or lost.
// A while loop to play rounds of the game.
// Key Concepts Covered: Storage classes (static), Type qualifiers (const), Decision-making (if-else), Looping (while).


#include <stdio.h>

int const wscore = 76;

int play(void);

int main(){

    static int status=0;
    char again;
    int l=1;

    printf("Welcome To the Game \n");
    printf("Score a total of %d points to win!! \n \t \t Lets Start...\n",wscore);

    while(l){

        if(status==0){

            play();
            status=1;
        }else{

            printf("Do you want to play another round?(Y/N) : \n");
            getchar();
            scanf("%c",&again);

            if(again == 'N' || again == 'n'){

                printf("Thanks for playing, Hvae a nice day \n");
                return 0;
                
            }

        }

 
    }



    return 0;
}

int play(void){

    static int cscore=0;

    int p=0,escore,fscore;
    char again;

    printf("Enter your number : ");
    scanf("%d",&escore);

    p = escore%2;
    fscore= (escore%2==1)? escore + escore/3 : - escore;

    cscore += fscore^(1<<(p+1));

    if(cscore>=wscore){

        printf("Congrats!!! You have won..... \n Your score is %d \n",cscore);
        cscore=0;
    }else
    if(cscore<0){

        printf("Oops, Game Over!!!,You lost....\n");
        cscore=0;
    }else{
        printf("Your current score is : %d\n",cscore);
        printf("Do you want to continue this round?(Y/N) : \n");
        getchar();
        scanf("%c",&again);

        if(again == 'Y' || again == 'y'){
            play();
        }else 
        if(again == 'N' || again == 'n'){

            cscore=0;
            // return 1;
        }
    }    
    return 0;


}