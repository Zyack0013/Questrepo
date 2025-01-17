/******************************************************************************

Stack (1)-- Array push

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Stack{
  
  int size;
  int top;
  int *s;
    
};

void create(struct Stack *st);
void display(struct Stack st);
void push(struct Stack *st, int x);


int main()
{
    struct Stack st;
    
    create(&st);
    
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    push(&st,5);
    
    display(st);
    

    return 0;
}

void create(struct Stack *st){
    
    printf("Enter the size : ");
    scanf("%d",&st->size);
    
    st->top = -1; // assigning top -1 
    
    st->s = (int *)malloc((st->size) *  sizeof(int)); // creating stack

    printf("Stack is been created\n");
}

void push(struct Stack *st, int x){
    
    if(st->top == st->size - 1){
        printf("Stack is full!\n");
        return;
    }else {
        
        st->top++;
        st->s[st->top] = x;
        
    }
}

void display(struct Stack st){
    
    for(int i = st.top; i >= 0; i--){  // displayed from top to bottom  
        
        printf("%d \n",st.s[i]);
        
    }
    
}



/******************************************************************************

Stack (2) -- Array pop

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Stack{
  
  int size;
  int top;
  int *s;
    
};

void create(struct Stack *st);
void display(struct Stack st);
void push(struct Stack *st, int x);
int pop(struct Stack *st);


int main()
{
    struct Stack st;
    int poppedValue;
    
    create(&st);
    
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    push(&st,5);
    
    display(st);
    
    poppedValue = pop(&st);
    printf("Popped value = %d\n",poppedValue);
    display(st);
    
    poppedValue = pop(&st);
    printf("Popped value = %d\n",poppedValue);
    display(st);

    return 0;
}

void create(struct Stack *st){
    
    printf("Enter the size : ");
    scanf("%d",&st->size);
    
    st->top = -1; // assigning top -1 
    
    st->s = (int *)malloc((st->size) *  sizeof(int)); // creating stack

    printf("Stack is been created\n");
}

void push(struct Stack *st, int x){
    
    if(st->top == st->size - 1){
        printf("Stack is full!\n");
        return;
    }else {
        
        st->top++;
        st->s[st->top] = x;
        
    }
}

void display(struct Stack st){
    
    for(int i = st.top; i >= 0; i--){  // displayed from top to bottom  
        
        printf("%d \n",st.s[i]);
        
    }
    
}

int pop(struct Stack *st){
    
    int x= -1;
    if(st->top == -1){
        printf("THe stack is empty\n");
    }else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

