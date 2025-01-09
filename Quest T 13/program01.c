/******************************************************************************

Structure and Function(1)

*******************************************************************************/
#include <stdio.h>

struct S{
    int a;
    int b;
};

int sum(struct S N1);

int main() {
    
    struct S sum1;
    sum1.a = 10;
    sum1.b = 20;
    
    int sum2 = sum(sum1);
    
    printf("Sum = %d",sum2);
    
    
    return 0;
}


int sum(struct S N1){
    
    int sum = N1.a + N1.b;
    return sum;  
    
}

/******************************************************************************

Structure and Function(2)

*******************************************************************************/
#include <stdio.h>

struct S{
    int a;
    int b;
};

int sumFun(struct S *N1);

int main() {
    
    struct S sum1;
    struct S *ptr = &sum1;
    ptr->a = 10;
    ptr->b = 20;
    
    int sum2 = sumFun(ptr);
    
    printf("Sum = %d",sum2);
    
    
    return 0;
}


int sumFun(struct S *ptr){
    
    int sum = ptr->a + ptr->b;
    return sum;  
    
}


/******************************************************************************

Returning a structure from a function

*******************************************************************************/
#include <stdio.h>
#include <string.h>

struct Student{

    int rollNumber;
    char name[50];
    char section;
    int marks_maths;
    
};

struct Student studentInfo(void);

int main() {
    
    printf("Enter the student details\n");
    struct Student S = studentInfo();
    
    printf("Roll Number : %d\n",S.rollNumber);
    printf("Name : %s\n",S.name);
    printf("Section : %c\n",S.section);
    printf("Maths mark : %d\n",S.marks_maths);
    
    return 0;
}


struct Student studentInfo(void){
    
    struct Student S1;
    
    S1.rollNumber = 12;
    strcpy(S1.name,"Ananthu");
    S1.section = 'A';
    S1.marks_maths = 77;
    
    return S1;
}
