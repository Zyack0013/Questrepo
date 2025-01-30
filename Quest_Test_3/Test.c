

#include <stdio.h>
#include <stdlib.h>

int main() {

	int n = 5,sum=0;
	int *arr = (int *)malloc(n * sizeof(int));
	
	if(arr == NULL){

		printf("Memoery allocation failed");

	}
	
	for(int i = 0;i < n;i++){
    	arr[i] = i + 15;
	}
	
	printf("Array elements are : ");
	for(int i = 0;i < n;i++){
		printf("%d ",*(arr+i));
	}
	
	for(int i = 0;i >= 0;i++){
		arr[i] = i - 5;
	}

	free(arr);
	return 0;
}
