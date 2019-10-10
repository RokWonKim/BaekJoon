#include <stdio.h>
#include <stdlib.h>

typedef struct Linkedlist {
    struct Linkedlist* left;
    struct Linkedlist* right;
    int value;
}Linkedlist;

Linkedlist* insertNode(int value, Linkedlist* h){
    if (h == NULL) {
        Linkedlist* node = (Linkedlist*)malloc(sizeof(Linkedlist));
        h = node;
        h->value = value;
    }
    else if (h->value > value)
        h->left = insertNode(value, h->left);
    else if (h->value < value)
        h->right = insertNode(value, h->right);
    return h;
}

int searchNode(int value, Linkedlist* h) {
    if(h == NULL)
        return 0;
    else if (h->value == value)
        return 1;
    else if (h->value > value)
        return searchNode(value, h->left);
    else
        return searchNode(value, h->right);
}

int main(void) {

    int N;
    int M;
    int a;
    int seek;
    Linkedlist* h;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a);
        if (i == 0) {
            h = (Linkedlist*)malloc(sizeof(Linkedlist));
            h->value = a;
        }
        else
            h = insertNode(a, h);
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d", &a);
        seek = searchNode(a, h);
        printf("%d\n",seek);
    }
    return 0;
}

