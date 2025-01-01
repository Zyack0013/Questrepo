// 1. Unit Conversion for Manufacturing Processes
// Input: A floating-point value representing the measurement and a character indicating the conversion type (e.g., 'C' for cm-to-inches or 'I' for inches-to-cm).
// Output: The converted value.
// Function:
// float convert_units(float value, char type);

#include <stdio.h>

float convert_units(float value,char type);

int main() {

    float value,result;
    char type;

    printf("Enter the value to convert: ");
    scanf("%f",&value);

    printf("Enter the conversion type\n C:cm-to-inches \n I: inches-to-cm");
    printf("\nEnter your choice : ");
    scanf(" %c", &type); 

    result = convert_units(value,type);

    
    if (result != -1) {

        if (type == 'C') {

            printf("%.2f cm = %.2f inches\n", value, result);


        } else if (type == 'I'){

            printf("%.2f inches = %.2f cm\n", value, result);
        }
    }

    return 0;
}


float convert_units(float value,char type){

    if (type == 'C') {
        
        return value / 2.54;

    }else 
    if(type == 'I') {
        
        return value * 2.54;  

    }else{
        
        printf("Invalid conversion type.\n");
        return -1;  

    }
}