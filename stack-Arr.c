#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 50

typedef struct stack{
    int data[STACK_SIZE];
    int head;
}stack;

void push(stack *stk, int data){
    stk->head++;
    stk->data[stk->head] = data;
}
int pop(stack *stk){
    int retVal;
    retVal = stk->data[stk->head];
    // stk->data[stk->head] = NULL;
    stk->head--;
    return retVal;
}
int peek(stack *stk){
    return stk->data[stk->head];
}

void printStack(stack *stk){
    for(int i=0; i<=stk->head; i++){
        printf("%d ", stk->data[i]);
    }
}

int main(){
    // init stack
    stack s;
    s.head =-1;
    // Code
    push(&s, 0);
    // Print Stack
    printStack(&s);
return 0;
}