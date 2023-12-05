#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList {
    int data;
    struct LinkedList *next;
} LinkedList;

void enqueue(LinkedList *head, int data) {
    LinkedList *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = (LinkedList *)malloc(sizeof(LinkedList));
    if (curr->next == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    curr->next->next = NULL;
    curr->next->data = data;
}

int dequeue(LinkedList **head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("Empty Queue !!!\n");
        return -1; // Using -1 to indicate an empty queue
    }

    LinkedList *tmp = (*head)->next;
    int data = tmp->data;

    // Update the head pointer to point to the next node
    (*head)->next = tmp->next;
    
    // Free the removed node
    free(tmp);

    if ((*head)->next == NULL) {
        printf("Queue is now Empty\n");
    }

    return data;
}

void printQueue(LinkedList *head) {
    LinkedList *curr = head->next;
    printf("\n-----\n");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n-----\n");
}

int main() {
    int inp;
    int data;
    LinkedList *head = (LinkedList *)malloc(sizeof(LinkedList));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    head->next = NULL;
    system("cls");
    while (1){
        printf("Select option :\n1) Enqueue\n2) Dequeue \n3) Show queue \n4) exit \n>");
        scanf("%d", &inp);
        switch (inp){
            case 1:
                printf("Item to enqueue : ");
                scanf("%d", &data);
                enqueue(head, data);
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Item Dequeued : %d\n", dequeue(&head));
                break;
            case 3:
                system("cls");
                printQueue(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                break;
        }
    }
        


    // Free the allocated memory
    LinkedList *curr = head;
    while (curr != NULL) {
        LinkedList *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
