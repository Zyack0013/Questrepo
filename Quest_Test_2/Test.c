// Problem 12: Personal Finance Tracker
// Specifications:
// Variables: Income, expenses, category, and balance.
// Static & Const: Static variable for total transactions; const for maximum categories.
// Switch Case: Menu for adding, viewing, and analyzing finances.
// Looping Statements: Loop through transactions.
// Pointers: Pointer for updating balance.
// Functions: Separate functions for each finance operation.
// Arrays: Store transaction details.
// Structures: Structure for transaction details.
// Nested Structures: Nested structures for income and expense details.
// Unions: Union for expense categories.
// Nested Unions: Nested union for subcategories.
// Output Expectations: Display financial summary and analysis.
// Menu Example:
// 1. Add Transaction
// 2. View Transactions
// 3. Analyze Finances
// 4. Exit

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 40

union category{

    float food;
    float transport;

};


typedef struct TransactionDetails{

    char ID[10];
    float income;
    float expenses;
    union category type;
    float balance;

}TransactionDetails;

static int  totalTransactionDetails =0;

// functions prototype
void addTransaction(TransactionDetails arr[],int N);
void viewTransactions(TransactionDetails arr[],int totalTransactionDetails);
void analyzeFinances(TransactionDetails arr[], int totalTransactionDetails);
void totalBalances(float balance,float *totalBalance);


int main() {

    TransactionDetails arr[MAX_SIZE];

    int choice,N;

    while(1){

        printf("\n\t\tWelcome\t\t\n");
        printf("1. Add Transaction\n2. View Transactions\n3. Analyze Finances\n4. Exit\n");
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1:
            printf("Enter the number of transactions : ");
            scanf("%d",&N);
            getchar();
            addTransaction(arr,N);
            break;

            case 2:
            viewTransactions(arr,totalTransactionDetails);
            break;

            case 3:
            analyzeFinances(arr,totalTransactionDetails);
            break;

            case 4:
            printf("Exiting ....\n");
            return 0;

            default:
            printf("Invallid choice!!!!\n");

        }

    }




    return 0;
}

// function def

void addTransaction(TransactionDetails arr[],int N){

    

    for (int i = 0; i < N; i++) {

        printf("\nEnter details for transaction %d\n",totalTransactionDetails + 1);
        printf("Enter the ID : ");
        fgets(arr[totalTransactionDetails].ID,sizeof(arr[totalTransactionDetails].ID),stdin);
        arr[totalTransactionDetails].ID[strcspn(arr[totalTransactionDetails].ID, "\n")] = '\0'; 

        printf("Enter the income: ");
        scanf("%f",&arr[totalTransactionDetails].income);

        printf("Enter the food expenses : ");
        scanf("%f",&arr[totalTransactionDetails].type.food);

        printf("Enter the transport expenses : ");
        scanf("%f",&arr[totalTransactionDetails].type.transport);
        getchar(); 

        arr[totalTransactionDetails].expenses = arr[totalTransactionDetails].type.food + arr[totalTransactionDetails].type.transport;

        arr[totalTransactionDetails].balance = arr[totalTransactionDetails].income - arr[totalTransactionDetails].expenses;

        printf("Transaction %d added successfully!\n", totalTransactionDetails + 1);

        totalTransactionDetails++;
        printf("\n");
    }

    
}


void viewTransactions(TransactionDetails arr[],int totalTransactionDetails){

    if (totalTransactionDetails == 0) {

        printf("No transactions\n");
        return;

    }
    printf("--------------------------------------------------------------------------------\n");

    printf("View Transaction Details\n");

    for (int i = 0; i < totalTransactionDetails; i++) {

        printf("\n\tDetails of ID %s\t\n",arr[i].ID);
        printf("Income : %.2f\tFood Expenses : %.2f\tTransport expenses : %.2f\tTotal expenses : %.2f\nBalance : %.2f\n",arr[i].income,arr[i].type.food,arr[i].type.transport,arr[i].expenses,arr[i].balance);
    }

    printf("--------------------------------------------------------------------------------\n");

}

void totalBalances(float balance,float *totalBalance){

    *totalBalance += balance;

}

void analyzeFinances(TransactionDetails arr[], int totalTransactionDetails){

    if (totalTransactionDetails == 0) {

        printf("No transactions.\n");
        return;
    }

    float totalIncome = 0.0,totalExpenses = 0.0,totalBalance = 0.0;

    for (int i = 0; i < totalTransactionDetails; i++) {

        totalIncome += arr[i].income;
        totalExpenses += arr[i].expenses;
        totalBalances(arr[i].balance,&totalBalance);

    }

    printf("\n Analysis:\n");
    printf("Total Income: %.2f\n",totalIncome);
    printf("Total Expenses: %.2f\n",totalExpenses);
    printf("Balance: %.2f\n",totalBalance);
}

