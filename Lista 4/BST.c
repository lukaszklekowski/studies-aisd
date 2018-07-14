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

int main (){
    char temp[256], order[15], number[15];
    FILE *fp;

    fp=fopen("test.txt", "rt");
    if(fp==NULL) {
        return 1;
    }

    fgets(temp, 256, fp);

    int n = atoi(temp);

    for(int k = 0; k<15; k++){
        order[k] = '\0';
        number[k] = '\0';
    }

    for(int i = 0; i<n; i++) {
        fgets(temp, 256, fp);
        int j = 0;
        while (temp[j]!=' ' && temp[j]!='\0' && temp[j] != '\n'){
            order[j] = temp[j];
            j++;
        }
        j++;
        int in = 0;
        if(strcmp(order,"insert")==0){
            while (temp[j]!='\0'){
                number[in] = temp[j];
                j++;
                in++;
            }
            int v = atoi(number);
            insert(v);
        }
        if(strcmp(order,"delete")==0){
            while (temp[j]!='\0'){
                number[in] = temp[j];
                j++;
                in++;
            }
            int v = atoi(number);
            delete(v, root1);
        }
        if(strcmp(order,"find")==0){
            while (temp[j]!='\0'){
                number[in] = temp[j];
                j++;
                in++;
            }
            int v = atoi(number);
            tr *tmp = find(v, root1);
            if(tmp!=NULL){
                printf("1\n");
            }else{
                printf("0\n");
            }
        }
        if(strcmp(order,"min")==0){
            tr *tmp = min(root1);
            if(tmp!=NULL){
                printf("%d\n",tmp->value);
            }else{
                printf("Empty Tree\n");
            }
        }
        if(strcmp(order,"max")==0){
            tr *tmp = max(root1);
            if(tmp!=NULL){
                printf("%d\n",tmp->value);
            }else{
                printf("Empty Tree\n");
            }
        }
        if(strcmp(order,"inorder")==0){
            if(root1==NULL){
                printf("Empty Tree");
            }else {
                inorder(root1);
                printf("\n");
            }
        }

        for(int k = 0; k<15; k++){
            order[k] = '\0';
            number[k] = '\0';
       }

    }
    return 0;
}
