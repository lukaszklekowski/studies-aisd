#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct Tree{
    int value;
    int size;
    struct Tree *parent;
    struct Tree *right;
    struct Tree *left;
}tr;


int compares =0;
int comp=0;
tr* root1 = NULL;

tr* max (tr * node){
    if(node==NULL){ return NULL;}
    while (node->right != NULL) {node = node->right;}
    return node;
}

tr* find (int v, tr *node){
    if(node==NULL){
        return NULL;
    }
    else{
        while(node!=NULL){
            if(node->value == v){
                return node;
            }else{
                if(node->value<v){ node = node->right;}
                else{ node = node->left; }
            }
        }
    }
    return NULL;
}

tr* successor(int key, tr *root)  {

    tr *node = find(key, root);

    if (node->right != NULL) {
        node = node->right;
        while (node->left != NULL) {node = node->left;}
        return node;
    }
    else {
        if (node->right == NULL && node != root && node != max(root)) {
            tr *parent = node->parent;
            while (parent != root && (node->value > parent->value)) {parent = parent->parent;}
            return parent;
        }
        else {return NULL;}
    }
}

void insert(int v){
    if (root1 == NULL) {
        root1 = (tr*)malloc(sizeof(tr));
        root1->right = NULL;
        root1->left = NULL;
        root1->parent = NULL;
        root1->value = v;
        root1->size = 1;
    }
    else {
        tr *actual = root1;
        tr *parent = NULL;
        while (actual != NULL) {
            parent = actual;
            if (v<actual->value) {
                actual->size++;
                actual = actual->left;
            }
            else {

                    if (v >= actual->value) {
                        actual->size++;
                        actual = actual->right;
                    }

            }
        }
        if (v < parent->value) {
            parent->left = (tr*)malloc(sizeof(tr));
            parent->left->value = v;
            parent->left->size = 1;
            parent->left->left = NULL;
            parent->left->right = NULL;
            parent->left->parent = parent;
        }
        if(v >= parent->value){
            parent->right = (tr*)malloc(sizeof(tr));
            parent->right->value = v;
            parent->right->size = 1;
            parent->right->left = NULL;
            parent->right->right = NULL;
            parent->right->parent = parent;
        }

    }
}

tr* delete (int v, tr *root) {
    tr *node = find(v, root);
    if(node==NULL){return NULL;}
    tr *parent = node->parent;
    tr *tmp;
    if(node->left != NULL && node->right != NULL) {
        tmp = delete(successor(v,root)->value,root);
        tmp->left = node->left;
        tmp->right = node->right;
        if (tmp->left != NULL) {tmp->left->parent = tmp;}
        if (tmp->right != NULL) {tmp->right->parent = tmp;}
        if (tmp != NULL) {tmp->parent = parent;}
        if (parent != NULL) {
            if (parent->left == node) {parent->left = tmp;
            }
            else {parent->right = tmp;}
        }
        else {
            root1 = tmp;
            return node;
        }
    }
    else
        tmp = (node->left != NULL) ? node->left : node->right;
    if(tmp != NULL)
        tmp->parent = parent;
    if(parent == NULL)
        root1 = tmp;
    else if(parent->left == node)
        parent->left = tmp;
    else
        parent->right = tmp;
    return node;
}



tr* min (tr * node){
    if(node==NULL){ return NULL;}
    while (node->left != NULL) {node = node->left;}
    return node;
}



void inorder(tr *node){
    if(node!=NULL){printf("%d ", node->value);
        inorder(node->left);

        inorder(node->right);
    }
}

int osSelect(tr *node, int i){
    if(root1->size<i){
        printf("Brak liczby na danym miejscu\n");
        return 0;
    }
    int r = 0;
    compares++;
    if(node->left==NULL){
       r=1;
    }else{
        r= node->left->size + 1;
    }
    compares++;
    if(r==i){
        return node->value;
    }else{

        compares++;
        if(i<r){
            return osSelect(node->left, i);
        }else{
            return osSelect(node->right, i-r);
        }
    }
}

int osRank(tr* node){
    if(node==NULL){
        printf("Brak poszukiwanej liczby");
        return 0;
    }
    int r = node->left->size +1;
    tr* y = node;
    while(y!=root1){
        if(y==y->parent->right){
            r=r+y->parent->left->size +1;
        }
        y=y->parent;
    }
    return r;
}
void deleteTree(tr *wezel){
    if(wezel!=NULL){
        deleteTree(wezel->left);
        deleteTree(wezel->right);
        free(wezel);
        wezel=NULL;
    }
}

int main (){


inorder(root1);

    FILE *f;
    f = fopen("osSelect.txt", "w");

    int size =100;

    for(int i=0; i<300; i++){
        root1 = NULL;
        printf("%d\n",i);
        for(int j=0; j<size; j++){
           //printf("%d\n",j);
            insert(rand());
        }

        for(int j=0; j<10000; j++){
            //printf("%d\n",j);
            osSelect(root1,rand()%(size-2)+2);

        }

        fprintf(f,"%d %d\n",size, compares/10000);
        compares=0;
        deleteTree(root1);
        size=size+100;

    }


    return 0;
}