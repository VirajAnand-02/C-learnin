#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

typedef struct DLL {
    node* head;
    int length;
} DLL;

void addNode(DLL* list, int data) {
    node* tmp = (node*)malloc(sizeof(node));
    tmp->data = data;
    tmp->next = NULL;

    if (list->head == NULL) {
        tmp->prev = NULL;
        list->head = tmp;
    } else {
        node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = tmp;
        tmp->prev = current;
    }

    list->length++;
}

void initList(DLL* list) {
    list->head = NULL;
    list->length = 0;
}

void display(DLL* list) {
    node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void dispRev(DLL* list) {
    node* curr = list->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
}

int main() {
    DLL list;
    initList(&list);
    addNode(&list, 2);
    addNode(&list, 4);
    addNode(&list, 6);
    addNode(&list, 0);
    addNode(&list, -3);

    printf("Forward: ");
    display(&list);

    printf("Reverse: ");
    dispRev(&list);

    return 0;
}
