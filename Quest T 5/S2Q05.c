// 5. Static Variable to Track Loop Re-entry
// Problem Statement: Write a program where a static variable keeps track of how many times the loop is re-entered after being interrupted (e.g., using a break statement).


#include <stdio.h>

static int count=0;

void loop(void);

int main(){

    loop();

    printf("The number of re-entry : %d\n",count);


    return 0;

}

void loop(void){

    int i,lcount=1;

    while(count<100){


        for(i=1;i<=10;i++){

            printf(" i=%d\n",i);
            printf(" lcount=%d\n",lcount);

            if(i==8){

                printf("Loop break!!\n");
                break;
            }

            lcount++;
        }

        if(lcount==8){

            count++;
            loop();
        }

        
    }


}