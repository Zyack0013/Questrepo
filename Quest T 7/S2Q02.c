// 2. Cutting Material Optimization
// Input: Two integers: the total length of the raw material and the desired length of each piece.
// Output: The maximum number of pieces that can be cut and the leftover material.
// Function:
// int cuts(int matLen, int pieLen);


#include <stdio.h>

void cuts(int matLen,int pieLen,int *numpiec,int *leftover);

int main(){

    int matLen, pieLen;
    int numpiec, leftover;

    
    printf("Enter the total length of the raw material: ");
    scanf("%d", &matLen);

    printf("Enter the desired length of each piece: ");
    scanf("%d", &pieLen);

    
    cuts(matLen,pieLen, &numpiec, &leftover);

    
    if(pieLen>0){

        printf("Maximum number of pieces: %d\n",numpiec);
        printf("Leftover material: %d\n",leftover);
    }

    return 0;
}


void cuts(int matLen,int pieLen,int *numpiec,int *leftover){

    if(pieLen <= 0){

        printf("Invalid piece length.\n");

        *numpiec = 0;
        *leftover = matLen;
        
        return;
    }

    *numpiec = matLen / pieLen; 
    *leftover = matLen % pieLen; 

}