#include<stdio.h>
#include<stdlib.h>
typedef struct dataNode{
    int data;
    dataNode *next;
}dataNode;

typedef struct queue{
    dataNode *head;
    dataNode *last;
}queue;

int enqueue(queue *q, int data){

}

int main(){
    //init queue
    queue Q;
    Q.head = NULL;
    Q.last = NULL;
    
    
return 0;
}