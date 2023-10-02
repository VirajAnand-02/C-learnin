#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct dataNode{
    int data;
    struct dataNode *next;
}dataNode;

typedef struct queue{
    dataNode *head;
    dataNode *last;
    int len;
    int max;
}queue;

int enqueue(queue *q, int data){
    dataNode *tmp = (dataNode *)malloc(sizeof(dataNode));
    if(tmp != NULL){
        tmp->next = NULL;
        tmp->data = data;
        q->last->next = tmp;
        q->last = tmp;
        q->len++;
        return 0;
    }
    else{
        return -1;
    }
}

int dequeue(queue *Q){
    dataNode *tmp = Q->head->next;
    int returnVal = Q->head->data;
    Q->head = tmp;
    Q->len--;
    return returnVal;
}

bool isEmpty(queue *Q){
    if(Q->len <= 0)
        return true;
    return false;
}

bool isFull(queue *Q){
    if(Q->len == Q->max)
        return true;
    return false;
}
int size(queue *Q){
    return Q->len;
}

int main(){
    printf("Initilazing ... ");
    //init queue
    queue Q;
    Q.head = NULL;
    Q.last = NULL;
    Q.max = 10;
    Q.len = 0;
    printf("Enqueuing ... ");
    enqueue(&Q, 20);
    printf("Enqueuing ... ");
    enqueue(&Q, 20);
    printf("Enqueuing ... ");
    enqueue(&Q, 20);
    printf("Enqueuing ... ");
    enqueue(&Q, 20);
    printf("Enqueuing ... ");
    enqueue(&Q, 20);
    printf("Enqueuing ... ");
    enqueue(&Q, 20);
    printf("Enqueuing ... ");
    printf("%d", dequeue(&Q));

    
return 0;
}