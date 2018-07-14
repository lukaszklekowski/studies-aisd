#include <stdio.h>
#include <stdlib.h>

typedef struct FIFO{
    int value;
    struct FIFO *next;
}FIFO;

void push(FIFO **head, FIFO **tail, int key) {
    FIFO *new;
    new= (FIFO *)malloc(sizeof(FIFO));
    new->value=key;
    new->next=NULL;

    if(*head==NULL){
        *head=new;
        *tail=new;
    }else{
        (*tail)->next=new;
        (*tail)=new;
    }
}
void pop(FIFO **head) {
    FIFO *tmp=(*head);

    if((*head)==NULL){
        printf("Kolejka jest pusta\n");
    }else if((*head)->next==NULL){
        printf("Usunieto element: %d\n", tmp->value);
        *head=NULL;
    }
    else{
        printf("Usunieto element: %d\n", tmp->value);
        (*head)=(*head)->next;
        free(tmp);
    }
}

void printFIFO(FIFO *head){

    if(head==NULL)printf("Kolejka jest pusta");
    else while(head!=NULL){
            printf("%d   ", head->value);
            head=head->next;
        }
    printf("\n");
}

int main() {
    FIFO *head=NULL;
    FIFO *tail=NULL;


    push(&head,&tail,3);
    push(&head,&tail,8);
    push(&head,&tail,7);
    printFIFO(head);
    pop(&head);
    printFIFO(head);

    return 0;
}