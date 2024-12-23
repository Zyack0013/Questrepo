// 9.Write a program to print lowercase alphabets from 'a' to 'z' using a do-while loop.


#include <stdio.h>

int main(){

    char ch ='a';  
    
    do{
        printf("%c ", ch); 
        ch++;               
    } while(ch<='z');     

    return 0;
}
