/******************************************************************************

Linked list (1) -- deletion in linked list

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int arr[],int N);
void display(struct Node *first);
void insert(struct Node *p,int index,int dat); //function for insertion
int deletion(struct Node *p,int pos);

int main()
{
    int arr[] = {1,2,3,4,5},pos,x;
    
    create(arr,5);
    
    printf("\nBefore insert\n");
    display(first);
    
    insert(first,2,6);
    
    printf("\nAfter insert\n");
    display(first);
    
    pos = 5;
    x = deletion(first,pos); // deteting the pos = 5
    
    printf("\nAfter deletion of value %d at pos(%d)\n",x,pos);
    
    return 0;
}
// function for create a new linked list

void create(int arr[],int N){
    
    struct Node *temp,*last;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    
    last = first;
    
    for(int i = 1;i<N;i++) {
        
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
// function for display
void display(struct Node *first){
    while(first != NULL){
        printf("->%d",first->data);
        first = first->next;
    }
}

// function insertion

void insert(struct Node *p,int index,int dat){
    
    int i;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = dat;
    
    if(index == 0){
        temp->next = first;
        first = temp;
    }else 
    {
    for(i = 0;i < index-1;i++){
        p = p->next;
    }
    
    temp->next = p->next;
    p->next = temp;
    
    }
}
// Function for deletion

int deletion(struct Node *p,int pos){
    
    struct Node *last = NULL;
    
    int value,i;
    
    if(pos == 1){
        last = first;
        value = first->data; // extracting the value from the first node
        first = first->next; // moving the pointer first point to the next Node 
        free(last); // deleting the first node
    }else{
        
        for(i=0;i < pos-1;i++){ // travesing to the pos at loop end last = pos-1 & p = pos;
            
            last = p;
            p = p->next;
        }
        value = p->data;
        last->next = p->next;
        free(p);
    }
    
    
    return value;
}

