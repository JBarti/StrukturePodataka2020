#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"


int isnum(char *str) {
    int size = strlen(str);
    int i;

    for(i=0; i<size; i++) {
        if(!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
    }

    return 1;
}

char *get_expr(char *filename) {
    FILE *fp = fopen(filename, "r");
    char buff[100];

    fgets(buff, 100, fp);
    
    fclose(fp);

    return strdup(buff);
}


char *get_next_val(char *expression) {
    static int step = 0;

    char buff[10];
    int size=0;

    sscanf(expression+step, "%s%n", buff, &size);

    if(size == 0) { return NULL; }

    step += size+1;
    return strdup(buff);
}


Node *build_expr_stack(char *expr) {
    char *expr_elem = get_next_val(expr);
    Node *head = create_node(NULL);

    while(expr_elem != NULL) {
        push_to_stack(head, expr_elem);
        expr_elem = get_next_val(expr);
    }

    return head;
}


Tree *build_expr_tree_util(Node *expr_stack, Tree *root) {
    if(expr_stack->next == NULL) {
        return root;
    }

    char *val1 = pop_from_stack(expr_stack)->val; 
    char *val2 = pop_from_stack(expr_stack)->val; 
    
    printf("%s %s\n", val1, val2);

    if(val1 == NULL || val2 == NULL) {
        printf("Tree not balanced.\n");
        return root;
    }

    Tree *leaf1 = add_leaf(root, val1);
    Tree *leaf2 = add_leaf(root, val2);

    if(!isnum(val1)) {
        build_expr_tree_util(expr_stack, leaf1);
    }
    
    if(!isnum(val2)) {
        build_expr_tree_util(expr_stack, leaf2);
    }

    return root;
}


Tree *build_expr_tree(char *expr) {
    Node *expr_stack = build_expr_stack(expr);
    print_stack(expr_stack);

    char *root_val = pop_val_from_stack(expr_stack);
    Tree *root = create_leaf(root_val);

    Tree *expr_tree = build_expr_tree_util(expr_stack, root);

    return NULL;
}


void print_expr(Tree *expr_tree) {
    if(expr_tree->ptr_right == NULL || expr_tree->ptr_left == NULL) {
        return;
    }    

    printf("%s", expr_tree->val);

    Tree *left = expr_tree->ptr_left;
    Tree *right = expr_tree->ptr_right;

    if(isnum(left->val)) {
        printf("%s", left->val);
    }
    else {
        print_expr(left);
    }

    if(isnum(right->val)) {
        printf("%s", right->val);
    }
    else {
        print_expr(right);
    }
}


int main() {
    char *expr = get_expr("./expr.txt");

    Tree *expr_tree = build_expr_tree(expr);

    printf("PRINTAJ\n");
    print_expr(expr_tree);

    return 1;
}
