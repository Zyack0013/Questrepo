// 9.Develop a program that uses a constant pointer to iterate over several integer variables (not in an array) using pointer arithmetic while keeping the pointer itself constant.


#include <stdio.h>

int main() {


    for(int i = 0;i < 5;i++) {

        int *const ptr = &i;

        printf("Variable %d value: %d\n",i+1,*ptr);
        printf("AM-Variable %d value: %d\n",i+1,*ptr+10);

    }

    return 0;
}


// int main() {
//     int i =0;
//     int *const ptr = &i;

//     for(*ptr;*ptr < 5;*ptr=*ptr+1) {

//         printf("Variable %d value: %d\n",*ptr+1,*ptr+10);
        
//     }

//     return 0;
// }