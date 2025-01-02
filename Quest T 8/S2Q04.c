// 4.Develop a program that uses a constant pointer to iterate over multiple integers stored in separate variables. Show how you can modify their values through dereferencing while keeping the pointer itself constant.



#include <stdio.h>

int main() {

    int arr[5]= {1,2,3,4,5};
    int *const ptr[5] = {&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]};

    for(int i = 0;i < 5;i++){

        printf("The array element at [%d] + 10 = %d\n",i,*ptr[i]+10);
    }


    return 0;
}