// 5. Temperature Monitoring System
// Problem Statement: Simulate a temp monitoring system using:
// A volatile variable to simulate temp input.
// A static variable to hold the maximum temp recorded.
// if-else statements to issue warnings when the temp exceeds thresholds.
// A while loop to continuously monitor and update the temp.
// Key Concepts Covered: Storage classes (volatile, static), Decision-making (if-else), Looping (while).


#include <stdio.h>

void upTemp(volatile int *temp);
void cTemp(volatile int temp,int maxtemp);

int main() {

    volatile int ctemp = 35; 
    static int maxtemp = -100;    

    printf("Temperature Monitoring System\n");
    printf("'Ctrl+C' to stop.\n\n");

    while(1){
        
        upTemp(&ctemp);

        if(ctemp>maxtemp){
            maxtemp = ctemp;
        }

        cTemp(ctemp,maxtemp);

        printf("\r Temperature: %d°C | Max Temperature Recorded: %d°C",ctemp,maxtemp);
        fflush(stdout);
    }

    return 0;
}

void upTemp(volatile int *temp){

    static int dir=1; 

    if(*temp>=50){

        dir=-1;

    }else 
    if(*temp<=0){

        dir = 1;

    }

    *temp += dir;

}

void cTemp(volatile int temp,int maxtemp){

    if(temp>45){

        printf("\n Warning!!!! High temp detected!(%d°C)\n",temp);
    
    }else 
    if(temp<5){

        printf("\n Alert!!!! Low temp detected!(%d°C)\n",temp);
    
    }


}
