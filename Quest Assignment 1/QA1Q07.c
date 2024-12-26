// 7. Bank Transaction Simulator
// Problem Statement: Simulate bank transactions. Use:
// A static variable to maintain the account balance.
// A const variable for the maximum withdrawal limit.
// if-else statements to check transaction validity.
// A do-while loop for performing multiple transactions.
// Key Concepts Covered: Storage classes (static), Type qualifiers (const), Decision-making (if-else), Looping (do-while).



#include <stdio.h>

void bank(void);

int main(){

    printf("Welcome to the Bank!\n");
    bank();
    return 0;

}

void bank(void){
    
    static double bal = 1100.0; 
    double const mWid = 1500.0,minbal=500; 
    int choice;
    double amount;

    do {
        
        printf("\n");
        printf("\nCurrent Balance : Rs.%.2f\n",bal);
        printf("Select a transaction :\n 1.Deposit\n 2.Withdraw\n 3.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        if (choice==1){
            
            printf("Enter the deposit amount: Rs ");
            scanf("%lf",&amount);
            
            if(amount<=0){

                printf("Invalid amount.\n");

            }else{

                bal += amount;
                printf("Rs.%.2f deposited successfully.\n", amount);

            }
        }else
        if(choice == 2){

            printf("Enter the withdrawal amount: Rs.");
            scanf("%lf", &amount);

            if(amount<=0){

                printf("Invalid amount. Withdrawal amount must be greater than zero.\n");

            }else 
            if(amount>mWid){

                printf("Transaction failed. Maximum withdrawal limit is Rs.%.2f.\n",mWid);

            }else 
            if(amount>bal){

                printf("Transaction failed. Insufficient balance.\n");

            }else{

                bal -= amount;
                printf("Rs.%.2f withdrawn successfully.\n",amount);

                if(bal<minbal){

                    printf("Warning!!,Your balance is lesser than your minimal balance");
                }
            }

        }else 
        if(choice==3){

            printf("Thank you. Goodbye!\n");

        }else{
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!=3);
}
