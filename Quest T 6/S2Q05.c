// 5. Heart Rate Monitor
// Write a program to record and analyze heart rates from a patient during 10 sessions.
// Use an array to store the heart rates.
// Include static variables to count abnormal readings (below 60 or above 100 BPM).
// Loop through the array to calculate average heart rate and display results.


#include <stdio.h>

#define READINGS 10
#define ULIMIT 100
#define LLIMIT 60

void getRead(int rateRead[]);

void analyze(int rateread[]);

int main(){

    int rateRead[READINGS];

    printf("Enter the 10 Readings.\n");
    getRead(rateRead);

    analyze(rateRead);

    return 0;

}

void getRead(int rateRead[]){

    for(int i = 0; i < READINGS; i++){

        printf("\nEnter the heart rate at %d : ",i+1);
        scanf("%d",&rateRead[i]);

    }

}

void analyze(int rateRead[]){

    static int abCount=0;

    int totalRate=0;
    float avgRate;

    for(int i = 0; i < READINGS; i++){

        totalRate += rateRead[i];

        if(rateRead[i] < LLIMIT || rateRead[i] > ULIMIT ){

            abCount++;
            printf("Abnormal heart rate detected in session %d: %d BPM\n", i+1,rateRead[i]);

        }
    }

    avgRate = (float)totalRate/READINGS;

    printf("\nTotal abnormal readings: %d\n", abCount);
    printf("Average heart rate over %d sessions: %.2f BPM\n",READINGS,avgRate);

    if(abCount>0){

        printf("The patient had %d abnormal readings\n",abCount);
        
    }else{

        printf("There are no abnormal readings\n");
    }


}