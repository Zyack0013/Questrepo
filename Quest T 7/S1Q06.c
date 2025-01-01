// 6.Calculate Simple Interest
//  Write a program that calculates simple interest using a function. Pass principal, rate, and time as arguments and return the computed interest.

#include <stdio.h>

void simpleInterest1(float p,float r,float t);
float simpleInterest2(float p,float r,float t);

int main(){

    float principal,rate,time,interest;

    printf("Enter the principal amount : Rs. ");
    scanf("%f",&principal);

    printf("Enter the rate of interest : ");
    scanf("%f",&rate);

    printf("Enter the time in years : ");
    scanf("%f",&time);

    simpleInterest1(principal,rate,time);
    interest = simpleInterest2(principal,rate,time);

    printf("simpleInterest2 - The simple interest is : Rs.%.2f\n",interest);


    return 0;
}
/*
Name : simpleInterest1
Return Datatype : void
parameters : float principal,rate & time
Short discription: its used to print the simpleInterest of given paramters

*/

void simpleInterest1(float p,float r,float t){

    float result;

    result = (p*r*t) / 100.0;

    printf("simpleInterest1 - The simple interest is : Rs.%.2f\n",result);


}
/*
Name : simpleInterest1
Return Datatype : void
parameters : float principal,rate & time
Short discription: its used to return the simpleInterest of given paramters

*/


float simpleInterest2(float p,float r,float t){

    float result;

    result = (p*r*t) / 100.0;

    return result;

}