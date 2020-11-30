#include<stdio.h>
#include<stdlib.h>

#define foreach(head, temp) for(temp=head->next; temp!=NULL; temp=temp->next)

typedef struct _node Node;

struct _node {
    int val;
    Node *next;
    Node *before;
};

Node *append_end(Node *, int);
Node *append_start(Node *, int);
Node *print_list(Node *);
Node *create_node(int);
Node *find_last(Node *);

Node *create_node(int val) {
    Node *new = (Node *)malloc(sizeof(Node));

    new->val = val;
    new->next = NULL;
    new->before = NULL;

    return new;
}


Node *append_start(Node *head, int val) {
    Node *node_new = create_node(val);

    node_new->next = head->next;
    if(head->next != NULL) {
        head->next->before = node_new;
    }
    head->next = node_new;
    node_new->before = head;

    return node_new;
}


Node *find_last(Node *head) {
    Node *temp;
    
    foreach(head, temp) {
        if(temp->next == NULL) {
            return temp;
        }
    }

    if(temp != NULL) {
        printf("Last node: %d\n", temp->val);
    }
    return temp;
}


Node *append_end(Node *head, int val) {
    Node *last_node = find_last(head);

    if(last_node == NULL) {
        append_start(head, val);
    }
    else {
        append_start(last_node, val);
    }
}


Node *print_list(Node *head) {
    Node *temp;

    foreach(head, temp) {
        printf("%d\n", temp->val);
    }

    return head;
}

int main() {
    Node *head = create_node(0);


    append_end(head, 40);
    append_start(head, 20);
    append_start(head, 10);

    print_list(head);

    return 0;
}
