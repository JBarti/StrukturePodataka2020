#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

int main() {
    Tree *head = create_leaf("");

    add_child(head, "T1");
    add_child(head, "T2");
    add_child(head, "T3");

    print_children(head);
}

