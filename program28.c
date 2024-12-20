// 5.Write a program to check if a student is eligible for admission based on the following criteria:
// Marks in mathematics >= 50
// Marks in physics >= 50
// Total marks (math + physics) >= 120
// Use nested if-else statements.
 #include <stdio.h>

 int main(){

    float maths,phy,total;

    printf("Enter mathematics mark : ");
    scanf("%f",&maths);

    printf("Enter Physics mark : ");
    scanf("%f",&phy);

    total= maths + phy;

    if(maths>=50){
        if(phy>=50){
            if(total>=120){
                printf("You are eligible for admission");
            }else{
                printf("You are not eligible for admission,Total mark < 120");
            }
        }else{
            printf("You are not eligible for admission,Physics mark < 50");
        }
    }else{
        printf("You are not eligible for admission, Mathematics mark < 50");
    }


    return 0;
 }