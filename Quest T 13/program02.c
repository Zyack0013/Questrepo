/******************************************************************************

Returning a structure from a function

*******************************************************************************/
#include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct student{

    int rollNo;

    char Name[20];

    char section;

    int marks_maths;

};
 
 
int main(){

    //Dynamically allocate and assign the values for the member elements in student struct for 5 students

    struct student *students = (struct student *)malloc(5*sizeof(struct student));

    if (students==NULL) {

        printf("Allocation failed!\n");
        return 1;

    }

    for(int i = 0;i < 5;i++) {

        printf("Enter the details of Student %d\n",i+1);
        printf("Enter the roll number : ");
        scanf("%d",&students[i].rollNo);
        getchar();

        printf("Enter the Name : ");
        fgets(students[i].Name,sizeof(students[i].Name),stdin);
        students[i].Name[strcspn(students[i].Name, "\n")] = '\0';

        printf("Enter the section : ");
        scanf("%c",&students[i].section);

        printf("Enter the mark of subject maths : ");
        scanf("%d",&students[i].marks_maths);

        printf("\n");

    }

    // printing

    for(int i = 0;i < 5;i++) {

        printf("Details of Student %d\n",i+1);
        printf("Roll Number : %d\n",students[i].rollNo);
        printf("Name : %s\n",students[i].Name);
        printf("Section : %c\n",students[i].section);
        printf("Maths mark : %d\n",students[i].marks_maths);

        printf("\n");

    }

    return 0;

}
 



