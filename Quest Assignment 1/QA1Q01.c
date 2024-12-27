// 1. Student Grade Management System
// Problem Statement: Create a program to manage student grades. Use:
// A static variable to keep track of the total number of students processed.
// A const global variable for the maximum number of grades.
// A volatile variable to simulate an external grade update process.
// Use if-else and switch to determine grades based on marks and a for loop to process multiple students.
// Key Concepts Covered: Storage classes (static, volatile), Type qualifiers (const), Decision-making (if-else, switch), Looping (for).


#include <stdio.h>

#define MAX_STUDENTS 10 
const int MAX_GRADES = 100; 


void garde(int marks);

int main(){

    static int totalS = 0;  
    volatile int exg = 0;  
    int scount, marks;

    printf("Enter the number of students : ");
    scanf("%d", &scount);

    if(scount<=0 || scount>MAX_STUDENTS){

        printf("Invalid number of students(1 and %d).\n", MAX_STUDENTS);
        return 1;

    }


    for(int i=0;i<scount;i++){

        printf("\nEnter marks for Student %d : ",i + 1);
        scanf("%d",&marks);


        if(marks<0 || marks>MAX_GRADES){

            printf("Invalid marks entered!!!");
            break;

        }

        if(marks%2==1){

            exg=marks+5;
            printf("External update: %d -> %d\n",marks,exg);
            marks=exg;

        }
        
        garde(marks);
        totalS++;
        
    }

    
    printf("\nTotal number of students processed: %d\n",totalS);

    return 0;
}


void garde(int marks){

    char grade;

    if(marks>=90){

        grade='A';

    }else 
    if(marks>=80){

        grade='B';

    }else 
    if(marks>=70){

        grade='C';

    }else 
    if(marks>=60){

        grade='D';

    }else{

        grade = 'F';

    }

    
    switch(grade){
        case 'A':
        printf("Grade: A \n");
        break;
        case 'B':
        printf("Grade: B \n");
        break;
        case 'C':
        printf("Grade: C \n");
        break;
        case 'D':
        printf("Grade: D \n");
        break;
        case 'F':
        printf("Grade: F \n");
        break;
        default:
        printf("Invalid mark!!!.\n");
        break;
    }
}
