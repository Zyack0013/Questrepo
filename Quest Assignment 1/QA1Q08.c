// 8. Digital Clock Simulation
// Problem Statement: Simulate a digital clock. Use:
// volatile variables to simulate clock ticks.
// A static variable to count the total number of ticks.
// Nested for loops for hours, minutes, and seconds.
// if statements to reset counters at appropriate limits.
// Key Concepts Covered: Storage classes (volatile, static), Decision-making (if), Looping (nested for).


#include <stdio.h>

int clock(int sth, int stm);
void delay(void);

int main(){

    int lhrs,lmin;

    printf("Enter the target time (hh mm ) : ");
    scanf("%d %d",&lhrs,&lmin);

    if(lhrs<0 || lhrs>23 || lmin<0 || lmin>59){

        printf("Invalid limit. Please use valid values\n");
        return 1; 
    }

    while(1){
        
        if(clock(lhrs,lmin)){
            break;
        }
        delay();
    }


    return 0;
}

int clock(int sth,int stm){
    
    static int sec=0,min=0,hrs=0,tcount=0;

    sec++;
    tcount++;

    if(sec==60){

        sec=0;
        min++;

        if(min==60){

            min=0;
            hrs++;

            if(hrs==24){

                hrs=0;
                printf(" A day have passed !!!");
            }
        }

    }
    printf("\r Time : %02d:%02d:%02d",hrs,min,sec);
    fflush(stdout);

    if(hrs==sth && min==stm && sec==0){
        
        printf("\n");
        printf("Its Time!!!!");
        return 1;
    }

    return 0;

}

void delay(void){

    volatile int tick;
    for(tick=0;tick<500000000;tick++);
    
}