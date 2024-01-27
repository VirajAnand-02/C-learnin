#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

void display(node *head){
    node *tmp = head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

node * push(node *last, int newData){
    last -> next = malloc(sizeof(node));
    (last -> next) -> data = newData;
    (last -> next) -> next = NULL;
    return last -> next;
}

node *insertBegining(node **head, int data){
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = *head;
    *head = tmp;
    return tmp;
}

node *insertEnd(node **head, int data){
    node *curr = (node *)malloc(sizeof(node));
    curr = *head;
    while (curr->next != NULL) curr = curr->next;
    curr->next = (node *)malloc(sizeof(node));
    curr->next->next = NULL;
    curr->next->data = data;    
    return *head;
}

node *insertAt(node **head,int index, int data){
    node *curr = (node *)malloc(sizeof(node));
    curr = *head;
    for (int i = 1; i < index; i++) curr = curr->next;
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = curr->next;
    curr->next = tmp;    
    return *head;
}

void deleteList(node **head) {
    node *curr = *head;
    while (curr != NULL) {
        node *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    *head = NULL;
}

void reverseList(node** head) {
    node *prev = NULL, *current = *head, *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    *head = prev;
}

void sortList(node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    int swapped;
    node *ptr1;
    node *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

node *concatList(node *first, node *second){
    node *curr = first;
    while (curr->next!=NULL) curr = curr->next;
    curr->next = second;
    second->prev = curr;
    return first;
}

int main(){
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    head->data = 1;
    display(head);
    insertBegining(&head, 20);
    display(head);
    insertEnd(&head, 69);
    display(head);
    insertAt(&head,2, 79);
    display(head);
    reverseList(&head);
    display(head);
    sortList(&head);
    display(head);
    deleteList(&head);
    display(head);
    return 0;
}
