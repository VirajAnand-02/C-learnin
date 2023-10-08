#include<stdio.h>
#include<stdlib.h>

typedef struct item{
    int data;
    struct item *prev;
}item;

typedef struct stack{
    item *head;
    int depth;
}stack;

int is_empty(stack *stk) {
    return stk->depth == 0;
}

void push(stack *stk, int DATA){// add item to stack
    item *tmp = (item *)malloc(sizeof(item));
    if(tmp == NULL){
        printf("Mem Not allocated / Stack Overflow");
        return 0;
    }
    tmp->prev = stk->head;
    stk->head = tmp;
    stk->depth++;
}

item pop(stack *stk){// returns Popped item
    if (is_empty(stk)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    item *tmp = stk->head->prev;
    item retVal = *(stk->head);
    free(stk->head);
    stk->head = tmp;
    stk->depth--;
    return retVal;

}

item peek(stack *stk){
    return *(stk->head);
}


int main(){
    // init Stack
    stack s;
    (s.head = (item *)malloc(sizeof(item))) ? printf("Stack Init...\n", s.depth=0, s.head->prev=NULL) : printf("Err Mem Not allocaed\n");
    //code
return 0;
}