#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval czas0, czas1;

typedef struct LIST {

    int value;
    struct LIST* next;

}LIST;


void add (LIST **node, int key) {
    if((*node) == NULL){
        (*node) = (LIST*) malloc (sizeof(LIST));
        (*node)->next = NULL;
        (*node)->value = key;
    }
    else{
        LIST *tmp, *new;
        tmp = (*node);
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        new = (LIST*) malloc(sizeof(LIST));
        new->value = key;
        new->next = NULL;
        tmp->next = new;
    }
}

void printList(LIST **node) {
    if ((*node) == NULL){
        printf("Lista jest pusta\n");
        return;
    }
    LIST *tmp=(*node);
    while( tmp != NULL ) {
        printf ("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

void removeElement (LIST **node, int key) {
    LIST *tmp=*node;
    while (tmp->next != NULL) {
        if (tmp->next->value == key) {
            LIST *removed = tmp->next;
            tmp->next = removed->next;
            free(removed);
        }
        else {
            tmp = tmp->next;
        }
    }
}


void merge (LIST **node1, LIST **node2){

    LIST *tmp = (*node1);

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = (*node2);

}

int get(LIST **node, int index){

    if ((*node) == NULL){
        printf("Lista jest pusta\n");
        return 0;
    }

    LIST *tmp = (*node);
    for(int i = 0; i<index; i++){
        tmp = tmp->next;
    }
    return tmp->value;
}

int main(){

    double time0=0, time250=0, time500=0, time750=0, time999=0, timerandom =0 ;


    LIST *node2 = NULL;
    LIST *node1 = NULL;


    for(int i=0; i<1000; i++){
        add(&node1,rand());
        add(&node2,rand());
    }

    for (int i = 0; i<=10000; i++){

        gettimeofday(&czas0,0);
        get(&node1,0);
        gettimeofday(&czas1,0);
        time0 = time0+(czas1.tv_usec - czas0.tv_usec);

        gettimeofday(&czas0,0);
        get(&node1,250);
        gettimeofday(&czas1,0);
        time250 = time250+(czas1.tv_usec - czas0.tv_usec);

        gettimeofday(&czas0,0);
        get(&node1,500);
        gettimeofday(&czas1,0);
        time500 = time500+(czas1.tv_usec - czas0.tv_usec);

        gettimeofday(&czas0,0);
        get(&node1,750);
        gettimeofday(&czas1,0);
        time750 = time750+(czas1.tv_usec - czas0.tv_usec);

        gettimeofday(&czas0,0);
        get(&node1,999);
        gettimeofday(&czas1,0);
        time999 = time999+(czas1.tv_usec - czas0.tv_usec);

        gettimeofday(&czas0,0);
        get(&node1,(int)(rand() / (RAND_MAX + 1.0) * 1000.0));
        gettimeofday(&czas1,0);
        timerandom = timerandom+(czas1.tv_usec - czas0.tv_usec);

    }

    time0 = time0/10000;
    printf("Czas 1 elementu: %f\n",time0);
    time250 = time250/10000;
    printf("Czas 251 elementu: %f\n",time250);
    time500 = time500/10000;
    printf("Czas 501 elementu: %f\n",time500);
    time750 = time750/10000;
    printf("Czas 751 elementu: %f\n",time750);
    time999 = time999/10000;
    printf("Czas 1000 elementu: %f\n",time999);
    timerandom = timerandom/10000;
    printf("Czas losowych elementow: %f\n",timerandom);


    merge(&node1,&node2);

  return 0;

}

