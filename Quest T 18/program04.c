/******************************************************************************

Stack ()-- linked list - push and pop

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x);
int pop();
void display();

int main()
{
   push(20);
   push(30);
   push(40);
   
   display();
   
  int poppedValue = pop();
   
  printf("Popped value = %d\n",poppedValue);

  display();
   
   return 0;
}

void push(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->next = NULL;
    if(t == NULL){
        printf("Stack is full\n");
    }else{
        
        t->data = x;
        t->next = top;
        top = t;
    }
    
}

void display(){
    struct Node *p;
    p = top;
    while(p !=NULL){
        printf("%d\n",p->data);
        p= p->next;
    }
    printf("\n");
}

int pop(){
    struct Node *t;
    int x = -1;
    if(top == NULL){
        printf("The stack is empty\n");
    }else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
