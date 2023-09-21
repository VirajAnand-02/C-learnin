#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;// "struct node" hasn't been renamed to "node" yet
}node;
void printList(node *head){
    node *tmp = head;
    while(tmp != NULL){
        printf("%d ", (*tmp).data);
        tmp = tmp->next;
    }
}
node * addNext(node *last, int newData){
    last -> next = malloc(sizeof(node));
    (last -> next) -> data = newData;
    (last -> next) -> next = NULL;
    return last -> next;
}
int main(){
    int i = 0;
    node *list;// pointer to Head node
    node *last;
    node *n = malloc(sizeof(node));// add of first allocated node
    if(n != NULL){
        n -> data = i;
        i++;
        n -> next = NULL;
    }
    list = n;
    last = list;
    for(int j=0;j<10;j++)
        last = addNext(last, i++);
    printList(list);
return 0;
}