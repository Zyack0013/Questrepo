// 14. Satellite Communication Link Budget
// Pointers: Handle parameter arrays for computation.
// Arrays: Store communication parameters like power and losses.
// Functions:
// double compute_link_budget(const double *parameters, int size): Calculates the total link budget.
// void update_parameters(double *parameters, int index, double value): Updates a specific parameter.
// Pass Arrays as Pointers: Pass parameter arrays as pointers.


#include <stdio.h>

double compute_link_budget(double const *parameters, int size);
void update_parameters(double *parameters, int index, double value);

int main() {

    int status,para;
    double parameters[2],link_budget,new_value;

    printf("Enter the power : ");
    scanf("%lf",&parameters[0]);

    printf("Enter the loss : ");
    scanf("%lf",&parameters[1]);

    link_budget = compute_link_budget(parameters,2);

    printf("The total link budget : %.2lf\n",link_budget);

    printf("Do you like to update any parameters(1-->Yes or 0-->No) : ");
    scanf("%d",&status);

    if(status){

        printf("Enter the parameter to change\n0-->Power\n1-->loss\n");
        scanf("%d",&para);

        printf("Enter the new value : ");
        scanf("%lf",&new_value);

        update_parameters(parameters,para,new_value);

        link_budget = compute_link_budget(parameters,2);

        printf("The new total link budget : %.2lf\n",link_budget);
    }else {

        printf("Exiting....!");
        return 1;
    }

    return 0;
}


double compute_link_budget(const double *parameters, int size){

    double link_budget = parameters[0] + parameters[1];

    return link_budget;

}

void update_parameters(double *parameters, int index, double value){

    if(index>=0){

        parameters[index] = value;
    }

}