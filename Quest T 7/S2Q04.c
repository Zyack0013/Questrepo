// 4. Production Rate Estimation
// Input: Two integers: machine speed (units per hour) and efficiency (percentage).
// Output: The effective production rate.
// Function:
// int calculate_production_rate(int speed, int efficiency);




#include <stdio.h>


int rate(int speed,int eff);


int main(){
    
    int speed,eff,prod_rate;

    printf("Enter the machine speed (units per hour): ");
    scanf("%d", &speed);

    printf("Enter the eff percentage: ");
    scanf("%d", &eff);

    prod_rate = rate(speed,eff);

    
    if(eff >= 0 && eff <= 100){

        printf("The effective production rate is: %d units per hou\n",prod_rate);

    }

    return 0;
    

}

int rate(int speed, int eff){

    if(eff < 0 || eff > 100){

        printf("Invalid eff percentage.\n");
        return 0;
    }
    return (speed*eff) / 100;
}