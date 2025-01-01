// 13.Binary to dec Conversion
//  Implement a function to convert a binary number (passed as an integer) into its dec equivalent.


#include <stdio.h>
#include <math.h>

void bToD1(int binary);
int bToD2(int binary);

int main(){

    int binary,dec;

    printf("Enter the binary : ");
    scanf("%d",&binary);

    bToD1(binary);

    dec=bToD2(binary);

    printf("Decimal equivalent f2 : %d\n",dec);


}


void bToD1(int binary){

    int dec=0,base=1,rem;

    while(binary > 0){

        rem = binary%10;          
        dec += rem*base;      
        base *= 2;                        
        binary /= 10;
    }

    printf("Decimal equivalent f1 : %d\n",dec);
}


int bToD2(int binary){

    int dec=0,base=1,rem;

    while(binary > 0){

        rem = binary%10;          
        dec += rem*base;      
        base *= 2;                        
        binary /= 10;
    }

    return dec;
}