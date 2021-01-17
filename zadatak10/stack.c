#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

#define foreach(p, q) for(p=q->next; p!=NULL; p=p->next)
#define ADD_LEAF_LEFT 0
#define ADD_LEAF_RIGHT 1

extern int errno;


Tree *create_leaf(char *str) {
    Tree *new_leaf = (Tree *)malloc(sizeof(Tree));

    if(new_leaf == NULL) {
        printf("Unable to allocate space.\n");
        exit(1);
    }

    new_leaf->val = strdup(str);
    new_leaf->ptr_left = NULL;
    new_leaf->ptr_right = NULL;

    return new_leaf;
}

Tree *add_leaf_at(Tree *head, char *val, int pos_flag) {
    Tree *new_tree = NULL;

    if(pos_flag == ADD_LEAF_LEFT) {
        new_tree = create_leaf(val);
        head->ptr_left = new_tree;
    }
    else if(pos_flag == ADD_LEAF_RIGHT) {
        new_tree = create_leaf(val);
        head->ptr_right = new_tree;
    }
    else {
        printf("Invalid flag %d\n", pos_flag);
    }

    return new_tree;
}


Tree *add_leaf(Tree *head, char *val) {
    if(head->ptr_left == NULL) {
        return add_leaf_at(head, val, ADD_LEAF_LEFT);
    }
    else if(head->ptr_right == NULL) {
        return add_leaf_at(head, val, ADD_LEAF_RIGHT);
    }

    printf("No empty space for new leaf at node: %s\n", head->val);
    return NULL;
}


Node *create_node(char *val) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Unable to allocate space\n");
        return NULL;
    }

    new_node->next = NULL;
    new_node->val = val;

    return new_node;
}


Node *pop_from_stack(Node *head) {
    if(head->next == NULL) {
        printf("No elements to pop\n");
        return NULL;
    }

    Node *removed = head->next;
    head->next = removed->next;
    return removed;
}


char *pop_val_from_stack(Node *head) {
    if(head->next == NULL) {
        printf("No elements to pop\n");
        return NULL;
    }

    Node *poped = pop_from_stack(head);
    char *poped_val = poped->val;

    free(poped);

    return poped_val;
}


Node *push_to_stack(Node *head, char *val) {  
    Node *new_node = create_node(val);

    new_node->next = head->next;
    head->next = new_node;

    return new_node;
}


void print_stack(Node *head) {
    Node *temp;

    foreach(temp, head) {
        printf("%s\n", temp->val);
    }
}
