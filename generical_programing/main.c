#include<stdio.h>
#include<stdlib.h>


typedef struct _node node;

struct _node {
    void *val;
    node *next;
};


node *create_node(int val) {
    node *nnode = (node *)malloc(sizeof(node));

    nnode->val = malloc(sizeof(int));
    *(int *)(nnode->val) = val;
    nnode->next = NULL;

    return nnode;
}

int main() {
    node *nnode = create_node(332);

    printf("%d", *(char *)(nnode->val));
}
