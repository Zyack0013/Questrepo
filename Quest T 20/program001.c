// Parenthesis  matching

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{

    int size;
    int top;
    char *s;

}Stack;

int parenthesisMatch(Stack *str,char *exp);

int main() {

    Stack str;

    char exp[50];

    printf("Enter the expression : ");
    fgets(exp,sizeof(exp),stdin);
    exp[strcspn(exp, "\n")]= '\0';

    if(parenthesisMatch(&str,exp)){

        printf("Balanced");
    }else {

        printf("Unbalanced");
    }

    return 0;

}



int parenthesisMatch(Stack *str,char *exp){

    str->size =strlen(exp);
    str->top = -1;
    str->s = (char *)malloc(str->size * sizeof(char));

    if(str->s == NULL){

        printf("Memory Allocation failed!\n");
    }
    
    for(int i = 0;exp[i] != '\0';i++){
        
        //push
        if(exp[i]== '('){

            str->top++;
            str->s[str->top] = exp[i];
            
        }else
        //pop
        if(exp[i]== ')') {

            str->top--;
        }

    }

    if(str->top == -1) {

        return 1;
    }
    
    return 0;

}