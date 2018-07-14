#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct Tree{
    int value;
    struct Tree *parent;
    struct Tree *right;
    struct Tree *left;
}tr;

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
            }else{if(node->value<v){ node = node->right;}
                else{ node = node->right; }
            }
        }
    }
    return NULL;
}

int find1 (int v, tr *node){
    int compare = 0;
    if(node==NULL){
        return 0;
    }
    else{
        while(node!=NULL){
            if(node->value == v){
                compare++;
                return compare;
            }else{if(node->value<v){
                    compare++;
                    node = node->right;}
                else{ node = node->right; }
            }
        }
    }
    return compare;
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
    }
    else {
        tr *actual = root1;
        tr *parent = NULL;
        while (actual != NULL) {
            parent = actual;
            if (v<actual->value) { actual = actual->left;}
            else {
                if (v == actual->value) { return; }else {
                    if (v > actual->value) { actual = actual->right; }
                }
            }
        }
        if (v < parent->value) {
            parent->left = (tr*)malloc(sizeof(tr));
            parent->left->value = v;
            parent->left->left = NULL;
            parent->left->right = NULL;
            parent->left->parent = parent;
        }
        if(v > parent->value){
            parent->right = (tr*)malloc(sizeof(tr));
            parent->right->value = v;
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
    if(node!=NULL){
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
}

int bsth(tr *root){
    if(root==NULL){
        return 0;
    }
    int left = bsth(root->left);
    int right = bsth(root->right);
    if(left>right){
        return left+1;
    }else{
        return right +1;
    }
}

int main (){
    int tab[10000];
    for(int i=0; i<10; i++){
        insert(i);
    }
    printf("Drzewo1:\n\n");

    printf("Ilosc porownan w najlepszym przypadku: %d\n", find1(0,root1));
    printf("Ilosc porownan w najgorszym przypadku: %d\n", find1(9,root1));

    printf("Wysokosc drzewa: %d\n", bsth(root1));

    delete(0,root1);

    for(int i = 0; i<1000; i++){
        tab[i] = rand();
        insert(tab[i]);
    }

    int count = 0;

    for(int i=0; i<1000; i++){
       count +=  find1(tab[rand()%1000],root1);
    }

    printf("Ilosc porownan: %d\n", count/1000);
    printf("Wysokosc drzewa: %d\n", bsth(root1));
    return 0;
}