#include<stdio.h>
#include<stdlib.h>

#define foreach(head, temp) for(temp=head->next; temp != head; temp=temp->next)

typedef struct _node Node;

struct _node {
    int val;
    Node *next;
};

Node *create_node(int);
Node *find_last(Node *);
Node *append_start(Node *, int);
Node *prepend_end(Node *, int);
Node *delete(Node *, int);


Node *create_node(int val) {
    Node *new = (Node *)malloc(sizeof(Node));
    
    new->val = val;
    new->next = NULL;

    return new;
}


Node *find_last(Node *head) {
    Node *temp;

    if(head->next == NULL) { return NULL; }
    foreach(head, temp) {
        if(temp->next == head) { return temp; }
    }    

    printf("Can't find last node. \n");
    return NULL;
}


Node *append_start(Node *head, int val) {
    Node *new_node = create_node(val);
    Node *last_node = find_last(head);

    new_node->next = head->next;
    head->next = new_node;

    if(last_node == NULL) {
        new_node->next = head;
    }
    else {
        last_node->next = head;
    }

    return head;
}


Node *append_end(Node *head, int val) {
    Node *new_node = create_node(val);
    Node *last_node = find_last(head);

    if(last_node == NULL) {
        head->next = new_node;
    }
    else {
        last_node->next = new_node;
    }

    new_node->next = head;

    return new_node;
}


Node *print_list(Node *head) {
    Node *temp;
    foreach(head, temp) {
        printf("%d\n", temp->val);
    }

    return head;
}


Node *delete(Node *head, int val) {
    Node *temp;

    if(head->next->val == val) {
        Node *to_delete = head->next; 
        head->next = to_delete->next;
        free(to_delete);
        return head->next;
    }

    foreach(head, temp) {
        if(temp->next->val == val && temp != head) {
            Node *to_delete = temp->next;
            temp->next = to_delete->next;
            free(to_delete);
            return temp;
        }
    } 

    printf("Couldn't delete element.\n");
    return NULL;
}

Node *insert_after(Node *head, int where, int what) {
    Node *temp;
    foreach(head, temp) {
        if(temp->val == where) { 
            return append_start(temp, what); 
        }
    }

    printf("Can't insert_after, node not found !\n");
    return NULL;
}

Node *insert_before(Node *head, int where, int what) {
    Node *temp;
    
    if(head->next->val == where) {
        return append_start(head, what);
    }

    foreach(head, temp) {
        if(temp->next->val == where) {
            return append_start(temp, what);
        }
    }

    printf("Can't insert_before, node not found !\n");
    return NULL;
}


int main() {
    Node *head = create_node(0);

    append_end(head, 10);
    append_end(head, 20);
    append_start(head, 30);

    insert_before(head, 30, 15);

    print_list(head);

    //printf("%d\n", head->next->next->next->next->val);

    return 0;
}
