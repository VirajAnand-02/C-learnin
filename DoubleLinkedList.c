#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct DLL{
    node *head;
    int length;
}DLL;

void addNode(DLL *list, int data){
    node *tmp = (node *)malloc(sizeof(node));
    node *current = list->head;
    for(int i=0; current->next != NULL; i++){
        current = current->next;
    }
}

void initList(DLL *list){
    list->head->prev=NULL;
    list->head->next=NULL;
    list->head->data = 0;
}
void printList(DLL *list){
    node *current = list->head;
    for(int i=0; current->next != NULL; i++){
        printf("%d ", current->data);
        current = current->next;
    }
}

int main(){
    node *head = (node *)malloc(sizeof(node));
    DLL list;
    list.head = head;
    initList(&list);
    addNode(&list, 2);
    printList(&list);
    
return 0;
}